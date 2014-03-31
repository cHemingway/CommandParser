#include "parse_assignment.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
		/* Input */
	char in[100];
	int in_len = sizeof(in)/sizeof(in[0]);

	/* Continually parse input */
	while(fgets(in, in_len, stdin)) {
		char *end = in + strlen(in);
		char *name = NULL;
		struct valout_t valout;
		int err;

		/* Parse the line */
		err = parse_assignment(in, end, &name, &valout);

		if (1) {
			/* Print the name */
			if (name) {
				printf("Name: %s \n", name);
			}
			else {
				printf("Error: No name found in input \n");
			}

			/* Print the value */
			if(valout.type == VAL_INT) {
				printf("Value = (int): %d \n", valout.integer);
			}
			else if (valout.type == VAL_STR) {
				printf("Value = (str): %s \n", valout.string);
			}
			else {
				printf("Error: No value found");
			}
		} else { /*err != 0*/
			printf("Error: parse_assignment() returned %d \n", err);
		}

		/* End with a trailing newline */
		printf("\n");
	}



	return 0;
}