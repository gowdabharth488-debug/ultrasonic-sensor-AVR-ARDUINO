# Ultrasonic Distance Indicator Using ATtiny13A,Atmega32A, Atmega16A, Arduino

---

## 1. Introduction
In modern embedded systems, distance measurement plays a vital role in automation,
robotics, and safety systems. Ultrasonic sensors are widely used because they are
non-contact, accurate, and cost-effective. This project presents a simple ultrasonic
distance indicator using the ATtiny13A microcontroller.

---

## 2. Project Overview
The Ultrasonic Distance Indicator measures the distance of an object using an HC-SR04
ultrasonic sensor. Based on the measured distance, an LED provides visual feedback.
The entire system is optimized using integer arithmetic to ensure reliable operation
on low-memory microcontrollers.

---

## 3. Components Description

### 3.1 ATtiny13A Microcontroller
ATtiny13A is an 8-bit AVR microcontroller with 1 KB Flash memory.
It is suitable for small embedded applications due to its low power consumption
and compact size.

### 3.2 HC-SR04 Ultrasonic Sensor
The HC-SR04 sensor uses ultrasonic sound waves to measure distance.
It consists of:
- Trigger pin (TRIG)
- Echo pin (ECHO)

### 3.3 LED Indicator
The LED acts as a visual alert to indicate object proximity.

---

## 4. Circuit Description
The ATtiny13A controls the HC-SR04 sensor by generating a trigger pulse.
The echo pulse width is measured using Timer0.
The LED output changes according to the measured distance.

---

## 5. Working Methodology
1. Microcontroller sends a 10µs trigger pulse
2. Ultrasonic wave is transmitted
3. Echo pulse is received
4. Timer counts echo duration
5. Distance is calculated using integer math
6. LED indicates distance range

---

## 6. Advantages
- Low cost
- Low power consumption
- Accurate distance measurement
- Simple circuit
- Fast execution using integer arithmetic

---

## 7. Applications
- Object detection
- Obstacle avoidance robots
- Parking sensors
- Industrial automation
- Proximity alert systems

---

## 8. Conclusion
The Ultrasonic Distance Indicator using ATtiny13A provides an efficient and reliable
solution for short-range distance measurement. The project demonstrates how optimized
embedded C programming improves performance on small microcontrollers.


