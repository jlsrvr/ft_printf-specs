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

static void ptn_converter_test(char *describe, t_specs my_specs, unsigned int ptn, char *expected)
{
	char *result;

	printf("<==== %s ====>\n", describe);
	result = ptn_converter(my_specs, ptn);
	check_result(result, expected);
	free(result);
	return ;
}

int main(void)
{
	char *expected;
	unsigned int ptn;
	printf("\\\\\\ Specs ptn converter ///\n");
	ptn = 43060960;
	expected = "0x2910ee0";
	ptn_converter_test("No specs", test_specs(1, 0, 0, 0, -1, 'p'), ptn, expected);
	ptn_converter_test("Only precision 5", test_specs(1, 0, 0, 0, 5, 'p'), ptn, expected);
	ptn_converter_test("Only precision 0", test_specs(1, 0, 0, 0, 0, 'p'), ptn, expected);
	ptn_converter_test("Only min-field-width 5", test_specs(1, 0, 0, 5, -1, 'p'), ptn, expected);
	expected = "           0x2910ee0";
	ptn_converter_test("Only min-field-width 20", test_specs(1, 0, 0, 20, -1, 'p'), ptn, expected);
	expected = "0x2910ee0           ";
	ptn_converter_test("Right-padded, min-field-width 20", test_specs(1, 0, 1, 20, -1, 'p'), ptn, expected);
	expected = "0x000000000002910ee0";
	ptn_converter_test("Zero-padded, min-field-width 20", test_specs(1, 1, 0, 20, -1, 'p'), ptn, expected);
	expected = "0x2910ee0           ";
	ptn_converter_test("Right and zero padded, min-field-width 20", test_specs(1, 1, 1, 20, -1, 'p'), ptn, expected);
	expected = "0x2910ee0";
	ptn_converter_test("Right and zero padded, min-field-width 0", test_specs(1, 1, 1, 0, -1, 'p'), ptn, expected);
	ptn = 1234;
	expected = "0x0000004d2";
	ptn_converter_test("min-field-width 2, precision 9", test_specs(1, 0, 0, 2, 9, 'p'), ptn, expected);
	ptn = 0;
	expected = "0x0";
	ptn_converter_test("No specs ptn = 0", test_specs(1, 0, 0, 0, -1, 'p'), ptn, expected);
	expected = "  0x0";
	ptn_converter_test("Min-f-width 5, ptn = 0", test_specs(1, 0, 0, 5, -1, 'p'), ptn, expected);
	expected = "0x000";
	ptn_converter_test("Zero-padded, min-f-width 5, ptn = 0", test_specs(1, 1, 0, 5, -1, 'p'), ptn, expected);
	expected = "0x0  ";
	ptn_converter_test("Zero-padded, right-padded, min-f-width 5, ptn = 0", test_specs(1, 1, 1, 5, -1, 'p'), ptn, expected);
	expected = "  0x0";
	ptn_converter_test("Precision 1, min-f-width 5, ptn = 0", test_specs(1, 0, 0, 5, 1, 'p'), ptn, expected);
	expected = "0x00000";
	ptn_converter_test("Precision 5, ptn = 0", test_specs(1, 0, 0, 0, 5, 'p'), ptn, expected);
	expected = "   0x";
	ptn_converter_test("Precision 0, min-f-width 5, ptn = 0", test_specs(1, 0, 0, 5, 0, 'p'), ptn, expected);

	return (1);
}
