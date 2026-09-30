# Technical Report: 3-DOF Articulated Robotic Arm with Pick-and-Place Simulation

**Program:** CodeAlpha Robotics & Automation Internship  
**Task:** Task 2 – Robotic Arm Simulation  
**Platform:** Dassault Systèmes SOLIDWORKS 2026  
**Author:** Robotics & Automation Intern  
**Date:** September 2026  

---

## 1. Executive Summary
This technical document presents the mechanical design, kinematic configuration, and pick-and-place motion simulation of an articulated industrial robotic arm designed natively in SOLIDWORKS. The robotic arm is engineered as a 3-Degree-of-Freedom (3-DOF) Revolute-Revolute-Revolute (RRR) spatial manipulator equipped with a parallel two-jaw mechanical end-effector. The kinematic chain is mathematically modeled using the standard Denavit-Hartenberg (D-H) convention. A full motion study validates the dynamic trajectory required to pick a payload ($25 \times 25 \times 25\text{ mm}$ target cube) from a defined pickup zone, elevate and translate it across a spatial arc, and place it at an off-axis target repository.

---

## 2. Degrees of Freedom (DOF) Analysis

The robotic manipulator possesses **3 primary rotational degrees of freedom (3-DOF)** governing spatial positioning, supplemented by a 1-DOF prismatic grasping action at the end-effector.

```
       [Gripper / End-Effector] (Tool Center Point - TCP)
                 |
             (Joint 3: Elbow Pitch)
                 |
              [Link 2: Forearm - 140 mm]
                 |
             (Joint 2: Shoulder Pitch)
                 |
              [Link 1: Boom - 180 mm]
                 |
             (Joint 1: Base / Waist Yaw - Z Axis)
                 |
         [Base Pedestal & Flange]
```

### 2.1 Joint Kinematic Specifications:
1. **Joint 1 (Base / Waist - Yaw):**
   * **Motion Type:** Revolute ($R_1$) around vertical Z-axis.
   * **Range of Motion:** $0^\circ \text{ to } 360^\circ$ continuous rotation.
   * **Role:** Establishes the azimuthal orientation of the entire manipulator arm in the horizontal plane ($X\text{--}Y$).
2. **Joint 2 (Shoulder - Pitch):**
   * **Motion Type:** Revolute ($R_2$) around horizontal Y-axis.
   * **Range of Motion:** $-15^\circ \text{ to } +105^\circ$ elevation.
   * **Role:** Dictates vertical reach and primary elevation of Link 1.
3. **Joint 3 (Elbow - Pitch):**
   * **Motion Type:** Revolute ($R_3$) around horizontal Y-axis parallel to Joint 2.
   * **Range of Motion:** $0^\circ \text{ to } +135^\circ$ flexion.
   * **Role:** Controls radial reach, enabling the Tool Center Point (TCP) to extend forward or fold inward.
4. **End-Effector (Parallel Gripper):**
   * **Motion Type:** Prismatic linear translation (dual-finger pinch).
   * **Grip Stroke:** $28\text{ mm}$ internal clearance designed to reliably clamp the $25\text{ mm}$ payload.

---

## 3. Denavit-Hartenberg (D-H) Kinematic Parameters

The forward kinematics of the manipulator link frames are defined via standard D-H notation:

| Link $i$ | Joint Angle $\theta_i$ | Link Twist $\alpha_i$ | Link Length $a_i$ (mm) | Link Offset $d_i$ (mm) | Operating Range |
| :---: | :---: | :---: | :---: | :---: | :---: |
| **1 (Base)** | $\theta_1^*$ | $+90^\circ$ | $0\text{ mm}$ | $d_1 = 50\text{ mm}$ | $[0^\circ, 360^\circ]$ |
| **2 (Shoulder)**| $\theta_2^*$ | $0^\circ$ | $a_2 = 180\text{ mm}$ | $0\text{ mm}$ | $[-15^\circ, 105^\circ]$|
| **3 (Elbow)** | $\theta_3^*$ | $0^\circ$ | $a_3 = 140\text{ mm}$ | $0\text{ mm}$ | $[0^\circ, 135^\circ]$ |
| **Tool (TCP)** | $0^\circ$ | $0^\circ$ | $a_4 = 40\text{ mm}$ | $0\text{ mm}$ | Fixed Tool Offset |

