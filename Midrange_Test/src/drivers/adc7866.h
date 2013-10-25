#ifndef ADC7866_H_
#define ADC7866_H_

#ifndef NULL
#define NULL 0
#endif


#include <DataTypes.h>

#define KNX_IP_ADC7866_LINELOSS		(KNX_IP_ADC7866 + 0x0024)
#define KNX_IP_ADC7866_ID_SCRATCH	(KNX_IP_ADC7866 + 0x0030)



typedef struct ADCRingBuffer{
    void *buffer;     // data buffer
    void *buffer_end; // end of data buffer
    int capacity;  // maximum number of items in the buffer
    int count;     // number of items in the buffer
    int sz;        // size of each item in the buffer
    void *head;       // pointer to head
    void *tail;       // pointer to tail
} ADCRingBuffer;

typedef struct PADCREG_BITS{
	volatile uint16 ADCVALUE:12;		//12 Bit ADC Value 			[11:0]
	uint16 ADC:1;			//1 Bit ADC Description 	[12:12]
	uint16 CHANNEL:1;		//1Bit Channel Description	[13:13]
	uint16 RANGE:1;			//0 indicates previous
							//conversion was for range 0 to Vref.
							//If 1 indicates conversion range was 0 to 2*Vref [14:14]

	uint16 rsvd:1;			//Always Zero
}PADCREG_BITS;

union PADCREG{
	volatile uint16 	all;
	struct PADCREG_BITS bits;
};

typedef struct{
	volatile uint16 ADC7866_DELPADC;
	volatile uint16 PADCCNT;
	volatile uint16 PADC1A_OFF;
	volatile uint16 PADC1B_OFF;
	volatile uint16 PADC2A_OFF;
	volatile uint16 PADC2B_OFF;
	volatile uint16 PADC1A_SCALE;
	volatile uint16 PADC1B_SCALE;
	volatile uint16 PADC2A_SCALE;
	volatile uint16 PADC2B_SCALE;
	volatile uint16 PADC1A_S;
	volatile uint16 PADC1B_S;
	volatile uint16 PADC2A_S;
	volatile uint16 PADC2B_S;
}ADC7866_Regs;

typedef struct{
	volatile uint16 ADC7866_DELPADC;
	volatile uint16 PADCCNT;
	volatile uint16 PADC1A_OFF;
	volatile uint16 PADC1B_OFF;
	volatile uint16 PADC2A_OFF;
	volatile uint16 PADC2B_OFF;
	volatile uint16 PADC1A_SCALE;
	volatile uint16 PADC1B_SCALE;
	volatile uint16 PADC2A_SCALE;
	volatile uint16 PADC2B_SCALE;
	union PADCREG PADC1A_S;
	union PADCREG PADC1B_S;
	union PADCREG PADC2A_S;
	union PADCREG PADC2B_S;
}ADC7866_Regs_Test;


typedef struct{
	volatile uint16 CH1ALPHA;
	volatile uint16 CH2ALPHA;
	volatile uint16 CH1LOSSLO;
	volatile uint16 CH1LOSSHI;
	volatile uint16 CH2LOSSLO;
	volatile uint16 CH2LOSSHI;
}ADC7866_LineLossReg;

typedef struct{
	volatile uint16 MODULE_ID;
	volatile uint16 MODULE_SCRATCH;
}ADC7866_Scratch_ID;




/**************************************************************************\
* Overlay structure typedef definition
\**************************************************************************/
typedef volatile ADC7866_Regs             *ADC7866_RegsOvly;
typedef volatile ADC7866_LineLossReg      *ADC7866_LineLossRegOvly;
typedef volatile ADC7866_Scratch_ID      *ADC7866_ScratchIDRegOvly;
typedef volatile ADC7866_Regs_Test      *ADC7866_RegsOvly_Test;

#ifdef __cplusplus
extern "C" {
#endif

int adc7866_get_module_id();
int adc7866_test_scratch();
void adc7866_test_scratch_zero();
int adc7866_get_channel_a();
int adc7866_get_channel_b();
int SetADCCountsPerChannel(int);
int SetADCDelay(int );
void popFrontOfADCBuffer();
void pushToBackADCBuffer();
void freeADCBuffer();
void initADCBuffer();
int initADC7866Default();
int bufferADCValues(int);
int adcRingBuff(int);
int verifyADCScaleRegisters();

#ifdef __cplusplus
}
#endif


#endif /*ADC7866_H_*/
