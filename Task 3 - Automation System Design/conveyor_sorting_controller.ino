/**
 * @file conveyor_sorting_controller.ino
 * @brief Automated Industrial Conveyor Sorting Controller
 * @author CodeAlpha Robotics & Automation Intern
 * @date September 2026
 * 
 * Hardware:
 * - Arduino Mega / Uno (ATmega328P)
 * - L298N Dual H-Bridge Motor Driver
 * - E18-D80NK Infrared Obstacle Sensor
 * - LJ12A3-4-Z/BX Inductive Proximity Sensor
 * - MG996R High-Torque Servomotors (Diverters)
 */

#include <Servo.h>

// Pin Definitions
const int PIN_IR_ENTRY     = 2;   // INT0: Entry Optical Sensor
const int PIN_INDUCTIVE    = 3;   // INT1: Inductive Proximity Sensor
const int PIN_ESTOP        = 4;   // Emergency Stop Button
const int PIN_SERVO_METAL  = 5;   // Servo Diverter 1 (Metallic Bin)
const int PIN_SERVO_HEIGHT = 6;   // Servo Diverter 2 (Oversize Bin)
const int PIN_MOTOR_PWM    = 9;   // Motor Speed (PWM)
const int PIN_MOTOR_IN1    = 7;   // Motor Direction A
const int PIN_MOTOR_IN2    = 8;   // Motor Direction B
const int PIN_LED_GREEN    = 10;  // System Running
const int PIN_LED_RED      = 11;  // Fault / E-Stop
const int PIN_BUZZER       = 12;  // Alarm Buzzer

// Actuator Objects
Servo servoMetal;
Servo servoHeight;

// System Timing & State Variables
volatile bool isEmergencyStopped = false;
unsigned long lastItemTime = 0;
const unsigned long TRANSIT_TIME_GATE1 = 1500; // ms from IR to Gate 1
const unsigned long TRANSIT_TIME_GATE2 = 2800; // ms from IR to Gate 2

void setup() {
  Serial.begin(115000);
  Serial.println(F("[SYSTEM INIT] Industrial Conveyor Sorting Active."));

  // Configure Pins
  pinMode(PIN_IR_ENTRY, INPUT_PULLUP);
  pinMode(PIN_INDUCTIVE, INPUT);
  pinMode(PIN_ESTOP, INPUT_PULLUP);
  pinMode(PIN_MOTOR_PWM, OUTPUT);
  pinMode(PIN_MOTOR_IN1, OUTPUT);
  pinMode(PIN_MOTOR_IN2, OUTPUT);
  pinMode(PIN_LED_GREEN, OUTPUT);
  pinMode(PIN_LED_RED, OUTPUT);
  pinMode(PIN_BUZZER, OUTPUT);

  // Attach Servos
  servoMetal.attach(PIN_SERVO_METAL);
  servoHeight.attach(PIN_SERVO_HEIGHT);
  resetDiverters();

  // Attach Emergency Interrupt
  attachInterrupt(digitalPinToInterrupt(PIN_ESTOP), handleEStop, FALLING);

  // Start Conveyor at Nominal Speed
  startConveyor(200); // 0-255 PWM duty cycle
  digitalWrite(PIN_LED_GREEN, HIGH);
}

void loop() {
  if (isEmergencyStopped) {
    haltSystem();
    return;
  }

  // Poll Entry IR Sensor (Active LOW)
  if (digitalRead(PIN_IR_ENTRY) == LOW) {
    Serial.println(F("-> Object Detected at Infeed. Inspecting..."));
    delay(50); // Debounce

    // Sample Inductive Sensor
    bool isMetallic = (digitalRead(PIN_INDUCTIVE) == HIGH);

    if (isMetallic) {
      Serial.println(F("   [CLASSIFICATION] Metallic Parcel Detected. Scheduling Diverter 1."));
      delay(TRANSIT_TIME_GATE1);
      divertMetal();
    } else {
      Serial.println(F("   [CLASSIFICATION] Non-Metallic Parcel. Passing through to Default Bin."));
    }

    // Wait until object clears infeed beam
    while (digitalRead(PIN_IR_ENTRY) == LOW) {
      delay(10);
    }
  }
}

void startConveyor(uint8_t speed) {
  digitalWrite(PIN_MOTOR_IN1, HIGH);
  digitalWrite(PIN_MOTOR_IN2, LOW);
  analogWrite(PIN_MOTOR_PWM, speed);
}

void stopConveyor() {
  digitalWrite(PIN_MOTOR_IN1, LOW);
  digitalWrite(PIN_MOTOR_IN2, LOW);
  analogWrite(PIN_MOTOR_PWM, 0);
}

void resetDiverters() {
  servoMetal.write(0);   // Retracted
  servoHeight.write(0);  // Retracted
}

void divertMetal() {
  servoMetal.write(60); // Deploy diverter arm
  delay(1200);          // Allow parcel to divert
  servoMetal.write(0);  // Retract
  Serial.println(F("   [DIVERT COMPLETE] Gate 1 Retracted."));
}

void handleEStop() {
  isEmergencyStopped = true;
}

void haltSystem() {
  stopConveyor();
  resetDiverters();
  digitalWrite(PIN_LED_GREEN, LOW);
  digitalWrite(PIN_LED_RED, HIGH);
  tone(PIN_BUZZER, 1000);
  Serial.println(F("!!! CRITICAL: EMERGENCY STOP ENGAGED !!!"));
  while (true) {
    // Lock until hardware power cycle
    delay(500);
  }
}
