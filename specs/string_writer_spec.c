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

static void string_writer_test(char *describe, char **dest, char *to_add, char *expected)
{
	printf("<==== %s ====>\n", describe);
	string_writer(dest, to_add);
	check_result(*dest, expected);
	free(*dest);
	return ;
}

int main(void)
{
	printf("\\\\\\ Specs string_writer function  ///\n");
	char *dest;

	dest = ft_strdup("");
	string_writer_test("Empty dest", &dest, ft_strdup("added"), "added");
	dest = ft_strdup("start");
	string_writer_test("Joining two strings", &dest, ft_strdup("finish"), "startfinish");
	dest = ft_strdup("start");
	string_writer_test("Empty add", &dest, ft_strdup(""), "start");
	dest = NULL;
	string_writer_test("NULL dest", &dest, ft_strdup("added"), "added");

	return (1);
}
