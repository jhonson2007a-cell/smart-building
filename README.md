# smart-building
smart building for save energy
# ⚡ AI-Driven Zonal Energy Manager

> **Smart Buildings & Campuses | AI + IoT Based Energy Optimization System**

An AI-powered IoT solution designed to reduce unnecessary energy consumption in **educational campuses, hostels, offices, laboratories, classrooms, and commercial buildings** by automatically controlling electrical appliances based on real-time occupancy and usage patterns.

---

## 🚀 Problem Statement

In colleges, hostels, offices, and commercial buildings, **lights, fans, and air conditioners often remain ON even when rooms are empty**.

Traditional solutions such as manual switches and fixed timers are not effective because room occupancy changes dynamically.

This results in:

* ⚡ Unnecessary electricity consumption
* 💰 Higher electricity bills
* 🌱 Increased carbon emissions
* 🏢 Inefficient building management
* ❌ Manual monitoring and control

---

## 💡 Our Solution

**AI-Driven Zonal Energy Manager** combines **AI, IoT, occupancy detection, and predictive analytics** to automatically manage energy consumption zone-by-zone.

### How it works

```text
Occupancy Sensors / Camera
          ↓
   AI Occupancy Detection
          ↓
   ESP32 / Raspberry Pi
          ↓
       MQTT Network
          ↓
  Energy Management Engine
          ↓
 ┌────────┼─────────┐
 ↓        ↓         ↓
Lights    Fans      AC
 ↓        ↓         ↓
 ON/OFF   Control   Cooling
          ↓
     Web Dashboard
          ↓
 Energy Saving Analytics
```

---

## ✨ Key Features

### 👥 1. Real-Time Occupancy Detection

The system detects whether a room is occupied and estimates the number of people.

Possible inputs:

* PIR sensors
* CCTV camera
* ESP32 camera
* Existing building sensors

For camera-based detection, a lightweight **YOLO model** can be used.

---

### 💡 2. Automatic Appliance Control

When a room becomes empty for a configurable period:

```text
Room Empty
     ↓
Wait 3–5 Minutes
     ↓
Check Occupancy Again
     ↓
No Occupants
     ↓
Turn OFF / Standby
Lights + Fans + AC
```

This helps prevent energy wastage caused by appliances being accidentally left ON.

---

### ❄️ 3. Smart HVAC Management

Instead of simply turning the AC ON/OFF, the system can use occupancy information to adjust cooling requirements.

Example:

```text
0 People → AC Standby
5 People → Normal Cooling
20 People → Higher Cooling Requirement
```

The exact control strategy depends on the connected HVAC system.

---

### 🧠 4. Predictive Pre-Cooling

The system can combine:

* College timetable
* Historical occupancy
* Room usage patterns
* Temperature
* Day/time

to predict when a room will be occupied.

Example:

```text
10:00 AM → Class starts
        ↓
Prediction
        ↓
09:55 AM → Start Pre-Cooling
        ↓
10:00 AM → Room Ready
```

Instead of cooling an empty room for a long period, cooling starts closer to actual usage.

---

### 📊 5. Real-Time Dashboard

The dashboard provides building-level and room-level information.

### Dashboard Metrics

* 🔌 Current Power Consumption
* ⚡ Energy Used
* 💰 Estimated Cost
* 🌱 Carbon Reduction
* 👥 Occupancy
* 🏫 Room Status
* 💡 Appliance Status
* 📈 Energy Saving Trends

Example:

```text
┌──────────────────────────────────────┐
│       SMART ENERGY DASHBOARD         │
├──────────────┬───────────────────────┤
│ Occupied     │ 12 / 20 Rooms         │
│ Power        │ 18.4 kW               │
│ Energy Saved │ 27.6 %                │
│ CO₂ Reduced  │ 14.2 kg               │
├──────────────┴───────────────────────┤
│                                      │
│ Room A101     🟢 Occupied             │
│ Lights        ON                     │
│ Fans          ON                     │
│ AC            ON                     │
│                                      │
│ Room A102     🔴 Empty               │
│ Lights        OFF                    │
│ Fans          OFF                    │
│ AC            Standby                │
└──────────────────────────────────────┘
```

