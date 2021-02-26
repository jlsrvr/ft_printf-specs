#!/bin/bash
gcc -Wall -Wextra -o base_converter_spec spec_utils.c ../srcs/utils/*.c ../srcs/string_writer.c ../srcs/converters/base_converter.c base_converter_spec.c -I. -I../srcs/headers && valgrind ./base_converter_spec
rm -rf base_converter_spec base_converter_spec.dSYM/
