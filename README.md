# intelligent_traffic_system
This Arduino program is designed to implement an Intelligent Zebra Crossing System for assisting visually impaired individuals. The system uses ultrasonic sensors, LEDs, and a buzzer to detect pedestrians and vehicles, control traffic signals, and ensure safe crossing.


# Intelligent Zebra Crossing System

This project demonstrates an **Intelligent Zebra Crossing System** designed to assist visually impaired individuals in safely navigating zebra crossings. It uses ultrasonic sensors, LEDs, and a buzzer to detect pedestrians, monitor crossing activity, and control traffic signals dynamically.

---

## Features

- **Pedestrian Detection**:  
  - Detects individuals near the crossing using left and right ultrasonic sensors.  

- **Dynamic Traffic Light Control**:  
  - Automatically switches between green (vehicle go) and red (pedestrian cross) based on the presence of pedestrians and vehicles.  

- **Center Monitoring**:  
  - Monitors the crossing path using a central ultrasonic sensor to ensure pedestrians cross safely.  

- **Auditory Feedback**:  
  - Uses a buzzer to signal the status of the crossing to visually impaired individuals.

---

## Hardware Requirements

- **Arduino Uno/Nano**  
- **Ultrasonic Sensors** (HC-SR04):  
  - Left and right pedestrian detection  
  - Center monitoring sensor  
- **LEDs**:  
  - Green LED for vehicles  
  - Red LED for pedestrians  
- **Buzzer**:  
  - For auditory alerts  
- **Power Supply**:  
  - Suitable for the Arduino board and components  

---

## Software Requirements

- **Arduino IDE**  
  - For uploading the code to the Arduino board  
- **Serial Monitor** (Optional):  
  - For debugging and distance measurement checks  

---

## Working Principle

1. **Initial State**:  
   - The traffic light is green, allowing vehicles to pass.  

2. **Pedestrian Detection**:  
   - Ultrasonic sensors detect pedestrians approaching from either side of the crossing.  
   - If detected within a 50 cm range, the system switches the traffic light to red.  

3. **Crossing Monitoring**:  
   - A central ultrasonic sensor monitors the pedestrian's presence on the crossing.  
   - If the pedestrian is within range, the red light stays on.  

4. **Timeout Alert**:  
   - If the pedestrian is not detected on the crossing for 10 seconds, a buzzer activates as an alert.  
   - After another 10 seconds without detection, the system resets to the initial state (green light).  

---

## Code Explanation

The system uses the following logic:  

- **Ultrasonic Sensors**: Measure distances to detect pedestrians and monitor the crossing.  
- **LED Control**: Green and red LEDs toggle based on sensor inputs.  
- **Buzzer Alert**: Activates when no movement is detected within a 10-second timeout period.  

### Key Functions in the Code:

- `measureDistance(triggerPin, echoPin)`:  
  Measures distance using the HC-SR04 ultrasonic sensor.  

- `setup()`:  
  Initializes all pins, sets the traffic light to green, and prepares the Serial Monitor.  

- `loop()`:  
  Controls the main logic:
  - Detects pedestrians near the crossing using left and right sensors.  
  - Activates the red light and monitors the crossing using the central sensor.  
  - Resets the system after the timeout period if no pedestrians are detected.  

---

## Circuit Diagram

1. Connect the ultrasonic sensors to the Arduino as follows:  
   - **Left Sensor**:  
     - Trigger: Pin 8  
     - Echo: Pin 9  
   - **Right Sensor**:  
     - Trigger: Pin 7  
     - Echo: Pin 6  
   - **Center Sensor**:  
     - Trigger: Pin 2  
     - Echo: Pin 3  

2. Connect the LEDs:  
   - **Green LED**: Pin 12  
   - **Red LED**: Pin 11  

3. Connect the Buzzer:  
   - Pin 4  

4. Power the system using an appropriate power supply.  

---

## How to Run

1. Clone this repository to your local machine.  
2. Open the `intelligent_zebra_crossing.ino` file in the Arduino IDE.  
3. Upload the code to your Arduino Uno/Nano board.  
4. Set up the circuit as described in the circuit diagram.  
5. Power the system and observe the behavior of the LEDs and buzzer as pedestrians approach and cross the zebra crossing.  

---

## Contributors

- **Pratik Patil**  
- **Don Das**  
- **Keearan Dhami**  
- **Sanjeev Kumar**  

---

## License

This project is licensed under the MIT License. Feel free to use, modify, and distribute the code and documentation.

