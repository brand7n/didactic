%{
#include <stdio.h>
#define yywrap() 1
extern yylex();
%}

%%
\n	puts("---");
[0-9]	puts("digit!");
[A-Za-z]	puts("letter!");
.	puts("something else!");

%%
mmain(){ yylex(); }
