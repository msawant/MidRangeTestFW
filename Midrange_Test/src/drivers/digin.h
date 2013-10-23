#ifndef DIGIN_H_
#define DIGIN_H_
#include <DataTypes.h>

#define FCLK (0x64280000)

typedef struct{
	volatile uint16 DIGIN;
	volatile uint16 DIGIN_FILT00;
	volatile uint16 DIGIN_FILT01;
	volatile uint16 DIGIN_FILT02;
	volatile uint16 DIGIN_FILT03;
	volatile uint16 DIGIN_FILT04;
	volatile uint16 DIGIN_FILT05;
	volatile uint16 DIGIN_FILT06;
	volatile uint16 DIGIN_FILT07;
	volatile uint16 DIGIN_ID;
	volatile uint16 DIGIN_SCRATCHPAD;
}DIGIN_controlRegs;


/**************************************************************************\
* Overlay structure typedef definition
\**************************************************************************/
typedef volatile DIGIN_controlRegs             *DIGIN_controlRegsOvly;

#ifdef __cplusplus
extern "C" {
#endif

int digin_get_module_id();
void set_debounce(uint16);

#ifdef __cplusplus
}
#endif
#endif /*DIGIN_H_*/
