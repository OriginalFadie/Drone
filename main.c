#include "pins.h"
#include "imu.h"

typedef unsigned int uint;

void write32(void *dst, uint val)
{
	uint* dst_u = (uint*)dst;
	*dst_u = val;

	return;
}

uint read32(void *src)
{
	uint* src_u = (uint*)src;
	return *src_u;
}

void main(void)
{

	uint five_volt_one = read32(BCM2835_GPFSEL2);
	uint five_volt_two = read32(BCM2835_GPFSEL4);

	uint three_volt_one = read32(BCM2835_GPFSEL1);
	uint three_volt_two = read32(BCM2835_GPFSEL17);

	five_volt_one |= (1<<3);
	five_volt_two |= (1<<3);

	three_volt_one |= (1<<3);
	five_volt_two |= (1<<3);

	write32(BCM2835_GPFSEL4, five_volt_two);
	write32(BCM2835_GPFSEL2, five_volt_one);

	write32(BCM2835_GPFSEL1, three_volt_one);
	write32(BCM2835_GPFSEL17, three_volt_two);

	rotation_matrix rm = axis_struct(x, y, z);
	float gyroscope_rotation = gyroscope_calibration();
	float roll,pitch = gyroscope_pitch_roll_retrieval(rm);
	float yaw = magnetometer_yaw(rm, roll, pitch);

}
