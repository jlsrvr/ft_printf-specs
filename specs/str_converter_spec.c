#include "spec.h"

static void str_converter_test(char *describe, t_specs my_specs, char *str, char *expected)
{
	char *result;

	printf("<==== %s ====>\n", describe);
	result = str_converter(my_specs, str);
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
	printf("\\\\\\ Specs str converter ///\n");
	str_converter_test("No specs", test_specs(1, 0, 0, 0, -1, 's'), "Toto", "Toto");
	str_converter_test("No specs and NULL", test_specs(1, 0, 0, 0, -1, 's'), NULL, "(null)");
	str_converter_test("Min-field-width and NULL", test_specs(1, 0, 0, 10, -1, 's'), NULL, "    (null)");
	str_converter_test("Only min-field-width 5", test_specs(1, 0, 0, 5, -1, 's'), "to", "   to");
	str_converter_test("Right-padded, min-field-width 5", test_specs(1, 0, 1, 5, -1, 's'), "to", "to   ");
	str_converter_test("Right & zero padded, min-field-width 5", test_specs(1, 1, 1, 5, -1, 's'), "to", "to   ");
	str_converter_test("Right-padded, min-field-width 3, word 5", test_specs(1, 0, 1, 5, -1, 's'), "12345", "12345");
	str_converter_test("Zero-padded min-field-width 5", test_specs(1, 1, 0, 5, -1, 's'), "to", "000to");
	str_converter_test("Zero-padded min-field-width 3, word 5", test_specs(1, 1, 0, 3, -1, 's'), "12345", "12345");
	str_converter_test("Only min-field-width 10", test_specs(1, 0, 0, 10, -1, 's'), "to", "        to");
	str_converter_test("Only min-field-width 5 word 10", test_specs(1, 0, 0, 10, -1, 's'), "1234567890", "1234567890");
	str_converter_test("Only precision 5, word 10", test_specs(1, 0, 0, 0, 5, 's'), "1234567890", "12345");
	str_converter_test("Zero-padded & precision 5, word 10", test_specs(1, 1, 0, 0, 5, 's'), "1234567890", "12345");
	str_converter_test("Right-padded & precision 5, word 10", test_specs(1, 0, 1, 0, 5, 's'), "1234567890", "12345");
	str_converter_test("Only precision 10, word 5", test_specs(1, 0, 0, 0, 10, 's'), "12345", "12345");
	str_converter_test("Precision 5, min-field-width 10, word 6", test_specs(1, 0, 0, 10, 5, 's'), "123456", "     12345");
	str_converter_test("zero-padded, precision 5, min-field-width 10, word 6", test_specs(1, 1, 0, 10, 5, 's'), "123456", "0000012345");
	str_converter_test("zero-padded, precision 11, min-field-width 10, word 6", test_specs(1, 1, 0, 10, 11, 's'), "123456", "0000123456");
	str_converter_test("precision 0, word 6", test_specs(1, 0, 0, 0, 0, 's'), "123456", "");
	str_converter_test("right-padded, precision 5, min-field-width 10, word 6", test_specs(1, 0, 1, 10, 5, 's'), "123456", "12345     ");
	str_converter_test("right-padded, precision 11, min-field-width 10, word 6", test_specs(1, 0, 1, 10, 11, 's'), "123456", "123456    ");
	str_converter_test("zero-padded, precision 0, min-field-width 10, word 6", test_specs(1, 1, 0, 10, 0, 's'), "123456", "0000000000");

	return (1);
}
