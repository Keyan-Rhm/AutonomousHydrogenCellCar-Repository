/*
Project Name : 	AutonomousHydrogenCellCar
Authors      : 	Yasir Al Shekerchi, David Perna, Tianyu Guo, Keyan Raahemifar
Course(s)    : 	MTE100, GENE121, CHE 120
Date Created : 	November 5, 2015
Date Modified:	November 10, 2015
Description  : 	The code below is used to debug the sensor. The Left Sensor
                is connected to the sensor1 port. The right sensor is connected	
                to the sensor2 port. 
Conclusions  :  Values less than 75 is black
                Values greater than 75 is white
*/

#include "UW_GENE_121.h"

void sensor(void)
{
    initialize();
    wait1Msec(200);
    
    int sensor1 = 1; //left
    int sensor2 = 1;//right
	
    while(sensor1 > 0 && sensor2 > 0)
    {
        sensor1 = getSensor(REFLECT_1);
        sensor2 = getSensor(REFLECT_2);
        // less than 70 is black
        // greater than 150 is white
    }
}
