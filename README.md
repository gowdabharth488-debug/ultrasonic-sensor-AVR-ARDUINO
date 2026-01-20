# 🔊 Ultrasonic Distance Indicator Using HC-SR04 📡  
### 🧠 Multi-Platform Implementation Using ATtiny13A, ATmega16A, ATmega32A & Arduino 🤖

---

## 📘 Project Implementation Overview 🧩

This project focuses on the design and implementation of a **low-cost ultrasonic distance
indicator system** 💡 using the **HC-SR04 ultrasonic sensor** 📡 and multiple microcontroller
platforms. The primary objective of the project is to measure the distance of an object
accurately 📏 and provide a visual indication using an LED 💡 based on the detected proximity.

To make the project flexible and scalable 🔄, the system is implemented on different
microcontroller platforms, including **ATtiny13A, ATmega16A, ATmega32A, and Arduino** 🧠🤖.
Although each platform differs in terms of hardware resources and development tools,
the **fundamental working principle and distance measurement algorithm remain the same**
across all implementations ✅.

---

## 💻 Source Code Availability & Implementation Details 📄

The source code for this project is developed separately for each supported platform
to ensure **optimal performance ⚡, accuracy 🎯, and hardware compatibility 🔌**.
Although the **core working logic remains identical**, the implementation differs
based on the available timers ⏱, registers, and development framework of each controller.

### 🧠 ATtiny13A Implementation
The ATtiny13A version is written using **Embedded C** 💻 and optimized for
**limited flash memory and RAM** 📦.
It uses **Timer0 with overflow counting** ⏱ to measure the echo pulse width
and performs **integer-based distance calculation** ➗ to achieve fast execution
and low memory usage 📉.

### 🔷 ATmega16A Implementation
The ATmega16A version is implemented using **Embedded C** 💻 and utilizes
the **16-bit Timer1** ⏱ for accurate pulse width measurement.
Due to increased hardware resources, this version provides improved timing precision 🎯
while maintaining the same distance indication logic using an LED 💡.

### 🔷 ATmega32A Implementation
The ATmega32A implementation is similar to the ATmega16A version and also uses
**Timer1** ⏱ for echo time measurement.
This version benefits from higher I/O availability 🔌 and is suitable for
extended applications 🚀 while preserving the same working principle.

### 🤖 Arduino (UNO / Nano) Implementation
The Arduino version is developed using the **Arduino framework** 🤖 and simplifies
hardware interaction using built-in functions such as `pulseIn()` ⚙.
This version is ideal for beginners 👨‍🎓 and rapid prototyping ⚡, while still following
the same ultrasonic distance measurement concept 📏 and LED indication logic 💡.

---

## 📌 Summary ✅
All platform-specific codes:
- Follow the **same hardware concept and algorithm** 🔁
- Differ only in **timer usage ⏱, pin mapping 🔌, and programming framework** 💻
- Are organized into **separate source files** 📁 for clarity and maintainability

This modular design allows the project to be easily extended to other
AVR microcontrollers in the future 🚀.
