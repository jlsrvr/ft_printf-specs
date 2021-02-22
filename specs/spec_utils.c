#include "spec.h"

t_specs test_specs(int valid, int zero_pad, int right_pad, int min_f_width, int precision, char format)
{
	t_specs specs;

	specs.valid = valid;
	specs.zero_pad = zero_pad;
	specs.right_pad = right_pad;
	specs.min_f_width = min_f_width;
	specs.precision = precision;
	specs.format = format;
	return (specs);
}

void	check_conversion_result(char *result, char *expected)
{
	if (strcmp(result, expected))
	{
		printf(RED "KO\n" RESET);
		printf("Expected = [%s]\n", expected);
		printf("Got      = [%s]\n", result);
		return ;
	}
	printf(GREEN "OK\n" RESET);
}

