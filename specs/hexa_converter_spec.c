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
	result = hexa_converter(my_specs, my_int);
	check_result(result, expected);
	free(result);
	return ;
}

char    *base_10 = "0123456789";
int main(void)
{
	char *expected;
	intmax_t my_int;
	printf("\\\\\\ Specs hexa converter ///\n");
	printf(BLINK"### Small x int ###\n"RESET);
	printf(UNDER"### Negative int ###\n"RESET);
	my_int = -53;
	expected = "ffffffcb";
	base_converter_test("No specs", test_specs(1, 0, 0, 0, -1, 'x'), my_int, expected);
	base_converter_test("Only precision 0", test_specs(1, 0, 0, 0, 0, 'x'), my_int, expected);
	base_converter_test("Only precision 5", test_specs(1, 0, 0, 0, 5, 'x'), my_int, expected);
	expected = "            ffffffcb";
	base_converter_test("Only min-f-width 20", test_specs(1, 0, 0, 20, -1, 'x'), my_int, expected);
	expected = "     0000000ffffffcb";
	base_converter_test("min-f-width 20 and precision 15", test_specs(1, 0, 0, 20, 15, 'x'), my_int, expected);
	base_converter_test("Zero-pad, min-f-width 20 and precision 15", test_specs(1, 1, 0, 20, 15, 'x'), my_int, expected);
	expected = "0000000ffffffcb     ";
	base_converter_test("Right-pad, min-f-width 20 and precision 15", test_specs(1, 0, 1, 20, 15, 'x'), my_int, expected);
	expected = "0000000ffffffcb";
	base_converter_test("Only precision 15", test_specs(1, 0, 0, 0, 15, 'x'), my_int, expected);
	expected = "000000000000ffffffcb";
	base_converter_test("Zero-pad, min-f-width 20", test_specs(1, 1, 0, 20, -1, 'x'), my_int, expected);
	printf(UNDER"### More than max int ###\n"RESET);
	my_int = 12345654321234;
	expected = "72572052";
	base_converter_test("No specs", test_specs(1, 0, 0, 0, -1, 'x'), my_int, expected);
	printf(UNDER"### int 0 ###\n"RESET);
	my_int = 0;
	expected = "";
	base_converter_test("Precision 0", test_specs(1, 0, 0, 0, 0, 'x'), my_int, expected);
	printf(UNDER"### Positive int ###\n"RESET);
	my_int = 30;
	expected = "     00000000000001e";
	base_converter_test("min-f-width 20 and precision 15", test_specs(1, 0, 0, 20, 15, 'x'), my_int, expected);
	base_converter_test("Zero-pad, min-f-width 20 and precision 15", test_specs(1, 1, 0, 20, 15, 'x'), my_int, expected);
	printf(BLINK"### Big X int ###\n"RESET);
	printf(UNDER"### Negative int ###\n"RESET);
	my_int = -53;
	expected = "FFFFFFCB";
	base_converter_test("No specs", test_specs(1, 0, 0, 0, -1, 'X'), my_int, expected);
	base_converter_test("Only precision 0", test_specs(1, 0, 0, 0, 0, 'X'), my_int, expected);
	base_converter_test("Only precision 5", test_specs(1, 0, 0, 0, 5, 'X'), my_int, expected);
	expected = "            FFFFFFCB";
	base_converter_test("Only min-f-width 20", test_specs(1, 0, 0, 20, -1, 'X'), my_int, expected);
	expected = "     0000000FFFFFFCB";
	base_converter_test("min-f-width 20 and precision 15", test_specs(1, 0, 0, 20, 15, 'X'), my_int, expected);
	base_converter_test("Zero-pad, min-f-width 20 and precision 15", test_specs(1, 1, 0, 20, 15, 'X'), my_int, expected);
	expected = "0000000FFFFFFCB     ";
	base_converter_test("Right-pad, min-f-width 20 and precision 15", test_specs(1, 0, 1, 20, 15, 'X'), my_int, expected);
	expected = "0000000FFFFFFCB";
	base_converter_test("Only precision 15", test_specs(1, 0, 0, 0, 15, 'X'), my_int, expected);
	expected = "000000000000FFFFFFCB";
	base_converter_test("Zero-pad, min-f-width 20", test_specs(1, 1, 0, 20, -1, 'X'), my_int, expected);
	printf(UNDER"### More than max int ###\n"RESET);
	my_int = 12345654321234;
	expected = "72572052";
	base_converter_test("No specs", test_specs(1, 0, 0, 0, -1, 'X'), my_int, expected);
	printf(UNDER"### int 0 ###\n"RESET);
	my_int = 0;
	expected = "";
	base_converter_test("Precision 0", test_specs(1, 0, 0, 0, 0, 'X'), my_int, expected);
	printf(UNDER"### Positive int ###\n"RESET);
	my_int = 30;
	expected = "     00000000000001E";
	base_converter_test("min-f-width 20 and precision 15", test_specs(1, 0, 0, 20, 15, 'X'), my_int, expected);
	base_converter_test("Zero-pad, min-f-width 20 and precision 15", test_specs(1, 1, 0, 20, 15, 'X'), my_int, expected);

	return (1);
}