$$\text{Homogeneous Transformation Matrix: } T_i^{i-1} = \text{Rot}_{z}(\theta_i) \text{Trans}_{z}(d_i) \text{Trans}_{x}(a_i) \text{Rot}_{x}(\alpha_i)$$

---

## 4. SolidWorks CAD Mechanical Architecture

All components were modeled natively in SOLIDWORKS 2026:

1. **`Base.SLDPRT`:** Heavy circular base flange ($\varnothing 120\text{ mm} \times 20\text{ mm}$) with an elevated central bearing pedestal ($\varnothing 60\text{ mm}$) and precision pivot pin ($\varnothing 30\text{ mm}$). Finished in matte anthracite cast iron.
2. **`Link1_Shoulder.SLDPRT`:** High-rigidity rectangular structural boom ($224\text{ mm} \times 44\text{ mm} \times 25\text{ mm}$) featuring reamed pivot bushings ($\varnothing 30\text{ mm}$ base, $\varnothing 24\text{ mm}$ elbow). Finished in industrial high-visibility safety orange (KUKA/ABB aesthetic).
3. **`Link2_Forearm.SLDPRT`:** Lightweight aluminum alloy horizontal forearm beam ($180\text{ mm} \times 36\text{ mm} \times 20\text{ mm}$) balancing inertial mass during high-speed actuation. Finished in anodized silver.
4. **`Gripper.SLDPRT`:** Two-jaw parallel mechanical clamping hand with a $25\text{ mm}$ stroke channel to securely mate with the target payload.
5. **`Target_Box.SLDPRT`:** A $25 \times 25 \times 25\text{ mm}$ reference cube finished in high-contrast crimson red for visual trajectory verification.
6. **`Robotic_Arm_Assembly.SLDASM`:** The master kinematic assembly incorporating 8 concentric, distance, and coincident mates constraining motion to the theoretical kinematic degrees of freedom.

---

## 5. Motion Simulation Protocol (Pick-and-Place Study)

The motion study was configured in the SOLIDWORKS **Motion Study** environment using Keyframe Animation / Basic Motion:

```
[0.0s] Home Pose -------> [2.0s] Descent & Align -------> [2.5s] Grip Clamping
                                                                   |
[6.0s] Return to Base <--- [5.0s] Descent & Release <--- [3.8s] Elevation & Arc
```

* **Phase 1: Home / Approach ($t = 0.0\text{s} \to 2.0\text{s}$):** Shoulder ($\theta_2$) and Elbow ($\theta_3$) rotate downward from standby to position the gripper jaws directly over the payload at $(X=0.14\text{ m}, Y=0.02\text{ m}, Z=0\text{ m})$.
* **Phase 2: Gripping ($t = 2.0\text{s} \to 2.5\text{s}$):** Parallel jaws close, forming structural contact with the payload.
* **Phase 3: Lift & Trajectory Transfer ($t = 2.5\text{s} \to 4.0\text{s}$):** Shoulder elevates to $+45^\circ$, lifting the box $120\text{ mm}$ vertically. Base ($\theta_1$) rotates $90^\circ$ along the azimuth.
* **Phase 4: Placement & Release ($t = 4.0\text{s} \to 5.0\text{s}$):** Forearm extends downward to set the payload gently on the target deposit zone. Jaws retract.
* **Phase 5: Return to Home ($t = 5.0\text{s} \to 6.0\text{s}$):** Manipulator returns smoothly to the upright initial configuration.

---

## 6. Verification and Submission Checklist
* [x] Complete 3D solid models modeled natively (`.SLDPRT`).
* [x] Master kinematic assembly with applied mates (`.SLDASM`).
* [x] Verified Degrees of Freedom (DOF) definition.
* [x] Motion Study pick-and-place execution sequence.
* [x] Technical report documenting mathematical and engineering parameters.
