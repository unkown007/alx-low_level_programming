#!/bin/bash
gcc -Wall -Werror -Wextra -pedantic -std=c99 -shared -Wl,-soname,all -o liball.so -fPIC *.c
