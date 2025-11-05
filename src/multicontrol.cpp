#include "damiao_can.h"
#include "CanPort.h"

// 定义电机对象
// 参数：电机型号、从机ID（CAN ID）、主机ID
//damiao::Motor M1(damiao::DM4310, 0x04, 0x14);
damiao::Motor M2(damiao::DM4310, 0x03, 0x13);

int main(int argc, char *argv[])
{
    // 创建 CAN 端口对象
    auto can = std::make_shared<CanPort>("can0");

    // 创建电机控制对象（基于 SocketCAN）
    damiao::Motor_Control dm(can);

    // 添加电机
    //dm.addMotor(&M1);
    dm.addMotor(&M2);

    // 设置零点
    //dm.set_zero_position(M1);
    dm.set_zero_position(M2);

    // 使能电机
    //dm.enable(M1);
    dm.enable(M2);

    // ======================== MIT 控制模式 =========================
    // 参数依次为: 电机对象, kp, kd, 位置, 速度, 扭矩
    while (true)
    {
        dm.control_mit(M2, 5.0f, 1.0f, 1.0f, 0.0f, 0.0f);
        // 这里如果电机没有动作，可以试着减小 kp/kd 或调节位置
        usleep(10000); // 10ms，防止占满 CPU
    }

    // 结束时可以失能电机（一般不会执行到这里）
    // dm.disable(M1);
    // dm.disable(M2);

    return 0;
}
