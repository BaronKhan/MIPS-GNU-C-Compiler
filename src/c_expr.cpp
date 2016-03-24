#include "c_ast.hpp"
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <cmath>


void Expr_Node::renderASM(Environment& env, std::ostream& out) {
	int value_left, value_right, result;
	
	

	/*
	//Debugging
	if (lhs->node_type == NODE_INTCONST) out << "#lhs is Int Node" << std::endl;
	if (rhs->node_type == NODE_INTCONST) out << "#rhs is Int Node" << std::endl;
	if (lhs->node_type == NODE_ID) out << "#lhs is ID Node" << std::endl;
	if (rhs->node_type == NODE_ID) out << "#rhs is ID Node" << std::endl;
	if (lhs->node_type == NODE_EXPR) out << "#lhs is Expr Node" << std::endl;
	if (rhs->node_type == NODE_EXPR) out << "#rhs is Expr Node" << std::endl;
	out << "#op is " << op->op << std::endl;
	*/
	

	//set lhs
	if (lhs->node_type == NODE_ID) {
		//is identifier on stack?
		if (env.symbol_table.find( (((ID_Node*)lhs)->name ) )  != env.symbol_table.end()) {
			//out << "\tlw      $2," << env.symbol_table[((ID_Node*)lhs)->name] << "($fp)" << std::endl;
			if (((ID_Node*)lhs)->array_offset != NULL) {
				((ID_Node*)lhs)->array_offset->renderASM(env,out);
				out << "\tmove    $8,$2" << std::endl;
				//$8 contains the index
				out << "\taddu    $fp,$fp,$8" << std::endl;
				out << "\tlw      $2," << env.symbol_table[((ID_Node*)lhs)->name]<<"($fp)" << std::endl;
				out << "\tsubu    $fp,$fp,$8" << std::endl;
			}
			else {
				out << "\tlw      $2," << env.symbol_table[((ID_Node*)lhs)->name]<<"($fp)" << std::endl;
			}
			
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
	else {
		//save old $3 on stack
		//out <<"\taddi    $sp,$sp,4" << std::endl;
		//out <<"\tsw      $3,0($sp)" << std::endl;
		lhs->renderASM(env, out);
		//restore saved $3 from stack
		//out <<"\tlw      $3,0($sp)" << std::endl;
		//out <<"\taddi    $sp,$sp,-4" << std::endl;
	}
	
	
	//set rhs
	if (rhs->node_type == NODE_ID) {
		//is identifier on stack?
		if (env.symbol_table.find( (((ID_Node*)rhs)->name ) )  != env.symbol_table.end()) {
			//out << "\tlw      $3," << env.symbol_table[((ID_Node*)rhs)->name]<<"($fp)" << std::endl;
			if (((ID_Node*)rhs)->array_offset != NULL) {
				out <<"\taddi    $sp,$sp,4" << std::endl;
				out <<"\tsw      $2,0($sp)		# save $2 onto stack" << std::endl;
				((ID_Node*)rhs)->array_offset->renderASM(env,out);
				out << "\tmove    $8,$2" << std::endl;
				out <<"\tlw      $2,0($sp)" << std::endl;
				out <<"\taddi    $sp,$sp,-4" << std::endl;
				//$8 contains the index
				out << "\taddu    $fp,$fp,$8" << std::endl;
				out << "\tlw      $3," << env.symbol_table[((ID_Node*)rhs)->name]<<"($fp)" << std::endl;
				out << "\tsubu    $fp,$fp,$8" << std::endl;
			}
			else {
				out << "\tlw      $3," << env.symbol_table[((ID_Node*)rhs)->name]<<"($fp)" << std::endl;
			}
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
	else {
		//save old $2 onto stack
		out <<"\taddi    $sp,$sp,4" << std::endl;
		out <<"\tsw      $2,0($sp)		# save $2 onto stack" << std::endl;
		
		rhs->renderASM(env, out);
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
		else if (rhs->node_type == NODE_INTCONST) {
			out << "\taddi    $2,$2," << value_right << std::endl;
		}
		else if (lhs->node_type == NODE_INTCONST) {
			out << "\taddi    $2,$3," << value_left << std::endl;
		}
		else {
			out << "\tadd     $2,$2,$3" << std::endl;
		}
	}
	else if (strcmp(op->op, "-") == 0) {
		if (lhs->node_type == NODE_INTCONST && rhs->node_type == NODE_INTCONST) {
			result = value_left-value_right;
			out << "\tli      $2," << result << std::endl;
		}
		else if (rhs->node_type == NODE_INTCONST) {
			out << "\taddi    $2,$2,-" << value_right << std::endl;
		}
		else if (lhs->node_type == NODE_INTCONST) {
			out << "\tli      $2," << value_left << std::endl;
			out << "\tsub     $2,$2,$3" << std::endl;
		}
		else {
			out << "\tsub     $2,$2,$3" << std::endl;
		}
	}
	else if (strcmp(op->op, "*") == 0) {
		if (lhs->node_type == NODE_INTCONST && rhs->node_type == NODE_INTCONST) {
			result = value_left*value_right;
			out << "\tli      $2," << result << std::endl;
		}
		else if (rhs->node_type == NODE_INTCONST) {
			if (value_right > 0) {
				/*int power = floor(log2(value_right));		//how much to shift by;
				int remainder = value_right - pow(2,power);	//how much to add by (*2)
				out << "\tsll     $2,$2," << power << std::endl;
				if (remainder != 0)
					out << "\taddiu   $2,$2," << remainder*2 << std::endl;
				*/
				out << "\tli      $3," << value_right << std::endl;
				out << "\tmul     $2,$2,$3		# mult, mflo" << std::endl;
			}
			else {	//temporary for negative numbers
				out << "\tli      $3," << value_right << std::endl;
				out << "\tmul     $2,$2,$3		# mult, mflo" << std::endl;
			}
		}
		else if (lhs->node_type == NODE_INTCONST) {
			if (value_left > 0) {
				/*
				int power = floor(log2(value_left));		//how much to shift by;
				int remainder = value_left - pow(2,power);	//how much to add by (*2)
				out << "\tsll     $3,$3," << power << std::endl;
				if (remainder != 0)
					out << "\taddiu   $2,$3," << remainder*2 << std::endl;
				*/
				out << "\tli      $2," << value_left << std::endl;
				out << "\tmul     $2,$2,$3		# mult, mflo" << std::endl;
			}
			else {	//temporary for negative numbers
				out << "\tli      $2," << value_left << std::endl;
				out << "\tmul     $2,$2,$3		# mult, mflo" << std::endl;
			}
		}
		else {
			out << "\tmul     $2,$2,$3		# mult, mflo" << std::endl;
		}
	}
	else if (strcmp(op->op, "/") == 0) {
		if (lhs->node_type == NODE_INTCONST && rhs->node_type == NODE_INTCONST) {
			result = value_left/value_right;
			out << "\tli      $2," << result << std::endl;
		}
		else {
			if (rhs->node_type == NODE_INTCONST) {
				out << "\tli      $3," << value_right << std::endl;
			}
			else if (lhs->node_type == NODE_INTCONST) {
				out << "\tli      $2," << value_left << std::endl;
			}
			out << "\tteq     $3,$0,7		# div by 0 exception handler, 7=int div" << std::endl;
			out << "\tdiv     $2,$3" << std::endl;
			out << "\tmfhi    $2" <<std::endl;
			out << "\tmflo    $2" <<std::endl;	//swap when implementing "%"
		}
	}
	else if (strcmp(op->op, "%") == 0) {
		if (lhs->node_type == NODE_INTCONST && rhs->node_type == NODE_INTCONST) {
			result = value_left/value_right;
			out << "\tli      $2," << result << std::endl;
		}
		else {
			if (rhs->node_type == NODE_INTCONST) {
				out << "\tli      $3," << value_right << std::endl;
			}
			else if (lhs->node_type == NODE_INTCONST) {
				out << "\tli      $2," << value_left << std::endl;
			}
			out << "\tteq     $3,$0,7		# div by 0 exception handler, 7=int div" << std::endl;
			out << "\tdiv     $2,$3" << std::endl;
			out << "\tmflo    $2" <<std::endl;
			out << "\tmfhi    $2" <<std::endl;

		}
	}
	else if (strcmp(op->op, "&") == 0) {
		if (lhs->node_type == NODE_INTCONST && rhs->node_type == NODE_INTCONST) {
			result = (value_left&value_right);
			out << "\tli      $2," << result << std::endl;
		}
		else if (rhs->node_type == NODE_INTCONST) {
			out << "\tandi    $2,$2," << value_right << std::endl;
		}
		else if (lhs->node_type == NODE_INTCONST) {
			out << "\tandi    $2,$3," << value_left << std::endl;
		}
		else {
			out << "\tand     $2,$2,$3" << std::endl;
		}
	}
	else if (strcmp(op->op, "|") == 0) {
		if (lhs->node_type == NODE_INTCONST && rhs->node_type == NODE_INTCONST) {
			result = (value_left|value_right);
			out << "\tli      $2," << result << std::endl;
		}
		else if (rhs->node_type == NODE_INTCONST) {
			out << "\tori     $2,$2," << value_right << std::endl;
		}
		else if (lhs->node_type == NODE_INTCONST) {
			out << "\tori     $2,$3," << value_left << std::endl;
		}
		else {
			out << "\tor      $2,$2,$3" << std::endl;
		}
	}
	else if (strcmp(op->op, "^") == 0) {
		if (lhs->node_type == NODE_INTCONST && rhs->node_type == NODE_INTCONST) {
			result = (value_left^value_right);
			out << "\tli      $2," << result << std::endl;
		}
		else if (rhs->node_type == NODE_INTCONST) {
			out << "\txori    $2,$2," << value_right << std::endl;
		}
		else if (lhs->node_type == NODE_INTCONST) {
			out << "\txori    $2,$3," << value_left << std::endl;
		}
		else {
			out << "\txor     $2,$2,$3" << std::endl;
		}
	}
	else if (strcmp(op->op, "<<") == 0) {
		if (lhs->node_type == NODE_INTCONST && rhs->node_type == NODE_INTCONST) {
			result = (value_left<<value_right);
			out << "\tli      $2," << result << std::endl;
		}
		else if (rhs->node_type == NODE_INTCONST) {
			out << "\tsll     $2,$2," << value_right << std::endl;
		}
		else if (lhs->node_type == NODE_INTCONST) {
			out << "\tsll     $2,$3," << value_left << std::endl;
		}
		else {
			out << "\tsll     $2,$2,$3" << std::endl;
		}
	}
	else if (strcmp(op->op, ">>") == 0) {
		if (lhs->node_type == NODE_INTCONST && rhs->node_type == NODE_INTCONST) {
			result = (value_left>>value_right);
			out << "\tli      $2," << result << std::endl;
		}
		else if (rhs->node_type == NODE_INTCONST) {
			out << "\tsra     $2,$2," << value_right << std::endl;
		}
		else if (lhs->node_type == NODE_INTCONST) {
			out << "\tsra     $2,$3," << value_left << std::endl;
		}
		else {
			out << "\tsra     $2,$2,$3" << std::endl;
		}
	}
	else if (strcmp(op->op, "&&") == 0) {
		if (lhs->node_type == NODE_INTCONST && rhs->node_type == NODE_INTCONST) {
			result = (value_left&&value_right);
			out << "\tli      $2," << result << std::endl;
		}
		else if (rhs->node_type == NODE_INTCONST) {
			if (value_right == 1) {
				out << "\txori    $2,$2,1" <<std::endl;
				out << "\tmovn    $2,$0,$2" << std::endl;
				out << "\tmovz    $2,$2,$2" << std::endl;
			}
			else {
				out << "\tmove    $2,$0" << std::endl;
			}
		}
		else if (lhs->node_type == NODE_INTCONST) {
			if (value_left == 1) {
				out << "\txori    $2,$2,1" <<std::endl;
				out << "\tmovn    $2,$0,$2" << std::endl;
				out << "\tmovz    $2,$2,$2" << std::endl;
			}
			else {
				out << "\tmove    $2,$0" << std::endl;
			}
		}
		else {
			out << "\tand     $2,$2,$3" << std::endl;
		}
	}
	else if (strcmp(op->op, "||") == 0) {
		if (lhs->node_type == NODE_INTCONST && rhs->node_type == NODE_INTCONST) {
			result = (value_left&&value_right);
			out << "\tli      $2," << result << std::endl;
		}
		else if (rhs->node_type == NODE_INTCONST) {
			if (value_right == 1) {
				out << "\tli      $2,1" << std::endl;
			}
			else {
				out << "\txori    $2,$2,1" <<std::endl;
				out << "\tmovn    $2,$0,$2" << std::endl;
				out << "\tmovz    $2,$2,$2" << std::endl;
			}
		}
		else if (lhs->node_type == NODE_INTCONST) {
			if (value_left == 1) {
				out << "\tli      $2,1" << std::endl;
			}
			else {
				
				out << "\txori    $2,$2,1" <<std::endl;
				out << "\tmovn    $2,$0,$2" << std::endl;
				out << "\tmovz    $2,$2,$2" << std::endl;
			}
		}
		else {
			out << "\tor      $2,$2,$3" << std::endl;
		}
	}
	
	
	
	

	
	
//Conditional operators
	
	else if (strcmp(op->op, "==") == 0) {
		if (lhs->node_type == NODE_INTCONST && rhs->node_type == NODE_INTCONST) {
			if (value_left == value_right)
				out << "\tli      $2,1" << std::endl;
			else
				out << "\tmove    $2,$0" << std::endl;
		}
		else if (rhs->node_type == NODE_INTCONST) {
			out << "\txori    $2,$2," << value_right << std::endl;
			out << "\tsltu    $2,$2,1" << std::endl;
			out << "\tandi    $2,$2,0x00ff" << std::endl;
		}
		else if (lhs->node_type == NODE_INTCONST) {
			out << "\txori    $2,$3," << value_left << std::endl;
			out << "\tsltu    $2,$2,1" << std::endl;
			out << "\tandi    $2,$2,0x00ff" << std::endl;
		}
		else {
			out << "\txor     $2,$3,$2" << std::endl;
			out << "\tsltu    $2,$2,1" << std::endl;
			out << "\tandi    $2,$2,0x00ff" << std::endl;
		}
	}
	else if (strcmp(op->op, "!=") == 0) {
		if (lhs->node_type == NODE_INTCONST && rhs->node_type == NODE_INTCONST) {
			if (value_left != value_right)
				out << "\tli      $2,1" << std::endl;
			else
				out << "\tmove    $2,$0" << std::endl;
		}
		else if (rhs->node_type == NODE_INTCONST) {
			out << "\txori    $2,$2," << value_right << std::endl;
			out << "\tsltu    $2,$0,$2" << std::endl;
			out << "\tandi    $2,$2,0x00ff" << std::endl;
		}
		else if (lhs->node_type == NODE_INTCONST) {
			out << "\txori    $2,$3," << value_left << std::endl;
			out << "\tsltu    $2,$0,$2" << std::endl;
			out << "\tandi    $2,$2,0x00ff" << std::endl;
		}
		else {
			out << "\txor     $2,$3,$2" << std::endl;
			out << "\tsltu    $2,$0,$2" << std::endl;
			out << "\tandi    $2,$2,0x00ff" << std::endl;
		}
	}
	else if (strcmp(op->op, "<") == 0) {
		if (lhs->node_type == NODE_INTCONST && rhs->node_type == NODE_INTCONST) {
			if (value_left < value_right)
				out << "\tli      $2,1" << std::endl;
			else
				out << "\tmove    $2,$0" << std::endl;
		}
		else if (rhs->node_type == NODE_INTCONST) {
			out << "\tslt     $2,$2," << value_right << std::endl;
			out << "\tandi    $2,$2,0x00ff" << std::endl;
		}
		else if (lhs->node_type == NODE_INTCONST) {
			out << "\tmove    $3,$2" << std::endl;
			out << "\tslt     $2,$2," << value_left+1 << std::endl;
			out << "\txori    $2,$2,0x1" << std::endl;
			out << "\tandi    $2,$2,0x00ff" << std::endl;
		}
		else {
			out << "\tslt     $2,$2,$3" << std::endl;
			out << "\tandi    $2,$2,0x00ff" << std::endl;
		}
	}
	else if (strcmp(op->op, ">") == 0) {
		if (lhs->node_type == NODE_INTCONST && rhs->node_type == NODE_INTCONST) {
			if (value_left > value_right)
				out << "\tli      $2,1" << std::endl;
			else
				out << "\tmove    $2,$0" << std::endl;
		}
		else if (rhs->node_type == NODE_INTCONST) {
			out << "\tslt     $2,$2," << value_right+1 << std::endl;
			out << "\txori    $2,$2,0x1" << std::endl;
			out << "\tandi    $2,$2,0x00ff" << std::endl;
		}
		else if (lhs->node_type == NODE_INTCONST) {
			out << "\tmove    $3,$2" << std::endl;
			out << "\tslt     $2,$2," << value_left << std::endl;
			out << "\tandi    $2,$2,0x00ff" << std::endl;
		}
		else {
			out << "\tslt     $2,$3,$2" << std::endl;
			out << "\tandi    $2,$2,0x00ff" << std::endl;
		}
	}
	
	else if (strcmp(op->op, "<=") == 0) {
		if (lhs->node_type == NODE_INTCONST && rhs->node_type == NODE_INTCONST) {
			if (value_left <= value_right)
				out << "\tli      $2,1" << std::endl;
			else
				out << "\tmove    $2,$0" << std::endl;
		}
		else if (rhs->node_type == NODE_INTCONST) {
			out << "\tslt     $2,$2," << value_right+1 << std::endl;
			out << "\tandi    $2,$2,0x00ff" << std::endl;
		}
		else if (lhs->node_type == NODE_INTCONST) {
			out << "\tmove    $3,$2" << std::endl;
			out << "\tslt     $2,$2," << value_left << std::endl;
			out << "\txori    $2,$2,0x1" << std::endl;
			out << "\tandi    $2,$2,0x00ff" << std::endl;
		}
		else {
			out << "\tslt     $2,$3,$2" << std::endl;
			out << "\txori    $2,$2,0x1" << std::endl;
			out << "\tandi    $2,$2,0x00ff" << std::endl;
		}
	}
	else if (strcmp(op->op, ">=") == 0) {
		if (lhs->node_type == NODE_INTCONST && rhs->node_type == NODE_INTCONST) {
			if (value_left >= value_right)
				out << "\tli      $2,1" << std::endl;
			else
				out << "\tmove    $2,$0" << std::endl;
		}
		else if (rhs->node_type == NODE_INTCONST) {
			out << "\tslt     $2,$2," << value_right << std::endl;
			out << "\txori    $2,$2,0x1" << std::endl;
			out << "\tandi    $2,$2,0x00ff" << std::endl;
		}
		else if (lhs->node_type == NODE_INTCONST) {
			out << "\tmove    $3,$2" << std::endl;
			out << "\tslt     $2,$2," << value_left+1 << std::endl;
			out << "\tandi    $2,$2,0x00ff" << std::endl;
		}
		else {
			out << "\tslt     $2,$2,$3" << std::endl;
			out << "\txori    $2,$2,0x1" << std::endl;
			out << "\tandi    $2,$2,0x00ff" << std::endl;
		}
	}
	
	
	
	
	if (is_negative)
		out << "\tsubu    $2,0,$2" << std::endl;
}

void Ternary_Node::renderASM(Environment& env, std::ostream& out) {
	//evaluate expr2, store in $4
	//evaluate expr3, store in $5
	//evaluate expr1, move $4 automatically
	expr2->renderASM(env, out);
	out << "\tmove    $4,$2" << std::endl;
	expr3->renderASM(env, out);
	out << "\tmove    $5,$2" << std::endl;
	expr1->renderASM(env,out);
	out << "\tmove    $6,$2" << std::endl;
	
	out << "\tmovn    $2,$4,$6" << std::endl;
	out << "\tmovz    $2,$5,$6" << std::endl;
	
	if (is_negative)
		out << "\tsubu    $2,0,$2" << std::endl;
	
}