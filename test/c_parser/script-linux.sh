#!/bin/bash
NAME=c_lexer 
TEST=cpptmp.c
LEXER=${NAME}.l;
CPP=${NAME}.cpp;
EXE=${NAME}

flex -o ${CPP} ${LEXER}
g++ ${CPP} -o ${EXE}
cat ${TEST} | ./${EXE} > tmpout.txt
