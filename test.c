#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "asm.h"

enum{L=1000,M=10240,N=100};
char src[N+1];
clock_t start(){
	srand(123);
	return clock();
}
void stop(clock_t t1){
	printf("done:%g\n",(clock()-t1)/(double)CLOCKS_PER_SEC);
}
int rnd(int x){
	return rand() % x;
}
	char ss[] = "**********";
void test1(char *p,int max){
	int len = 0,l = strlen(ss);
	*p = 0;
	for(;len+l<max;){
		strcat(p,ss);
		len += l;
	}
}
void test2(char *p,int max){
	int len = 0,l = strlen(ss);
	*p = 0;
	for(;len+l<max;){
		p = cat(p,ss);
		len += l;
	}
}

#define X(a,b) a # b


main(){
	char *p = malloc(M);
	char *q;
	int i;
	clock_t t;

	X("1","2");

	for(i=N,q=src;i--;) *q++ = '*';

	t = start();
	for(i=L;i--;) test1(p,M);
	stop(t);

	t = start();
	for(i=L;i--;) test2(p,M);
	stop(t);

}
