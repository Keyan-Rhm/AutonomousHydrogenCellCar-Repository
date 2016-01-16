#include "UW_GENE_121.h"

int const VAL = 75;
int const POWERA = (30*0.9);
int const POWERB = 30;
int const MOTORWAIT = 0;

void goForward()
{
	setMotor(MOTOR_A, POWERA);
    setMotor(MOTOR_B, POWERB);
    LEDnum(1);
}

void turnLeft()
{
	setMotor(MOTOR_A, POWERA);
    setMotor(MOTOR_B, 0);
    LEDnum(3);
}

void turnRight()
{
	setMotor(MOTOR_A, 0);
    setMotor(MOTOR_B, POWERB);
    LEDnum(5);
}

void main3(void)
{
	initialize();
	wait1Msec(200);
	
	int sensorL = 10;
	int sensorR = 10;
	
	while(sensorL > 0 && sensorR > 0 && getSensor(BUMPER) == 0)
	{
		sensorL = getSensor(REFLECT_1);
		sensorR = getSensor(REFLECT_2);
		
		if (sensorR > VAL && sensorL > VAL)
		{
			//Drive Forward
			goForward();
			wait1Msec(MOTORWAIT);
		}
		else if (sensorL < VAL && sensorR < VAL)
		{
			do
			{
				sensorR = getSensor(REFLECT_2);
				//Turn Left
                turnLeft();
                wait1Msec(175);
			} while (sensorR < VAL);
		}
		else if (sensorL < VAL)
		{
			//Turn Left
			turnLeft();
			wait1Msec(MOTORWAIT);
			
		}
		else if (sensorR < VAL)
		{
			//Turn Right
			turnRight();
			wait1Msec(MOTORWAIT);
		}  
	}
}
