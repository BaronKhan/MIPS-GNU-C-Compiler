bin/c_lexer:
	flex -o bin/c_lexer.yy.cpp src/c_lexer.l
	g++ bin/c_lexer.yy.cpp -o bin/c_lexer

clean:
	rm -f bin/c_lexer.yy.cpp bin/c_parser bin/c_parser.exe