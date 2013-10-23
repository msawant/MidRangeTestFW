#ifndef SIMPLETIMER_H_
#define SIMPLETIMER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <DataTypes.h>
#include <StatusCodes.h>

// Enumeration for the timer ID.
// Note: The code IS SENSITIVE to the values in this enumeration. Do not change unless you know what you are doing.
typedef enum TimerID_e
{
	TMR_UPPER = 100,		// Anything greater than 100 is an upper timer
#if defined (OMAP_DSP)		// Timers 0 & 1 belong to the DSP
	TMR_0_LOWER = 0,
	TMR_0_UPPER = 100,
	TMR_1_LOWER = 1,
	TMR_1_UPPER = 101
#elif defined (OMAP_ARM)	// Timers 2 & 3 belong to the ARM
	TMR_2_LOWER = 2,
	TMR_2_UPPER = 102,
	TMR_3_LOWER = 3,
	TMR_3_UPPER = 103
#endif
} TimerID;

typedef enum TimerType_e
{
	TMR_TYPE_CONTINUOUS = 0,
	TMR_TYPE_ONESHOT = 1
} TimerType;

// Method responsible for configuring the specified timer to interrupt in a given period
StatusCode TMR_Init(TimerID tID, TimerType tType, float64 tPeriod);

// Method to start a given timer ID. Note timer must be initialized first
void TMR_Start(TimerID tID);

// Method to stop a given timer ID. Note timer must be initialized first
void TMR_Stop(TimerID tID);

// Method to reset/reload the timer
void TMR_Reset(TimerID tID);

#ifdef __cplusplus
}
#endif



#endif /*SIMPLETIMER_H_*/
