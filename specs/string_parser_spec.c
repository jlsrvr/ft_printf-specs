#include "spec.h"

static void	check_result(char *result, char *expected)
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

static void converting_function_test(char *describe, char **dest, char *string, char *expected, ...)
{
	va_list args;

	va_start(args, expected);
	printf("<==== %s ====>\n", describe);
	string_parser(&string, &args, dest);
	check_result(*dest, expected);
	free(*dest);
	va_end(args);
	return ;
}

int main(void)
{
	printf("\\\\\\ Specs converting_function function  ///\n");
	char *dest;
	char *input;
	char *expected;

	dest = ft_strdup("");
	input = "String with no conversions";
	expected = input;
	converting_function_test(input, &dest, input, expected);
	dest = ft_strdup("");
	input = "%s";
	expected = "string";;
	converting_function_test("String with only %s", &dest, input, expected, "string");
	dest = ft_strdup("");
	input = "%s print stuff after conversion";
	expected = "string print stuff after conversion";
	converting_function_test("String with %s and things after", &dest, input, expected, "string");
	dest = ft_strdup("");
	input = "print this before conversion of %s";
	expected = "print this before conversion of string";
	converting_function_test("String with %s and things before", &dest, input, expected, "string");
	dest = ft_strdup("");
	input = "Print first: %s, then : %s ";
	expected = "Print first: one, then : two ";
	converting_function_test("String with two %s", &dest, input, expected, "one", "two");
	dest = ft_strdup("");
	input = "%010s%010s";
	expected = "0000string0000string";;
	converting_function_test("String with %010s%010s", &dest, input, expected, "string", "string");
	dest = ft_strdup("");
	input = "%s%s%c";
	expected = "stringstringK";;
	converting_function_test("String with %s%s%c", &dest, input, expected, "string", "string", 'K');

	return (1);
}
