#!/bin/bash
gcc -Wall -Wextra -o signed_converter_spec spec_utils.c ../srcs/utils/*.c ../srcs/string_writer.c ../srcs/converters/*.c signed_converter_spec.c -I. -I../srcs/headers  && valgrind ./signed_converter_spec
rm -rf signed_converter_spec signed_converter_spec.dSYM/
