
#include "drivers/kmcl2.h"
#include "drivers/adc7866.h"
#include "drivers/ringbuff.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"


ADC7866_RegsOvly adc_regs = (ADC7866_RegsOvly) KNX_IP_ADC7866;
ADC7866_LineLossRegOvly adc_lineloss = (ADC7866_LineLossRegOvly) KNX_IP_ADC7866_LINELOSS;
ADC7866_ScratchIDRegOvly adc_scratch_id = (ADC7866_ScratchIDRegOvly) KNX_IP_ADC7866_ID_SCRATCH;
volatile uint16 ADCRegPADC1AValues;


int adc7866_get_module_id(){
	uint16 moduleId=0;
	moduleId  = adc_scratch_id->MODULE_ID;
	return moduleId;
}

int initADC7866Default(){
	adc_regs->ADC7866_DELPADC = 0x3;
	adc_regs->PADCCNT = 0x2;
	adc_regs->PADC1A_SCALE = 16384;
	adc_regs->PADC1B_SCALE = 16384;
	adc_regs->PADC2A_SCALE = 16384;
	adc_regs->PADC2B_SCALE = 16384;
	return 1;
}

int SetADCCountsPerChannel(int countPerChannel){
	adc_regs->PADCCNT=countPerChannel;
	return adc_regs->PADCCNT=countPerChannel;
}

int SetADCDelay(int delayADC){
	adc_regs->ADC7866_DELPADC=delayADC;
		return adc_regs->ADC7866_DELPADC;
}

int adc7866_test_scratch(){
	int stat;
	uint16 test_dat = 0xbeef;
	adc_scratch_id->MODULE_SCRATCH = 0x1234;
	adc_scratch_id->MODULE_SCRATCH = test_dat;
	if(test_dat==adc_scratch_id->MODULE_SCRATCH){
		stat=1;
	}
	else{
		stat = 0;
	}
	return stat;
}

void adc7866_test_scratch_zero(){
	adc_scratch_id->MODULE_SCRATCH = 0x0000;
}

int adc7866_get_channel_1a(){
	return adc_regs->PADC1A_S.all;
}

