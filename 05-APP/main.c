/*
 * main.c
 *
 *  Created on: Sep 7, 2020
 *      Author: zaki
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"RCC_interface.h"
#include "GPIO_init.h"

#include"RTOS_interface.h"

void LED1(void);
void LED2(void);
void LED3(void);


void main(void)
{
	RCC_voidInitSystemClock();
	/*Enable peripheral 2 on APB2 Bus(GPIOA)*/
	RCC_voidEnableClock(RCC_APB2 , IOPAEN);

	RCC_voidEnableClock(RCC_APB2 , IOPBEN);
//MSTK_voidInit(_AHB_DIV8);


	GPIO_voidSetPinDirection(GPIOA , PIN0 , OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(GPIOA , PIN1 , OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(GPIOA , PIN2 , OUTPUT_SPEED_2MHZ_PP);



	RTOS_VoidCreateTask(0 , 1000 , LED1 , 0);
	RTOS_VoidCreateTask(1 , 2000 , LED2 , 0);
	RTOS_VoidCreateTask(2 , 3000 , LED3 , 0);

	RTOS_VoidStart();

	while(TRUE)
	{

	}
}


void LED1(void)
{
	static u8 i=0;
	TOGGLE_BIT(i,0);
	GPIO_voidSetPinvalue(GPIOA , PIN0 ,i);
}

void LED2(void)
{
	static u8 i=0;
	TOGGLE_BIT(i,0);
	GPIO_voidSetPinvalue(GPIOA , PIN1 ,i);
}

void LED3(void)
{
	static u8 i=0;
	TOGGLE_BIT(i,0);
	GPIO_voidSetPinvalue(GPIOA , PIN2 ,i);
}
