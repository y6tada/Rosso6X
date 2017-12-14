#include "mbed.h"
#include "mainLoop.hpp"
#include "DRIVE/drive.hpp"
#include "SENSORS/imuCtrl.hpp"
#include "SENSORS/IR.hpp"
#include "SENSORS/US.hpp"

mbed::Serial	pc(PA_2,PA_3);
mbed::Serial	imu_uart(PC_6, PC_7);

mbed::Ticker	mainLoopTicker;

DRIVE	drive;
IMU		imu;
IR		i2cIR(I2C_SDA, I2C_SCL);
US		i2cUS(I2C_SDA, I2C_SCL);

void test_first(void) {
	/*
	 テストファーストプログラミング
	 しません
	 */
}

void imu_dataRecieve(void) {
	imu.calculate(imu_uart.getc());
}

// ========== main ここから ==============================  //
int main()
{
	/*	関数のテストファースト */
	test_first();
	
	/*	PCシリアルデバッグ */
	pc.baud(115200);
	pc.printf("hello!\n");
	
	/*	IMU:シリアル受信割込み */
	imu_uart.baud(115200);
	imu_uart.attach(imu_dataRecieve, mbed::Serial::RxIrq);
	
	/*	メインループ:タイマー割り込み */
	mainLoopTicker.attach_us(mainLoop, 4000);
	
	/*	モーターPWM周期 */
	drive.setMotorPwmPeriod(50);
	imu.setPD(5.0, 2.2);
	
	while (true) {
		/*
		 処理は全て割込みで動作
		 ・IMUからのシリアル割込み
		 ・mainLoopのタイマー割り込み：250Hz
		 */
	}
	
	return 0;
}
// ========== main ここまで ==============================  //
