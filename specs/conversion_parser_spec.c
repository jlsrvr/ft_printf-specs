#include "spec.h"

void	print_struct_diff(char *what, int result, int expected, int is_char, int first)
{
	if (!first)
		printf(RED "KO\n" RESET);
	printf(UNDER RED"%s :\n" RESET, what);
	if (is_char)
	{
		printf("Expected = [%c]\n", expected);
		printf("Got      = [%c]\n", result);
	}
	else
	{
		printf("Expected = [%d]\n", expected);
		printf("Got      = [%d]\n", result);
	}
}
static void	check_result(t_specs result, t_specs expected)
{
	int first = 0;

	if (result.valid != expected.valid)
		print_struct_diff("Validity", result.valid, expected.valid, 0, first++);
	if (result.zero_pad != expected.zero_pad)
		print_struct_diff("Zero pad", result.zero_pad, expected.zero_pad, 0, first++);
	if (result.right_pad != expected.right_pad)
		print_struct_diff("Right pad", result.right_pad, expected.right_pad, 0, first++);
	if (result.min_f_width != expected.min_f_width)
		print_struct_diff("Min field width", result.min_f_width, expected.min_f_width, 0, first++);
	if (result.precision != expected.precision)
		print_struct_diff("Precision", result.precision, expected.precision, 0, first++);
	if (result.format != expected.format)
		print_struct_diff("Format", result.format, expected.format, 1, first++);
	if (first == 0)
		printf(GREEN "OK\n" RESET);
}

static void conversion_parser_test(char *describe, t_specs expected, char **string, ...)
{
	t_specs result;
	va_list arguments;

	va_start(arguments, string);
	printf("<==== %s ====>\n", describe);
	result = conversion_parser(string, &arguments);
	check_result(result, expected);
	return ;
}

int main(void)
{
	printf("\\\\\\ Specs conversion_parser function  ///\n");
	int index;
	char *conversion;
	char *formats[9] = {"c", "s", "p", "d", "i", "u", "x", "X", "%"};
	for (index = 0; index < 9; index++)
		conversion_parser_test("Only format", test_specs(1, 0, 0, 0, -1, *(formats[index])), &(formats[index]));
	conversion = "0d";
	conversion_parser_test("Zero padded, format", test_specs(1, 1, 0, 0, -1, 'd'), &conversion);
	conversion = "00000d";
	conversion_parser_test("Zero padded with multiple '0', format", test_specs(1, 1, 0, 0, -1, 'd'), &conversion);
	conversion = "-d";
	conversion_parser_test("Right padded, format", test_specs(1, 0, 1, 0, -1, 'd'), &conversion);
	conversion = "----d";
	conversion_parser_test("Right padded with multiple '-', format", test_specs(1, 0, 1, 0, -1, 'd'), &conversion);
	conversion = "-0d";
	conversion_parser_test("Right padded then zero padded, format", test_specs(1, 1, 1, 0, -1, 'd'), &conversion);
	conversion = "0-d";
	conversion_parser_test("Zero padded then right padded, format", test_specs(1, 1, 1, 0, -1, 'd'), &conversion);
	conversion = "0-0-0-0-0-000---00---00--00--0d";
	conversion_parser_test("Right padded and zero padded randomly many times, format", test_specs(1, 1, 1, 0, -1, 'd'), &conversion);
	conversion = "5d";
	conversion_parser_test("Min field with 5, format", test_specs(1, 0, 0, 5, -1, 'd'), &conversion);
	conversion = "100d";
	conversion_parser_test("Min field with 100, format", test_specs(1, 0, 0, 100, -1, 'd'), &conversion);
	conversion = "0100d";
	conversion_parser_test("Zero pad, min field with 100, format", test_specs(1, 1, 0, 100, -1, 'd'), &conversion);
	conversion = "*d";
	conversion_parser_test("Min field with '*' and given 5, format", test_specs(1, 0, 0, 5, -1, 'd'), &conversion, 5);
	conversion = "*d";
	conversion_parser_test("Min field with '*' and given -5, format", test_specs(1, 0, 1, 5, -1, 'd'), &conversion, -5);
	conversion = ".5d";
	conversion_parser_test("Precision of 5, format", test_specs(1, 0, 0, 0, 5, 'd'), &conversion);
	conversion = ".*d";
	conversion_parser_test("Precision of with '*' and given 5, format", test_specs(1, 0, 0, 0, 5, 'd'), &conversion, 5);
	conversion = ".*d";
	conversion_parser_test("Precision of with '*' and given -5, format", test_specs(1, 0, 0, 0, -1, 'd'), &conversion, -5);
	conversion = ".d";
	conversion_parser_test("Precision of signaled but nothing given, format", test_specs(1, 0, 0, 0, 0, 'd'), &conversion);
	conversion = "y";
	conversion_parser_test("Invalid format", test_specs(0, 0, 0, 0, -1, 0), &conversion);
	conversion = "y";
	conversion_parser_test("Invalid format", test_specs(0, 0, 0, 0, -1, 0), &conversion);
	conversion = "ptoto";
	conversion_parser_test("format with things after", test_specs(1, 0, 0, 0, -1, 'p'), &conversion);
	printf(BLINK CYAN"toto == %s\n"RESET, conversion);
	conversion = "-0-0-10.5p";
	conversion_parser_test("random right and zero pad, 10 min-f-width, precision 5, format p", test_specs(1, 1, 1, 10, 5, 'p'), &conversion);
	conversion = "-0-0-10.5W";
	conversion_parser_test("random right and zero pad, 10 min-f-width, precision 5, INVALID format p", test_specs(0, 1, 1, 10, 5, 0), &conversion);
	conversion = "-0-0-*.*p";
	conversion_parser_test("random right and zero pad, * 10 min-f-width, precision * 5, format p", test_specs(1, 1, 1, 10, 5, 'p'), &conversion, 10, 5);
	return (1);
}
