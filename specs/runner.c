//#include "libftprintf.a"
#include "spec.h"
#include <stdarg.h>

int main(int ac, char **av)
{
	(void)ac;
	(void)av;

	char *str = "string";
	int dec = 123;
	//int	oct = 0172; //octal equivalent of decimal 10
    /*int a, b, c;

    printf("Enter value of a in decimal format:");
    scanf("%d", &a);

    printf("Enter value of b in octal format: ");
    scanf("%i", &b);

    printf("Enter value of c in hexadecimal format: ");
    scanf("%i", &c);

    printf("a = %d, b = %d, c = %d", a, b, c);*/
	dec = printf("[%010s]", str);
	printf("%d", dec);
	//printf("[%.*s]", -3, str);
	//printf("[%5d]", dec);
	//printf("[%x]", dec);
	//printf("[%0-10s]", str);
	/*void (*parts[5])(char **argv);
	parts[4] = 0;

	int selected;

	if (ac > 1)
	{
		selected = (atoi(av[1]) - 1);
		(*parts[selected])(&(av[2]));
		return (0);
	}
	for (selected = 0; parts[selected]; selected++)
		(*parts[selected])(av);*/
	return (0);
}
