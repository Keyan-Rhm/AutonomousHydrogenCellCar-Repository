#include "UW_GENE_121.h"

void track1(void)
{
	initialize();
	wait1Msec(200);
	
	int sensorL = 10;
	int sensorR = 10;
	
	int const VAL = 75;
	int const POWERA = (30*0.95);
	int const POWERB = 30;
	int const MOTORWAIT = 50;
	
	//Turn Motors Off    
	setMotor(MOTOR_A, 0);
	setMotor(MOTOR_B, 0);

	int button = 0;
	while (getSensor(BUMPER) == 0)
	{
		while (getSensor(BUTTON) == 0)
		{}
		button ++;
		while (getSensor(BUTTON) == 1)
		{}
	}

	if (button == 1)
	{
		//End 1
		while(sensorL > 0 && sensorR > 0 && getSensor(BUMPER) == 0)
		{
			sensorL = getSensor(REFLECT_1);
			sensorR = getSensor(REFLECT_2);
			
			if (sensorR > VAL && sensorL > VAL)
			{
				//Drive Forward
				setMotor(MOTOR_A, POWERA);
				setMotor(MOTOR_B, POWERB);
				LEDnum(1);
				wait1Msec(MOTORWAIT);
			}
			else if (sensorL < VAL)
			{
				//Turn Left
				setMotor(MOTOR_A, POWERA);
				setMotor(MOTOR_B, -POWERB);
				LEDnum(3);
				wait1Msec(MOTORWAIT);
			}
			else if (sensorR < VAL)
			{
				//Turn Right
				setMotor(MOTOR_A, -POWERA);
				setMotor(MOTOR_B, POWERB);
				wait1Msec(MOTORWAIT);
				LEDnum(5);
			}  
		}
	}
	else if (button == 2)
	{
		//End 2: Same as End 1 but missing a Turn Left function
		while(sensorL > 0 && sensorR > 0 && getSensor(BUMPER) == 0)
		{
			sensorL = getSensor(REFLECT_1);
			sensorR = getSensor(REFLECT_2);
			
			if (sensorR > VAL && sensorL > VAL)
			{
				//Drive Forward
				setMotor(MOTOR_A, POWERA);
				setMotor(MOTOR_B, POWERB);
				LEDnum(1);
				wait1Msec(MOTORWAIT);

			}
			else if (sensorR < VAL)
			{
				//Turn Right
				setMotor(MOTOR_A, -POWERA);
				setMotor(MOTOR_B, POWERB);
				wait1Msec(MOTORWAIT);
				LEDnum(5);
			}  
		}
	}
	else if (button == 3)
	{
		//End 3: Go forward until the road starts turning left
		//		 Then start veering right toward End 3
		while(sensorL > 0 && sensorR > 0 && getSensor(BUMPER) == 0)
		{
			sensorL = getSensor(REFLECT_1);
			sensorR = getSensor(REFLECT_2);
			
			if (sensorR > VAL && sensorL > VAL)
			{
				//Drive Forward
				setMotor(MOTOR_A, POWERA);
				setMotor(MOTOR_B, POWERB);
				LEDnum(1);
				wait1Msec(MOTORWAIT);
			}
			else if (sensorL < VAL)
			{
				//If sensor left turns black (road starts curving left)
				//Start turning RIGHT towards end 3
				setMotor(MOTOR_A, -POWERA);
				setMotor(MOTOR_B, POWERB);
				wait1Msec(MOTORWAIT);
				LEDnum(5);
			}
			else if (sensorR < VAL)
			{
				//Turn Right
				setMotor(MOTOR_A, -POWERA);
				setMotor(MOTOR_B, POWERB);
				wait1Msec(MOTORWAIT);
				LEDnum(5);
			}  
		}
	}
}