#include "spec.h"

static void	check_result(char *result, char *expected)
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

static void converting_function_test(char *describe, char **dest, int valid, char format, char *expected, ...)
{
	t_specs specs;
	va_list args;

	va_start(args, expected);
	specs = test_specs(valid, 0, 0, 0, -1, format);
	printf("<==== %s ====>\n", describe);
	converting_function(specs, args, dest);
	check_result(*dest, expected);
	free(*dest);
	return ;
}

int main(void)
{
	printf("\\\\\\ Specs string_writer function  ///\n");
	char *dest;

	dest = ft_strdup("");
	string_writer_test("Valid s", &dest, 1, 's', "added", "added");

	return (1);
}
