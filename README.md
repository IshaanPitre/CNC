# ✏️ ESP32 CNC Drawing Machine

This project is a minimalist 2-axis CNC drawing machine powered by an ESP32. It’s designed to interpret G-code and translate it into motion using stepper motors—ideal for plotting simple designs or experimenting with motion control. Built as a hobbyist exploration, it emphasizes modularity, Bluetooth control, and SD card-based file handling.

---

![](plotter(1).gif)

## 🧠 Project Overview

- **Purpose**: Create a simple, low-cost CNC drawing system using an ESP32
- **Axes**: X and Y only (2-axis)
- **Use Case**: Drawing/plotting designs from G-code files
- **Modularity**: Designed for future upgrades (e.g., limit switches, web UI)

---

## 🔩 Hardware Stack

| Component              | Description                          |
|------------------------|--------------------------------------|
| Microcontroller        | ESP32 DevKit V1 (DOIT)               |
| Motor Drivers          | 2 × L298N                            |
| Stepper Motors         | 2 × Bipolar NEMA 17                  |
| Storage                | MicroSD card reader (G-code files)   |
| Communication          | Bluetooth serial console             |
| Limit Switches         | Planned for future implementation    |


## 🧬 Software Architecture

- **G-code Parsing**: Manual parsing via custom script
- **Workflow**:
  1. Convert SVG to G-code using online tool
  2. Run G-code through a second script to format for ESP32
  3. Upload to SD card or send via Bluetooth
- **Control Interface**: Bluetooth serial console (laptop → ESP32)
- **Motion Logic**: Hardcoded step counts for axis limits (no position feedback yet)
- **Web Server**: In development—will allow file uploads directly to ESP32

---

## 🚧 Current Status

| Feature                | Status         | Notes                          |
|------------------------|----------------|--------------------------------|
| G-code Parsing         | ✅ Working      | Custom format required         |
| Bluetooth Console      | ✅ Working      | Accepts commands + file calls  |
| SD Card Integration    | ✅ Working      | Reads G-code files             |
| Motion Control         | ✅ Working      | Hardcoded limits               |
| Web Server             | ⚙️ In Progress  | File upload via browser        |
| Limit Switches         | ⏳ Planned      | For homing and safety          |

---

## 🧵 Future Plans

- Add limit switches for homing routine
- Finalize ESP32 web server for file uploads
- Explore basic UI/dashboard for command input
- Improve motion accuracy and feedback
