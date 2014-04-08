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

int netprot_cmd_reset(const char *in, char *out, int outlen) {
	int i = 0, j = 0;

	/* Loop over each object until empty name*/
	while (strcmp(netprot_objects[i].name,"")) {
		/* Loop over each parameter */
		while (strcmp(netprot_objects[i].attrs[j].name,"")) {
			/* Reset values */
			netprot_objects[i].attrs[j].intval = netprot_objects[i].attrs[j].default_intval;
			strcpy(netprot_objects[i].attrs[j].strval, netprot_objects[i].attrs[j].default_strval);
			j++;
		}
		i++;
	}

	/* Success */
	strncpy(out,"+OK \r\n",outlen);
	return 0;
}