
/*  A Bison parser, made from nova/parser.y
    by GNU Bison version 1.28  */

#define YYBISON 1  /* Identify Bison output.  */

#define	TOK_LE	257
#define	TOK_GE	258
#define	TOK_EQ	259
#define	TOK_NE	260
#define	TOK_SEP	261
#define	TOK_SKIP	262
#define	TOK_NOAC	263
#define	TOK_ONEAC	264
#define	TOK_TWOAC	265
#define	TOK_IO	266
#define	TOK_TRAP	267
#define	TOK_SYM	268
#define	TOK_DALC	269
#define	TOK_DIAC	270
#define	TOK_DIO	271
#define	TOK_DIOA	272
#define	TOK_DISD	273
#define	TOK_DISS	274
#define	TOK_DMR	275
#define	TOK_DMRA	276
#define	TOK_DUSR	277
#define	TOK_XPNG	278
#define	TOK_BLK	279
#define	TOK_NREL	280
#define	TOK_ZREL	281
#define	TOK_COMM	282
#define	TOK_CSIZ	283
#define	TOK_ENT	284
#define	TOK_ENTO	285
#define	TOK_EXTD	286
#define	TOK_EXTN	287
#define	TOK_EXTU	288
#define	TOK_GADD	289
#define	TOK_GLOC	290
#define	TOK_GREF	291
#define	TOK_ENDC	292
#define	TOK_IFE	293
#define	TOK_IFG	294
#define	TOK_IFL	295
#define	TOK_IFN	296
#define	TOK_TXT	297
#define	TOK_TXTE	298
#define	TOK_TXTF	299
#define	TOK_TXTM	300
#define	TOK_TXTN	301
#define	TOK_TXTO	302
#define	TOK_EJEC	303
#define	TOK_NOCON	304
#define	TOK_NOLOC	305
#define	TOK_NOMAC	306
#define	TOK_REV	307
#define	TOK_RDX	308
#define	TOK_RDXO	309
#define	TOK_TITL	310
#define	TOK_RB	311
#define	TOK_LMIT	312
#define	TOK_PASS	313
#define	TOK_EOF	314
#define	TOK_EOT	315
#define	TOK_END	316
#define	TOK_LOC	317
#define	TOK_NUM	318
#define	TOK_DOT	319
#define	TOK_NUMD	320
#define	TOK_FPS	321
#define	TOK_STRING	322

#line 1 "nova/parser.y"
 
/*  
    This file is part of The Didactic PDP-8 Assembler
    Copyright (C) 2002 Toby Thain, toby@telegraphics.com.au

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by  
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License  
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "asm.h"
#include "nova.h"

extern int endflag,curloc,nrel_loc,zrel_loc;
int radix,saveradix,saveinexpr,indexseen,seenterm,relmode = NORMAL_REL,
    condtop = 0,cond = 1,condstack[MAXCONDDEPTH],txtm=0,txtn=0;
struct sym_rec *symlist[MAXSYMLIST];
int nsyms = 0;

void dalc(struct sym_rec *symbol,int v){
	char *sym = symbol->name,*p;
	/* look for trailing flag characters */
	if( strlen(sym) > 3 && (p = strpbrk(sym+3,"ZOCLRS")) == sym ){
		DPUTS(".DALC: stripping flag characters from mnemonic");
		*p = 0; // strip flags. FIXME: there might be non-flag characters in the trailing part!!
		twoac(sym,v);
	}else
		doassign(symbol,v,TOK_TWOAC,ABSOLUTE); 
}

void dio(struct sym_rec *s,int v){
	extern char *class_f[];
	char *sym = s->name,*p;
	
	/* look for a three character mnemonic immediately followed by flags */
	if( strlen(sym) > 3 && (p = strpbrk(sym+3,"SCP")) == sym ){
		DPUTS(".DIO: stripping flag characters from mnemonic");
		*p = 0; // strip flags. FIXME: there might be non-flag characters in the trailing part!!
		iodata(sym,v,class_f);
	}else
		doassign(s,v,TOK_IO,ABSOLUTE); 
}

void badreloc(char *op){
	char s[100];
	if(cond && pass==2){
		sprintf(s,"bad relocation mode: %s",op);
		fatal(s);
	}
}

void popcond(){
	if(condtop) 
		cond = condstack[--condtop];
	else 
		fatal("ENDC without IF");
}

void pushcond(int c){
	if(condtop == MAXCONDDEPTH)
		fatal("too many nested IFs!");
	else{
		condstack[condtop++] = cond;
		cond = cond && c;
	}
}


#line 81 "nova/parser.y"
typedef union{
	struct operand value;
	unsigned long valuel;
	struct sym_rec *symbol;
	char *string;
} YYSTYPE;
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		216
#define	YYFLAG		-32768
#define	YYNTBASE	85

#define YYTRANSLATE(x) ((unsigned)(x) <= 322 ? yytranslate[x] : 131)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    75,     2,    81,     2,     2,    76,     2,    83,
    84,    73,    72,    82,    71,     2,    74,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    79,     2,    69,
    78,    70,     2,    80,     2,    77,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
    47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
    57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
    67,    68
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     1,     5,     8,    12,    14,    16,    18,    20,    23,
    25,    28,    29,    31,    34,    36,    38,    40,    42,    43,
    45,    46,    48,    49,    52,    53,    56,    58,    60,    61,
    66,    69,    71,    73,    75,    76,    81,    82,    87,    88,
    93,    94,    99,   100,   105,   106,   111,   112,   117,   118,
   123,   124,   129,   130,   135,   136,   141,   142,   147,   148,
   153,   155,   159,   162,   167,   174,   175,   177,   181,   184,
   191,   193,   195,   197,   199,   201,   203,   204,   206,   208,
   212,   214,   216,   218,   220,   225,   230,   235,   240,   245,
   250,   255,   260,   265,   267,   270,   272,   274,   277,   282,
   285,   286,   290,   293,   294,   298,   299,   303,   308,   313,
   315,   318,   321,   324,   327,   330,   333,   336,   337,   341,
   344,   347,   349
};

