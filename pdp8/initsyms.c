#include "asm.h"
#include "pdp8.h"

char target_arch[] = "DEC PDP-8";
int rbformat = 0;


extern char *iot[0100][3];

void cpu_initsyms(void){
	struct sym_rec *p;
	for(p=predefs;p->name;p++){
		/* setup disassembly table for IOT instruction */
		if((p->value & OPCODE)==OPCODE_IOT){
			int devsel = (p->value & DEVICE_SELECT) >> 3;
			if((p->value & 07) == 04)
				iot[devsel][0] = p->name;
			if((p->value & 07) == 02)
				iot[devsel][1] = p->name;
			if((p->value & 07) == 01)
				iot[devsel][2] = p->name;
		}
	}
}