int verifyADCScaleRegisters(){
	uint16 testValueReset = 0x0000;
	uint16 testValue2 = 0x1234;

	printf("Setting all PADC SCALE Registers to %X\n", testValueReset);
	adc_regs->PADC1A_SCALE = testValueReset;
	adc_regs->PADC2A_SCALE = testValueReset;
	adc_regs->PADC1B_SCALE = testValueReset;
	adc_regs->PADC2B_SCALE = testValueReset;

	printf("Testing PADC1A and PADC1B SCALE Registers \n");
	printf("\t Wrote 0x%X to PADC1A Register\n", testValue2 );
	adc_regs->PADC1A_SCALE = testValue2;
	printf("\t ------------------------------------------Results-------------------------------\n\t\t PADC1A_SCALE \t\t PADC1B_SCALE \n \t\t\t %X \t\t\t %X \n\n",adc_regs->PADC1A_SCALE, adc_regs->PADC1B_SCALE);
	if(((adc_regs->PADC1A_SCALE)!=testValue2)||((adc_regs->PADC1B_SCALE)!=0x0000)){
			printf("FAILED\n");
		}
	else{
		printf("Success\n");
	}

	//Reset all to zero
	printf("\nSetting all PADC SCALE Registers to 0x%X\n\n", testValueReset);
	adc_regs->PADC1A_SCALE = testValueReset;
	adc_regs->PADC2A_SCALE = testValueReset;
	adc_regs->PADC1B_SCALE = testValueReset;
	adc_regs->PADC2B_SCALE = testValueReset;

	printf("Testing PADC1A and PADC1B SCALE Registers\n");
	adc_regs->PADC1B_SCALE = testValue2;
	printf("\t Wrote 0x%X to PADC1B Register\n\n", testValue2 );
	printf("\t ------------------------------------------Results-------------------------------\n"
			"\t\t PADC1A_SCALE \t\t PADC1B_SCALE \n:"
			" \t\t\t %X \t\t\t %X \n\n",adc_regs->PADC1A_SCALE, adc_regs->PADC1B_SCALE);
	//check if PADC1B was not written correctly or if PADC1A got written
	if(((adc_regs->PADC1B_SCALE)!=testValue2)||((adc_regs->PADC1A_SCALE)!=0x0000)){
		printf("FAILED\n");
	}
	else{
			printf("Success\n");
		}


	//Reset all to zero
	printf("\nSetting all PADC SCALE Registers to 0x%X\n\n", testValueReset);
	adc_regs->PADC1A_SCALE = testValueReset;
	adc_regs->PADC2A_SCALE = testValueReset;
	adc_regs->PADC1B_SCALE = testValueReset;
	adc_regs->PADC2B_SCALE = testValueReset;

	printf("Testing PADC2A and PADC2B SCALE Registers \n");
	printf("\t Wrote 0x%X to PADC2A Register\n", testValue2 );
	adc_regs->PADC2A_SCALE = testValue2;
	printf("\t ------------------------------------------Results-------------------------------\n\t\t PADC2A_SCALE \t\t PADC2B_SCALE \n \t\t\t %X \t\t\t %X \n\n",adc_regs->PADC2A_SCALE, adc_regs->PADC2B_SCALE);
	if(((adc_regs->PADC2A_SCALE)!=testValue2)||((adc_regs->PADC2B_SCALE)!=0x0000)){
			printf("FAILED\n");
		}
		else{
				printf("Success\n");
			}

	//Reset all to zero
	printf("\nSetting all PADC SCALE Registers to 0x%X\n\n", testValueReset);
	adc_regs->PADC1A_SCALE = testValueReset;
	adc_regs->PADC2A_SCALE = testValueReset;
	adc_regs->PADC1B_SCALE = testValueReset;
	adc_regs->PADC2B_SCALE = testValueReset;


	printf("Testing PADC2A and PADC2B SCALE Registers\n");
	adc_regs->PADC2B_SCALE = testValue2;
	printf("\t Wrote 0x%X to PADC2B Register\n\n", testValue2 );
	printf("\t ------------------------------------------Results-------------------------------\n\t\t PADC2A_SCALE \t\t PADC2B_SCALE \n \t\t\t %X \t\t\t %X \n\n",adc_regs->PADC2A_SCALE, adc_regs->PADC2B_SCALE);
	if(((adc_regs->PADC2B_SCALE)!=testValue2)||((adc_regs->PADC2A_SCALE)!=0x0000)){
			printf("!!!FAILED!!!\n");
		}
		else{
				printf("Success\n");
			}

	//Reset all to zero
	printf("\nSetting all PADC SCALE Registers to 0x%X\n\n", testValueReset);
	adc_regs->PADC1A_SCALE = testValueReset;
	adc_regs->PADC2A_SCALE = testValueReset;
	adc_regs->PADC1B_SCALE = testValueReset;
	adc_regs->PADC2B_SCALE = testValueReset;


	return 1;
}

int captureADCValuesToBuff(int countOfSamples){
	ringBufS adcBuff1A,adcBuff1B,adcBuff2A,adcBuff2B;

	int count;
	ringBufS_init(&adcBuff1A);
	ringBufS_init(&adcBuff1B);
	ringBufS_init(&adcBuff2A);
	ringBufS_init(&adcBuff2B);

	for(count = 0;count<countOfSamples;count++){
		ringBufS_put(&adcBuff1A, adc_regs->PADC1A_S.bits.ADCVALUE);
		ringBufS_put(&adcBuff1B, adc_regs->PADC1B_S.bits.ADCVALUE);
		ringBufS_put(&adcBuff2A, adc_regs->PADC2A_S.bits.ADCVALUE);
		ringBufS_put(&adcBuff2B, adc_regs->PADC2B_S.bits.ADCVALUE);
	}
	printf("Reading 12bit Values \n%-10 |%-10s|%-10s|%-10s|%-10s	\n", "PADC1A","PADC1B","PADC2A","PADC2B");

	for(count = 0;count<countOfSamples;count++){
		ADCRegPADC1AValues =ringBufS_get(&adcBuff1A);
		printf("%-10 |%-10X|%-10X|%-10X|%-10X\n",ADCRegPADC1AValues,ringBufS_get(&adcBuff1B),ringBufS_get(&adcBuff2A),ringBufS_get(&adcBuff2B));
	}

	ringBufS_empty(&adcBuff1A);
	ringBufS_empty(&adcBuff2A);
	ringBufS_empty(&adcBuff1B);
	ringBufS_empty(&adcBuff2B);

	return 1;
}

