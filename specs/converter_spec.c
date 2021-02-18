#include "spec.h"

static void char_converter_test(char *describe, t_specs my_specs, char c, char *expected)
{
	char *result;

	printf("<==== %s ====>\n", describe);
	result = char_converter(my_specs, c);
	if (strcmp(result, expected))
	{
		printf(RED "KO\n" RESET);
		printf("Excpected = [%s]\n", expected);
		printf("Got       = [%s]\n", result);
		return ;
	}
	printf(GREEN "OK\n" RESET);
	return ;
}

static t_specs test_specs(int zero_pad, int right_pad, int min_f_width, int precision)
{
	t_specs specs;

	specs.zero_pad = zero_pad;
	specs.right_pad = right_pad;
	specs.min_f_width = min_f_width;
	specs.precision = precision;
	return (specs);
}

int main(void)
{
	int neg_int = -20;
	char special[2];
	special[0] = (unsigned char)neg_int;
	special[1] = 0;
	char_converter_test("No specs", test_specs(0, 0, 0, -1), 'J', "J");
	char_converter_test("No specs but 0 instead of char", test_specs(0, 0, 0, -1), 0, "\0");
	char_converter_test("No specs but negative argument", test_specs(0, 0, 0, -1), neg_int, special);
	char_converter_test("Only min-field-width 5", test_specs(0, 0, 5, -1), 'J', "    J");
	char_converter_test("Only precision 5", test_specs(0, 0, 0, 5), 'J', "J");
	char_converter_test("Only min-field-width 100", test_specs(0, 0, 100, -1), 'J', "                                                                                                   J");
	char_converter_test("Zero padded min-field-width 5", test_specs(1, 0, 5, -1), 'J', "0000J");
	char_converter_test("Zero padded, min-field-width 5, precision 3", test_specs(1, 0, 5, 3), 'J', "0000J");
	char_converter_test("Right padded min-field-width 5", test_specs(0, 1, 5, -1), 'J', "J    ");
	char_converter_test("Right & zero padded min-field-width 5", test_specs(1, 1, 5, -1), 'J', "J    ");

	return (1);
}
