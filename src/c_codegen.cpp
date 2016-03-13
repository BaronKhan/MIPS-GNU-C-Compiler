#include "c_ast.hpp"
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <cmath>

void IntConst_Node::renderASM(Environment& env, std::ostream& out) {
	

}

void ID_Node::renderASM(Environment& env, std::ostream& out) {
	out << name;
}

void Type_Node::renderASM(Environment& env, std::ostream& out) {
	out << type_name;
	if (type_next != NULL) {
		out << " ";
		type_next->renderASM(env,out);
	}
}

void Op_Node::renderASM(Environment& env, std::ostream& out) {
	

}


void Expr_Node::renderASM(Environment& env, std::ostream& out) {
	int value_left, value_right, result;

	/*
	//Debugging
	if (lhs->node_type == NODE_INTCONST) out << "lhs is Int Node" << std::endl;
	if (rhs->node_type == NODE_INTCONST) out << "rhs is Int Node" << std::endl;
	if (lhs->node_type == NODE_ID) out << "lhs is ID Node" << std::endl;
	if (rhs->node_type == NODE_ID) out << "rhs is ID Node" << std::endl;
	if (lhs->node_type == NODE_EXPR) out << "lhs is Expr Node" << std::endl;
	if (rhs->node_type == NODE_EXPR) out << "rhs is Expr Node" << std::endl;
	*/
	
	
	//set lhs
	if (lhs->node_type == NODE_ID) {
		//is identifier on stack?
		if (env.symbol_table.find( (((ID_Node*)lhs)->name ) )  != env.symbol_table.end()) {
			out << "\tlw      $2," << env.symbol_table[((ID_Node*)lhs)->name] << "($fp)" << std::endl;
			if (lhs->is_negative)
				out << "\tsubu    $2,0,$2" << std::endl;
		}
		else {
			std::cerr << "Error: " << ((ID_Node*)lhs)->name << " undeclared" << std::endl;
			//exit(EXIT_FAILURE);
		}
	}
	else if (lhs->node_type == NODE_INTCONST) {
		value_left = ((IntConst_Node*)lhs)->value;
		if (lhs->is_negative == true)
			value_left = -value_left;
	}
	else if (lhs->node_type == NODE_EXPR) {
		//save old $3 on stack
		//out <<"\taddi    $sp,$sp,4" << std::endl;
		//out <<"\tsw      $3,0($sp)" << std::endl;
		lhs->renderASM(env, out);
		if (lhs->is_negative)
			out << "\tsubu    $2,0,$2" << std::endl;
		//restore saved $3 from stack
		//out <<"\tlw      $3,0($sp)" << std::endl;
		//out <<"\taddi    $sp,$sp,-4" << std::endl;
	}
	
	
	//set rhs
	if (rhs->node_type == NODE_ID) {
		//is identifier on stack?
		if (env.symbol_table.find( (((ID_Node*)rhs)->name ) )  != env.symbol_table.end()) {
			out << "\tlw      $3," << env.symbol_table[((ID_Node*)rhs)->name]<<"($fp)" << std::endl;
			if (rhs->is_negative)
				out << "\tsubu    $3,0,$3" << std::endl;
		}
		else {
			std::cerr << "Error: " << ((ID_Node*)rhs)->name << " undeclared" << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	else if (rhs->node_type == NODE_INTCONST) {
		value_right = ((IntConst_Node*)rhs)->value;
		if (rhs->is_negative == true)
			value_right = -value_right;
	}
	else if (rhs->node_type == NODE_EXPR) {
		//save old $2 onto stack
		out <<"\taddi    $sp,$sp,4" << std::endl;
		out <<"\tsw      $2,0($sp)		# save $2 onto stack" << std::endl;
		
		rhs->renderASM(env, out);
		if (rhs->is_negative)
			out << "\tsubu    $2,0,$2" << std::endl;
		//move result to $3
		out << "\tmove    $3,$2" << std::endl;
		
		//restore saved $2 from stack
		out <<"\tlw      $2,0($sp)" << std::endl;
		out <<"\taddi    $sp,$sp,-4" << std::endl;
	}
	

	

	//evaluate according to Op node
	if (strcmp(op->op, "+") == 0) {
		if (lhs->node_type == NODE_INTCONST && rhs->node_type == NODE_INTCONST) {
			result = value_left+value_right;
			out << "\tli      $2," << result << std::endl;
		}
		else if ((lhs->node_type == NODE_EXPR && rhs->node_type == NODE_INTCONST)
			|(lhs->node_type == NODE_ID && rhs->node_type == NODE_INTCONST)) {
			out << "\taddiu   $2,$2," << value_right << std::endl;
		}
		else if ((lhs->node_type == NODE_INTCONST && rhs->node_type == NODE_EXPR)
			|(lhs->node_type == NODE_INTCONST && rhs->node_type == NODE_ID)) {
			out << "\taddiu   $2,$3," << value_left << std::endl;
		}
		else if ((lhs->node_type == NODE_EXPR && rhs->node_type == NODE_ID)
			|(lhs->node_type == NODE_ID && rhs->node_type == NODE_EXPR)
			|(lhs->node_type == NODE_EXPR && rhs->node_type == NODE_EXPR)
			|(lhs->node_type == NODE_ID && rhs->node_type == NODE_ID)) {
			out << "\taddu    $2,$2,$3" << std::endl;
		}
	}
	else if (strcmp(op->op, "-") == 0) {
		if (lhs->node_type == NODE_INTCONST && rhs->node_type == NODE_INTCONST) {
			result = value_left-value_right;
			out << "\tli      $2," << result << std::endl;
		}
		else if ((lhs->node_type == NODE_EXPR && rhs->node_type == NODE_INTCONST)
			|(lhs->node_type == NODE_ID && rhs->node_type == NODE_INTCONST)) {
			out << "\taddiu   $2,$2,-" << value_right << std::endl;
		}
		else if ((lhs->node_type == NODE_INTCONST && rhs->node_type == NODE_EXPR)
			|(lhs->node_type == NODE_INTCONST && rhs->node_type == NODE_ID)) {
			out << "\tli      $2," << value_left << std::endl;
			out << "\tsubu    $2,$2,$3" << std::endl;
		}
		else if ((lhs->node_type == NODE_EXPR && rhs->node_type == NODE_ID)
			|(lhs->node_type == NODE_ID && rhs->node_type == NODE_EXPR)
			|(lhs->node_type == NODE_EXPR && rhs->node_type == NODE_EXPR)
			|(lhs->node_type == NODE_ID && rhs->node_type == NODE_ID)) {
			out << "\tsubu    $2,$2,$3" << std::endl;
		}
	}
	else if (strcmp(op->op, "*") == 0) {
		if (lhs->node_type == NODE_INTCONST && rhs->node_type == NODE_INTCONST) {
			result = value_left*value_right;
			out << "\tli      $2," << result << std::endl;
		}
		else if ((lhs->node_type == NODE_EXPR && rhs->node_type == NODE_INTCONST)
			|(lhs->node_type == NODE_ID && rhs->node_type == NODE_INTCONST)) {
			//TODO: sort out negative values (just invert sign and sub from 0 at end)
			if (value_right > 0) {
				int power = floor(log2(value_right));		//how much to shift by;
				int remainder = value_right - pow(2,power);	//how much to add by (*2)
				out << "\tsll     $2,$2," << power << std::endl;
				if (remainder != 0)
					out << "\taddiu   $2,$2," << remainder*2 << std::endl;	
			}
			else {	//temporary for negative numbers
				out << "\tli      $3," << value_right << std::endl;
				out << "\tmul     $2,$2,$3		# mult, mflo" << std::endl;
			}
		}
		else if ((lhs->node_type == NODE_INTCONST && rhs->node_type == NODE_EXPR)
			|(lhs->node_type == NODE_INTCONST && rhs->node_type == NODE_ID)) {
			//TODO: sort out negative values (just invert sign and sub from 0 at end)
			if (value_left > 0) {
				int power = floor(log2(value_left));		//how much to shift by;
				int remainder = value_left - pow(2,power);	//how much to add by (*2)
				out << "\tsll     $3,$3," << power << std::endl;
				if (remainder != 0)
					out << "\taddiu   $2,$3," << remainder*2 << std::endl;	
			}
			else {	//temporary for negative numbers
				out << "\tli      $2," << value_left << std::endl;
				out << "\tmul     $2,$2,$3		# mult, mflo" << std::endl;
			}
		}
		else if ((lhs->node_type == NODE_EXPR && rhs->node_type == NODE_ID)
			|(lhs->node_type == NODE_ID && rhs->node_type == NODE_EXPR)
			|(lhs->node_type == NODE_EXPR && rhs->node_type == NODE_EXPR)
			|(lhs->node_type == NODE_ID && rhs->node_type == NODE_ID)) {
			out << "\tmul     $2,$2,$3		# mult, mflo" << std::endl;
		}
	}
	else if (strcmp(op->op, "/") == 0) {
		if (lhs->node_type == NODE_INTCONST && rhs->node_type == NODE_INTCONST) {
			result = value_left/value_right;
			out << "\tli      $2," << result << std::endl;
		}
		else {
			if ((lhs->node_type == NODE_EXPR && rhs->node_type == NODE_INTCONST)
				|(lhs->node_type == NODE_ID && rhs->node_type == NODE_INTCONST)) {
				out << "\tli      $3," << value_right << std::endl;
			}
			else if ((lhs->node_type == NODE_INTCONST && rhs->node_type == NODE_EXPR)
				|(lhs->node_type == NODE_INTCONST && rhs->node_type == NODE_ID)) {
				out << "\tli      $2," << value_right << std::endl;
			}
			out << "\tteq     $3,$0,7		# div by 0 exception handler, 7=int div" << std::endl;
			out << "\tdiv     $2,$3" << std::endl;
			out << "\tmfhi    $2" <<std::endl;
			out << "\tmflo    $2" <<std::endl;	//remove when implementing "%"
		}
	}





}







void Assignment_Node::renderASM(Environment& env, std::ostream& out) {
	//TODO: change for different assignments (+=, -=)
	if (id->node_type == NODE_ID) {
		if (value->node_type == NODE_INTCONST) {
			int n = ((IntConst_Node*)value)->value;
			out << "\tli      $2," << n << std::endl;
			out << "\tsw      $2," << env.symbol_table[((ID_Node*)id)->name] << "($fp)" << std::endl;
		}
		else if (value->node_type == NODE_ID) {
			if (env.symbol_table.find( (((ID_Node*)value)->name ) )  != env.symbol_table.end()) {
				out << "\tlw      $2," << env.symbol_table[((ID_Node*)value)->name]<<"($fp)" << std::endl;
				out << "\tsw      $2," << env.symbol_table[((ID_Node*)id)->name] << "($fp)" << std::endl;
			}
			else {
				std::cerr << "Error: " << ((ID_Node*)value)->name << " undeclared" << std::endl;
				exit(EXIT_FAILURE);
			}
		}
		else if (value->node_type == NODE_EXPR) {
			value->renderASM(env, out);
			out << "\tsw      $2," << env.symbol_table[((ID_Node*)id)->name] << "($fp)" << std::endl;
			out << "\tmove    $2,$0" << std::endl;
		}
	}
	/*
	else if (id->node_type == NODE_ASSIGNMENT) {
		
	}
	*/
	else {
		std::cerr << "Error: lvalue required as left operand of assignment" << std::endl;
		//exit(EXIT_FAILURE);
	}
}

void ExprStatement_Node::renderASM(Environment& env, std::ostream& out) {
	expr->renderASM(env, out);
}

void ReturnStatement_Node::renderASM(Environment& env, std::ostream& out) {
	//store return value in $2;
	if (return_expr != NULL) {
		if (return_expr->node_type == NODE_INTCONST) {
			int n = ((IntConst_Node*)return_expr)->value;
			if (return_expr->is_negative)
				out << "\tli      $2,-" << n << std::endl;
			else
				out << "\tli      $2," << n << std::endl;
		}
		else if (return_expr->node_type == NODE_ID) {
			if (env.symbol_table.find( (((ID_Node*)return_expr)->name ) )  != env.symbol_table.end()) {
				out << "\tlw      $2," << env.symbol_table[((ID_Node*)return_expr)->name]<<"($fp)" << std::endl;
				if (return_expr->is_negative)
					out << "\tsubu    $2,0,$2" << std::endl;
			}
			else {
				std::cerr << "Error: " << ((ID_Node*)return_expr)->name << " undeclared" << std::endl;
				exit(EXIT_FAILURE);
			}
		}
		else if (return_expr->node_type == NODE_EXPR) {
			return_expr->renderASM(env, out);
			if (return_expr->is_negative)
					out << "\tsubu    $2,0,$2" << std::endl;
		}
	}
}

void Statement_Node::renderASM(Environment& env, std::ostream& out) {
	statement->renderASM(env, out);
}

void CompoundStatement_Node::renderASM(Environment& env, std::ostream& out) {
	comp_start->renderASM(env, out);
	if (next != NULL) {
		next->renderASM(env, out);
	}
}

void DeclStatement_Node::renderASM(Environment& env, std::ostream& out) {
	env.current_type = type;
	if (decl_start != NULL) {
		decl_start->renderASM(env, out);
	}
}

void Decl_Node::renderASM(Environment& env, std::ostream& out) {
	//assign a register`
	env.addSymbol(id->name);
	if (has_value) {
		if (value->node_type == NODE_INTCONST) {
			int n = ((IntConst_Node*)value)->value;
			if (value->is_negative)
				out << "\tli      $2,-" << n << std::endl;
			else
				out << "\tli      $2," << n << std::endl;
			out << "\tsw      $2," << env.symbol_table[id->name] << "($fp)" << std::endl;
		}
		else if (value->node_type == NODE_ID) {
			if (env.symbol_table.find( (((ID_Node*)value)->name ) )  != env.symbol_table.end()) {
				out << "\tlw      $2," << env.symbol_table[((ID_Node*)value)->name]<<"($fp)" << std::endl;
				if (value->is_negative)
					out << "\tsubu    $2,0,$2" << std::endl;
				out << "\tsw      $2," << env.symbol_table[id->name] << "($fp)" << std::endl;
			}
			else {
				std::cerr << "Error: " << ((ID_Node*)value)->name << " undeclared" << std::endl;
				exit(EXIT_FAILURE);
			}
		}
		else if (value->node_type == NODE_EXPR) {
			//evaluate expression using $2 and $3 and store final result in $2
			//out << "EVALUATING EXPRESSION" <<std::endl;
			value->renderASM(env, out);
			//out << std::endl;
			if (value->is_negative)
				out << "\tsubu    $2,$0,$2" << std::endl;
			out << "\tsw      $2," << env.symbol_table[id->name] << "($fp)" << std::endl;
			out << "\tmove    $2,$0" << std::endl;
		}
	}
	//out << std::endl;
	if (next != NULL) {
		next->renderASM(env, out);
	}
}

void Block_Node::renderASM(Environment& env, std::ostream& out) {
	if (block_start != NULL) {
		block_start->renderASM(env,out);
	}
	//nop after if no return statement
	//out << "\tnop" << std::endl;
	
	//remove symbols added by block (now out of scope)

}

void Parameter_Node::renderASM(Environment& env, std::ostream& out) {
	env.current_type = type;
	env.addParameter(id->name);
	int reg = 4+env.param_index;
	out << "\tsw      $" << reg << "," << env.symbol_table[id->name] << "($fp)" << std::endl;
	env.param_index++;
	if (next != NULL) {
		next->renderASM(env , out);
	}
	
}

void Function_Node::renderASM(Environment& env, std::ostream& out) {
	f_name->renderASM(env,out);
	out << ":" << std::endl;
	//std::cerr << "function has " << variable_count << " variables" << std::endl;
	
	if (variable_count >= 3) {
		env.scope_start = 16+(variable_count*4);
	}
	else {
		env.scope_start = 20;
	}
	out << "\t.frame  $fp,24,$31" << std::endl;
	out << "\t.mask   0x40000000,-4" << std::endl;
	out << "\t.fmask  0x00000000,0" << std::endl;
	out << "\t.set    noreorder" << std::endl;
	out << "\t.set    nomacro" << std::endl;
	out << "\taddiu   $sp,$sp,-" << env.scope_start+4 << std::endl;
	out << "\tsw      $fp," << env.scope_start << "($sp)" << std::endl;
	out << "\tmove    $fp,$sp" << std::endl;		
	
	//save current symbol_table (todo)
	
	
	//add parameters (could be NULL) to symbol table
	//and store parameters onto stack (first four set to $4-$7)
	env.param_index = 0;
	if (parameters_start != NULL) {
		parameters_start->renderASM(env, out);
	}
        
	
	blk->renderASM(env, out);
	
	
	//remove parameters added by function from symbol table (todo)
	
	out << "\tmove    $sp,$fp" << std::endl;
	out << "\tlw      $fp,20($sp)" << std::endl;	
	out << "\taddiu   $sp,$sp,24" << std::endl;
	out << "\tj       $31" << std::endl;
	out << "\tnop" << std::endl;
	out << std::endl;
	
	out << "\t.set    macro" << std::endl;
        out << "\t.set    reorder" << std::endl;
        out << "\t.end    ";
	f_name->renderASM(env,out);
	out << std::endl;
        out << "\t.size   ";
	f_name->renderASM(env,out);
	out << ", .-";
	f_name->renderASM(env,out);
	out << std::endl;
	
	
}


void File_Node::renderASM(Environment& env, std::ostream& out) {
	//out << "\t.file\t1 """ << file_name << """" << std::endl;
	//out << "\t.ent\t" << ((ID_Node*)f_name)->name << std::endl;
	//out << "\t.type\t" << ((ID_Node*)f_name)->name << ", @function" << std::endl;
	
	for (int i=0; i<file_list.size(); i++) {
		(file_list[i])->renderASM(env, out);
	}
	//out << "end" << std::endl;
}
