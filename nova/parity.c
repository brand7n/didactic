#include <stdio.h>
#include <stdlib.h>

/* method due to http://remus.rutgers.edu/~rhoads/Code/bitcount2.c */
int bit_count(long x)
{
        int n = 0;

        if (x)
            do {
               n++;
            } while ((x &= x-1));

        return(n);
}
void dotable(char *name,int omask,int emask){
	int i;
	printf("unsigned char %s[0200] = {",name);
	for(i=0;i<0200;++i){
		if(!(i % 8)){
			putchar('\n');
			putchar('\t');
		}
		printf("%04o",bit_count(i) & 1 ? i|omask : i|emask);
		putchar(',');
	}
	printf("\n};\n");
}

int main(){
	dotable("eparity",0200,0);
	dotable("oparity",0,0200);
	return EXIT_SUCCESS;
}
