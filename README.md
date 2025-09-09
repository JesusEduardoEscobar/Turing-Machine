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

## Hardware (suggested / example)

> **⚠️ Replace the pin numbers and components below with the actual values used in `turinUltrasonico.ino`.**

- Arduino UNO (or compatible)
- Ultrasonic distance sensor (HC-SR04 or similar)
  - VCC -> 5V
  - GND -> GND
  - TRIG -> Arduino pin `X` (replace)
  - ECHO -> Arduino pin `Y` (replace)
- (Optional) Servo / DC motor / LEDs to indicate head movement and state transitions
  - Servo signal -> Arduino pin `Z` (replace)
- Wires, breadboard, power supply

---

## Software / Dependencies

- Arduino IDE (version recommended: latest stable)
- No external libraries required unless the sketch uses them (check top of `turinUltrasonico.ino`). If the project uses libraries (e.g., `Servo.h`), install them via the Arduino Library Manager.

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

- **Tape:** Represented by a sequence of sensor readings (e.g., distance ranges → symbols).
- **Head:** The sensor/reading point that "reads" the current symbol.
- **States:** Internal variables in the sketch representing the Turing Machine states.
- **Transition function:** Implemented as conditional logic (if/else or `switch`) that, given the current state and read symbol, decides the next state, the action (write/move), and any actuator commands (LEDs/servo).

---

## Examples / Demo

- Short demonstration video (if available): *link or embed here*  
- Example inputs and expected behavior:
  - `distance < 10 cm` → symbol `A`
  - `10 cm <= distance < 20 cm` → symbol `B`
  - (Add actual mapping used in the sketch)

---

## Team & Course

- **Team:** Jesús Eduardo Escobar, Ángel Gabriel Camacho Pérez, Ivana Banderas  
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

