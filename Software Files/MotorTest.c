#include "UW_GENE_121.h"

void motor(void)
{
	initialize();
	wait1Msec(200);

    //Drive Forward
	setMotor(MOTOR_A, (50*0.95));
	setMotor(MOTOR_B, 50);
    wait1Msec(30000);
        
    //Test Right Motor
    setMotor(MOTOR_A, 50);
	setMotor(MOTOR_B, 0);
    wait1Msec(3000);
          
    //Test Left Motor    
    setMotor(MOTOR_A, 0);
	setMotor(MOTOR_B, 50);
    wait1Msec(3000);
        
    //Turn Motors Off    
    setMotor(MOTOR_A, 0);
	setMotor(MOTOR_B, 0);
                       
}