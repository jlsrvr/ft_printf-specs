#!/bin/bash

gcc -Wall -Wextra -o string_parser_spec spec_utils.c ../srcs/string_parser.c ../srcs/conversion_parser.c ../srcs/converting_function.c ../srcs/printf_utils.c ../srcs/converters/*.c ../srcs/string_writer.c string_parser_spec.c -I. -I../srcs/headers -I../srcs/libft/headers -L../srcs/libft -lft && valgrind ./string_parser_spec
