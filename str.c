#include "asm.h"

/* return pointer after last character of string */
char *endof(char *s){
	while(*s)
		++s;
	return s;
}
/* copy string; return pointer after last char copied */
char *scpy(char *dst,char *s){
	while(*dst = *s++)
		++dst;
	return dst;
}
char *sdup(char *s){
	char *p = malloc(strlen(s)+1);
	strcpy(p,s);
	return p;
}
char *uppercase(char *s){
	char *p;
	p = s;
	while(*p = toupper(*p))
		p++;
	return s;
}
		
int read_num(char *p,int radix) /* read a positive constant */
{
	int acc;
	for(acc=0;isdigit(*p);)
		acc = (acc*radix) + (*p++) - '0';
	return acc;
}
int read_signed(char *p,int radix){
	int sign = 1;
	if(*p == '+'){
		++p;
	}else if(*p == '-'){
		++p;
		sign = -1;
	}
	return sign*read_num(p,radix);
}
