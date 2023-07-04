# Accessible-Control-System - Audible-feedback accessibility device for visually impaired

## Introduction
The project designed to assist visually impaired individuals in using home appliances with ease. 
The system converts visual feedback to auditory feedback for home appliances, enabling visually impaired individuals to receive auditory real-time program updates.

The system was implemented for an AEG drying machine.

This GitHub repository contains all the necessary code, circuit diagrams, and parts list required to build and implement the system on a compatible drying machine. The system uses light-dependent resistors (LDRs) to detect the lit program LED, and then it generates audible feedback to announce the selected drying program.

## Diagrams
* The following diagram is a simplified HW version of the system. The implemented system included 10 LEDs and LDRs with an amplifier system and speaker.
![circuit](https://github.com/Yuvalmaster/Accessible-Control-System/assets/121662835/6cbc4ece-578d-4360-b9dc-b2860e0ff091)

* The following diagram is a simplified version of the algorithm used in system.
![Screenshot 2022-06-08 212703](https://github.com/Yuvalmaster/Accessible-Control-System/assets/121662835/44e5d629-3639-4b21-abc2-303408fccace)

## Components
* Arduino Mega R3 2560
* 10xLight-dependent resistors (LDRs)
* 10x3mm LEDs (for indicating program selection)
* 10x10kOhm resistors
* Audio Card WTV020SD
* Audio Amplifier MAX98357A

## DEMO 
* Board layout:
![Panel](https://github.com/Yuvalmaster/Accessible-Control-System/assets/121662835/0d4d4c10-58d7-48f3-b0c3-b31b35a80b41)

* Assembly:
![IMG_20220531_151828](https://github.com/Yuvalmaster/Accessible-Control-System/assets/121662835/fc17e0f9-afbf-4bec-a3a4-edffb1605223)
![IMG_20220607_103904](https://github.com/Yuvalmaster/Accessible-Control-System/assets/121662835/4d9c2278-bdfd-49bf-8ee9-5701f5f8f262)

* Demo:
[![Watch the video]](https://github.com/Yuvalmaster/Accessible-Control-System/assets/121662835/bdb85c44-010a-4161-a659-c374c67a3198)