static const short yyrhs[] = {    -1,
    85,    91,     7,     0,     1,     7,     0,    14,    78,    87,
     0,    86,     0,   122,     0,   122,     0,   126,     0,    14,
    79,     0,    89,     0,    90,    89,     0,     0,    90,     0,
    90,    88,     0,    88,     0,    66,     0,    86,     0,   114,
     0,     0,    80,     0,     0,    81,     0,     0,    82,     8,
     0,     0,    82,   114,     0,    64,     0,    65,     0,     0,
    83,    98,   100,    84,     0,    71,    99,     0,    97,     0,
    14,     0,    99,     0,     0,    97,    77,   101,    99,     0,
     0,   100,    72,   102,   100,     0,     0,   100,    71,   103,
   100,     0,     0,   100,    73,   104,   100,     0,     0,   100,
    74,   105,   100,     0,     0,   100,    76,   106,   100,     0,
     0,   100,    75,   107,   100,     0,     0,   100,     5,   108,
   100,     0,     0,   100,     4,   109,   100,     0,     0,   100,
    70,   110,   100,     0,     0,   100,    69,   111,   100,     0,
     0,   100,     3,   112,   100,     0,     0,   100,     6,   113,
   100,     0,   100,     0,    93,   114,    96,     0,     9,   115,
     0,    10,    92,    82,   115,     0,    11,    94,    92,    82,
    92,    95,     0,     0,   114,     0,    92,    82,   114,     0,
    12,   119,     0,    13,    92,    82,    92,    82,   114,     0,
   114,     0,   116,     0,   117,     0,   118,     0,   120,     0,
   121,     0,     0,   114,     0,    14,     0,   124,    82,    14,
     0,    43,     0,    44,     0,    45,     0,    48,     0,    15,
    14,    78,   122,     0,    16,    14,    78,   122,     0,    17,
    14,    78,   122,     0,    18,    14,    78,   122,     0,    19,
    14,    78,   122,     0,    20,    14,    78,   122,     0,    21,
    14,    78,   122,     0,    22,    14,    78,   122,     0,    23,
    14,    78,   122,     0,    24,     0,    25,   114,     0,    26,
     0,    27,     0,    63,   114,     0,    28,    14,    82,   114,
     0,    29,   114,     0,     0,    30,   127,   124,     0,    31,
    14,     0,     0,    32,   128,   124,     0,     0,    33,   129,
   124,     0,    35,    14,    82,   114,     0,    37,    14,    82,
   114,     0,    38,     0,    39,   114,     0,    40,   114,     0,
    41,   114,     0,    42,   114,     0,   125,    68,     0,    46,
   114,     0,    47,   114,     0,     0,    54,   130,   114,     0,
    56,    14,     0,    62,   123,     0,    60,     0,    61,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   118,   119,   120,   124,   128,   128,   130,   131,   134,   144,
   144,   147,   148,   149,   150,   151,   152,   155,   158,   159,
   161,   162,   164,   165,   167,   168,   174,   175,   177,   177,
   178,   184,   185,   223,   224,   224,   234,   234,   248,   248,
   257,   257,   278,   278,   284,   284,   290,   290,   296,   296,
   300,   300,   304,   304,   308,   308,   312,   312,   316,   316,
   321,   324,   328,   332,   336,   343,   344,   345,   347,   351,
   357,   357,   357,   357,   357,   357,   359,   360,   363,   364,
   367,   367,   367,   367,   369,   373,   376,   379,   382,   385,
   388,   391,   394,   397,   399,   409,   412,   415,   419,   422,
   425,   425,   428,   432,   432,   435,   435,   439,   442,   447,
   448,   449,   450,   451,   453,   454,   455,   458,   460,   467,
   471,   472,   473
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","TOK_LE",
"TOK_GE","TOK_EQ","TOK_NE","TOK_SEP","TOK_SKIP","TOK_NOAC","TOK_ONEAC","TOK_TWOAC",
"TOK_IO","TOK_TRAP","TOK_SYM","TOK_DALC","TOK_DIAC","TOK_DIO","TOK_DIOA","TOK_DISD",
"TOK_DISS","TOK_DMR","TOK_DMRA","TOK_DUSR","TOK_XPNG","TOK_BLK","TOK_NREL","TOK_ZREL",
"TOK_COMM","TOK_CSIZ","TOK_ENT","TOK_ENTO","TOK_EXTD","TOK_EXTN","TOK_EXTU",
"TOK_GADD","TOK_GLOC","TOK_GREF","TOK_ENDC","TOK_IFE","TOK_IFG","TOK_IFL","TOK_IFN",
"TOK_TXT","TOK_TXTE","TOK_TXTF","TOK_TXTM","TOK_TXTN","TOK_TXTO","TOK_EJEC",
"TOK_NOCON","TOK_NOLOC","TOK_NOMAC","TOK_REV","TOK_RDX","TOK_RDXO","TOK_TITL",
"TOK_RB","TOK_LMIT","TOK_PASS","TOK_EOF","TOK_EOT","TOK_END","TOK_LOC","TOK_NUM",
"TOK_DOT","TOK_NUMD","TOK_FPS","TOK_STRING","'<'","'>'","'-'","'+'","'*'","'/'",
"'!'","'&'","'B'","'='","':'","'@'","'#'","','","'('","')'","program","assign",
"assignval","asminstr","label","labels","stmt","ac","optind","opthash","optskip",
"optindex","termnotsym","@1","term","subexpr","@2","@3","@4","@5","@6","@7",
"@8","@9","@10","@11","@12","@13","@14","expr","ea","noac","oneac","twoac","iooperand",
"io","trap","instr","optexpr","symlist","textop","pseudoop","@15","@16","@17",
"@18", NULL
};
#endif

