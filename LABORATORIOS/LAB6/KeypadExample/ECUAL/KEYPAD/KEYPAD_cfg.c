/*
 * File: KEYPAD_cfg.c
 * Driver Name: [[ 4x4 KEYPAD ]]
 * SW Layer:   ECUAL
 * Created on: Jun 28, 2020
 * Author:     Khaled Magdy
 * -------------------------------------------
 * For More Information, Tutorials, etc.
 * Visit Website: www.DeepBlueMbedded.com
 *
 */

#include "KEYPAD.h"

const KEYPAD_CfgType KEYPAD_CfgParam[KEYPAD_UNITS] =
{
	// KeyPAD Unit 1 Configurations
    {
    	/* ROWs Pins Info */
	    {GPIOA, GPIOA, GPIOB, GPIOB},
		{GPIO_PIN_6, GPIO_PIN_7, GPIO_PIN_0, GPIO_PIN_1},
		/* COLs Pins */
		{GPIOA, GPIOA, GPIOA, GPIOA},
		{GPIO_PIN_12, GPIO_PIN_11, GPIO_PIN_9, GPIO_PIN_4}
	}
};
