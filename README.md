# CodeAlpha Robotics & Automation Internship Portfolio

![Robotics & Automation](https://img.shields.io/badge/Domain-Robotics%20%26%20Automation-blue.svg)
![SolidWorks 2026](https://img.shields.io/badge/CAD-SOLIDWORKS%202026-red.svg)
![Status](https://img.shields.io/badge/Status-Completed-success.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)

This repository contains the complete technical deliverables for the **CodeAlpha Robotics & Automation Internship Program (September 2026)**.

---

## 📂 Repository Structure

```tree
codealpha_tasks/
├── Task 1 - Research Report/
│   ├── Autonomous_Vehicles_vs_Drones_IEEE.tex             # IEEE Conference LaTeX Source
│   ├── Autonomous_Vehicles_vs_Drones_Research_Report.md   # Complete Academic Markdown Report
│   └── Autonomous_Vehicles_vs_Drones_Research_Report.html # Interactive Formatted Report
│
├── Task 2 - Robotic Arm Simulation/
│   ├── CAD_Models/
│   │   ├── Base.SLDPRT                                   # 3D Base Flange & Azimuth Axis
│   │   ├── Link1_Shoulder.SLDPRT                         # 3D Shoulder Boom Link
│   │   ├── Link2_Forearm.SLDPRT                          # 3D Forearm Beam Link
│   │   ├── Gripper.SLDPRT                                # 3D Two-Jaw Mechanical Gripper
│   │   ├── Target_Box.SLDPRT                             # 3D Target Payload Cube
│   │   └── Robotic_Arm_Assembly.SLDASM                   # Master Kinematic Assembly
│   └── Robotic_Arm_Technical_Report.md                   # Full Kinematics & DOF Report
│
└── Task 3 - Automation System Design/
    ├── Conveyor_Sorting_Automation_Report.md             # 3-Page System Engineering Report
    └── conveyor_sorting_controller.ino                   # Embedded C++ / Arduino Controller Code
```

---

## 📑 Tasks Overview

### ✅ Task 1: Autonomous Vehicles vs. Drones (Research Report)
* **Topic:** *Autonomous Vehicles vs. Unmanned Aerial Vehicles (drones): A Comparative Analysis of Sensing, Navigation, and Regulatory Challenges.*
* **Scope:**
  * Multi-modal sensor suites (LiDAR, Radar, Cameras, IMU, GNSS, Barometers, Ultrasonic).
  * Navigation architectures: Terrestrial HD Maps + Factor Graph SLAM vs. Aerial 6-DOF Visual-Inertial Odometry (VIO) and Minimum Snap trajectories.
  * Operational constraints (Payload, SWaP-C, Weather, Fail-Safe states).
  * Regulatory frameworks (FAA Part 135, BVLOS, ISO 26262 ASIL-D, SOTIF).
  * Future Multimodal Hybrid Integration (Mobile Mothership & In-Transit Autonomous Docking).
* **Deliverable Formats:** Full academic paper available in LaTeX (`.tex`) and Markdown (`.md`).

---

### ✅ Task 2: 3-DOF Robotic Arm Mechanical Design & Simulation
* **Platform:** Dassault Systèmes SOLIDWORKS 2026.
* **Kinematics:** 3-DOF Revolute-Revolute-Revolute (RRR) spatial manipulator + 1-DOF Prismatic parallel gripper.
* **Mates & Constraints:** Fully constrained assembly utilizing 8 kinematic mates (distance, concentric, and planar coincident constraints).
* **Simulation Protocol:** Pick-and-Place trajectory picking up a $25\text{ mm}$ payload, executing an azimuth translation arc, and depositing it at the target station.
* **Deliverable Files:** Native SolidWorks parts (`.SLDPRT`), master assembly (`.SLDASM`), and mathematical D-H parameter analysis.

---

### ✅ Task 3: Automated Industrial Conveyor Sorting System
* **Architecture:** Multi-sensor sorting station utilizing Optical Infrared (IR), Inductive Proximity (Eddy-Current), and Time-of-Flight (ToF) height profiling.
* **Actuation:** Dual high-speed servo diverter gates (MG996R) and PWM DC conveyor drive with L298N H-Bridge.
* **Control:** Embedded firmware implementing real-time classification, debounced interrupts, and emergency stop (E-Stop) hardware fail-safes.
* **Deliverable Files:** Architectural report and production-ready embedded C++ firmware (`.ino`).

---

## 🛠️ Software & Tools Used
* **CAD & Simulation:** Dassault Systèmes SOLIDWORKS 2026
* **Typography & Typesetting:** LaTeX (IEEEtran), Markdown, HTML5/CSS3
* **Embedded Programming:** Arduino C++ / Embedded C
* **Version Control:** Git & GitHub

---

## 👤 Author
* **Intern:** Robotics & Industrial Automation Intern
* **Program:** CodeAlpha Technology Internship
* **Submission Date:** September 30, 2026
