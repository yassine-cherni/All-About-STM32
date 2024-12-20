# STM32 Learning Resources

This repository provides a curated list of YouTube channels and playlists for learning STM32 microcontroller programming. The resources are organized by difficulty level to support learners from beginner to advanced stages. Use the checkboxes to track your progress as you explore each resource.

---
# STM32F407 Discovery vs STM32F446RE: A Comparison

This document compares the features of the **STM32F407 Discovery** and **STM32F446RE** boards to help you choose the best platform for your embedded system projects.

---

## Overview

| Feature                    | STM32F407 Discovery                       | STM32F446RE                              |
|----------------------------|-------------------------------------------|------------------------------------------|
| **Core**                   | ARM Cortex-M4, 168 MHz                   | ARM Cortex-M4, 180 MHz                  |
| **Flash Memory**           | 1 MB                                     | 512 KB                                   |
| **RAM**                    | 192 KB                                   | 128 KB                                   |
| **GPIO Pins**              | 40                                        | 48                                       |
| **Clock Speed**            | 168 MHz                                  | 180 MHz                                  |
| **Power Consumption**      | Slightly higher than STM32F446RE         | Optimized for lower power consumption    |
| **Onboard Peripherals**    | Accelerometer, Gyroscope, Audio DAC       | None                                     |
| **Development Focus**      | Ideal for learning and prototyping        | Better for real-time and advanced projects |
| **Price**                  | Lower (entry-level board)                | Slightly higher than STM32F407           |

---

## Communication Interfaces

| Interface         | STM32F407 Discovery         | STM32F446RE               |
|--------------------|-----------------------------|---------------------------|
| **UART**          | Yes (Multiple UART ports)   | Yes (Multiple UART ports) |
| **SPI**           | Yes (Multiple SPI interfaces) | Yes (Multiple SPI interfaces) |
| **I2C**           | Yes (Multiple I2C interfaces) | Yes (Multiple I2C interfaces) |
| **CAN**           | Yes (CAN1, CAN2)            | Yes (CAN1, CAN2)          |
| **USB**           | Yes (USB OTG FS, device)    | Yes (USB OTG FS, host/device) |
| **Ethernet**      | Yes                         | No                        |
| **PWM**           | Yes                         | Yes                       |

---

## Key Features

### STM32F407 Discovery
- **Pros**:
  - Built-in sensors (accelerometer, gyroscope, audio DAC).
  - Higher flash memory (1 MB).
  - Lower price; ideal for beginners.
  - Includes Ethernet for networking projects.
- **Cons**:
  - Slightly slower clock speed (168 MHz).
  - Fewer GPIO pins compared to STM32F446RE.
  - Higher power consumption.

### STM32F446RE
- **Pros**:
  - Faster clock speed (180 MHz).
  - More GPIO pins (48 vs. 40).
  - Lower power consumption; optimized for real-time systems.
  - More suitable for advanced or power-efficient applications.
- **Cons**:
  - No onboard sensors; requires external modules.
  - Higher price compared to STM32F407 Discovery.

---

## Development Tools and Ecosystem

| Feature                   | STM32F407 Discovery        | STM32F446RE              |
|---------------------------|----------------------------|--------------------------|
| **IDE Support**           | STM32CubeIDE, Keil, IAR    | STM32CubeIDE, Keil, IAR  |
| **HAL Library Support**   | Yes                        | Yes                      |
| **RTOS Support**          | FreeRTOS, embOS, etc.      | FreeRTOS, embOS, etc.    |
| **Debugging**             | ST-Link debugger included  | Requires external ST-Link |
| **Power Management Tools**| Moderate                  | Advanced                 |

---

## Conclusion

- **Choose STM32F407 Discovery**:
  - If you're just starting with embedded systems or need built-in sensors for prototyping.
  - Ideal for projects requiring Ethernet connectivity.
  - More cost-effective for educational purposes.

- **Choose STM32F446RE**:
  - If you need higher processing power and more GPIO pins for advanced projects.
  - Ideal for low-power, real-time applications.
  - Suitable for industrial and professional-grade systems.

---

## Resources

