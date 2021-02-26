#!/bin/bash

gcc -Wall -Wextra -fsanitize=address -o str_converter_spec spec_utils.c ../srcs/utils/*.c ../srcs/converters/str_converter.c str_converter_spec.c -I. -I../srcs/headers && ./str_converter_spec
rm -rf str_converter_spec str_converter_spec.dSYM/
