#!/bin/bash

NAME=c_lexer
TEST=cpptmp.c

LEXER=src/${NAME}.l;
CPP=bin/${NAME}.cpp;
EXE=bin/${NAME}

cd ..
cd ..
#flex -o ${CPP} ${LEXER}
#g++ ${CPP} -o ${EXE}
cat test/c_lexer/${TEST} | ./${EXE} > test/c_lexer/out.txt