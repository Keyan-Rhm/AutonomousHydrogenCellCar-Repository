
#include "UW_GENE_121.h"
//100 as the black-white point

void sensor(void)
{
    initialize();
    wait1Msec(200);
    
    int sensor1 = 1;//left
    int sensor2 = 1;//right
	
    while(sensor1 > 0 && sensor2 > 0)
    {
        sensor1 = getSensor(REFLECT_1);
        sensor2 = getSensor(REFLECT_2);
        // less than 70 is black
        // greater than 150 is white
    }
}
