// @Author: Ryan Zhang
// @Date:   9/25/23
// @Last Modified by:   Ryan Zhang
// @Last Modified time: 9/25/23
// @Github: hz157 (https://github.com/hz157)
#include <Servo.h>

void setup() {
    Servo servo;    // 声明舵机对象
    int pos = 90;   // 初始化舵机角度
    servo.attach(9); // 舵机引脚，设定为9
    servo.write(pos); // 初始化舵机角度
    delay(15); // 延时
}

void loop() {
    // 循环舵机0-180之间转动
    for(int i=0; i<180; i++) {
        servo.write(i);
    }

    for (int i=180; i>0; i--) {
        servo.write(i)
    }
}
