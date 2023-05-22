#include <stdint.h>
#include "ADC_LIB.h"
#define _XTAL_FREQ 8000000




void ADC_Init(void) 
{
    // ADCON2
    ADCON2bits.ADFM=1;			// Results format 1= Right justified
    ADCON2bits.ACQT=1;			// Acquition time 7 = 20TAD 2 = 4TAD 1=2TAD
    ADCON2bits.ADCS=2;			// Clock conversion bits 6= FOSC/64 2=FOSC/32
    // ADCON1
	ADCON1bits.PVCFG0 =0;		// Vref+ = AVdd
	ADCON1bits.NVCFG1 =0;		// Vref- = AVss
	// ADCON0
	ADCON0bits.CHS=2;			// Select ADC channel
	ADCON0bits.ADON=1;			// Turn on ADC
   }

uint16_t Leer_Canal_ADC(uint8_t Canal)
{
	uint16_t ADC;                       // Variable que retornará el valor de los registros ADRESH y ADRESL.
	while(1){
	PIR1bits.ADIF = 0;	 							//make sure A/D Int not set
	ADCON0bits.GO=1;				   				//begin A/D conv
	while(!PIR1bits.ADIF); 							//Wait for A/D convert complet
	ADC = (int)((ADRESH << 8) + ADRESL);			//Get the value from the A/D
	__delay_ms(4);
	return ADC;

}


