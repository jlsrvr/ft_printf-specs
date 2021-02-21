#!/bin/bash

gcc -Wall -Wextra -o string_writer_spec spec_utils.c ../srcs/string_writer.c string_writer_spec.c -I. -I../srcs/headers -I../srcs/libft/headers -L../srcs/libft -lft && valgrind ./string_writer_spec
