# PowerGrid Solutions – Electrical Safety Monitoring System

## Overview
PowerGrid Solutions is a real-time electrical safety monitoring system designed to detect abnormal current or voltage conditions in public power infrastructure and prevent electrocution hazards.

## Problem Statement
Unexpected electrical faults in public power lines can lead to severe safety risks and delayed response times, often resulting in serious injuries or fatalities.

## Solution
The system continuously monitors electrical parameters using current and voltage sensors. Upon detecting abnormal flow, it automatically isolates the circuit and sends an alert to concerned authorities for immediate action.

## System Architecture
- **Sensors:** ACS712 (Current), ZMPT101B (Voltage)
- **Controller:** ESP32
- **Safety Mechanism:** Relay-based automated circuit breaker
- **Communication:** Bluetooth-based alert system

## Key Features
- Real-time electrical fault detection  
- Automatic circuit isolation to prevent hazards  
- Fast alert notification to authorities  
- Reliable and low-latency response system  

## Use Cases
- Public power poles  
- High-risk electrical zones  
- Temporary power setups during large events  

## Learnings
- Embedded system design and sensor integration  
- Fault tolerance and safety-oriented system development  
- Real-time monitoring and response mechanisms  
