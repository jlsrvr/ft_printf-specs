#!/bin/bash

gcc -Wall -Wextra -o conversion_parser_spec spec_utils.c ../srcs/conversion_parser.c ../srcs/printf_utils.c conversion_parser_spec.c -I. -I../srcs/headers -I../srcs/libft/headers -L../srcs/libft -lft && valgrind ./conversion_parser_spec
