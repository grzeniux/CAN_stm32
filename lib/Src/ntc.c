
#include "math.h"
#include "ntc.h"

void NTC_Init(NTC_t *ntc, double R0, double T0, double B, double Rs, double Ucc)
{
    ntc->B = B;
    ntc->R0 = R0;
    ntc->Rs = Rs;
    ntc->T0 = T0;
    ntc->Ucc = Ucc;
}

uint16_t NTC_CalculateTemperature(NTC_t *ntc, uint16_t AdcValue)
{
	double r_inf = ntc->R0 * exp(-(ntc->B)/ntc->T0);
	double U = (AdcValue * ntc->Ucc) / 4095;
	double Rt = ( U*ntc->Rs ) / ( ntc->Ucc - U );

	double temperature = ntc->B / log(Rt/r_inf) - 273.15;
    temperature *= 100;
	return (uint16_t) temperature;
}



