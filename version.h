/* version history
v1.0, 4-Sep-2002
 01-Jul-2003: 1.4b1 - Nova, PDP-8 targets
 02-          1.4b2 - Makefile fixes
		    - Nova: now parses a lone label as a statement
 26-Nov-2003: 1.5 - produce conventional assembly listing file
 02-Dec-2003: 1.6 - fix Nova TXT  pseudo-ops (lexer,parser)
 05-Dec-2003: 1.7 - finish TXT; add -s for 'header' files; other changes
 07-Dec-2003: 1.8 - add proper relocation mode handling; basic RB file output; fix implicit EA modes
 08-Dec-2003: 1.9 - Makefile cleanups
 10-Dec-2003: 1.91 - finally fix B operator, now lexed correctly in all cases 
 14-Dec-2003: 1.92 - add relocation flags to listing
 19-Dec-2003: 1.93 - implement conditional assembly
 19-Dec-2003: 1.94 - fix .RDX; check for invalid Nova 3 2AC instructions
 07-Jan-2004: 1.95 - fix failure to increment curloc on pass 1 (Nova)
 16-May-2004: 1.95r2 - fix missing files (pdp8/list.c, nova/list.c) in dist :( !
*/
#define VERS_STR "1.95"
