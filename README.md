# 💡 Smart Home IoT LED Control System

An end-to-end smart home IoT system that enables real-time control of an LED via a cloud-connected web interface.

## 🔧 Tech Stack

- **Hardware**: ESP32  
- **Software**: Arduino IDE  
- **Cloud Services**: AWS IoT Core, MQTT, Lambda, API Gateway, S3  
- **Frontend**: HTML, CSS, JavaScript  

## 🌐 Features

- Real-time LED control from any device with internet access  
- Secure communication using **MQTT protocol** and **X.509 certificates**  
- Responsive frontend hosted on **AWS S3**  
- Bi-directional communication between ESP32 and AWS using **API Gateway + Lambda**

## 🖥️ System Architecture

[ Web Interface (HTML/CSS/JS) ]
⬇️
[ API Gateway ➝ AWS Lambda ]
⬇️
[ AWS IoT Core (MQTT) ]
⬇️
[ ESP32 Device ]

## 🔐 Security

- MQTT communication secured with **X.509 certificates**  
- IAM roles and policies to restrict AWS service access


## 🚀 How It Works

1. ESP32 connects to AWS IoT Core using MQTT.  
2. Web UI sends commands (e.g., turn LED on/off) via API Gateway.  
3. Lambda forwards the message to AWS IoT Core.  
4. ESP32 receives the message and switches the LED accordingly.

## 📸 Demo

> *Add screenshots or a demo GIF/video here if available*

## 📚 Requirements

- ESP32 board  
- AWS account with IoT Core, Lambda, S3, and API Gateway access  
- Arduino IDE with required libraries  
- Basic understanding of MQTT and AWS services  

## 🧠 Learnings

- Secure IoT device-cloud communication  
- Real-time control over MQTT  
- Serverless backend using AWS Lambda  
- Hosting and integrating a static frontend with cloud services  

## 📎 Useful Links

- [AWS IoT Core Documentation](https://docs.aws.amazon.com/iot/)  
- [ESP32 Arduino Setup](https://docs.espressif.com/projects/arduino-esp32/en/latest/)  
- [MQTT Protocol](https://mqtt.org/)  


---

> Developed by Bhuvesh  

