#include <stdio.h>
#include <stdlib.h>

#include "rb.h"

void dumpsym(FILE *f){
	RB_WORD w[3];
	char sym[6];

	if(rb_getwords(f,w,3)){
		//printf("symbol: %06o %06o %06o\n",w[0],w[1],w[2]);
		from_radix50(sym,w[0],w[1]);
		printf("  \"%s\" = %#o (%s)\n",sym,w[2],rb_sym_types[w[1] & 037]);
	}
}

void dumprb(FILE *f){
	RB_WORD w,header[RB_HEADER_WORDS];
	int c,i,j,rf;

	/* skip zero bytes at beginning of file */
	while( !(c = fgetc(f)) )
		;
	if(c != EOF){
		ungetc(c,f);
		rb_checksum = 0;
		while(rb_getwords(f,header,RB_HEADER_WORDS)){
			int t = header[RB_TYPE],
			    n = 0200000 - header[RB_WORDCOUNT];
			if(!t){
				/* block type 0 (must be time to stop) */
				break;
			}
			printf("=%02o= %s Block, %d words, checksum=%06o\n",
				t, t>=2 && t<=020 ? rb_block_types[t] : "unknown", n, header[RB_CHECKSUM] );

			switch(t){
			case TITL_BLK: dumpsym(f); break;

			case GADD_BLK:
			case GREF_BLK:
				printf("  address = %06o\n",rb_getword(f));
			case COMM_BLK: 
				dumpsym(f); 
				rf = getrelflag(header,0);
				printf("  relflag=%o (%s)\n  expression value = %#o\n",
					rf,rb_relflag_short[rf],rb_getword(f));
				break;

			case EXTD_BLK:
			case ENT_BLK:
			case GLOC_START_BLK:
			case EXTN_BLK:
			case LOCAL_SYM_BLK:
				for( i = 0 ; i < n/3 && !feof(f) ; ++i ){
					rf = getrelflag(header,i);
					printf("  [%2d] relflag=%o (%s)", i,rf,rb_relflag_short[rf]);
					dumpsym(f);
				}
				break;
			case GLOC_END_BLK:	
			case LIB_START_BLK:
			case LIB_END_BLK:
				/* empty block */ 
				break;
			case REL_DATA_BLK:
			case CSIZ_BLK:
			case START_BLK:
				for( i = 0 ; i < n && !feof(f) ; ++i ){
					rf = getrelflag(header,i);
					printf("  [%2d] relflag=%o (%s)", i,rf,rb_relflag_short[rf]);
					w = rb_getword(f);
					printf("  %c %06o\n", i ? ' ' : '@', w);
				}
				break;
			default:
				puts("### unknown block type!");
				for( i = 0 ; i < n && !feof(f) ; ++i )
					printf("  [%2d] %06o\n",i,rb_getword(f));
			}
			if(rb_checksum & RB_WORDMASK)
				printf("### checksum error! (=%06o)\n", rb_checksum & RB_WORDMASK);
			putchar('\n');
		}
	}
}

int main(int argc,char *argv[]){
	int i;
	FILE *f;

	for( i = 1 ; i < argc ; ++i )
		if(f = fopen(argv[i],"r")){
			printf("## RB file: \"%s\"\n",argv[i]);
			dumprb(f);
			fclose(f);
		}
	return EXIT_SUCCESS;
}

