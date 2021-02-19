#ifndef SPEC_H
# define SPEC_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "libftprintf.h"

# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define PINK	"\e[35m"
# define CYAN	"\e[36m"
# define BOLD	"\e[1m"
# define UNDER	"\e[4m"
# define BLINK	"\e[5m"
# define RESET  "\e[0m"

t_specs test_specs(int zero_pad, int right_pad, int min_f_width, int precision);
void    check_spec_result(char *result, char * expected);
#endif
