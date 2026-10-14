# PIC18F4580 Peripheral Timer Interrupts

A microcontroller programming project demonstrating Timer0, Timer1, Timer2, and Timer3 interrupts using the **PIC18F4580**, MPLAB C18, and Proteus Design Suite.

This project explores timer configuration, interrupt handling, interrupt service routines (ISRs), and LED output behavior through circuit simulation.

## Project Overview

The PIC18F4580 microcontroller provides multiple hardware timers that can generate interrupts at configured intervals. This project demonstrates the configuration and simulation of four timers.

| Timer | Description | Source Code |
|---|---|---|
| Timer0 | Timer0 overflow interrupt and LED toggling | [peri_intr_t0.c](Source_Code/peri_intr_t0.c) |
| Timer1 | Timer1 peripheral interrupt | [peri_intr_t1.c](Source_Code/peri_intr_t1.c) |
| Timer2 | Timer2 peripheral interrupt and LED toggling | [peri_intr_t2.c](Source_Code/peri_intr_t2.c) |
| Timer3 | Timer3 peripheral interrupt | [peri_intr_t3.c](Source_Code/peri_intr_t3.c) |

## Software Requirements

- **MPLAB IDE:** To develop and compile the microcontroller programs.
- **MPLAB C18 Compiler:** To compile the C programs for PIC18 microcontrollers.
- **Proteus Design Suite:** To simulate the PIC18F4580 circuits and observe timer output.
- **PIC18F4580 device support:** Required for compiling and simulating the microcontroller.

*Note: MPLAB C18 is a legacy compiler. Use a compatible development environment and verify compiler settings before building the programs.*

## Repository Structure

```text
PIC18F4580-Peripheral-Timer-Interrupts/
├── README.md
├── Source_Code/
│   ├── peri_intr_t0.c
│   ├── peri_intr_t1.c
│   ├── peri_intr_t2.c
│   └── peri_intr_t3.c
└── Proteus/
    ├── peri_intr_t0.pdsprj
    ├── peri_intr_t0.png.png
    ├── peri_intr_t1.pdsprj
    ├── peri_intr_t1.png.png
    ├── peri_intr_t2.pdsprj
    ├── peri_intr_t2.png.png
    ├── peri_intr_t3.pdsprj
    └── peri_intr_t3.png.png
```

## Proteus Simulation Results

Open the simulation screenshots to view the circuit connections and observed output waveforms.

### Timer0 Peripheral Interrupt
- [View Proteus Project](Proteus/peri_intr_t0.pdsprj)
- [View Simulation Screenshot](Proteus/peri_intr_t0.png.png)

### Timer1 Peripheral Interrupt
- [View Proteus Project](Proteus/peri_intr_t1.pdsprj)
- [View Simulation Screenshot](Proteus/peri_intr_t1.png.png)

### Timer2 Peripheral Interrupt
- [View Proteus Project](Proteus/peri_intr_t2.pdsprj)
- [View Simulation Screenshot](Proteus/peri_intr_t2.png.png)

### Timer3 Peripheral Interrupt
- [View Proteus Project](Proteus/peri_intr_t3.pdsprj)
- [View Simulation Screenshot](Proteus/peri_intr_t3.png.png)

## How to Run the Project

1. Clone or download this repository.
2. Open the required C source file from the `Source_Code` folder in your MPLAB development environment.
3. Select the PIC18F4580 device and configure the appropriate compiler.
4. Compile the program and generate the HEX file.
5. Open the corresponding Proteus project from the `Proteus` folder.
6. Load the generated HEX file into the PIC18F4580 component.
7. Set the oscillator frequency to match the program's timing configuration.
8. Run the simulation and observe the LED behavior or oscilloscope waveform.

## Key Learning Outcomes

- Understanding hardware timer operation in PIC18 microcontrollers.
- Configuring timer registers, prescalers, and period values.
- Enabling peripheral and global interrupts.
- Writing and handling interrupt service routines.
- Setting and clearing interrupt flags.
- Simulating embedded C programs using Proteus.
- Observing timing behavior using a digital oscilloscope.

## Author

**Raju Malekar**

GitHub: [@malekarraju](https://github.com/malekarraju)

## Disclaimer

This project is intended for educational purposes. Actual timer periods depend on the oscillator frequency, timer configuration, register values, and interrupt handling overhead. Verify each program and simulation before using it in hardware.