static const short yyr1[] = {     0,
    85,    85,    85,    86,    87,    87,    88,    88,    89,    90,
    90,    91,    91,    91,    91,    91,    91,    92,    93,    93,
    94,    94,    95,    95,    96,    96,    97,    97,    98,    97,
    97,    99,    99,   100,   101,   100,   102,   100,   103,   100,
   104,   100,   105,   100,   106,   100,   107,   100,   108,   100,
   109,   100,   110,   100,   111,   100,   112,   100,   113,   100,
   114,   115,   116,   117,   118,   119,   119,   119,   120,   121,
   122,   122,   122,   122,   122,   122,   123,   123,   124,   124,
   125,   125,   125,   125,   126,   126,   126,   126,   126,   126,
   126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
   127,   126,   126,   128,   126,   129,   126,   126,   126,   126,
   126,   126,   126,   126,   126,   126,   126,   130,   126,   126,
   126,   126,   126
};

static const short yyr2[] = {     0,
     0,     3,     2,     3,     1,     1,     1,     1,     2,     1,
     2,     0,     1,     2,     1,     1,     1,     1,     0,     1,
     0,     1,     0,     2,     0,     2,     1,     1,     0,     4,
     2,     1,     1,     1,     0,     4,     0,     4,     0,     4,
     0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
     0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
     1,     3,     2,     4,     6,     0,     1,     3,     2,     6,
     1,     1,     1,     1,     1,     1,     0,     1,     1,     3,
     1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
     4,     4,     4,     1,     2,     1,     1,     2,     4,     2,
     0,     3,     2,     0,     3,     0,     3,     4,     4,     1,
     2,     2,     2,     2,     2,     2,     2,     0,     3,     2,
     2,     1,     1
};

static const short yydefact[] = {     0,
     0,    12,     3,    19,     0,    21,    66,     0,    33,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    94,     0,
    96,    97,     0,     0,   101,     0,   104,   106,     0,     0,
   110,     0,     0,     0,     0,    81,    82,    83,     0,     0,
    84,   118,     0,   122,   123,    77,     0,    27,    28,    16,
     0,    29,    17,    15,    10,    13,     0,    32,    34,    61,
    71,    72,    73,    74,    75,    76,     7,     0,     8,    20,
     0,    63,    33,     0,    18,    22,     0,     0,    18,    69,
     0,     0,     9,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    95,     0,   100,     0,   103,     0,     0,     0,
     0,   111,   112,   113,   114,   116,   117,     0,   120,    78,
   121,    98,    32,    31,     0,    33,    14,    11,     2,    35,
    57,    51,    49,    59,    55,    53,    39,    37,    41,    43,
    47,    45,   115,    25,    19,     0,     0,     0,    33,     5,
     4,     6,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    79,   102,   105,   107,     0,     0,   119,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,    62,    64,     0,    68,     0,    85,
    86,    87,    88,    89,    90,    91,    92,    93,    99,     0,
   108,   109,    30,    36,    58,    52,    50,    60,    56,    54,
    40,    38,    42,    44,    48,    46,    26,    23,     0,    80,
     0,    65,    70,    24,     0,     0
};

static const short yydefgoto[] = {     2,
    53,   141,    54,    55,    56,    57,    74,    71,    77,   212,
   175,    58,   115,    59,    60,   161,   169,   168,   170,   171,
   173,   172,   164,   163,   167,   166,   162,   165,    61,    72,
    62,    63,    64,    80,    65,    66,    67,   111,   154,    68,
    69,    96,    98,    99,   108
};

static const short yypact[] = {   170,
    11,   245,-32768,   -67,     0,   -55,     0,     0,   -71,    17,
    18,    19,    22,    23,    24,    25,    26,    35,-32768,     0,
-32768,-32768,    36,     0,-32768,    43,-32768,-32768,    44,    45,
-32768,     0,     0,     0,     0,-32768,-32768,-32768,     0,     0,
-32768,-32768,    46,-32768,-32768,     0,     0,-32768,-32768,-32768,
     0,-32768,-32768,-32768,-32768,   320,    54,   -15,-32768,    88,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,    -1,-32768,-32768,
     0,-32768,-32768,   -19,-32768,-32768,     0,   -14,    62,-32768,
   -12,    34,-32768,     7,     8,     9,    10,    30,    31,    32,
    37,    40,-32768,    -9,-32768,    70,-32768,    70,    70,    13,
    14,-32768,-32768,-32768,-32768,-32768,-32768,     0,-32768,-32768,
-32768,-32768,-32768,-32768,     0,    21,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,    15,   -67,    20,     0,     0,    41,-32768,
-32768,-32768,    42,    42,    42,    42,    42,    42,    42,    42,
    42,     0,-32768,    38,    38,    38,     0,     0,-32768,     6,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,-32768,-32768,     0,-32768,    39,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,    75,
-32768,-32768,-32768,-32768,   -51,   -51,   -51,   -51,   -51,   -51,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,    47,     0,-32768,
    93,-32768,-32768,-32768,   104,-32768
};

static const short yypgoto[] = {-32768,
    48,-32768,    56,    58,-32768,-32768,    -3,-32768,-32768,-32768,
-32768,   -50,-32768,   -45,   262,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,    -5,   -13,
-32768,-32768,-32768,-32768,-32768,-32768,   272,-32768,   -82,-32768,
-32768,-32768,-32768,-32768,-32768
};


#define	YYLAST		435


