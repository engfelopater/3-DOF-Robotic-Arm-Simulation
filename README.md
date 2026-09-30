# CodeAlpha Robotics & Automation Internship Portfolio

![Robotics & Automation](https://img.shields.io/badge/Domain-Robotics%20%26%20Automation-blue.svg)
![SolidWorks 2026](https://img.shields.io/badge/CAD-SOLIDWORKS%202026-red.svg)
![AI & Edge Compute](https://img.shields.io/badge/AI-NVIDIA%20Jetson%20Orin-76B900.svg)
![Status](https://img.shields.io/badge/Tasks%20Completed-4%20of%204%20(100%25)-success.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)

This repository contains the complete technical engineering deliverables for the **CodeAlpha Robotics & Automation Internship Program (September 2026)**. All 4 tasks have been comprehensively completed, modeled, simulated, and documented according to industrial engineering standards.

---

## 📂 Repository Structure

```tree
codealpha_tasks/
├── Task 1 - Research Report/
│   ├── Autonomous_Vehicles_vs_Drones_IEEE.tex             # IEEE Conference LaTeX Source
│   ├── Autonomous_Vehicles_vs_Drones_Research_Report.md   # Complete Academic Markdown Report
│   └── Autonomous_Vehicles_vs_Drones_Research_Report.html # Formatted Printable HTML/PDF Report
│
├── Task 2 - Robotic Arm Simulation/
│   ├── CAD_Models/
│   │   ├── Base.SLDPRT                                   # 3D Solid Base Flange & Azimuth Axis
│   │   ├── Link1_Shoulder.SLDPRT                         # 3D Solid Shoulder Boom Link (KUKA Orange)
│   │   ├── Link2_Forearm.SLDPRT                          # 3D Solid Forearm Beam Link (Metallic)
│   │   ├── Gripper.SLDPRT                                # 3D Solid Two-Jaw Parallel Gripper
│   │   ├── Target_Box.SLDPRT                             # 3D Solid Target Payload Cube (Red)
│   │   └── Robotic_Arm_Assembly.SLDASM                   # Master Kinematic Assembly with 8 Mates
│   └── Robotic_Arm_Technical_Report.md                   # Full Kinematics & D-H Parameters Report
│
├── Task 3 - Automation System Design/
│   ├── Conveyor_Sorting_Automation_Report.md             # 3-Page System Engineering Report
│   ├── circuit_diagram.svg                               # Vector Electrical & Interconnect Schematic
│   ├── system_flowchart.svg                              # State Machine Logic Flowchart Diagram
│   └── conveyor_sorting_controller.ino                   # Embedded C++ / Arduino Controller Firmware
│
└── Task 4 - Mini Project Proposal/
    ├── Role_of_AI_in_Autonomous_Robots_Proposal.md       # 5–6 Page Industrial Engineering Proposal
    └── Role_of_AI_in_Autonomous_Robots_Proposal.html     # Styled Printable A4 Technical Proposal
```

---

## 📑 Tasks Summary

### ✅ Task 1: Autonomous Vehicles vs. Drones (Comparative Research Report)
* **Topic:** *Autonomous Vehicles vs. Unmanned Aerial Vehicles (drones): A Comparative Analysis of Sensing, Navigation, and Regulatory Challenges.*
* **Content:** Multi-modal sensor suites (LiDAR, Radar, Cameras, IMU, GNSS, Barometers, Ultrasonic), Terrestrial HD Maps vs. Aerial 6-DOF Visual-Inertial Odometry, SWaP-C constraints, FAA Part 135 & ISO 26262 regulations, and Symbiotic Multimodal Hybrid Logistics.
* **Formats:** IEEE Conference LaTeX (`.tex`), Markdown (`.md`), and HTML.

---

### ✅ Task 2: 3-DOF Robotic Arm Mechanical Design & Simulation
* **Platform:** Dassault Systèmes SOLIDWORKS 2026.
* **Kinematics:** 3-DOF Revolute-Revolute-Revolute (RRR) spatial manipulator + 1-DOF parallel mechanical gripper.
* **Modeling:** 100% Solid 3D CAD parts (`.SLDPRT`), master assembly (`.SLDASM`) with 8 kinematic distance and coincident constraints.
* **Motion Study:** Validated Pick-and-Place sequence transporting a $25\text{ mm}$ payload from pickup to dropoff.

---

### ✅ Task 3: Intelligent Sensor-Based Conveyor Sorting System
* **Architecture:** Multi-sensor industrial sorting station combining Optical IR, Inductive Proximity (eddy-current metal sensing), and Time-of-Flight (ToF) height profiling.
* **Actuation:** Dual high-speed servo diverter gates (MG996R) and PWM DC motor conveyor drive.
* **Deliverables:** Full 3-page report, vector circuit schematic (`circuit_diagram.svg`), logic flowchart (`system_flowchart.svg`), and production-ready embedded C++ firmware (`conveyor_sorting_controller.ino`).

---

### ✅ Task 4: Role of AI in Next-Gen Autonomous Mobile Robots (Mini Project)
* **Title:** *Edge-AI Enabled Autonomous Mobile Robot for Unstructured Dynamic Industrial Environments.*
* **Scope:** 5–6 page technical engineering proposal covering NVIDIA Jetson AGX Orin edge computing, YOLOv10 TensorRT perception, Soft Actor-Critic (SAC) Deep Reinforcement Learning for dynamic obstacle avoidance, ISO 3691-4 / ANSI R15.08 safety standards, 6-month WBS timeline, and prototype budget matrix ($8,447 USD).
* **Formats:** Full technical Markdown proposal and styled printable HTML.

---

## 🛠️ Software & Tools Used
* **CAD & Simulation:** Dassault Systèmes SOLIDWORKS 2026
* **Typography & Typesetting:** LaTeX (IEEEtran), Markdown, HTML5/CSS3
* **Embedded & Automation:** Arduino C++, Micro-ROS, ROS 2 Humble
* **Version Control:** Git & GitHub

---

## 👤 Author
* **Intern:** Robotics & Industrial Automation Intern
* **Program:** CodeAlpha Technology Internship
* **Date:** September 30, 2026
