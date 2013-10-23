/*
 * kmcl2_config.c
 *
 *  Created on: Oct 11, 2013
 *      Author: miglab
 */


#include "drivers/kmcl2.h"
#include "drivers/kmcl2_config.h"

KMCL2_Config_RegsOvly kmcl2_config = (KMCL2_Config_RegsOvly) KMCL2_IP_CONFIG;

int kmcl2_config_get_rev_id(){
	uint16 revId=0;
	revId  = kmcl2_config->KMCL2_REV;
	return revId;
}
