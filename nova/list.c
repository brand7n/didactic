#include "asm.h"
#include "nova.h"

extern int relmode,noloc;

//efine LISTFORMAT "LL CCCCCRDDDDDDR....."
char listfmt[] = "%02d %05o%c%06o%c%s\n",
     listfmt_noloc[] = "%02d       %06o%c%s\n",
     listfmt_empty[] = "%02d              %s\n";

void listo(int a,int w,int m){
	if(listpos){
		if(listfile) fprintf(listfile,listfmt,lineno,a,rb_relflag_chars[relmode],
							 w,rb_relflag_chars[m],listline);
		newline();
	}else if(!noloc && listfile) 
		fprintf(listfile,listfmt_noloc,lineno,w,rb_relflag_chars[m],listline);
}
void printsym(struct sym_rec *p){
	extern int maxlen;
	if(listfile) fprintf(listfile,"%-*s %06o%c %s    %d/%02d\n",
		   maxlen,p->name,p->value & WORDMASK,rb_relflag_chars[p->relmode],
		   p->type == USER_SYMBOL ? "  " : rb_sym_typecodes[p->type],
		   p->pageno,p->lineno);
}

void listempty(char *line){
	if(listfile) fprintf(listfile,listfmt_empty,lineno,line);
}
