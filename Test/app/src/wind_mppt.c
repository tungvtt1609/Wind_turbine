/*
 * wind_mppt.c
 *
 *  Created on: Mar 8, 2023
 *      Author: Thanh Tung
 */

#include "wind_mppt.h"
#define DEFAULT_DC_POWER_RATING 1000.0f

void WindMPPTInit(MPPT_PNO *v){
	v->Iwt = 0;
	v->Vwt = 0;
	v->DeltaPmin = 0;
	v->Delta_V = 0;
	v->Delta_P = 0;
	v->MaxVolt = 0;
	v->MinVolt = 0;
	v->MaxCur = 0;
	v->MinCur = 0;
	v->Stepsize = 0;
	v->VmppOut = 0;
	v->ImppOut = 0;
	v->Power_wind = 0;
	v->Power_wind_prev = 0;
	v->Iwt_prev = 0;
	v->Vwt_prev = 0;
	v->StepSizeVolMax = 0;
	v->StepSizeCurMax = 0;
	v->StepSizeVol = v->StepSizeVolMax;
	v->mppt_enable = 1;
	v->mppt_first = 1;
}

float DpDu = 0.0;
uint32_t count = 0;

void WindMPPTProcess(MPPT_PNO *v){
	v->Delta_V = v->Vwt - v->Vwt_prev;
	v->Delta_P = v->Power_wind - v->Power_wind_prev;

	if(v->mppt_enable == 1){
		/*MPPT mode enable*/
		if(v->mppt_first == 1){
			v->VmppOut = v->Vwt - 0.02;
			v->mppt_first = 0;
			v->Power_wind_prev = v->Power_wind;
		}
		else if(v->Delta_P > v->DeltaPmin){
			if(v->Delta_V > 0){
				v->VmppOut = v->VmppOut + v->StepSizeVol;
			}
			else if(v->Delta_V <= 0){
				v->VmppOut = v->VmppOut - v->StepSizeVol;
			}
		}
		else if(v->Delta_P < -v->DeltaPmin){
			if(v->Delta_V > 0){
				v->VmppOut = v->VmppOut - v->StepSizeVol;
			}
			else if(v->Delta_V <= 0){
				v->VmppOut = v->VmppOut + v->StepSizeVol;
			}
		}
		else{
			if(v->Delta_V > 0){
				v->VmppOut = v->VmppOut - v->StepSizeVol;
			}
			else if(v->Delta_V <= 0){
				v->VmppOut = v->VmppOut + v->StepSizeVol;
			}
		}
	}
	if(v->VmppOut < v->MinVolt) v->VmppOut = v->MinVolt;
	if(v->VmppOut > v->MaxVolt) v->VmppOut = v->MaxVolt;

	v->Power_wind_prev = v->Power_wind;
	v->Iwt_prev = v->Iwt;
	v->Vwt_prev = v->Vwt;
}

void WindMPPTUpdate(MPPT_PNO *mppt, float cur, float vol){
	static float vwt_avg_multiplier = 0.0002f;
	static float iwt_avg_multiplier = 0.0002f;
	mppt->Vwt = ((vol - mppt->Vwt) * vwt_avg_multiplier) + mppt->Vwt;
	mppt->Iwt = ((cur - mppt->Iwt) * iwt_avg_multiplier) + mppt->Iwt;
}

