#include "asm.h"

extern int noloc;

char listfmt[] = "%05o  %04o  %s\n",
     listfmt_noloc[] = "       %04o  %s\n",
     listfmt_empty[] = "             %s\n";

void listo(int a,int w,int m){
	if(listpos){
		if(listfile) fprintf(listfile,listfmt,a,w,listline);
		newline();
	}else if(!noloc && listfile) 
		fprintf(listfile,listfmt_noloc,w,listline);
}
void printsym(struct sym_rec *p){
	extern int maxlen;
	if(listfile) fprintf(listfile,"%-*s %04o\n", maxlen,p->name,p->value);
}

void listempty(char *line){
	if(listfile) fprintf(listfile,listfmt_empty,line);
}
