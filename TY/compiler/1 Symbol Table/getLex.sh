#! /bin/bash
lex "$1"
gcc lex.yy.c -lfl 