---

# 🏗️ System Architecture

```text
                ┌───────────────────┐
                │  PIR / Camera     │
                │ Occupancy Sensors │
                └─────────┬─────────┘
                          │
                          ▼
                ┌───────────────────┐
                │ AI Occupancy      │
                │ Detection         │
                │ YOLO Lightweight  │
                └─────────┬─────────┘
                          │
                          ▼
                ┌───────────────────┐
                │ ESP32 / Raspberry │
                │ Pi IoT Node       │
                └─────────┬─────────┘
                          │
                       MQTT
                          │
                          ▼
                ┌───────────────────┐
                │ Backend Server     │
                │ Python + FastAPI   │
                └─────────┬─────────┘
                          │
              ┌───────────┴───────────┐
              ▼                       ▼
     ┌─────────────────┐     ┌─────────────────┐
     │ Energy Control  │     │ Database        │
     │ Engine          │     │ & Analytics     │
     └────────┬────────┘     └────────┬────────┘
              │                       │
              └───────────┬───────────┘
                          ▼
                ┌───────────────────┐
                │ Web Dashboard     │
                │ Real-Time Monitor │
                └───────────────────┘
```

---

# 🛠️ Technology Stack

## Hardware

| Component          | Purpose                  |
| ------------------ | ------------------------ |
| ESP32              | IoT control node         |
| Raspberry Pi       | Edge AI / gateway        |
| PIR Sensor         | Occupancy detection      |
| Camera             | AI-based people counting |
| Relay Module       | Appliance switching      |
| Current Sensor     | Energy monitoring        |
| Voltage Sensor     | Electrical monitoring    |
| Temperature Sensor | Environmental monitoring |

> **Prototype Note:** For a hackathon prototype, use low-voltage demonstration loads or suitable isolated modules rather than directly switching mains electricity.

---

## Software

### Backend

* Python
* FastAPI
* MQTT
* NumPy
* OpenCV
* YOLO lightweight model
* SQLite / PostgreSQL

### Frontend

* React / Next.js
* Tailwind CSS
* JavaScript / TypeScript
* Chart.js / Recharts

### IoT

* ESP32
* MQTT
* Wi-Fi

### AI

* YOLO
* Occupancy Detection
* Time-Series / Predictive Analytics

---



# 🔄 Working Flow

### Step 1 — Detect Occupancy

Sensors/camera detect people inside the room.

### Step 2 — Process Data

The edge device processes occupancy information.

### Step 3 — Send Data

ESP32/Raspberry Pi sends data to the backend using MQTT.

### Step 4 — Decision Making

The Energy Management Engine decides whether appliances should remain ON, switch to standby, or turn OFF.

### Step 5 — Appliance Control

Control commands are sent to the IoT node.

### Step 6 — Dashboard Update

The dashboard displays:

```text
Occupancy
+
Power Consumption
+
Appliance Status
+
Energy Saving
+
Carbon Reduction
```

---

# 🧠 Smart Decision Logic

```text
              Room Occupancy
                    │
          ┌─────────┴─────────┐
          │                   │
       Occupied             Empty
          │                   │
          ▼                   ▼
   Check Occupancy      Start Timer
   Count & Time              │
          │             3–5 Minutes
          │                   │
          │                   ▼
          │             Still Empty?
          │              /         \
          │            Yes          No
          │             │            │
          ▼             ▼            ▼
   Adjust Energy     Standby      Continue
   According to      Appliances   Operation
   Demand
```

---

# 📈 Energy Saving Calculation

The system estimates energy savings using:

```text
Energy Saved =
Baseline Energy Consumption
-
Actual Energy Consumption
```

Percentage saving:

```text
Energy Saving % =
(Energy Saved / Baseline Energy) × 100
```

For the prototype, baseline and savings should be measured using actual test data rather than assuming a fixed percentage.

---

# 🌱 Environmental Impact

Reducing unnecessary electricity consumption can also reduce associated carbon emissions.

The dashboard can calculate an estimated reduction using:

```text
CO₂ Reduction =
Energy Saved × Grid Emission Factor
```

The emission factor should be configurable according to the region or dataset being used.

---

# 🔐 Privacy & Security

