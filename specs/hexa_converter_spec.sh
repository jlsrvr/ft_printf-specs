#!/bin/bash
gcc -Wall -Wextra -o hexa_converter_spec spec_utils.c ../srcs/utils/*.c ../srcs/string_writer.c ../srcs/converters/*.c hexa_converter_spec.c -I. -I../srcs/headers && valgrind ./hexa_converter_spec
rm -rf hexa_converter_spec hexa_converter_spec.dSYM/
