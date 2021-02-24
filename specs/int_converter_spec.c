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

static void int_converter_test(char *describe, t_specs my_specs, unsigned int my_int, char *expected)
{
	char *result;

	printf("<==== %s ====>\n", describe);
	result = int_converter(my_specs, my_int);
	check_result(result, expected);
	free(result);
	return ;
}

int main(void)
{
	char *expected;
	int my_int;
	printf("\\\\\\ Specs int converter ///\n");
	printf(UNDER"### Negative int ###\n"RESET);
	my_int = -53;
	expected = "-53";
	int_converter_test("No specs", test_specs(1, 0, 0, 0, -1, 'i'), my_int, expected);
	int_converter_test("Only precision 0", test_specs(1, 0, 0, 0, 0, 'i'), my_int, expected);
	expected = "-00053";
	int_converter_test("Only precision 5", test_specs(1, 0, 0, 0, 5, 'i'), my_int, expected);
	expected = "-00053";
	int_converter_test("Zero-padded, precision 5", test_specs(1, 1, 0, 0, 5, 'i'), my_int, expected);
	expected = "  -53";
	int_converter_test("Only min-field-width 5", test_specs(1, 0, 0, 5, -1, 'i'), my_int, expected);
	expected = " -0000000053";
	int_converter_test("Min-field-width 12, precision 10", test_specs(1, 0, 0, 12, 10, 'i'), my_int, expected);
	expected = " -0000000053";
	int_converter_test("Zero_padded, min-field-width 12, precision 10", test_specs(1, 1, 0, 12, 10, 'i'), my_int, expected);
	expected = "-0000000053 ";
	int_converter_test("Right-padded, min-field-width 12, precision 10", test_specs(1, 1, 1, 12, 10, 'i'), my_int, expected);
	expected = "-0053";
	int_converter_test("Zero-padded, min-field-width 5", test_specs(1, 1, 0, 5, -1, 'i'), my_int, expected);
	expected = "-00053    ";
	int_converter_test("Right-padded, min-field-width 10, precision 5", test_specs(1, 0, 1, 10, 5, 'i'), my_int, expected);
	expected = "-0000000053 ";
	int_converter_test("Right-padded, min-field-width 12, precision 10", test_specs(1, 0, 1, 12, 10, 'i'), my_int, expected);
	expected = "-000053                  ";
	int_converter_test("Right & zero padded, min-field-width 25, precision 6", test_specs(1, 1, 1, 25, 6, 'i'), my_int, expected);
	printf(UNDER"### Positive int ###\n"RESET);
	my_int = 53;
	expected = "53";
	int_converter_test("No specs", test_specs(1, 0, 0, 0, -1, 'i'), my_int, expected);
	int_converter_test("Only precision 0", test_specs(1, 0, 0, 0, 0, 'i'), my_int, expected);
	expected = "00053";
	int_converter_test("Only precision 5", test_specs(1, 0, 0, 0, 5, 'i'), my_int, expected);
	expected = "   53";
	int_converter_test("Only min-field-width 5", test_specs(1, 0, 0, 5, -1, 'i'), my_int, expected);
	expected = "00053";
	int_converter_test("Zero-padded, min-field-width 5", test_specs(1, 1, 0, 5, -1, 'i'), my_int, expected);
	expected = "  0000000053";
	int_converter_test("min-field-width 12, precision 10", test_specs(1, 0, 0, 12, 10, 'i'), my_int, expected);
	expected = "  0000000053";
	int_converter_test("Zero-padded, min-field-width 12, precision 10", test_specs(1, 1, 0, 12, 10, 'i'), my_int, expected);
	expected = "0000000053  ";
	int_converter_test("Right-padded, min-field-width 12, precision 10", test_specs(1, 0, 1, 12, 10, 'i'), my_int, expected);
	expected = "0000000053  ";
	int_converter_test("Right-padded, min-field-width 12, precision 10", test_specs(1, 0, 1, 12, 10, 'i'), my_int, expected);
	expected = "00053     ";
	int_converter_test("Right-padded, min-field-width 10, precision 5", test_specs(1, 0, 1, 10, 5, 'i'), my_int, expected);
	printf(UNDER"### Zero int ###\n"RESET);
	my_int = 0;
	expected = "0";
	int_converter_test("No specs", test_specs(1, 0, 0, 0, -1, 'i'), my_int, expected);
	expected = "";
	int_converter_test("Only precision 0", test_specs(1, 0, 0, 0, 0, 'i'), my_int, expected);
	expected = "00000";
	int_converter_test("Only precision 5", test_specs(1, 0, 0, 0, 5, 'i'), my_int, expected);
	expected = "    0";
	int_converter_test("Only min-field-width 5", test_specs(1, 0, 0, 5, -1, 'i'), my_int, expected);
	expected = "00000";
	int_converter_test("Zero-padded, min-field-width 5", test_specs(1, 1, 0, 5, -1, 'i'), my_int, expected);
	expected = "  0000000000";
	int_converter_test("min-field-width 12, precision 10", test_specs(1, 0, 0, 12, 10, 'i'), my_int, expected);
	expected = "  0000000000";
	int_converter_test("Zero-padded, min-field-width 12, precision 10", test_specs(1, 1, 0, 12, 10, 'i'), my_int, expected);
	expected = "0000000000  ";
	int_converter_test("Right-padded, min-field-width 12, precision 10", test_specs(1, 0, 1, 12, 10, 'i'), my_int, expected);
	expected = "0000000000  ";
	int_converter_test("Right-padded, min-field-width 12, precision 10", test_specs(1, 0, 1, 12, 10, 'i'), my_int, expected);
	expected = "00000     ";
	int_converter_test("Right-padded, min-field-width 10, precision 5", test_specs(1, 0, 1, 10, 5, 'i'), my_int, expected);
	printf(UNDER"### Decimal 10 in octal ###\n"RESET);
	my_int = 012;
	expected = "10";
	int_converter_test("No specs", test_specs(1, 0, 0, 0, -1, 'i'), my_int, expected);
	expected = "10";
	int_converter_test("Only precision 0", test_specs(1, 0, 0, 0, 0, 'i'), my_int, expected);
	expected = "00010";
	int_converter_test("Only precision 5", test_specs(1, 0, 0, 0, 5, 'i'), my_int, expected);
	expected = "   10";
	int_converter_test("Only min-field-width 5", test_specs(1, 0, 0, 5, -1, 'i'), my_int, expected);
	expected = "00010";
	int_converter_test("Zero-padded, min-field-width 5", test_specs(1, 1, 0, 5, -1, 'i'), my_int, expected);
	expected = "  0000000010";
	int_converter_test("min-field-width 12, precision 10", test_specs(1, 0, 0, 12, 10, 'i'), my_int, expected);
	expected = "  0000000010";
	int_converter_test("Zero-padded, min-field-width 12, precision 10", test_specs(1, 1, 0, 12, 10, 'i'), my_int, expected);
	expected = "0000000010  ";
	int_converter_test("Right-padded, min-field-width 12, precision 10", test_specs(1, 0, 1, 12, 10, 'i'), my_int, expected);
	expected = "0000000010  ";
	int_converter_test("Right-padded, min-field-width 12, precision 10", test_specs(1, 0, 1, 12, 10, 'i'), my_int, expected);
	expected = "00010     ";
	int_converter_test("Right-padded, min-field-width 10, precision 5", test_specs(1, 0, 1, 10, 5, 'i'), my_int, expected);
	printf(UNDER"### Int min ###\n"RESET);
	my_int = -2147483648;
	expected = "-2147483648";
	int_converter_test("No specs", test_specs(1, 0, 0, 0, -1, 'i'), my_int, expected);
	int_converter_test("Only precision 0", test_specs(1, 0, 0, 0, 0, 'i'), my_int, expected);
	expected = "-2147483648";
	int_converter_test("Only precision 5", test_specs(1, 0, 0, 0, 5, 'i'), my_int, expected);
	expected = "-2147483648";
	int_converter_test("Zero-padded, precision 5", test_specs(1, 1, 0, 0, 5, 'i'), my_int, expected);
	expected = "-2147483648";
	int_converter_test("Only min-field-width 5", test_specs(1, 0, 0, 5, -1, 'i'), my_int, expected);
	expected = " -2147483648";
	int_converter_test("Min-field-width 12, precision 10", test_specs(1, 0, 0, 12, 10, 'i'), my_int, expected);
	expected = " -2147483648";
	int_converter_test("Zero_padded, min-field-width 12, precision 10", test_specs(1, 1, 0, 12, 10, 'i'), my_int, expected);
	expected = "-2147483648 ";
	int_converter_test("Right-padded, min-field-width 12, precision 10", test_specs(1, 1, 1, 12, 10, 'i'), my_int, expected);
	expected = "-2147483648";
	int_converter_test("Zero-padded, min-field-width 5", test_specs(1, 1, 0, 5, -1, 'i'), my_int, expected);
	expected = "-2147483648";
	int_converter_test("Right-padded, min-field-width 10, precision 5", test_specs(1, 0, 1, 10, 5, 'i'), my_int, expected);
	expected = "-2147483648 ";
	int_converter_test("Right-padded, min-field-width 12, precision 10", test_specs(1, 0, 1, 12, 10, 'i'), my_int, expected);
	expected = "-2147483648              ";
	int_converter_test("Right & zero padded, min-field-width 25, precision 6", test_specs(1, 1, 1, 25, 10, 'i'), my_int, expected);
	int_converter_test("Precision 0, min-f-width 5, my_int = 0", test_specs(1, 0, 0, 5, 0, 'i'), my_int, expected);*/

	return (1);
}