Because occupancy may be detected using cameras, privacy is an important part of the system.

The system should preferably:

* Process video locally at the edge
* Avoid storing unnecessary raw video
* Store only occupancy counts/events where possible
* Use authenticated MQTT communication
* Restrict dashboard access
* Encrypt sensitive network communication

---

# 🎯 Use Cases

The system can be deployed in:

### 🏫 Educational Campuses

* Classrooms
* Computer Labs
* Laboratories
* Libraries
* Seminar Halls

### 🏢 Commercial Buildings

* Offices
* Meeting Rooms
* Conference Rooms
* Workspaces

### 🏨 Hostels

* Common Rooms
* Study Rooms
* Corridors
* Shared Facilities

### 🏥 Institutional Buildings

* Waiting Areas
* Offices
* Non-critical common areas

---

# 🏆 Why This Solution?

| Traditional System      | AI Zonal Energy Manager |
| ----------------------- | ----------------------- |
| Manual control          | Automatic control       |
| Fixed timers            | Occupancy-based control |
| Same cooling everywhere | Demand-based control    |
| No prediction           | Predictive usage        |
| Limited monitoring      | Real-time dashboard     |
| Reactive                | Proactive               |
| Zone-independent        | Zonal management        |

---

# 🚀 Future Scope

* 🔮 Advanced energy demand forecasting
* 🌦️ Weather-aware HVAC optimization
* 📱 Mobile application
* 🏢 Multi-building management
* 🔌 Integration with smart meters
* 🤖 Reinforcement-learning based optimization
* ☁️ Cloud analytics
* 🔐 Enterprise-grade authentication
* 🏭 Integration with Building Management Systems
* ⚡ Integration with Schneider Electric EcoStruxure ecosystem

---

# 🧪 Prototype Demo

A small-scale prototype can contain:

```text
        CAMERA / PIR
             ↓
          ESP32
             ↓
       MQTT Broker
             ↓
       Python Backend
             ↓
     Energy Decision Engine
             ↓
      Relay / LED / Fan
             ↓
       Web Dashboard
```

### Example Demo

```text
Room A101
Occupancy: 0
Lights: OFF
Fan: OFF
AC: STANDBY
Energy Saved: 32 W
```

Then:

```text
Person Detected
      ↓
Occupancy = 1
      ↓
Lights = ON
Fan = ON
      ↓
Dashboard Updated
```

---

# 📊 Expected Outcomes

The prototype aims to demonstrate:

* Reduced unnecessary appliance runtime
* Automated room-level energy management
* Real-time occupancy monitoring
* Predictive room preparation
* Energy consumption visualization
* Data-driven building management

Actual energy savings should be validated experimentally on the prototype and reported from measured data.

---

# 💻 Installation

## 1. Clone Repository

```bash
git clone https://github.com/YOUR-USERNAME/AI-Zonal-Energy-Manager.git
cd AI-Zonal-Energy-Manager
```

## 2. Backend Setup

```bash
cd backend
python -m venv venv
```

### Windows

```bash
venv\Scripts\activate
```

Install dependencies:

```bash
pip install -r requirements.txt
```

Run backend:

```bash
uvicorn main:app --reload
```

---

## 3. Frontend Setup

```bash
cd frontend
npm install
npm run dev
```

---

# 🔌 MQTT Communication

Example occupancy message:

```json
{
  "building": "Block-A",
  "room": "A101",
  "occupancy": 12,
  "temperature": 24.5,
  "timestamp": "2026-09-10T10:30:00"
}
```

Example control message:

```json
{
  "room": "A101",
  "lights": true,
  "fan": true,
  "ac": true,
  "mode": "normal"
}
```

---

# 👨‍💻 Team

**Project:** AI-Driven Zonal Energy Manager

**Challenge Area:** Smart Buildings & Campuses

**Domain:** AI + IoT + Smart Infrastructure + Energy Management

---

# 📜 License

This project is developed for educational, research, and hackathon purposes.

See the `LICENSE` file for details.

---

## ⭐ Support

If you find this project useful, consider giving the repository a ⭐ on GitHub.

**Build smarter buildings. Save energy. Reduce waste. 🌱⚡**
