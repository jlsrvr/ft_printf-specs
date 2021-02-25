#!/bin/bash

gcc -Wall -Wextra -o signed_converter_spec spec_utils.c ../srcs/printf_utils.c ../srcs/string_writer.c ../srcs/converters/*.c signed_converter_spec.c -I. -I../srcs/headers -I../srcs/libft/headers -L../srcs/libft -lft && valgrind ./signed_converter_spec
