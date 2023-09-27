// @Author: Ryan Zhang
// @Date:   9/23/23
// @Last Modified by:   Ryan Zhang
// @Last Modified time: 9/23/23
// @Github: hz157 (https://github.com/hz157)
int TrigPin = A0;
int EchoPin = A1;
float distance;

void setup() {
  Serial.begin(9600);
  pinMode(TrigPin,OUTPUT);
  pinMode(EchoPin,INPUT);
}


void loop() {
  // 初始化 防止还在高电平状态，给低电平将超声波传感器重置
  digitalWrite(TrigPin,LOW);
  delayMicroseconds(2);
  // 超声波开始测距
  digitalWrite(TrigPin,HIGH); // 输出高电平信号，SR04开始发射超声波脉冲
  delayMicroseconds(10);  // 持续10μs
  digitalWrite(TrigPin,LOW);  // 测距完成，重新给低电平
  distance = (pulseIn(EchoPin,HIGH) * 0.0343) / 2;  //单位换算 距离=(高电平持续时间*声速)/2
  if (distance >= 2 && distance <= 400){
    Serial.print("usg1: ");
    Serial.println(distance);  // 发送距离值(unit: cm)
  } else {
    Serial.print("distance error");
  }
  delay(1000); // 刷新时间为1s
}
