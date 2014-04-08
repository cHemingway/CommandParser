#include "netprot_command.h"
#include "netprot_command_list.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
		/* Input */
	char in[100];
	int in_len = sizeof(in)/sizeof(in[0]);

	/* Continually parse input */
	while(fgets(in, in_len, stdin)) {
		char out[100];
		int outlen = 100;
		int err;

		/* Process Commands */
		err = netprot_process_command(netprot_default_command_list, in, out, outlen);
		puts(out);
		if (!err) {
			printf("Error: netprot_process_command returned %d", err);
		}

		/* End with a trailing newline */
		printf("\n");
	}



	return 0;
}