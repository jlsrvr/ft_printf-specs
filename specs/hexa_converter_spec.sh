#!/bin/bash
gcc -Wall -Wextra -o hexa_converter_spec spec_utils.c ../srcs/printf_utils.c ../srcs/string_writer.c ../srcs/converters/*.c hexa_converter_spec.c -I. -I../srcs/headers -I../srcs/libft/headers -L../srcs/libft -lft && valgrind ./hexa_converter_spec
