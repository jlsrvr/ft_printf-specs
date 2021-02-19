#include "spec.h"

t_specs test_specs(int zero_pad, int right_pad, int min_f_width, int precision)
{
	t_specs specs;

	specs.zero_pad = zero_pad;
	specs.right_pad = right_pad;
	specs.min_f_width = min_f_width;
	specs.precision = precision;
	return (specs);
}

void	check_spec_result(char *result, char * expected)
{
	if (strcmp(result, expected))
	{
		printf(RED "KO\n" RESET);
		printf("Excpected = [%s]\n", expected);
		printf("Got       = [%s]\n", result);
		return ;
	}
	printf(GREEN "OK\n" RESET);
}

