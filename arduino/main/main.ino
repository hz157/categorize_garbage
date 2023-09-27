// @Author: Ryan Zhang
// @Date:   9/25/23
// @Last Modified by:   Ryan Zhang
// @Last Modified time: 9/25/23
// @Github: hz157 (https://github.com/hz157)

#include <Servo.h>

// 舵机控制
class RDS3225Servo {
private:
  Servo servo;
  int pos = 90;
  int servoNum = -1;
  static const int MIN_SPEED = 1000; // 舵机的最小脉冲宽度（microseconds）
  static const int MAX_SPEED = 2000; // 舵机的最大脉冲宽度（microseconds）

public:
  RDS3225Servo() {}

  // 初始化舵机
  void Init(int servoNum, int servoPin){
    servo.attach(servoPin); // 舵机引脚
    servo.write(pos); // 初始化舵机角度
    this->servoNum = servoNum; // 声明舵机编号
    delay(15);
  }

  // 舵机角度
  void Write(int angle) {
    // angle = constrain(angle, 0, 180); // 限制角度在0-180度之间
    servo.write(angle);
    SendDataToSerial(angle);
    delay(15);
  }

  // 舵机转速
  void SetSpeed(int speed) {
    speed = constrain(speed, 0, 100); // 限制速度在0-100%之间
    int mappedSpeed = map(speed, 0, 100, MIN_SPEED, MAX_SPEED);
    servo.writeMicroseconds(mappedSpeed);
  }

  // 分离舵机以停止运动
  void Detach() {
    servo.detach();
  }

  void SendDataToSerial(int angle) {
    Serial.print("Servo ");
    Serial.print(servoNum);
    Serial.print(": ");
    Serial.println(angle);
    delay(1000); // 刷新时间为1s
  }
};

// 超声波传感器
class UltrasonicSensor {
private:
  int trigPin;
  int echoPin;
  float distance;
  int UltrasonicSensorNum;

public:
  UltrasonicSensor(int sensorNum, int trigPin, int echoPin) : trigPin(trigPin), echoPin(echoPin) {
    this->UltrasonicSensorNum = sensorNum;
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
  }

  double MeasurementDistance() {
     // 初始化 防止还在高电平状态，给低电平将超声波传感器重置
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // 超声波开始测距
    digitalWrite(trigPin, HIGH); // 输出高电平信号，SR04开始发射超声波脉冲
    delayMicroseconds(10); // 持续10μs
    digitalWrite(trigPin, LOW); // 测距完成，重新给低电平
    distance = (pulseIn(echoPin, HIGH) * 0.0343) / 2; //单位换算 距离=(高电平持续时间*声速)/2
    return distance;
  }

  void SendDataToSerial() {
    double distance = this->MeasurementDistance();
    if (distance >= 2 && distance <= 400) {
      Serial.print("UltrasonicSensor ");
      Serial.print(UltrasonicSensorNum);
      Serial.print(": "); 
      Serial.println(distance); // 发送距离值(unit: cm)
    } else {
      Serial.println("distance error");
    }
    delay(1000); // 刷新时间为1s
  }
};


class Serial

UltrasonicSensor sensor(1, A0, A1);  // 声明超声波传感器
RDS3225Servo servo1;

void setup() {
  Serial.begin(9600);
  servo1.Init(1, 9);
}

void loop() {
  sensor.SendDataToSerial();  //发送超声波传感器数据
  servo1.Write(80);  // 将舵机转到新位置
  delay(1000); // 延时1s
}
