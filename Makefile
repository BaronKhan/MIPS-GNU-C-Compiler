bin/c_codegen:
	bison -d src/c_parser.y -o src/c_parser.tab.cpp
	flex -o src/c_lexer.yy.cpp src/c_lexer.l
	g++ src/c_parser.tab.cpp src/c_lexer.yy.cpp src/c_ast.cpp src/c_codegen.cpp -o bin/c_codegen


clean:
	rm -f src/c_lexer.yy.cpp src/c_parser.tab.cpp src/c_parser.tab.hpp bin/c_codegen bin/c_codegen.exe