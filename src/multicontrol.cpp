#include "damiao.h"
//THIS IS A TEST version- For getting familiar with the SDK

//定义相关的电机控制对象和电机对象 Master_ID=CAN_ID+0x10

damiao::Motor M1(damiao::DM4310,0x05, 0x15);
damiao::Motor M2(damiao::DM4310,0x06, 0x16);
damiao::Motor M3(damiao::DM4310,0x07, 0x17);

int main(int argc, char  *argv[]){
//串口对象
auto serial = std::make_shared<SerialPort>("/dev/ttyACM0", B921600);
auto dm =damiao::Motor_Control(serial);
dm.addMotor(&M1);
dm.addMotor(&M2);
dm.addMotor(&M3);

//设置电机零点
dm.set_zero_position(M1);
dm.set_zero_position(M2);
dm.set_zero_position(M3);

//使能电机
dm.enable(M1);
dm.enable(M2);
dm.enable(M3);

//========================================MIT模式============================================
//默认的control是mit控制模式，第一个参数电机对象，第二个是kp，第三个是kd，第四个是位置，第五个是速度,第六个是扭矩
dm.control_mit(M1, 50, 0.3, 0, 0, 0);
dm.control_mit(M2, 50, 0.3, 0, 0, 0);
dm.control_mit(M2, 50, 0.3, 0, 0, 0);




}
