#!/bin/bash
gcc -Wall -Wextra -o unsigned_converter_spec spec_utils.c ../srcs/utils/*.c ../srcs/string_writer.c ../srcs/converters/*.c unsigned_converter_spec.c -I. -I../srcs/headers && valgrind ./unsigned_converter_spec
rm -rf unsigned_converter_spec unsigned_converter_spec.dSYM/
