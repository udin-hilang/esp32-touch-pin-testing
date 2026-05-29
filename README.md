# Capacitive Touch Sensor Control (ESP32)

A simple, lightweight ESP32 project that utilizes the built-in capacitive touch sensor peripheral to control a digital output (such as an LED or a relay module) based on a defined threshold. It also includes optimized Serial styling designed for real-time visualization using the Arduino IDE Serial Plotter.

## Features
- **Capacitive Touch Sensing:** Utilizes the ESP32 hardware touch pin tracking (`touchRead()`).
- **Dynamic Threshold Control:** Automatically toggles an output state when capacitance drops below a fixed threshold.
- **Serial Plotter Optimized:** Formatted console output allows easy multi-channel plotting of raw data, threshold lines, and output states.

## Hardware Pinout
| Component / Function | ESP32 GPIO Pin | Type |
|----------------------|---------------|------|
| Touch Sensor Input   | GPIO 27       | Input (Touch 7) |
| Controlled Output    | GPIO 2        | Output (Onboard LED) |

## How It Works
1. The microcontroller continuously polls the touch sensor on **GPIO 27**.
2. When a finger approaches or touches a wire/pad connected to the pin, the raw capacitance value drops.
3. If the value falls below the threshold of **1416**, the system pulls **GPIO 2 HIGH**. Otherwise, it remains **LOW**.
4. The `Serial.printf` statement outputs three streams of data to the port:
   - The current raw `touchValue`
   - The static threshold reference line (`1416`)
   - An offset representation of the output pin state (`1200` for LOW, `1700` for HIGH) to cleanly visualize binary transitions on a graph.

## Setup Instructions
1. Open the source file in your Arduino IDE or VS Code with PlatformIO.
2. Ensure your target board configuration is set to **ESP32 Dev Module** (or your specific ESP32 variant).
3. Connect a jumper wire or touch pad to **GPIO 27**.
4. Upload the code.
5. Open the **Serial Plotter** (`Ctrl + Shift + L` in Arduino IDE) and set the baud rate to **115200** to view the live graph.

## License
This project is open-source and available under the [MIT License](LICENSE).
