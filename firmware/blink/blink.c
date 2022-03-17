/*
 * main.c
 *  Created on: Mar 6, 2019
 *      Author: wrongbaud
 */

#include <tc1767.h>
#include <tc1767/scu/addr.h>
#include <tc1767/scu/types.h>
#include <tc1767/port5-struct.h>

typedef struct
{
	unsigned int _con0;
	unsigned int _con1;
}WdtCon_t;

void disable_gpios()
{
	unsigned int * GPIO_CTRL_REG = 0xF0000F1C;
	unsigned int * GPIO_OUTPUT_REG = 0xF0000F04;
	*GPIO_CTRL_REG = 0x80208020;
	*GPIO_OUTPUT_REG = 0x00000000;
}
void toggle_pin_15()
{
	unsigned int * GPIO_CTRL_REG = 0xF0000F1C;
	unsigned int * GPIO_OUTPUT_REG = 0xF0000F04;
	*GPIO_CTRL_REG = 0x80208020;
	*GPIO_OUTPUT_REG = 0x80008000;
}

void main()
{
    // Configure WDT and ENDINT as described in user manual
	unsigned int wcon0,wcon1;
	volatile WdtCon_t *wdtaddr = 0xF00005F0;
	wcon0 = wdtaddr->_con0;
	wcon1 = wdtaddr->_con1;
	// Unlock WDT and disable ENDINT protection so we can reconfigure clocks
	wcon0 &= 0xffffff03;
	wcon0 |= 0xf0;
	wcon0 |= (wcon1 & 0xc);
	wcon0 ^= 0x2;
	wdtaddr->_con0 = wcon0;
	wcon0 &= 0xfffffff0;
	wcon0 |= 0x2;
	wdtaddr->_con0 = wcon0;
	(void) wdtaddr->_con0;
	// Reconfigure clock speed as reccomended in user manual
	SCU_PLLCON0_t * SCU_PLLCON0 = (SCU_PLLCON0_t*) SCU_PLLCON0_ADDR;
	SCU_PLLCON0->bits.VCOBYP = 0;
	SCU_PLLCON1_t * SCU_PLLCON1 = (SCU_PLLCON1_t *) SCU_PLLCON1_ADDR;
	SCU_PLLCON1->bits.K1DIV = 0;
	toggle_pin_15();
}
