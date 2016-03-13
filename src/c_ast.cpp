#include "c_ast.hpp"
#include <iostream>

//ENVIRONMENT
Environment::Environment() {
	symbol_fp_offset = 8;	//starting postion on the stack relative to frame pointer (offset)
}

void Environment::addSymbol(std::string name) {
	symbol_table[name] = symbol_fp_offset;		//{variable, fp offset}
	symbol_fp_offset+=4;
}

void Environment::addParameter(std::string name) {
	symbol_table[name] = scope_start+(param_index*4);		//{variable, fp offset}
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
}



Type_Node::Type_Node(char* n, Node* next) {
	node_type = NODE_TYPE;
	type_name = n;
	type_next = next;
}




Op_Node::Op_Node(char* o) {
	node_type = NODE_OP;
	op = o;
}


Expr_Node::Expr_Node(Node* l, Op_Node* oper, Node* r) {
	node_type = NODE_EXPR;
	lhs = l;
	op = oper;
	rhs = r;
	is_negative = false;
}

Decl_Node::Decl_Node(Type_Node* t, ID_Node* i, bool has, Node* v, Node* n) {
	type = t;
	id = i;
	has_value = has;
	value = v;
	next = n;
}

Assignment_Node::Assignment_Node(Node* iden, Op_Node* oper, Node* v) {
	node_type = NODE_ASSIGNMENT;
	id = iden;
	op = oper;
	value = v;
	
}

ExprStatement_Node::ExprStatement_Node(Node* e) {
	expr = e;
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



