/* --- The following code comes from C:\lcc\lib64\wizard\textmode.tpl. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static const char *infile = NULL, *batchfile = NULL;


void Usage(char *programName)
{
	const char * USAGESTR =
		"Usage: %s [opts] <infile>\n"
		"  In file must be in CARD format and include a CODE section.\n"
		" -rnd       Will randomize RAM before loading CARD file.\n"
		" -b=batch   Will be used instead of STDIN if given.\n"
	;

	fprintf(stderr, USAGESTR, programName);
}


/* returns the index of the first argument that is not an option; i.e.
   does not start with a dash or a slash
*/
int HandleOptions(int argc,char *argv[])
{
	int i,firstnonoption=0;

	for (i=1; i< argc;i++) {
		if (argv[i][0] == '/' || argv[i][0] == '-') {
			switch (argv[i][1]) {
				/* An argument -? means help is requested */
				case 'h': case 'H': case '?':
					Usage(argv[0]);
					return -1;

				case 'b': case 'B':
					if( argv[i][2] == '=' ) {
						batchfile = argv[i] + 3;
					}
					break;

				/* add your option switches here */

				default:
					fprintf(stderr,"unknown option %s\n",argv[i]);
					break;
			}
		}
		else {
			firstnonoption = i;
			break;
		}
	}
	return firstnonoption;
}



int main(int argc,char *argv[])
{
	int infilepos;
	if (argc == 1 || 1 > (infilepos = HandleOptions(argc,argv)) ) {
		/* If no arguments we call the Usage routine and exit */
		Usage(argv[0]);
		return 1;
	}

	/* handle the program options */
	if( infilepos == 0 ) {
		Usage(argv[0]);
		return 1;
	}

	infile = argv[infilepos];
	printf("IN: %s\nBT: %s\n", infile, batchfile ? batchfile : "<none>");

	/* The code of your application goes here */



	return 0;
}

