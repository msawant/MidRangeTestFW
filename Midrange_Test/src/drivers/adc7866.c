#
#include "drivers/kmcl2.h"
#include "drivers/adc7866.h"

#define ADCBufferLength 256


ADC7866_RegsOvly adc_regs = (ADC7866_RegsOvly) KNX_IP_ADC7866;
ADC7866_LineLossRegOvly adc_lineloss = (ADC7866_LineLossRegOvly) KNX_IP_ADC7866_LINELOSS;
ADC7866_ScratchIDRegOvly adc_scratch_id = (ADC7866_ScratchIDRegOvly) KNX_IP_ADC7866_ID_SCRATCH;



// memcpy

void * memcpyNew (void * dst, volatile void * src, size_t count)
{
        void * ret = dst;

        while (count--) {
                *(char *)dst = *(char *)src;
                dst = (char *)dst + 1;
                src = (char *)src + 1;
        }

        return(ret);
}

//ADC Buffer Implementation

void initADCBuffer(ADCRingBuffer *cb, int capacity, int sz)
{
    cb->buffer = (int *) malloc(capacity * sz);
    if(cb->buffer == NULL){
    	printf("Not enough memory Dude! \n");
    }
    cb->buffer_end = (char *)cb->buffer + capacity * sz;
    cb->capacity = capacity;
    cb->count = 0;
    cb->sz = sz;
    cb->head = cb->buffer;
    cb->tail = cb->buffer;
}

void freeADCBuffer(ADCRingBuffer *cb)
{
    if(cb) {
        free(cb->buffer);
        free(cb);
    }
    // clear out other fields too, just to be safe
}

void pushToBackADCBuffer(ADCRingBuffer *cb, const void *item)
{
    if(cb->count == cb->capacity){
    	printf("Reached Capacity");
    }
        // handle error
    memcpy(cb->head, item, cb->sz);
//    printf("%X has value %X\n",cb->head, *(volatile int*)(cb->head)); 	//For Debug
    cb->head = (char*)cb->head + cb->sz;
    if(cb->head == cb->buffer_end)
        cb->head = cb->buffer;
    cb->count++;
}

void popFrontOfADCBuffer(ADCRingBuffer *cb, void *item)
{
    if(cb->count == 0){
    	printf("Count is set to zero");
    }
//    printf("%X has value %X\n",cb->tail, *(volatile int*)(cb->tail)); 	//For Debug
    memcpy(item, cb->tail, cb->sz);
    cb->tail = (char*)cb->tail + cb->sz;
    if(cb->tail == cb->buffer_end)
        cb->tail = cb->buffer;
    cb->count--;
}

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
	return adc_regs->PADC1A_S;
}

int bufferADCValues(int countOfSamples){
	//ADCRingBuffer *adcBuffer = (ADCRingBuffer *) malloc(sizeof(ADCRingBuffer));
	ADCRingBuffer adcBufferChannel1A;
	ADCRingBuffer adcBufferChannel2A;
	ADCRingBuffer adcBufferChannel1B;
	ADCRingBuffer adcBufferChannel2B;
	int count = 0;

	//Channel Data
	int *pChannel1AData=(int*)malloc(sizeof(int));
	int *pChannel2AData=(int*)malloc(sizeof(int));
	int *pChannel1BData=(int*)malloc(sizeof(int));
	int *pChannel2BData=(int*)malloc(sizeof(int));

	int volatile * const ptemp1A = (int*)adc_regs->PADC1A_S;
	int volatile * const ptemp2A = (int*)malloc(sizeof(int));
	int volatile * const ptemp1B = (int*)malloc(sizeof(int));
	int volatile * const ptemp2B = (int*)malloc(sizeof(int));

	*ptemp2A = adc_regs->PADC2A_S;
	*ptemp1B = adc_regs->PADC1B_S;
	*ptemp2B = adc_regs->PADC2B_S;

	initADC7866Default();

	//initialize all adcBuffers
	initADCBuffer(&adcBufferChannel1A, ADCBufferLength, sizeof(int));
	initADCBuffer(&adcBufferChannel2A, ADCBufferLength, sizeof(int));
	initADCBuffer(&adcBufferChannel1B, ADCBufferLength, sizeof(int));
	initADCBuffer(&adcBufferChannel2B, ADCBufferLength, sizeof(int));

	for(count = 0;count<countOfSamples;count++){

//		pushToBackADCBuffer(&adcBufferChannel1A,ptemp1A);
//		pushToBackADCBuffer(&adcBufferChannel2A,ptemp2A);
//		pushToBackADCBuffer(&adcBufferChannel1B,ptemp1B);
//		pushToBackADCBuffer(&adcBufferChannel2B,ptemp2B);
		printf("\t \t \t \t %X",*ptemp1A);
		printf("\t \t \t \t %X",adc_regs->PADC1A_S);
		printf("From Register \t \t PADC1A= %X \n",*ptemp1A);
		printf("From Register \t \t PADC2B %X \n",*ptemp2B);
	}

	//Gather all channel Data from buffer
	for(count = 0;count<countOfSamples;count++){
//			popFrontOfADCBuffer(&adcBufferChannel1A,pChannel1AData);
//			popFrontOfADCBuffer(&adcBufferChannel2A,pChannel2AData);
//			popFrontOfADCBuffer(&adcBufferChannel1B,pChannel1BData);
//			popFrontOfADCBuffer(&adcBufferChannel2B,pChannel2BData);
			printf("From Buffer PADC1A= %X \n",*pChannel1AData);
			printf("From Buffer PADC2B= %X \n",*pChannel2BData);
		}

	freeADCBuffer(&adcBufferChannel1A);
	freeADCBuffer(&adcBufferChannel2A);
	freeADCBuffer(&adcBufferChannel1B);
	freeADCBuffer(&adcBufferChannel2B);
	return 1;
}
