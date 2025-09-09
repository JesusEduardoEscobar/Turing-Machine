# Turing-Machine

Repository with the code and resources for a Turing Machine-inspired school project using an ultrasonic sensor and Arduino.  
This project was developed as a team project during 4th semester of the ITC program at Tecnológico de Monterrey as part of the course *Implementation of Computational Methods*.

> **Repository:** https://github.com/JesusEduardoEscobar/Turing-Machine

---

## Contents

- `turinUltrasonico.ino` – Arduino sketch that implements the Turing-Machine-like behavior using an ultrasonic sensor (and actuators if used).
- `README.md` – This file.
- (Add any other files or folders here, e.g. `docs/`, `diagrams/`, `videos/`)

---

## Project overview

This project implements a physical/embedded simulation of a Turing Machine concept using an Arduino and sensors. The system interprets sensor readings as tape symbols and performs transitions/actions that emulate state changes and head movement in a Turing Machine.

**Goals**
- Translate theoretical automata concepts into an embedded prototype.
- Visualize how rules and states move the computation forward using sensor inputs and actuator outputs.
- Work collaboratively to design, implement and test the model.

---

## Materials

To replicate this project, you will need:

- **1x Arduino Uno**
- **1x Arduino UNO** (or compatible board)
- **1x Ultrasonic distance sensor** (e.g., HC-SR04)
- **1x Breadboard**
- **6x strcutures that can be placed at different distances to calculate distances and input them**
- **1x Servo motor reducer**
- **1x H-bridge**
- **1x MDF wood (Turing machine frame)**
- **Glue**
- **4x Ball bearing**
- Paper for the conveyor belt**
- **1x 12V power supply**
- **Jumper wires** (male-to-male)
- **USB cable** to connect Arduino to your computer

---

## Hardware setup

> ⚠️ Replace pin numbers according to `turinUltrasonico.ino`.

- Ultrasonic sensor connections:
  - VCC → 5V  
  - GND → GND  
  - TRIG → Arduino pin `X`  
  - ECHO → Arduino pin `Y`  

- Servo motor / LED connections (optional):
  - Servo signal → Arduino pin `Z`  
  - LED anode → Digital pin `N` (through resistor)  
  - LED cathode → GND  

---

## Software / Dependencies

- Arduino IDE (latest stable version recommended)
- Required libraries:
  - `Servo.h` *(if used in the sketch)*  
  - No additional libraries unless specified at the top of `turinUltrasonico.ino`.

---

## How to run

1. Open `turinUltrasonico.ino` in the Arduino IDE.
2. Verify/modify pin assignments in the sketch to match your wiring.
3. Connect the Arduino to your computer via USB.
4. Select the correct board and port in the Arduino IDE.
5. Click **Upload**.
6. Open the Serial Monitor (baud rate as specified in the sketch, e.g., `9600`) to observe debug messages (states, tape symbols, transitions).
7. Interact with the prototype (present objects at different distances to the ultrasonic sensor) to see how the machine interprets symbols and changes state.

---

## How the model maps to a Turing Machine (conceptual)

- **Tape:** Sequence of sensor readings (distance ranges → symbols).  
- **Head:** The sensor/reading point that "reads" the current symbol.  
- **States:** Internal variables in the sketch representing the Turing Machine states.  
- **Transition function:** Conditional logic (if/else or `switch`) that, given the current state and read symbol, decides the next state, the action (write/move), and any actuator commands (LEDs/servo).  

---

## Team & Course

- **Team:** Jesús Eduardo Escobar, Ángel Gabriel Camacho Pérez, Ivana Banderas Elliot 
- **Course:** *Implementation of Computational Methods* — ITC, Tecnológico de Monterrey (4th semester)

---

## Next steps / Improvements

- Add a visual representation (diagram) of the automaton states and transitions.
- Create a web/desktop simulator that mirrors the physical behavior.
- Add configuration file or constants for easy tuning of distance thresholds and pin assignments.
- Add unit tests or simulated inputs to validate transitions offline.

---

## License

Specify your license (e.g., MIT, GPL-3.0). Example:
MIT License
© 2025 Jesús Eduardo Escobar

## Contact

If you want to replicate or improve this project, open an issue or contact me via GitHub:  
👉 [GitHub Profile](https://github.com/JesusEduardoEscobar)
