#include "spec.h"

static void	check_result(char *result, char *expected, int result_int, int expected_int)
{
	if (strcmp(result, expected) || result_int != expected_int)
	{
		printf(RED "KO\n" RESET);
		printf("Expected |%d| = [%s]\n", expected_int, expected);
		printf("Got      |%d| = [%s]\n", result_int, result);
		return ;
	}
	printf(GREEN "OK\n" RESET);
}

static void converting_function_test(char *describe, char **dest, int valid, char format, int expected_int, char *expected, ...)
{
	t_specs specs;
	va_list args;
	int result;

	va_start(args, expected);
	specs = test_specs(valid, 0, 0, 0, -1, format);
	printf("<==== %s ====>\n", describe);
	result = converting_function(specs, &args, dest);
	check_result(*dest, expected, result, expected_int);
	free(*dest);
	return ;
}

int main(void)
{
	printf("\\\\\\ Specs converting_function function  ///\n");
	char *dest;

	dest = ft_strdup("");
	converting_function_test("Valid s", &dest, 1, 's', 1, "added", "added");

	return (1);
}
