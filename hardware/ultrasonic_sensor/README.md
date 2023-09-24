# Ultrasonic sensor description 
![run status](../static/img/Ultrasonic_sensor_example.gif)

## 硬件清单 Hardware List
- Arduino UNO R3
- HC-SR04
- USB cable

## 描述 Description
超声波感测器（Ultrasonic sensor）采用HC-SR04模块，该模块采用5V电压供电，带有Echo与Trig两个引脚，其中Trig引脚用于高电平脉冲触发，Echo引脚用于接收回波。

The ultrasonic sensor adopts the HC-SR04 module, which is powered by a 5V voltage and has two pins, Echo and Trig. The Trig pin is used for high-level pulse triggering and the Echo pin is used for receiving echoes.

### 工作原理 Working Principle
HC-SR04模块工作原理：
- 使用用IO触发测距，给至少10us的高电平信号
- 模块自动发送8个40khz的方波，自动检测是否有信号返回
- 有信号返回时通过IO输出一高电平，高电平持续的时间就是超声波从发射到返回的时间
- 测试距离=（高电平时间*声速（340M/S））/2
- 本产品使用方法简单，一个控制口发一个10US以上的高电平，就可以在接收口等待高电平输出，一有输出就可以开定时器计时，当此口变为低电平时就可以读定时器的值，此时就为此次测距的时间，
方可算出距离，如此不断的周期测试，就可以达到你移动测量的值了。
- 侦测距离：输入DC5V时、侦测距离2cm~450cm

### 项目介绍 Description of the project
侦测距离：输入DC5V时、**侦测距离2cm~400cm**，超出数据范围的数据会被过滤

Detection distance: When inputting DC5V, **detection distance 2cm~400cm**, data beyond the data range will be filtered

#### 超声波传感器接线 Ultrasonic Sensor Cable Description
|HC-SR04|Arduino UNO|
|:---:|:---:|
|VCC|5v|
|GND|GND|
|Trig|A0|
|Echo|A1|

## 运行 Run
PC打开对应串口，波特率9600开始接受Arduino UNO发送的数据

Open the corresponding serial port on the PC, and start accepting data sent by Arduino UNO at a baud rate of 9600
