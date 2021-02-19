#!/bin/bash

gcc -Wall -Wextra -fsanitize=address -o str_converter_spec spec_utils.c ../srcs/converters/*.c str_converter_spec.c -I. -I../srcs/headers -I../srcs/libft/headers -L../srcs/libft -lft && ./str_converter_spec
