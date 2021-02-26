#!/bin/bash
gcc -Wall -Wextra -o ptn_converter_spec spec_utils.c ../srcs/utils/*.c ../srcs/string_writer.c ../srcs/converters/ptn_converter.c ptn_converter_spec.c -I. -I../srcs/headers && valgrind ./ptn_converter_spec
rm -rf ptn_converter_spec ptn_converter_spec.dSYM/
