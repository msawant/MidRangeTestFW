#include "drivers/kmcl2.h"
#include "drivers/digin.h"


DIGIN_controlRegsOvly digin_control = (DIGIN_controlRegsOvly) KNX_IP_DIG_INPUTS;

int digin_get_module_id(){
	volatile uint16 moduleId=0;
	moduleId  = digin_control->DIGIN_ID;
	return moduleId;
}
