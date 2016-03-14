#ifndef C_AST_HPP_
#define C_AST_HPP_

#include <iostream>
#include <vector>
#include <map>

//define AST structures here

enum {
	NODE_ID = 1024,
	NODE_INTCONST,
	NODE_FLOATCONST,
	NODE_STRING,
	NODE_TYPE,
	NODE_COMPOUNDTYPE,
	NODE_DECL,
	NODE_DECL_LIST,
	NODE_STATEMENT,
	NODE_STATEMENT_LIST,
	NODE_BLOCK,
	NODE_FUNCTION,
	NODE_FILE,
	NODE_OP,
	NODE_EXPR,
	NODE_ASSIGNMENT

};

struct Type_Node;

struct Environment {
	std::map<std::string, int> global_symbol_table;	//Used for declarations outside of functions
	std::map<std::string, int> symbol_table;		//<variable, fp offset>

	int symbol_fp_offset;					//position of varriable relative to frame pointer

	int scope_start;					//position in stack where current scope variables are located (for later)
	void addSymbol(std::string name);
	void addParameter(std::string name);
	void saveTable(int& old_offset,	std::map<std::string, int>& old_table) const;
	void restoreTable(const int& old_offset, const	std::map<std::string, int>& old_table);
	Environment();
	Type_Node* current_type;
	int param_index;	//initialise to 0 at start of each function;
	void printTable() const;
};

struct Node {
	int node_type;
	bool is_negative;	//for Expr, ID, Int
	virtual void renderASM(Environment& env, std::ostream& out) = 0;
	virtual ~Node() {}
};

struct IntConst_Node: public Node {
	int value;
	IntConst_Node(int n);
	void renderASM(Environment& env, std::ostream& out);
};

struct FloatConst_Node: public Node {
	double value;
	FloatConst_Node(double n);
};


struct String_Node: public Node {
	char* str;
	String_Node(char* s);
};


struct ID_Node: public Node {
	char* name;
	ID_Node(char* iden);
	void renderASM(Environment& env, std::ostream& out);
};


struct Type_Node: public Node {
	char* type_name;
	Node* type_next;
	Type_Node(char* n, Node* next);
	void renderASM(Environment& env, std::ostream& out);
};


struct Decl_Node: public Node {
	Type_Node* type;
	ID_Node* id;
	bool has_value;
	Node* value;
	Node* next;
	Decl_Node(Type_Node* t, ID_Node* i, bool has, Node* v, Node* n);
	void renderASM(Environment& env, std::ostream& out);
};

struct DeclStatement_Node: public Node {
	Type_Node* type;
	Node* decl_start;
	bool pointer;
	DeclStatement_Node(Type_Node* t, Node* start, bool p);
	void renderASM(Environment& env, std::ostream& out);
};



struct Op_Node: public Node {
	char* op;
	Op_Node(char* o);
	void renderASM(Environment& env, std::ostream& out);
};

struct Expr_Node: public Node {
	Node* lhs;
	Op_Node* op;
	Node* rhs;
	//Note: check if lhs and rhs are the correct nodes (id, value, expr, etc)
	Expr_Node(Node* l, Op_Node* oper, Node* r);
	void renderASM(Environment& env, std::ostream& out);
	//int evalExpr();
};

struct Assignment_Node: public Node {
	//just set for one assignment for now (add chaining later)
	Node* id;
	Op_Node* op;
	Node* value;
	Assignment_Node(Node* iden, Op_Node* oper, Node* v);
	void renderASM(Environment& env, std::ostream& out);
};

struct ExprStatement_Node:public Node {
	Node* expr;
	ExprStatement_Node(Node* e);
	void renderASM(Environment& env, std::ostream& out);
};


struct ReturnStatement_Node:public Node {
	Node* return_expr;
	ReturnStatement_Node(Node* r);
	void renderASM(Environment& env, std::ostream& out);
};


struct Statement_Node: public Node {
	Node* statement;
	Statement_Node(Node* s);
	void renderASM(Environment& env, std::ostream& out);
};


struct CompoundStatement_Node: public Node {
	Node* comp_start;
	Node* next;
	CompoundStatement_Node(Node* start, Node* n);
	CompoundStatement_Node();
	void renderASM(Environment& env, std::ostream& out);
};


struct Block_Node: public Node {
	Node* block_start;
	Block_Node(Node* start);
	void renderASM(Environment& env, std::ostream& out);
	
};

struct Parameter_Node: public Node {
	Type_Node* type;
	ID_Node* id;
	Node* next;
	Parameter_Node(Type_Node* t, ID_Node* iden, Node* n);
	void renderASM(Environment& env, std::ostream& out);
};

struct Function_Node: public Node{
	Type_Node* type;			//Need to add this!!!!!
	ID_Node* f_name;
	Parameter_Node* parameters_start;
	Node* blk;
	int variable_count;
	
	Function_Node(ID_Node* f, Parameter_Node* params, Node* b, int n);
	void renderASM(Environment& env, std::ostream& out);
};


struct File_Node: public Node {
	char* file_name;
	std::vector<Node*> file_list;
	
	void renderASM(Environment& env, std::ostream& out);
};





//GLOBAL FUNCTIONS

//void addNode(Node* hdtree, Node& new_node);


#endif