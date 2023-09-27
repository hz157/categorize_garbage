# -*- coding: utf-8 -*-
# @Author: Ryan Zhang
# @Date:   9/27/23
# @Last Modified by:   Ryan Zhang
# @Last Modified time: 9/27/23
# @Github: hz157 (https://github.com/hz157)
import serialutils

class hardware:
    def __init__(self):
        self.ser = serialutils.SerialUtils()
        self.ser.start_read_data()

    def SendServoAngle(self, servoNum: int, angle: int):
        readySendData = f"FE 00 01 01 {hex(servoNum)[2:].upper().zfill(2)} {hex(angle)[2:].upper().zfill(2)}"
        self.ser.send_data(readySendData)
        if self.ser.serialData == str(angle):   # 舵机控制完成，串口返回数据
            return True
        return False

    def GetUltrasonicSensorData(self, sensorNum: int=None):

        if sensorNum is None:
            readySendData = "FE 00 02 00 00 00"
        else:
            readySendData = f"FE 00 02 00 {hex(sensorNum)[2:].upper().zfill(2)} 00"
        self.ser.send_data(readySendData)
        if readySendData == "FE 00 02 00 00 00":
            return True
