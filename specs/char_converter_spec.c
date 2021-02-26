#include "spec.h"

static void char_converter_test(char *describe, t_specs my_specs, char c, char *expected)
{
	char *result;

	printf("<==== %s ====>\n", describe);
	result = char_converter(my_specs, c);
	check_conversion_result(result, expected);
	free(result);
	return ;
}

int main(void)
{
	int neg_int = -20;
	char special[2];
	special[0] = (unsigned char)neg_int;
	special[1] = 0;
	printf("\\\\\\ Specs char converter ///\n");
	char_converter_test("No specs", test_specs(1, 0, 0, 0, -1, 'c'), 'J', "J");
	char_converter_test("No specs but 0 instead of char", test_specs(1, 0, 0, 0, -1, 'c'), (char)0, '0');
	char_converter_test("No specs but negative argument", test_specs(1, 0, 0, 0, -1, 'c'), neg_int, special);
	char_converter_test("Only min-field-width 5", test_specs(1, 0, 0, 5, -1, 'c'), 'J', "    J");
	char_converter_test("Only precision 5", test_specs(1, 0, 0, 0, 5, 'c'), 'J', "J");
	char_converter_test("Only min-field-width 100", test_specs(1, 0, 0, 100, -1, 'c'), 'J', "                                                                                                   J");
	char_converter_test("Zero padded min-field-width 5", test_specs(1, 1, 0, 5, -1, 'c'), 'J', "0000J");
	char_converter_test("Zero padded, min-field-width 5, precision 3", test_specs(1, 1, 0, 5, 3, 'c'), 'J', "0000J");
	char_converter_test("Right padded min-field-width 5", test_specs(1, 0, 1, 5, -1, 'c'), 'J', "J    ");
	char_converter_test("Right & zero padded min-field-width 5", test_specs(1, 1, 1, 5, -1, 'c'), 'J', "J    ");
	printf("\\\\\\ Specs percentage converter "UNDER"(char function)"RESET" ///\n");
	char_converter_test("No specs", test_specs(1, 0, 0, 0, -1, 'c'), '%', "%");
	char_converter_test("Only min-field-width 5", test_specs(1, 0, 0, 5, -1, 'c'), '%', "    %");
	char_converter_test("Only precision 5", test_specs(1, 0, 0, 0, 5, 'c'), '%', "%");
	char_converter_test("Only min-field-width 100", test_specs(1, 0, 0, 100, -1, 'c'), '%', "                                                                                                   %");
	char_converter_test("Zero padded min-field-width 5", test_specs(1, 1, 0, 5, -1, 'c'), '%', "0000%");
	char_converter_test("Zero padded, min-field-width 5, precision 3", test_specs(1, 1, 0, 5, 3, 'c'), '%', "0000%");
	char_converter_test("Right padded min-field-width 5", test_specs(1, 0, 1, 5, -1, 'c'), '%', "%    ");
	char_converter_test("Right & zero padded min-field-width 5", test_specs(1, 1, 1, 5, -1, 'c'), '%', "%    ");

	return (1);
}
