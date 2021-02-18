#!/bin/bash

gcc -Wall -Wextra -fsanitize=address -o converter_spec ../srcs/converters/*.c converter_spec.c -I. -I../srcs/headers && ./converter_spec
