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
	va_end(args);
	return ;
}

int main(void)
{
	printf("\\\\\\ Specs converting_function function  ///\n");
	char *dest;

	dest = ft_strdup("");
	converting_function_test("Invalid struct", &dest, 0, 0, 0, "", "added");
	dest = ft_strdup("start ");
	converting_function_test("Valid with simple s", &dest, 1, 's', 1, "start added", "added");
	dest = ft_strdup("start ");
	converting_function_test("Valid with simple c", &dest, 1, 'c', 1, "start +", '+');
	dest = ft_strdup("start ");
	converting_function_test("Valid with simple %", &dest, 1, '%', 1, "start %", "ne doit pas etre vu");
	dest = ft_strdup("start ");
	dest = ft_strdup("start ");
	converting_function_test("Valid with simple p", &dest, 1, 'p', 1, "start 0x0", NULL);
	/*converting_function_test("Valid with simple d", &dest, 1, 'd', 1, "start 42", 42);
	dest = ft_strdup("start ");
	converting_function_test("Valid with simple i", &dest, 1, 'i', 1, "start 42", 42);
	dest = ft_strdup("start ");
	converting_function_test("Valid with simple u", &dest, 1, 'u', 1, "start 4294967254", -42);
	dest = ft_strdup("start ");
	converting_function_test("Valid with simple x", &dest, 1, 'x', 1, "start 2a", 42);
	dest = ft_strdup("start ");
	converting_function_test("Valid with simple x", &dest, 1, 'x', 1, "start ffffffd6", -42);
	dest = ft_strdup("start ");
	converting_function_test("Valid with simple X", &dest, 1, 'X', 1, "start 2A", 42);
	dest = ft_strdup("start ");
	converting_function_test("Valid with simple p", &dest, 1, 'p', 1, "start 0x0", NULL);*/

	return (1);
}
