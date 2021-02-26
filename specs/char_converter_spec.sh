#!/bin/bash
gcc -Wall -Wextra -fsanitize=address -o char_converter_spec spec_utils.c ../srcs/converters/char_converter.c char_converter_spec.c ../srcs/utils/*.c -I. -I../srcs/headers && ./char_converter_spec
rm char_converter_spec
