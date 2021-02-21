#!/bin/bash

gcc -Wall -Wextra -fsanitize=address -o char_converter_spec spec_utils.c ../srcs/converters/*.c char_converter_spec.c -I. -I../srcs/headers -I../srcs/libft/headers -L../srcs/libft -lft && ./char_converter_spec
