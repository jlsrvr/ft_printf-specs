#!/bin/bash

gcc -Wall -Wextra -o ptn_converter_spec spec_utils.c ../srcs/printf_utils.c ../srcs/string_writer.c ../srcs/converters/ptn_converter.c ptn_converter_spec.c -I. -I../srcs/headers -I../srcs/libft/headers -L../srcs/libft -lft && valgrind ./ptn_converter_spec