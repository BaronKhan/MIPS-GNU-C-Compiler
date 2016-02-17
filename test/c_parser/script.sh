#!/bin/bash

NAME=c_parser
TEST=prog4.c

LEXER=${NAME}.l;
CPP=${NAME}.cpp;
EXE=${NAME}

flex -o c_lexer.yy.cpp c_lexer.l
bison -d c_parser.y
g++ c_parser.tab.c c_lexer.yy.cpp -o c_parser

cat ${TEST} | ./${EXE}