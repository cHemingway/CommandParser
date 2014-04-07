#include "netprot_commands_setget.h"
#include "parse_assignment.h"
#include "netprot_setget_params.h"
#include "netprot_setget_params_list.h"
#include <string.h>


int netprot_cmd_set(const char *in, char *out, int outlen) {
	char success[] = "+OK \n";


	/* Success */
	strcpy(out, success);
	return 0;	
}

int netprot_cmd_get(const char *in, char *out, int outlen) {


	/* Success */
	return 0;	
}