static const short yytable[] = {    75,
   113,    79,    75,    78,    81,   114,    82,    83,   121,   122,
   123,   124,    70,    73,    93,   155,   156,     3,    95,   127,
   128,   129,   130,   131,   132,    76,   102,   103,   104,   105,
    84,    85,    86,   106,   107,    87,    88,    89,    90,    91,
   110,   112,     4,     5,     6,     7,     8,   139,    92,    94,
     4,     5,     6,     7,     8,    73,    97,   100,   101,   109,
   119,   120,   135,    48,    49,   134,   133,   137,   -67,   138,
    51,    75,   152,   136,   125,   126,   127,   128,   129,   130,
   131,   132,    52,   153,   143,   144,   145,   146,   210,   193,
   121,   122,   123,   124,   157,   158,   174,    48,    49,    83,
   214,   177,   159,   216,    51,    48,    49,   147,   148,   149,
   113,   117,    51,   118,   150,   194,    52,   151,    82,   190,
   209,   176,     0,     0,    52,     0,     0,     0,   211,   140,
     0,   178,    75,     0,   179,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,   189,     0,     0,     0,
     0,   191,   192,     0,     0,     0,   125,   126,   127,   128,
   129,   130,   131,   132,     0,     0,     0,     0,   207,    -1,
     1,    75,     0,   208,     0,     0,    -1,     0,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   213,    -1,     0,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,     0,
     0,     0,     0,    -1,     0,    -1,     0,     0,     0,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,     0,     0,     0,     0,
    -1,     0,     0,     0,   215,     0,     0,     0,     0,     0,
     0,     0,    -1,     4,     5,     6,     7,     8,     9,    10,
    11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
    21,    22,    23,    24,    25,    26,    27,    28,     0,    29,
     0,    30,    31,    32,    33,    34,    35,    36,    37,    38,
    39,    40,    41,     0,     0,     0,     0,     0,    42,     0,
    43,     0,     0,     0,    44,    45,    46,    47,    48,    49,
    50,     0,     0,     0,     0,    51,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    52,     4,     5,
     6,     7,     8,   116,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,   142,    29,     0,    30,    31,    32,    33,
    34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
     0,     0,     0,    42,     0,    43,   160,     0,     0,    44,
    45,    46,    47,    48,    49,     0,     0,     0,     0,     0,
    51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    52,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,   180,   181,   182,   183,   184,   185,
   186,   187,   188,   195,   196,   197,   198,   199,   200,   201,
   202,   203,   204,   205,   206
};

static const short yycheck[] = {     5,
    51,     7,     8,     7,     8,    51,    78,    79,     3,     4,
     5,     6,    80,    14,    20,    98,    99,     7,    24,    71,
    72,    73,    74,    75,    76,    81,    32,    33,    34,    35,
    14,    14,    14,    39,    40,    14,    14,    14,    14,    14,
    46,    47,     9,    10,    11,    12,    13,    14,    14,    14,
     9,    10,    11,    12,    13,    14,    14,    14,    14,    14,
     7,    77,    82,    64,    65,    71,    68,    82,     7,    82,
    71,    77,    82,    77,    69,    70,    71,    72,    73,    74,
    75,    76,    83,    14,    78,    78,    78,    78,    14,    84,
     3,     4,     5,     6,    82,    82,    82,    64,    65,    79,
     8,    82,   108,     0,    71,    64,    65,    78,    78,    78,
   161,    56,    71,    56,    78,   161,    83,    78,    78,    82,
    82,   135,    -1,    -1,    83,    -1,    -1,    -1,    82,    82,
    -1,   137,   138,    -1,   138,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,
    -1,   157,   158,    -1,    -1,    -1,    69,    70,    71,    72,
    73,    74,    75,    76,    -1,    -1,    -1,    -1,   174,     0,
     1,   177,    -1,   177,    -1,    -1,     7,    -1,     9,    10,
    11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
    21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
    31,    32,    33,   209,    35,    -1,    37,    38,    39,    40,
    41,    42,    43,    44,    45,    46,    47,    48,    -1,    -1,
    -1,    -1,    -1,    54,    -1,    56,    -1,    -1,    -1,    60,
    61,    62,    63,    64,    65,    66,    -1,    -1,    -1,    -1,
    71,    -1,    -1,    -1,     0,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    83,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
    -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    -1,    -1,    -1,    -1,    -1,    54,    -1,
    56,    -1,    -1,    -1,    60,    61,    62,    63,    64,    65,
    66,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,     9,    10,
    11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
    21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
    31,    32,    33,    82,    35,    -1,    37,    38,    39,    40,
    41,    42,    43,    44,    45,    46,    47,    48,    -1,    -1,
    -1,    -1,    -1,    54,    -1,    56,   115,    -1,    -1,    60,
    61,    62,    63,    64,    65,    -1,    -1,    -1,    -1,    -1,
    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,   148,
   149,   150,   151,   162,   163,   164,   165,   166,   167,   168,
   169,   170,   171,   172,   173
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/share/misc/bison.simple"
/* This file comes from bison-1.28.  */

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

#ifndef YYSTACK_USE_ALLOCA
#ifdef alloca
#define YYSTACK_USE_ALLOCA
#else /* alloca not defined */
#ifdef __GNUC__
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi) || (defined (__sun) && defined (__i386))
#define YYSTACK_USE_ALLOCA
#include <alloca.h>
#else /* not sparc */
/* We think this test detects Watcom and Microsoft C.  */
/* This used to test MSDOS, but that is a bad idea
   since that symbol is in the user namespace.  */
#if (defined (_MSDOS) || defined (_MSDOS_)) && !defined (__TURBOC__)
#if 0 /* No need for malloc.h, which pollutes the namespace;
	 instead, just don't use alloca.  */
#include <malloc.h>
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
/* I don't know what this was needed for, but it pollutes the namespace.
   So I turned it off.   rms, 2 May 1997.  */
/* #include <malloc.h>  */
 #pragma alloca
#define YYSTACK_USE_ALLOCA
#else /* not MSDOS, or __TURBOC__, or _AIX */
#if 0
#ifdef __hpux /* haible@ilog.fr says this works for HPUX 9.05 and up,
		 and on HPUX 10.  Eventually we can turn this on.  */
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#endif /* __hpux */
#endif
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc */
#endif /* not GNU C */
#endif /* alloca not defined */
#endif /* YYSTACK_USE_ALLOCA not defined */

