typedef union{
	int value;
	struct sym_rec *symbol;
} YYSTYPE;
#define	TOK_SEP	257
#define	TOK_FIELD	258
#define	TOK_EXPUNGE	259
#define	TOK_FIXMRI	260
#define	TOK_PAUSE	261
#define	TOK_FIXTAB	262
#define	TOK_DECIMAL	263
#define	TOK_OCTAL	264
#define	TOK_SYM	265
#define	TOK_MRI	266
#define	TOK_NUM	267


extern YYSTYPE yylval;
