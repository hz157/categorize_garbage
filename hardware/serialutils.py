# -*- coding: utf-8 -*-
# @Author: Ryan Zhang
# @Date:   9/22/23
# @Last Modified by:   Ryan Zhang
# @Last Modified time: 9/22/23
# @Github: hz157 (https://github.com/hz157)


import threading
import time
import serial
import serial.tools.list_ports


class SerialUtils:

    def __init__(self):
        self.serial_port = None
        self.get_serial_port()
        self.ser = serial.Serial(port=self.serial_port, baudrate=9600)
        self.readSerialThread = threading.Thread(target=self.read_data)

    # 查看系统串口
    def get_serial_port(self):
        try:
            # 获取系统中可用的串口列表
            # 串口名称: port.device 描述: port.description 串口号: port.serial_number
            # 遍历串口列表并打印信息
            for port in serial.tools.list_ports.comports():
                if port.description == "IOUSBHostDevice":
                    self.serial_port = port.device
        except ImportError:
            return None

    # 读取串口数据
    def read_data(self):
        self.ser.flushInput()
        while True:
            try:
                # 判断串口是否已经打开
                if not self.ser.is_open:
                    self.ser.flushInput()
                # 读取一行数据
                data = self.ser.readline()
                # 打印读到的数据
                print(data)
                # 延时1秒
                time.sleep(1)
            except serial.SerialException as e:
                print(f"Serial port error: {e}")

    # 发送串口数据
    def send_data(self, data):
        try:
            # 判断串口是否已经打开
            if not self.ser.is_open:
                self.ser.flushInput()
            self.ser.write(bytes.fromhex(data))
        except serial.SerialException as e:
            print(f"Serial port error: {e}")

    # 开始读取串口数据
    def start_read_data(self):
        self.readSerialThread.start()

    # 停止读取串口数据
    def stop_read_data(self):
        self.readSerialThread.join()


if __name__ == '__main__':
    ser = SerialUtils()
    ser.start_read_data()
