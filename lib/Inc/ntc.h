#ifndef INC_NTC_H_
#define INC_NTC_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"

typedef struct
{
    double R0;   	//nominal resistance @ 25*C
    double T0;   	//reference temerature (25*C) [K]
    double B;      	//thermistor constant
    double Rs;    	//series resistor value
    double Ucc;     //ADC reference voltage

    double a;
    double b;

}NTC_t;

void NTC_Init(NTC_t *ntc, double R0, double T0, double B, double Rs, double Ucc);
uint16_t NTC_CalculateTemperature(NTC_t *ntc, uint16_t AdcValue);


#ifdef __cplusplus
}
#endif
#endif
