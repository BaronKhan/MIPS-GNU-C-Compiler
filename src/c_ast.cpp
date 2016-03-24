#include "c_ast.hpp"
#include <iostream>

//ENVIRONMENT
Environment::Environment() {
	symbol_fp_offset = 4;	//starting postion on the stack relative to frame pointer (offset)
	if_count = 0;
	label_count = 2;	//start at L2
	scope_start = 16;
	arg_count = 0;
	global_variable_count = 0;
}

void Environment::addSymbol(std::string name) {
	symbol_table[name] = symbol_fp_offset;		//{variable, fp offset}
	symbol_fp_offset+=4;
}

void Environment::addArraySymbol(std::string name, int n) {
	symbol_table[name] = symbol_fp_offset;		//{variable, fp offset}
	symbol_fp_offset+=4*n;
}

bool Environment::findSymbol(const std::string name) const {
	if (symbol_table.find(name)  != symbol_table.end()) {
		return true;
	}
	return false;
}

void Environment::addParameter(std::string name) {
	symbol_table[name] = scope_start-16+(param_index*4);		//{variable, fp offset}
}

void Environment::saveTable(int& old_offset, std::map<std::string, int>& old_table) const {
	old_table = symbol_table;
	old_offset = symbol_fp_offset;
}

void Environment::restoreTable(const int& old_offset, const std::map<std::string, int>& old_table) {
	symbol_table = old_table;
	symbol_fp_offset = old_offset;
}

void Environment::printTable() const {
	std::cout << "#symbol table:" << std::endl;
	typedef std::map<std::string, int>::const_iterator it_type;
	for(it_type iterator = symbol_table.begin(); iterator != symbol_table.end(); iterator++) {
	    // iterator->first = key
	    // iterator->second = value
	    std::cerr << "#" << iterator->first << ": " << iterator->second << std::endl;
	}
	std::cout << "#-------------" << std::endl;
}

//NODES

IntConst_Node::IntConst_Node(int n) {
	node_type = NODE_INTCONST;
	value = n;
	is_negative = false;
}


FloatConst_Node::FloatConst_Node(double n) {
	node_type = NODE_FLOATCONST;
	value = n;
	is_negative = false;
}


String_Node::String_Node(char* s) {
	node_type = NODE_STRING;
	str = s;
}



ID_Node::ID_Node(char* iden) {
	node_type = NODE_ID;
	name = iden;
	is_negative = false;
	array_offset = NULL;
}



Type_Node::Type_Node(char* n, Node* next) {
	node_type = NODE_TYPE;
	type_name = n;
	type_next = next;
}




Op_Node::Op_Node(char* o) {
	node_type = NODE_OP;
	op = o;
	op_prefix = "";
}

Op_Node::Op_Node(char* o, std::string o2) {
	node_type = NODE_OP;
	op = o;
	op_prefix = o2;
}


Expr_Node::Expr_Node(Node* l, Op_Node* oper, Node* r) {
	node_type = NODE_EXPR;
	lhs = l;
	op = oper;
	rhs = r;
	is_negative = false;
}


Ternary_Node::Ternary_Node(Node* e1, Node* e2, Node* e3) {
	node_type = NODE_TERNARY;
	expr1 = e1;
	expr2 = e2;
	expr3 = e3;
	is_negative = false;
}


Decl_Node::Decl_Node(Type_Node* t, ID_Node* i, bool has, Node* v, Node* n) {
	type = t;
	id = i;
	has_value = has;
	value = v;
	next = n;
	size = 1;
}

Decl_Node::Decl_Node(Type_Node* t, ID_Node* i, bool has, Node* v, Node* n, int s) {
	type = t;
	id = i;
	has_value = has;
	value = v;
	next = n;
	size = s;
}

Assignment_Node::Assignment_Node(Node* iden, Op_Node* oper, Node* v) {
	node_type = NODE_ASSIGNMENT;
	id = iden;
	op = oper;
	value = v;
	
}


Call_Node::Call_Node(Node* iden, Node* ar) {
	node_type = NODE_CALL;
	id = iden;
	args = ar;
	is_negative = false;
}

Argument_Node::Argument_Node(Node* v, Node* n) {
	value = v;
	next = n;
}

ExprStatement_Node::ExprStatement_Node(Node* e) {
	expr = e;
}


IfStatement_Node::IfStatement_Node(Node* e, Node* b, Node* eb) {
	expr = e;
	body = b;
	else_block = eb;
}


WhileStatement_Node::WhileStatement_Node(Node* e, Node* b) {
	expr = e;
	body = b;
}

DoWhileStatement_Node::DoWhileStatement_Node(Node* e, Node* b) {
	expr = e;
	body = b;
}


ForStatement_Node::ForStatement_Node(Node* e1, Node* e2, Node* e3, Node* b) {
	expr1 = e1;
	expr2 = e2;
	expr3 = e3;
	body = b;
}


ReturnStatement_Node::ReturnStatement_Node(Node* r) {
	return_expr = r;
}

Statement_Node::Statement_Node(Node* s) {
	statement = s;
}


Parameter_Node::Parameter_Node(Type_Node* t, ID_Node* iden, Node* n) {
	type = t;
	id = iden;
	next = n;
}


Function_Node::Function_Node(ID_Node* f, Parameter_Node* params, Node* b, int n) {
	f_name = f;
	parameters_start = params;
	blk = b;
	variable_count = n;
}


DeclStatement_Node::DeclStatement_Node(Type_Node* t, Node* start, bool p) {
	type = t;
	decl_start = start;
	pointer = p;
}


CompoundStatement_Node::CompoundStatement_Node(Node* start, Node* n) {
	comp_start = start;
	next = n;
}


Block_Node::Block_Node(Node* start) {
	block_start = start;
}



