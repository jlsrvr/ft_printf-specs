#!/bin/bash

gcc -Wall -Wextra -o converting_function_spec spec_utils.c ../srcs/converting_function.c converting_function_spec.c -I. -I../srcs/headers -I../srcs/libft/headers -L../srcs/libft -lft && valgrind ./converting_function_spec
