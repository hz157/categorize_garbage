# 硬件描述 HardWare description
> 该项目硬件设备通信采用Serial 串口通信，通过USB线缆连接Arduino开发板

> The project hardware device communication using Serial serial communication, through the USB cable connected to the Arduino development board

## 该方案传感器及控制器 Sensors and controllers for the project
- 超声波传感器 Ultrasonic sensor description 
- 25KG舵机


## 指令规范 Command Specifications
通信过程全程使用HEX格式发送指令，下面是对应的指令规范

The entire communication process uses the HEX format to send commands, and the following is the corresponding command specification

### 查询 Query
|  Function   | Command  |
|  ----  | ----  |
| 查询超声波传感器(All)  | FE 00 02 00 00 00 |
| 查询单路超声波传感器（1）  | FE 00 02 00 01 00 |
| 查询单路超声波传感器（2）  | FE 00 02 00 02 00 |
| 查询单路超声波传感器（3）  | FE 00 02 00 03 00 |
| 查询单路超声波传感器（4）  | FE 00 02 00 04 00 |
| 查询单路超声波传感器（5）  | FE 00 02 00 05 00 |
| 查询单路超声波传感器（6）  | FE 00 02 00 06 00 |
| 查询单路超声波传感器（7）  | FE 00 02 00 07 00 |
| 查询单路超声波传感器（8）  | FE 00 02 00 08 00 |
| 查询单路舵机角度（1）  | FE 00 02 01 01 00 |
| 查询单路舵机角度（2）  | FE 00 02 01 02 00 |
| 查询单路舵机角度（3）  | FE 00 02 01 03 00 |
| 查询单路舵机角度（4）  | FE 00 02 01 04 00 |
| 查询单路舵机角度（5）  | FE 00 02 01 05 00 |
| 查询单路舵机角度（6）  | FE 00 02 01 06 00 |

### 控制 Control
| Function | Command |
| --- | --- |
| 控制单路舵机角度（1） 90度  | FE 00 01 01 01 5A |
| 控制单路舵机角度（2） 180度 | FE 00 01 01 02 B4 |
| 控制单路舵机角度（3） 0度  | FE 00 01 01 03 00 |
| 控制单路舵机角度（4） 45度 | FE 00 01 01 04 2D |
| 控制单路舵机角度（5） 15度 | FE 00 01 01 05 0F |
| 控制单路舵机角度（6） 35度 | FE 00 01 01 06 23 |