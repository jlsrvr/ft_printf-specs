#!/bin/bash
gcc -Wall -Wextra -o conversion_parser_spec spec_utils.c ../srcs/conversion_parser.c ../srcs/utils/*.c conversion_parser_spec.c -I. -I../srcs/headers && valgrind ./conversion_parser_spec
rm -rf conversion_parser_spec conversion_parser_spec.dSYM/
