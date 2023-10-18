# IoT Soil Moisture Sensor with ESP32 and LED

This project demonstrates a soil moisture sensor connected to an ESP32 microcontroller that activates an LED when the soil moisture exceeds a predefined threshold.

## Purpose

The purpose of this project is to provide a simple and practical solution for monitoring soil moisture in a garden or plant pot. When the soil moisture level is above a certain threshold, indicating that the soil is adequately moist, the connected LED will be turned on. This feature helps in efficient watering and plant care.

## Setup

### Components Required

- ESP32 development board
- Soil moisture sensor
- LED
- Resistors (as needed)
- Jumper wires

### Wiring

1. Connect the soil moisture sensor to the ESP32 analog input pin.
2. Connect the LED to a digital output pin on the ESP32 through appropriate wiring and resistors.

### Installation

1. Set up the Arduino IDE on your computer.
2. Install the ESP32 board in the Arduino IDE.
3. Clone or download the project code from this repository.

## Usage

1. Open the Arduino IDE and load the project code.
2. Customize the code with your specific pin configurations, threshold values, and LED logic as needed.
3. Upload the code to the ESP32 board.
4. Power up the ESP32 board and ensure it is connected to the soil moisture sensor.
5. Observe the LED behavior based on the soil moisture level:
   - LED ON: Soil moisture above the threshold.
   - LED OFF: Soil moisture below the threshold.

Feel free to adjust the threshold and LED behavior according to your requirements in the Arduino code.

For detailed setup and usage instructions, refer to the project documentation.

If you would like to contribute to this project, feel free to submit issues, fork the repository, and create pull requests.

## License

This project is licensed under the [MIT License](LICENSE).

## Citation
- [w3schools CSS Tutorials](https://www.w3schools.com/css/)
- [Esp32io Soil Moisture Sensor Wiring Tutorial](https://esp32io.com/tutorials/esp32-soil-moisture-sensor)
- [Esp32io LED Wiring Tutorial](https://esp32io.com/tutorials/esp32-led-blink)
