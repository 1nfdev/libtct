#include <stdio.h>

#include "libtct.h"

int main() {
	char* template = "Welcome to {{ project_name }}!\n"
		"{{ project_name }}({{ project_abbreviation }}) is a micro template "
		"engine for {{ language }}. It has C-style usage, fewer lines of code "
		"and just needs a standard library. The {{ project_name }} project is "
		"released under the terms of the {{ license }} license.\n";
	char* result;

	tct_arguments_t* args = NULL;

	tct_add_argument(args, "project_abbreviation", "%s", "TCT");
	tct_add_argument(args, "project_name", "%s", "Tiny C Template engine");
	tct_add_argument(args, "language", "%s", "C Language");
	tct_add_argument(args, "license", "%s", "MIT");

	result = tct_render(template, args);

	if (result != NULL && args != NULL) {
		fputs(result, stdout);

		tct_free_argument(args);
		free(result);

		system("pause");
		return 0;
	}

	return 1;
}