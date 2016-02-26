bin/c_parser:
	flex -o bin/c_lexer.yy.cpp src/c_lexer.l
	bison -d src/c_parser.y -o bin/c_parser.tab.c
	g++ bin/c_parser.tab.c bin/c_lexer.yy.cpp -o bin/c_parser


clean:
	rm -f bin/c_lexer.yy.cpp bin/c_parser.tab.c bin/c_parser.tab.h bin/c_parser bin/c_parser.exe