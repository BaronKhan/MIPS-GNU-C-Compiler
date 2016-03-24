bin/c_compiler: src/c_lexer src/c_parser
	g++ src/c_parser.tab.cpp src/c_lexer.yy.cpp src/c_ast.cpp src/c_expr.cpp src/c_codegen.cpp -o bin/c_compiler

src/c_parser: src/c_lexer
	bison -d src/c_parser.y -o src/c_parser.tab.cpp

src/c_lexer:
	flex -o src/c_lexer.yy.cpp src/c_lexer.l

clean:
	rm -f src/c_lexer.yy.cpp src/c_parser.tab.cpp src/c_parser.tab.hpp bin/c_compiler bin/c_compiler.exe