#ifdef YYSTACK_USE_ALLOCA
#define YYSTACK_ALLOC alloca
#else
#define YYSTACK_ALLOC malloc
#endif

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Define __yy_memcpy.  Note that the size argument
   should be passed with type unsigned int, because that is what the non-GCC
   definitions require.  With GCC, __builtin_memcpy takes an arg
   of type size_t, but it can handle unsigned int.  */

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     unsigned int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, unsigned int count)
{
  register char *t = to;
  register char *f = from;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 217 "/usr/share/misc/bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int yyparse (void *);
#else
int yyparse (void);
#endif
#endif

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;
  int yyfree_stacks = 0;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  if (yyfree_stacks)
	    {
	      free (yyss);
	      free (yyvs);
#ifdef YYLSP_NEEDED
	      free (yyls);
#endif
	    }
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
#ifndef YYSTACK_USE_ALLOCA
      yyfree_stacks = 1;
#endif
      yyss = (short *) YYSTACK_ALLOC (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1,
		   size * (unsigned int) sizeof (*yyssp));
      yyvs = (YYSTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1,
		   size * (unsigned int) sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1,
		   size * (unsigned int) sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 2:
#line 119 "nova/parser.y"
{ flushlist(); ;
    break;}
case 3:
#line 120 "nova/parser.y"
{ flushlist(); yyerrok; ;
    break;}
case 4:
#line 125 "nova/parser.y"
{ if(cond) doassign(yyvsp[-2].symbol,yyvsp[0].value.value,TOK_SYM,yyvsp[0].value.relmode); 
		yyval.value = yyvsp[0].value; ;
    break;}
case 7:
#line 130 "nova/parser.y"
{ assemble(yyvsp[0].value.value,yyvsp[0].value.relmode); ;
    break;}
case 9:
#line 134 "nova/parser.y"
{     
			if(cond){
				if( yyvsp[-1].symbol->flags & F_ASSIGNED ){
					if(pass==1)
						warning("label already defined; ignoring this definition");
				}else 
					doassign(yyvsp[-1].symbol,currentloc(),TOK_SYM,relmode);
			}
		;
    break;}
case 15:
#line 150 "nova/parser.y"
{ ;
    break;}
case 16:
#line 151 "nova/parser.y"
{ assemble(yyvsp[0].valuel >> 16,ABSOLUTE); assemble(yyvsp[0].valuel,ABSOLUTE); ;
    break;}
case 17:
#line 152 "nova/parser.y"
{ ;
    break;}
case 18:
#line 155 "nova/parser.y"
{ yyval.value.value = yyvsp[0].value.value & 3; 
			if(cond && yyvsp[0].value.value>3) fatal("no such accumulator"); ;
    break;}
case 19:
#line 158 "nova/parser.y"
{ yyval.value.value = 0; ;
    break;}
case 20:
#line 159 "nova/parser.y"
{ yyval.value.value = NOAC_INDIRECT; DPUTS("-- saw @"); ;
    break;}
case 21:
#line 161 "nova/parser.y"
{ yyval.value.value = 0; ;
    break;}
case 22:
#line 162 "nova/parser.y"
{ yyval.value.value = TWOAC_NOLOAD; DPUTS("-- saw #"); ;
    break;}
case 23:
#line 164 "nova/parser.y"
{ yyval.value.value = 0; ;
    break;}
case 24:
#line 165 "nova/parser.y"
{ yyval.value.value = yyvsp[0].symbol->value; DPRINTF("-- saw skip (%s)",yyvsp[0].symbol->name); ;
    break;}
case 25:
#line 167 "nova/parser.y"
{ yyval.value.value = indexseen = 0; ;
    break;}
case 26:
#line 168 "nova/parser.y"
{ yyval.value.value = yyvsp[0].value.value & 3; 
				 indexseen = 1;
				 if(cond && yyvsp[0].value.value>3) fatal("bad index");
				 DPRINTF("-- saw index = %o\n",yyvsp[0].value.value); ;
    break;}
case 27:
#line 174 "nova/parser.y"
{ seenterm=1; ;
    break;}
case 28:
#line 175 "nova/parser.y"
{ /* special symbol: location counter */
				seenterm=1; yyval.value.value = currentloc(); yyval.value.relmode = relmode; ;
    break;}
case 29:
#line 177 "nova/parser.y"
{ inputradix = radix; ;
    break;}
case 30:
#line 177 "nova/parser.y"
{ seenterm=1; DPUTS(" () "); yyval.value = yyvsp[-1].value; ;
    break;}
case 31:
#line 178 "nova/parser.y"
{ seenterm=1; DPUTS(" (negate)"); 
				yyval.value.value = - yyvsp[0].value.value; 
				yyval.value.relmode = yyvsp[0].value.relmode; 
				if(yyvsp[0].value.relmode != ABSOLUTE) badreloc("-"); ;
    break;}
case 33:
#line 185 "nova/parser.y"
{ if(cond && pass==2 && !(yyvsp[0].symbol->flags & F_ASSIGNED)) 
					fatal("undefined symbol");
		        yyval.value.value = yyvsp[0].symbol->value;
		        yyval.value.relmode = yyvsp[0].symbol->relmode; ;
    break;}
case 35:
#line 224 "nova/parser.y"
{ seenterm=0; inputradix = 10; ;
    break;}
case 36:
#line 224 "nova/parser.y"
{ 
				inputradix = radix; 
				yyval.value.value = yyvsp[-3].value.value << (15-yyvsp[0].value.value); 
				yyval.value.relmode = ABSOLUTE;
				if(yyvsp[-3].value.relmode != ABSOLUTE || yyvsp[0].value.relmode != ABSOLUTE) 
					badreloc("B [both operands must be absolute]");
				if(yyvsp[0].value.value < 0 || yyvsp[0].value.value > 15)
					warning("bit alignment value not in range 0-15");
				DPUTS(" (bit align) "); 
			;
    break;}
case 37:
#line 234 "nova/parser.y"
{seenterm=0;;
    break;}
case 38:
#line 234 "nova/parser.y"
{ 
				yyval.value.value = yyvsp[-3].value.value + yyvsp[0].value.value; 
				if(yyvsp[-3].value.relmode == ABSOLUTE && yyvsp[0].value.relmode == ABSOLUTE)
					yyval.value.relmode = ABSOLUTE;
				else if(yyvsp[-3].value.relmode == ABSOLUTE && ISRELOC(yyvsp[0].value.relmode))
					yyval.value.relmode = yyvsp[0].value.relmode;
				else if(ISRELOC(yyvsp[-3].value.relmode) && yyvsp[0].value.relmode == ABSOLUTE)
					yyval.value.relmode = yyvsp[-3].value.relmode;
				else if(yyvsp[-3].value.relmode == NORMAL_REL && yyvsp[0].value.relmode == NORMAL_REL)
					yyval.value.relmode = NORMAL_BYTE_REL;
				else if(yyvsp[-3].value.relmode == PAGE_ZERO_REL && yyvsp[0].value.relmode == PAGE_ZERO_REL)
					yyval.value.relmode = PAGE_ZERO_BYTE_REL;
				else badreloc("+");
				DPUTS(" (add) "); ;
    break;}
case 39:
#line 248 "nova/parser.y"
{seenterm=0;;
    break;}
case 40:
#line 248 "nova/parser.y"
{ 
				yyval.value.value = yyvsp[-3].value.value - yyvsp[0].value.value; 
				if( (yyvsp[-3].value.relmode == ABSOLUTE || ISRELOC(yyvsp[-3].value.relmode))
						 && yyvsp[0].value.relmode == yyvsp[-3].value.relmode )
					yyval.value.relmode = ABSOLUTE;
				else if(ISRELOC(yyvsp[-3].value.relmode) && yyvsp[0].value.relmode == ABSOLUTE)
					yyval.value.relmode = yyvsp[-3].value.relmode;
				else badreloc("-");
				DPUTS(" (subtract) "); ;
    break;}
case 41:
#line 257 "nova/parser.y"
{seenterm=0;;
    break;}
case 42:
#line 257 "nova/parser.y"
{ 
				yyval.value.value = yyvsp[-3].value.value * yyvsp[0].value.value; 
				if(yyvsp[-3].value.relmode == ABSOLUTE){
					if(yyvsp[0].value.relmode == ABSOLUTE) yyval.value.relmode = ABSOLUTE;
					else if(yyvsp[-3].value.value==1) yyval.value.relmode = yyvsp[0].value.relmode;
					else if(yyvsp[0].value.relmode == NORMAL_REL && yyvsp[-3].value.value==2)
						yyval.value.relmode = NORMAL_BYTE_REL;
					else if(yyvsp[0].value.relmode == PAGE_ZERO_REL && yyvsp[-3].value.value==2)
						yyval.value.relmode = PAGE_ZERO_BYTE_REL;
					else badreloc("* [unsuitable reloc for second operand]");
				}else if(yyvsp[0].value.relmode == ABSOLUTE){
					if(yyvsp[-3].value.relmode == ABSOLUTE) yyval.value.relmode = ABSOLUTE;
					else if(yyvsp[0].value.value==1) yyval.value.relmode = yyvsp[-3].value.relmode;
					else if(yyvsp[-3].value.relmode == NORMAL_REL && yyvsp[0].value.value==2)
						yyval.value.relmode = NORMAL_BYTE_REL;
					else if(yyvsp[-3].value.relmode == PAGE_ZERO_REL && yyvsp[0].value.value==2)
						yyval.value.relmode = PAGE_ZERO_BYTE_REL;
					else badreloc("* [unsuitable reloc for first operand]");
				}else badreloc("* [neither operand is absolute]");
				DPUTS(" (multiply) "); 
				;
    break;}
case 43:
#line 278 "nova/parser.y"
{seenterm=0;;
    break;}
case 44:
#line 278 "nova/parser.y"
{ 
				yyval.value.value = yyvsp[-3].value.value / yyvsp[0].value.value; 
				if(yyvsp[-3].value.relmode == ABSOLUTE && yyvsp[0].value.relmode == ABSOLUTE)
					yyval.value.relmode = ABSOLUTE;
				else badreloc("/ [both operands must be absolute]");
				DPUTS(" (divide) "); ;
    break;}
case 45:
#line 284 "nova/parser.y"
{seenterm=0;;
    break;}
case 46:
#line 284 "nova/parser.y"
{ 
				yyval.value.value = yyvsp[-3].value.value & yyvsp[0].value.value;
				if(yyvsp[-3].value.relmode == ABSOLUTE && yyvsp[0].value.relmode == ABSOLUTE)
					yyval.value.relmode = ABSOLUTE;
				else badreloc("& [both operands must be absolute]");
				DPUTS(" (logical AND) "); ;
    break;}
case 47:
#line 290 "nova/parser.y"
{seenterm=0;;
    break;}
case 48:
#line 290 "nova/parser.y"
{ 
				yyval.value.value = yyvsp[-3].value.value | yyvsp[0].value.value;
				if(yyvsp[-3].value.relmode == ABSOLUTE && yyvsp[0].value.relmode == ABSOLUTE)
					yyval.value.relmode = ABSOLUTE;
				else badreloc("! [both operands must be absolute]");
				DPUTS(" (logical OR) "); ;
    break;}
case 49:
#line 296 "nova/parser.y"
{seenterm=0;;
    break;}
case 50:
#line 296 "nova/parser.y"
{ 
				yyval.value.value = (yyvsp[-3].value.value == yyvsp[0].value.value) && (yyvsp[-3].value.relmode == yyvsp[0].value.relmode);
				yyval.value.relmode = ABSOLUTE;
				DPUTS(" (==) "); ;
    break;}
case 51:
#line 300 "nova/parser.y"
{seenterm=0;;
    break;}
case 52:
#line 300 "nova/parser.y"
{ 
				yyval.value.value = (yyvsp[-3].value.value >= yyvsp[0].value.value) && (yyvsp[-3].value.relmode == yyvsp[0].value.relmode);
				yyval.value.relmode = ABSOLUTE;
				DPUTS(" (>=) "); ;
    break;}
case 53:
#line 304 "nova/parser.y"
{seenterm=0;;
    break;}
case 54:
#line 304 "nova/parser.y"
{ 
				yyval.value.value = (yyvsp[-3].value.value > yyvsp[0].value.value) && (yyvsp[-3].value.relmode == yyvsp[0].value.relmode);
				yyval.value.relmode = ABSOLUTE;
				DPUTS(" (>) "); ;
    break;}
case 55:
#line 308 "nova/parser.y"
{seenterm=0;;
    break;}
case 56:
#line 308 "nova/parser.y"
{ 
				yyval.value.value = (yyvsp[-3].value.value < yyvsp[0].value.value) && (yyvsp[-3].value.relmode == yyvsp[0].value.relmode);
				yyval.value.relmode = ABSOLUTE;
				DPUTS(" (<) "); ;
    break;}
case 57:
#line 312 "nova/parser.y"
{seenterm=0;;
    break;}
case 58:
#line 312 "nova/parser.y"
{ 
				yyval.value.value = (yyvsp[-3].value.value < yyvsp[0].value.value) && (yyvsp[-3].value.relmode == yyvsp[0].value.relmode);
				yyval.value.relmode = ABSOLUTE;
				DPUTS(" (<=) "); ;
    break;}
case 59:
#line 316 "nova/parser.y"
{seenterm=0;;
    break;}
case 60:
#line 316 "nova/parser.y"
{ 
				yyval.value.value = (yyvsp[-3].value.value != yyvsp[0].value.value) || (yyvsp[-3].value.relmode != yyvsp[0].value.relmode);
				yyval.value.relmode = ABSOLUTE;
				DPUTS(" (<>) "); ;
    break;}
case 61:
#line 321 "nova/parser.y"
{ seenterm = 0; ;
    break;}
case 62:
#line 324 "nova/parser.y"
{ 
				yyval.value = yyvsp[-1].value;
				yyval.value.value = ea(yyvsp[0].value.value,indexseen,&(yyval.value)) | yyvsp[-2].value.value; ;
    break;}
case 63:
#line 328 "nova/parser.y"
{ 
				yyval.value.value = yyvsp[-1].symbol->value | yyvsp[0].value.value; 
				yyval.value.relmode = yyvsp[0].value.relmode; ;
    break;}
case 64:
#line 332 "nova/parser.y"
{ 
				yyval.value.value = yyvsp[-3].symbol->value | (yyvsp[-2].value.value<<11) | yyvsp[0].value.value; 
				yyval.value.relmode = yyvsp[0].value.relmode; ;
    break;}
case 65:
#line 337 "nova/parser.y"
{ yyval.value.value = yyvsp[-5].symbol->value | yyvsp[-4].value.value | (yyvsp[-3].value.value<<13) | (yyvsp[-1].value.value<<11) | yyvsp[0].value.value;
		  if(yyvsp[-4].value.value && !yyvsp[0].value.value)
			warning("invalid instruction for Nova 3 ('no load' & 'never skip')");
		  yyval.value.relmode = ABSOLUTE; /* ALC instruction; no address to relocate! */
		  DPRINTF("2AC %#o acs=%o acd=%o\n",yyvsp[-5].symbol->value,yyvsp[-3].value.value,yyvsp[-1].value.value); ;
    break;}
case 66:
#line 343 "nova/parser.y"
{ yyval.value.value = 0; ;
    break;}
case 68:
#line 345 "nova/parser.y"
{ yyval.value.value = (yyvsp[-2].value.value<<11) | yyvsp[0].value.value; ;
    break;}
case 69:
#line 347 "nova/parser.y"
{ 
				yyval.value.value = yyvsp[-1].symbol->value | yyvsp[0].value.value; 
				yyval.value.relmode = ABSOLUTE; /* no address encoded in I/O instr */ ;
    break;}
case 70:
#line 352 "nova/parser.y"
{ yyval.value.value = yyvsp[-5].symbol->value | (yyvsp[-4].value.value<<13) | (yyvsp[-2].value.value<<11) | (yyvsp[0].value.value<<4);
		  yyval.value.relmode = ABSOLUTE;
		  DPRINTF("TRAP %#o acs=%o acd=%o trap=%#o\n",yyvsp[-5].symbol->value,yyvsp[-4].value,yyvsp[-2].value,yyvsp[0].value); ;
    break;}
case 78:
#line 360 "nova/parser.y"
{ if(cond) rbexpr(START_BLK,yyvsp[0].value.value,yyvsp[0].value.relmode); ;
    break;}
case 79:
#line 363 "nova/parser.y"
{ symlist[nsyms++] = yyvsp[0].symbol; ;
    break;}
case 80:
#line 364 "nova/parser.y"
{ symlist[nsyms++] = yyvsp[0].symbol; ;
    break;}
case 85:
#line 370 "nova/parser.y"
{ 
	  	/* define an ALC instruction or expression */
		if(cond) dalc(yyvsp[-2].symbol,yyvsp[0].value.value); ;
    break;}
case 86:
#line 373 "nova/parser.y"
{
		/* define an instruction requiring an accumulator */
		if(cond) doassign(yyvsp[-2].symbol,yyvsp[0].value.value,TOK_ONEAC,0); ;
    break;}
case 87:
#line 376 "nova/parser.y"
{ 
		/* define an I/O instruction that does not use an accumulator */
		if(cond) dio(yyvsp[-2].symbol,yyvsp[0].value.value); ;
    break;}
case 88:
#line 379 "nova/parser.y"
{ 
		/* define an I/O instruction having two required fields */
		if(cond) dio(yyvsp[-2].symbol,yyvsp[0].value.value); ;
    break;}
case 89:
#line 382 "nova/parser.y"
{ 
		/* define an instruction with source and destination accumulators, no skip */
		if(cond) doassign(yyvsp[-2].symbol,yyvsp[0].value.value,TOK_TWOAC,0); ;
    break;}
case 90:
#line 385 "nova/parser.y"
{ 
		/* define an instruction with source and destination accumulators allowing skip */
		if(cond) doassign(yyvsp[-2].symbol,yyvsp[0].value.value,TOK_TWOAC,0); ;
    break;}
case 91:
#line 388 "nova/parser.y"
{ 
		/* define a memory reference instruction with displacement and index */
		if(cond) doassign(yyvsp[-2].symbol,yyvsp[0].value.value,TOK_NOAC,0); ;
    break;}
case 92:
#line 391 "nova/parser.y"
{ 
		/* define a memory reference instruction with 2 or 3 fields */
		if(cond) doassign(yyvsp[-2].symbol,yyvsp[0].value.value,TOK_NOAC,0); ;
    break;}
case 93:
#line 394 "nova/parser.y"
{ 
		/* define a user symbol without implied formatting */
		if(cond) doassign(yyvsp[-2].symbol,yyvsp[0].value.value,TOK_SYM,ABSOLUTE /*??*/ ); ;
    break;}
case 94:
#line 397 "nova/parser.y"
{ if(cond) clean_syms(); ;
    break;}
case 95:
#line 399 "nova/parser.y"
{ /* reserve a block of storage */ 
				if(cond){
					flushrb(); 
					switch(relmode){
					case ABSOLUTE: curloc += yyvsp[0].value.value; break;
					case NORMAL_REL: nrel_loc += yyvsp[0].value.value; break; 
					case PAGE_ZERO_REL: zrel_loc += yyvsp[0].value.value; break;
					}
				}
		;
    break;}
case 96:
#line 409 "nova/parser.y"
{ /* specify NREL code relocation */
			if(cond && relmode != NORMAL_REL){ flushrb(); relmode = NORMAL_REL; } 
		;
    break;}
case 97:
#line 412 "nova/parser.y"
{ /* specify page zero relocation */
			if(cond && relmode != PAGE_ZERO_REL){ flushrb(); relmode = PAGE_ZERO_REL; }
		;
    break;}
case 98:
#line 415 "nova/parser.y"
{ /* set the current location counter, to an absolute address */
			if(cond){ flushrb(); relmode = ABSOLUTE; curloc = yyvsp[0].value.value; }
		;
    break;}
case 99:
#line 419 "nova/parser.y"
{ /* reserve a named common area */ 
		if(cond) rbcomm(yyvsp[-2].symbol,yyvsp[0].value.value,yyvsp[0].value.relmode);
		;
    break;}
case 100:
#line 422 "nova/parser.y"
{ /* specify an unlabelled common area */ 
		if(cond) rbexpr(CSIZ_BLK,yyvsp[0].value.value,yyvsp[0].value.relmode); 
		;
    break;}
case 101:
#line 425 "nova/parser.y"
{ nsyms=0; ;
    break;}
case 102:
#line 425 "nova/parser.y"
{ /* define a program entry */ 
		if(cond) rbsymlist(ENT_BLK,ENTRY_SYM,symlist,nsyms); 
		;
    break;}
case 103:
#line 428 "nova/parser.y"
{ /* define an overlay entry */
		symlist[0] = yyvsp[0].symbol;
		if(cond) rbsymlist(ENT_BLK,OVERLAY_SYM,symlist,1); 
		;
    break;}
case 104:
#line 432 "nova/parser.y"
{ nsyms=0; ;
    break;}
case 105:
#line 432 "nova/parser.y"
{ /* define an external displacement reference */
		if(cond) rbsymlist(EXTD_BLK,EXT_DISP_SYM,symlist,nsyms); 
		;
    break;}
case 106:
#line 435 "nova/parser.y"
{ nsyms=0; ;
    break;}
case 107:
#line 435 "nova/parser.y"
{ /* define an external normal reference */
		if(cond) rbsymlist(EXTN_BLK,NORMAL_EXT_SYM,symlist,nsyms); 
		;
    break;}
case 108:
#line 439 "nova/parser.y"
{ /* add an expression value to an external symbol */ 
		if(cond) rbgadd(GADD_BLK,yyvsp[-2].symbol,yyvsp[0].value.value,yyvsp[0].value.relmode);
		;
    break;}
case 109:
#line 442 "nova/parser.y"
{ /* add an expression value to an external symbol (0b0) */
		if(cond) rbgadd(GREF_BLK,yyvsp[-2].symbol,yyvsp[0].value.value,yyvsp[0].value.relmode);
		;
    break;}
case 110:
#line 447 "nova/parser.y"
{ popcond(); ;
    break;}
case 111:
#line 448 "nova/parser.y"
{ pushcond(yyvsp[0].value.value == 0); /* assemble if expr = 0 */ ;
    break;}
case 112:
#line 449 "nova/parser.y"
{ pushcond(yyvsp[0].value.value > 0);  /* assemble if expr > 0 */ ;
    break;}
case 113:
#line 450 "nova/parser.y"
{ pushcond(yyvsp[0].value.value < 0);  /* assemble if expr < 0 */ ;
    break;}
case 114:
#line 451 "nova/parser.y"
{ pushcond(yyvsp[0].value.value != 0); /* assemble if expr != 0 */ ;
    break;}
case 115:
#line 453 "nova/parser.y"
{ DPUTS("TXT directive"); ;
    break;}
case 116:
#line 454 "nova/parser.y"
{ if(cond) txtm = yyvsp[0].value.value; /* change text byte packing */ ;
    break;}
case 117:
#line 455 "nova/parser.y"
{ if(cond) txtn = yyvsp[0].value.value; /* determine text string termination */ ;
    break;}
case 118:
#line 458 "nova/parser.y"
{ /* radix for numeric input conversion */ 
			saveradix = radix; inputradix = 10; ;
    break;}
case 119:
#line 460 "nova/parser.y"
{ radix = saveradix; 
			if(yyvsp[0].value.value < 2 || yyvsp[0].value.value > 20)
				warning("invalid input radix; must be >=2 and <=20");
			else 
				if(cond) radix = inputradix = yyvsp[0].value.value; 
		;
    break;}
case 120:
#line 467 "nova/parser.y"
{ /* entitle an RB file */ 
		if(cond) rbtitle(yyvsp[0].symbol); ;
    break;}
case 121:
#line 471 "nova/parser.y"
{ if(cond){ endflag = 1; YYACCEPT; } /* end of program */ ;
    break;}
case 122:
#line 472 "nova/parser.y"
{ if(cond) YYACCEPT; ;
    break;}
case 123:
#line 473 "nova/parser.y"
{ if(cond) YYACCEPT; ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 543 "/usr/share/misc/bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;

 yyacceptlab:
  /* YYACCEPT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 0;

 yyabortlab:
  /* YYABORT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 1;
}
#line 476 "nova/parser.y"

