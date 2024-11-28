/*
 * LED.h
 *
 * Created: 11/26/2024 3:53:44 PM
 *  Author: aweka
 */ 


#ifndef LED_H_
#define LED_H_

/*
#define A 0
#define B 1
#define C 2
#define D 3
*/
typedef enum  {A,B,C,D}ports;
typedef enum  {P0,P1,P2,P3,P4,P5,P6,P7}pins;
typedef struct
{
	ports p;
	pins pi;
}LED;

void lED_inti(LED *l);
void LED_ON(LED *l);
void LED_OFF(LED *l);



#endif /* LED_H_ */