#!/bin/bash
gcc -Wall -Wextra -o string_writer_spec spec_utils.c ../srcs/string_writer.c ../srcs/utils/*c string_writer_spec.c -I. -I../srcs/headers && valgrind ./string_writer_spec
rm -rf string_writer_spec string_writer_spec.dSYM/
