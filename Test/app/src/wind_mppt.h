/*
 * wind_mppt.h
 *
 *  Created on: Mar 8, 2023
 *      Author: Thanh Tung
 */

#ifndef SRC_WIND_MPPT_H_
#define SRC_WIND_MPPT_H_

#include "math.h"
#include "types.h"

typedef struct {
	float Iwt;
	float Vwt;
	float DeltaPmin;
	float Delta_V;
	float Delta_P;
	float MaxVolt;
	float MinVolt;
	float MaxCur;
	float MinCur;
	float Stepsize;
	float VmppOut;
	float ImppOut;
	float Power_wind;
	float Power_wind_prev;
	float Iwt_prev;
	float Vwt_prev;
	float StepSizeVol;
	float StepSizeCur;
	float StepSizeVolMax;
	float StepSizeCurMax;
	uint16_t mppt_enable;
	uint16_t mppt_first;

} MPPT_PNO;

typedef enum {
	MPPT_tang, MPPT_giam, MPPT_giu_nguyen,
} MPPT_option;

void WindMPPTInit(MPPT_PNO *v);
void WindMPPTProcess(MPPT_PNO *v);
void WindMPPTUpdate(MPPT_PNO *mppt, float cur, float vol);

extern float Input_power_avg;

#endif /* SRC_WIND_MPPT_H_ */
