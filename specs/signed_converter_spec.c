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

static void base_converter_test(char *describe, t_specs my_specs, int my_int, char *expected)
{
	char *result;

	printf("<==== %s ====>\n", describe);
	result = signed_converter(my_specs, my_int);
	check_result(result, expected);
	free(result);
	return ;
}

char    *base_10 = "0123456789";
int main(void)
{
	char *expected;
	intmax_t my_int;
	printf("\\\\\\ Specs unsigned converter ///\n");
	printf(BLINK"### using i flag ###\n"RESET);
	printf(UNDER"### Negative int ###\n"RESET);
	my_int = -53;
	expected = "-53";
	base_converter_test("No specs", test_specs(1, 0, 0, 0, -1, 'i'), my_int, expected);
	base_converter_test("Only precision 0", test_specs(1, 0, 0, 0, 0, 'i'), my_int, expected);
	expected = "  -53";
	base_converter_test("Only min-f-width 5", test_specs(1, 0, 0, 5, -1, 'i'), my_int, expected);
	expected = " -00053";
	base_converter_test("min-f-width 7 and precision 5", test_specs(1, 0, 0, 7, 5, 'i'), my_int, expected);
	base_converter_test("Zero-pad, min-f-width 7 and precision 5", test_specs(1, 1, 0, 7, 5, 'i'), my_int, expected);
	expected = "-00053 ";
	base_converter_test("Right-pad, min-f-width 7 and precision 5", test_specs(1, 0, 1, 7, 5, 'i'), my_int, expected);
	expected = "-00053";
	base_converter_test("Only precision 5", test_specs(1, 0, 0, 0, 5, 'i'), my_int, expected);
	expected = "-000000053";
	base_converter_test("Zero-pad, min-f-width 10", test_specs(1, 1, 0, 10, -1, 'i'), my_int, expected);
	printf(UNDER"### Positive int ###\n"RESET);
	my_int = 53;
	expected = "53";
	base_converter_test("No specs", test_specs(1, 0, 0, 0, -1, 'i'), my_int, expected);
	base_converter_test("Only precision 0", test_specs(1, 0, 0, 0, 0, 'i'), my_int, expected);
	expected = "   53";
	base_converter_test("Only min-f-width 5", test_specs(1, 0, 0, 5, -1, 'i'), my_int, expected);
	expected = "  00053";
	base_converter_test("min-f-width 7 and precision 5", test_specs(1, 0, 0, 7, 5, 'i'), my_int, expected);
	base_converter_test("Zero-pad, min-f-width 7 and precision 5", test_specs(1, 1, 0, 7, 5, 'i'), my_int, expected);
	expected = "00053  ";
	base_converter_test("Right-pad, min-f-width 7 and precision 5", test_specs(1, 0, 1, 7, 5, 'i'), my_int, expected);
	expected = "00053";
	base_converter_test("Only precision 5", test_specs(1, 0, 0, 0, 5, 'i'), my_int, expected);
	expected = "0000000053";
	base_converter_test("Zero-pad, min-f-width 10", test_specs(1, 1, 0, 10, -1, 'i'), my_int, expected);
	printf(UNDER"### More than max int ###\n"RESET);
	my_int = 12345654321234;
	expected = "1918312530";
	base_converter_test("No specs", test_specs(1, 0, 0, 0, -1, 'i'), my_int, expected);
	printf(UNDER"### 0 ###\n"RESET);
	my_int = 0;
	expected = "";
	base_converter_test("Precision 0", test_specs(1, 0, 0, 0, 0, 'u'), my_int, expected);

	printf(BLINK"### using d flag ###\n"RESET);
	printf(UNDER"### Negative int ###\n"RESET);
	my_int = -53;
	expected = "-53";
	base_converter_test("No specs", test_specs(1, 0, 0, 0, -1, 'd'), my_int, expected);
	base_converter_test("Only precision 0", test_specs(1, 0, 0, 0, 0, 'd'), my_int, expected);
	expected = "  -53";
	base_converter_test("Only min-f-width 5", test_specs(1, 0, 0, 5, -1, 'd'), my_int, expected);
	expected = " -00053";
	base_converter_test("min-f-width 7 and precision 5", test_specs(1, 0, 0, 7, 5, 'd'), my_int, expected);
	base_converter_test("Zero-pad, min-f-width 7 and precision 5", test_specs(1, 1, 0, 7, 5, 'd'), my_int, expected);
	expected = "-00053 ";
	base_converter_test("Right-pad, min-f-width 7 and precision 5", test_specs(1, 0, 1, 7, 5, 'd'), my_int, expected);
	expected = "-00053";
	base_converter_test("Only precision 5", test_specs(1, 0, 0, 0, 5, 'd'), my_int, expected);
	expected = "-000000053";
	base_converter_test("Zero-pad, min-f-width 10", test_specs(1, 1, 0, 10, -1, 'd'), my_int, expected);
	printf(UNDER"### Positive int ###\n"RESET);
	my_int = 53;
	expected = "53";
	base_converter_test("No specs", test_specs(1, 0, 0, 0, -1, 'd'), my_int, expected);
	base_converter_test("Only precision 0", test_specs(1, 0, 0, 0, 0, 'd'), my_int, expected);
	expected = "   53";
	base_converter_test("Only min-f-width 5", test_specs(1, 0, 0, 5, -1, 'd'), my_int, expected);
	expected = "  00053";
	base_converter_test("min-f-width 7 and precision 5", test_specs(1, 0, 0, 7, 5, 'd'), my_int, expected);
	base_converter_test("Zero-pad, min-f-width 7 and precision 5", test_specs(1, 1, 0, 7, 5, 'd'), my_int, expected);
	expected = "00053  ";
	base_converter_test("Right-pad, min-f-width 7 and precision 5", test_specs(1, 0, 1, 7, 5, 'd'), my_int, expected);
	expected = "00053";
	base_converter_test("Only precision 5", test_specs(1, 0, 0, 0, 5, 'd'), my_int, expected);
	expected = "0000000053";
	base_converter_test("Zero-pad, min-f-width 10", test_specs(1, 1, 0, 10, -1, 'd'), my_int, expected);
	printf(UNDER"### More than max int ###\n"RESET);
	my_int = 12345654321234;
	expected = "1918312530";
	base_converter_test("No specs", test_specs(1, 0, 0, 0, -1, 'd'), my_int, expected);
	printf(UNDER"### 0 ###\n"RESET);
	my_int = 0;
	expected = "";
	base_converter_test("Precision 0", test_specs(1, 0, 0, 0, 0, 'u'), my_int, expected);
	return (1);
}