- **STM32F407 Discovery**:
  - [Datasheet](https://www.st.com/resource/en/datasheet/stm32f407vg.pdf)
  - [User Manual](https://www.st.com/resource/en/user_manual/um1472-stm32f4-discovery-stmicroelectronics.pdf)

- **STM32F446RE**:
  - [Datasheet](https://www.st.com/resource/en/datasheet/stm32f446re.pdf)
  - [User Manual](https://www.st.com/resource/en/user_manual/dm00166116-stm32-nucleo64-boards-stmicroelectronics.pdf)



## 1. Beginner Level 🎯

1. **[STM32 Beginner Guide Tutorial Series using STM32F401RE](https://www.youtube.com/playlist?list=PLGh4659DkyarOFZVtnah4KORCJzuPbWg_)**  
   Aimed at beginners, focusing on hands-on development.

2. **[Starting with STM32 - Programming Tutorial for Beginners](https://www.youtube.com/watch?v=dnfuNT1dPiM)**  
   Step-by-step beginner-friendly guide.

3. **[GPIO Programming Basics - STM32 Tutorial](https://www.youtube.com/watch?v=YNeOotn4jsc)**  
   Learn fundamental GPIO concepts with STM32.

4. **[STM32CubeIDE for Beginners](https://www.youtube.com/playlist?list=PLWk49HLpWHRBDgLC2A1IIEOTtnplSgvJ8)**  
   Start learning STM32CubeIDE from scratch.

5. **[Getting Started with STM32](https://www.youtube.com/watch?v=fcm5wmtgkcc)**  
   Covers the basics of the STM32 ecosystem and setup.

---

## 2. Intermediate Level ⚙️

1. **[Master STM32 Microcontroller Tutorials](https://www.youtube.com/playlist?list=PLtVUYRe-Z-mfKO0lg_-MBvwWl6VjWT8Dt)**  
   Comprehensive tutorials for intermediate-level developers.

2. **[STM32 Microcontroller Tutorials](https://www.youtube.com/playlist?list=PLO89phzZmnHj7BGaRjCRbhowrwjaH-Uqx)**  
   Hands-on programming with examples.

3. **[Embedded Systems Development with STM32](https://www.youtube.com/playlist?list=PLzJTJ1FSIHJsse4emR9Hynz79e32YgKic)**  
   Learn practical embedded systems development.

4. **[PWM Programming in STM32](https://www.youtube.com/watch?v=jyZzxrOBWkM)**  
   Understand and implement PWM functionality.

5. **[Bare Metal Programming Using STM32](https://www.youtube.com/playlist?list=PL4cGeWgaBTe155QQSQ72DksLIjBn5Jn2Z)**  
   Dive into low-level programming without libraries.

---

## 3. Advanced Level 🚀

1. **[Advanced Embedded Systems with STM32](https://www.youtube.com/channel/UCF3XK5xP__GqT4BGdXnXbXw)**  
   High-level programming and hardware interfacing tutorials.

2. **[STM32 Project Tutorials](https://www.youtube.com/playlist?list=PLtuqBdbsL-DvXMyzhGnODxjYmrH9v-PPY)**  
   Advanced project development and applications.

3. **[Keil IDE Advanced Programming with STM32](https://www.youtube.com/playlist?list=PLexx2wRznGadF7Mtx9AZSeff-SHT9a4Sn)**  
   Detailed insights into Keil IDE for STM32.

4. **[MOOC - STM32L4 Hands-on Workshop](https://www.youtube.com/playlist?list=PL93s1O11OowkCWybzGKrqdrtRrwTHWlsv)**  
   Covers advanced features, including power-saving techniques.

5. **[RTOS on STM32](https://www.youtube.com/playlist?list=PL15Xgb4zU4UO-AYmd1WmhkifpnQ48eLzX)**  
   Implement Real-Time Operating Systems with STM32.

---

## 4. Mixed Levels 🔄

1. **[STMicroelectronics Official Channel](https://www.youtube.com/user/STonlineMedia)**  
   Tutorials and webinars from STM32's official team.

2. **[DeepBlue Embedded](https://www.youtube.com/c/DeepBlueEmbedded)**  
   Creative projects and tutorials for STM32 users.

3. **[Controllerstech](https://www.youtube.com/c/controllerstech)**  
   Covers diverse STM32 topics for all skill levels.

4. **[Phil's Lab](https://www.youtube.com/c/Philslab)**  
   Advanced tutorials on embedded systems and STM32.

5. **[EMBD Logic](https://www.youtube.com/channel/UCET1xMIF13xjO8E8QYB-LqA)**  
   Hands-on projects and insights into STM32 programming.

---

## 5. Honorable Mentions 🏅

1. **[Microcontroller Projects with STM32](https://www.youtube.com/user/embeddedhobby)**  
   Real-world projects using STM32 microcontrollers.

2. **[EDA Playground STM32](https://www.youtube.com/user/eda-playground)**  
   Tutorials and examples for embedded enthusiasts.

3. **[Fastbit Embedded Academy](https://www.youtube.com/channel/UCya8PyAjbavPrZR7C1KAVmg)**  
   Comprehensive STM32 and embedded system learning.

4. **[Tutorials with STM32 Blue Pill](https://www.youtube.com/playlist?list=PLRTE3JhcF0w88f1zxdOzjlQifZJXHGTfc)**  
   Explore the STM32 Blue Pill board and its capabilities.

5. **[ARM Cortex-M Programming](https://www.youtube.com/channel/UCrg9g96UoF6I4bPoAB_-Vyw)**  
   Focused on ARM Cortex-M architecture programming.

6. **[Electronics Hub](https://www.youtube.com/user/ElectronicsHub)**  
   Mix of tutorials and STM32-based projects.

7. **[Learn Embedded Systems](https://www.youtube.com/user/LearnEmbeddedSystems)**  
   Embedded system tutorials with STM32 highlights.

8. **[STM32 Hardware and Software Projects](https://www.youtube.com/user/EmbeddedHardwareProjects)**  
   Holistic project-based learning with STM32.

9. **[DIY Engineers](https://www.youtube.com/c/DIYEngineers)**  
   Explore advanced concepts and DIY projects with STM32.

10. **[Techiesms](https://www.youtube.com/user/techiesms)**  
   Embedded systems and STM32-focused tutorials.

---

## Check-In

Use this checklist to track your progress. Explore each resource, and mark it complete once you're confident in the material. If you encounter broken links or have suggestions for additional content, feel free to contribute via issues or pull requests.

---

## Contribution

Feel free to add new resources or suggest improvements. Contributions are welcome!

## License

This list is provided under [MIT License](LICENSE).
