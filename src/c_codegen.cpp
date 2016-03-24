#include "c_ast.hpp"
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <cmath>

void IntConst_Node::renderASM(Environment& env, std::ostream& out) {
	int n = value;
	if (is_negative)
		out << "\tli      $2,-" << n << std::endl;
	else
		out << "\tli      $2," << n << std::endl;

}

void FloatConst_Node::renderASM(Environment& env, std::ostream& out) {
	

}

void String_Node::renderASM(Environment& env, std::ostream& out) {
	

}

void ID_Node::renderASM(Environment& env, std::ostream& out) {
	if (env.symbol_table.find(name)  != env.symbol_table.end()) {
		if (array_offset != NULL) {
			array_offset->renderASM(env,out);
			out << "\tmove    $8,$2" << std::endl;
			//$8 contains the index
			out << "\taddu    $fp,$fp,$8" << std::endl;
			out << "\tlw      $2," << env.symbol_table[name]<<"($fp)" << std::endl;
			out << "\tsubu    $fp,$fp,$8" << std::endl;
		}
		else {
			out << "\tlw      $2," << env.symbol_table[name]<<"($fp)" << std::endl;
		}
		if (is_negative)
			out << "\tsubu    $2,0,$2" << std::endl;
	}
	else {
		std::cerr << "Error: " << name << " undeclared" << std::endl;
		exit(EXIT_FAILURE);
	}
}

void ID_Node::getName(Environment& env, std::ostream& out) {
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


//Expr_Node::renderASM() in c_expr.cpp

//Ternary_Node::renderASM() in c_expr.cpp





void Assignment_Node::renderASM(Environment& env, std::ostream& out) {

	if (id->node_type == NODE_ID) {
		if (env.symbol_table.find( (((ID_Node*)id)->name ) )  != env.symbol_table.end()) {
			if (((ID_Node*)id)->array_offset != NULL) {
				((ID_Node*)id)->array_offset->renderASM(env, out);
				out << "\tmove    $9,$2" << std::endl;
				//$9 contains sw array offset
			}
			
			
			if (op->op_prefix != "") {
				out << "\tlw      $7," << env.symbol_table[((ID_Node*)id)->name]<<"($fp)" << std::endl;
			}
				
			if (value->node_type == NODE_INTCONST) {
				int n = ((IntConst_Node*)value)->value;
				if (value->is_negative)
					out << "\tli      $2,-" << n << std::endl;
				else
					out << "\tli      $2," << n << std::endl;
				
				if (((ID_Node*)id)->array_offset == NULL) {
					out << "\tsw      $2," << env.symbol_table[((ID_Node*)id)->name] << "($fp)" << std::endl;
				}
				else {
					out << "\taddu    $fp,$fp,$9" << std::endl;
					out << "\tsw      $2," << env.symbol_table[((ID_Node*)id)->name] << "($fp)" << std::endl;
					out << "\tsubu    $fp,$fp,$9" << std::endl;
				}
			}
			else if (value->node_type == NODE_ID) {
				if (env.symbol_table.find( (((ID_Node*)value)->name ) )  != env.symbol_table.end()) {
					
					
					//out << "\tlw      $2," << env.symbol_table[((ID_Node*)value)->name]<<"($fp)" << std::endl;
					
					if (((ID_Node*)value)->array_offset != NULL) {
						((ID_Node*)value)->array_offset->renderASM(env,out);
						out << "\tmove    $8,$2" << std::endl;
						//$8 contains the index
						out << "\taddu    $fp,$fp,$8" << std::endl;
						out << "\tlw      $2," << env.symbol_table[((ID_Node*)value)->name]<<"($fp)" << std::endl;
						out << "\tsubu    $fp,$fp,$8" << std::endl;
					}
					else {
						out << "\tlw      $2," << env.symbol_table[((ID_Node*)value)->name]<<"($fp)" << std::endl;
					}
					
					if (value->is_negative)
						out << "\tsubu    $2,0,$2" << std::endl;
						
					//out << "\tsw      $2," << env.symbol_table[((ID_Node*)id)->name] << "($fp)" << std::endl;
					if (((ID_Node*)id)->array_offset == NULL) {
						out << "\tsw      $2," << env.symbol_table[((ID_Node*)id)->name] << "($fp)" << std::endl;
					}
					else {
						out << "\taddu    $fp,$fp,$9" << std::endl;
						out << "\tsw      $2," << env.symbol_table[((ID_Node*)id)->name] << "($fp)" << std::endl;
						out << "\tsubu    $fp,$fp,$9" << std::endl;
					}
				}
				else {
					std::cerr << "Error: " << ((ID_Node*)value)->name << " undeclared" << std::endl;
					exit(EXIT_FAILURE);
				}
			}
			else if (value->node_type == NODE_EXPR || value->node_type == NODE_CALL || value->node_type == NODE_TERNARY) {
				value->renderASM(env, out);
				//out << "\tsw      $2," << env.symbol_table[((ID_Node*)id)->name] << "($fp)" << std::endl;
				if (((ID_Node*)id)->array_offset == NULL) {
					out << "\tsw      $2," << env.symbol_table[((ID_Node*)id)->name] << "($fp)" << std::endl;
				}
				else {
					out << "\taddu    $fp,$fp,$9" << std::endl;
					out << "\tsw      $2," << env.symbol_table[((ID_Node*)id)->name] << "($fp)" << std::endl;
					out << "\tsubu    $fp,$fp,$9" << std::endl;
				}
				out << "\tmove    $2,$0" << std::endl;
			}
			
			if (op->op_prefix != "") {
				if (op->op_prefix == "+") {
					out << "\taddu    $2,$7,$2" << std::endl;
				}
				else if (op->op_prefix == "-") {
					out << "\tsubu    $2,$7,$2" << std::endl;
				}
				else if (op->op_prefix == "*") {
					out << "\tmul     $2,$7,$2" << std::endl;
				}
				else if (op->op_prefix == "/") {
					out << "\tteq     $2,$0,7		# div by 0 exception handler, 7=int div" << std::endl;
					out << "\tdivu    $7,$2" << std::endl;
					out << "\tmfhi    $2" <<std::endl;
					out << "\tmflo    $2" <<std::endl;
				}
				else if (op->op_prefix == "%") {
					out << "\tteq     $2,$0,7		# div by 0 exception handler, 7=int div" << std::endl;
					out << "\tdivu    $7,$2" << std::endl;
					out << "\tmflo    $2" <<std::endl;
					out << "\tmfhi    $2" <<std::endl;
				}
				else if (op->op_prefix == "&") {
					out << "\tand     $2,$7,$2" << std::endl;
				}
				else if (op->op_prefix == "|") {
					out << "\tor      $2,$7,$2" << std::endl;
				}
				else if (op->op_prefix == "^") {
					out << "\txor     $2,$7,$2" << std::endl;
				}
				else if (op->op_prefix == "<<") {
					out << "\tsll     $2,$7,$2" << std::endl;
				}
				else if (op->op_prefix == ">>") {
					out << "\tsra     $2,$7,$2" << std::endl;
				}
				//out << "\tsw      $2," << env.symbol_table[((ID_Node*)id)->name] << "($fp)" << std::endl;
				if (((ID_Node*)id)->array_offset == NULL) {
					out << "\tsw      $2," << env.symbol_table[((ID_Node*)id)->name] << "($fp)" << std::endl;
				}
				else {
					out << "\taddu    $fp,$fp,$9" << std::endl;
					out << "\tsw      $2," << env.symbol_table[((ID_Node*)id)->name] << "($fp)" << std::endl;
					out << "\tsubu    $fp,$fp,$9" << std::endl;
				}
			}
			
		}
		else {
			std::cerr << "Error: " << ((ID_Node*)id)->name << " undeclared" << std::endl;
			exit(EXIT_FAILURE);
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


void Call_Node::renderASM(Environment& env, std::ostream& out) {
	if (!env.findSymbol(((ID_Node*)id)->name)) {
		std::cerr << "Warning: implicit declaration of function " << ((ID_Node*)id)->name << std::endl;
	}
	
	if (args != NULL) {
		env.arg_count = 0;
		args->renderASM(env, out);
	}
	out << "\tsw      $31," << env.scope_start-8 << "($sp)" << std::endl;
	out << "\t.option pic0" << std::endl;
	out << "\tjal     " << ((ID_Node*)id)->name << std::endl;
	out << "\tnop" << std::endl << std:: endl;
	out << "\t.option pic2" << std::endl;
	out << "\tlw      $31," << env.scope_start-8 << "($sp)" << std::endl;
	if (is_negative)
		out << "\tsubu    $2,0,$2" << std::endl;

	
}


void Argument_Node::renderASM(Environment& env, std::ostream& out) {
	if (value->node_type == NODE_INTCONST) {
		int n = ((IntConst_Node*)value)->value;
			if (value->is_negative)
				out << "\tli      $" << 4+env.arg_count << ",-" << n << std::endl;
			else
				out << "\tli      $" << 4+env.arg_count << "," << n << std::endl;
	}
	else if (value->node_type == NODE_ID) {
		if (env.symbol_table.find( (((ID_Node*)value)->name ) )  != env.symbol_table.end()) {
			//out << "\tlw      $2," << env.symbol_table[((ID_Node*)value)->name]<<"($fp)" << std::endl;
			
			if (((ID_Node*)value)->array_offset != NULL) {
				((ID_Node*)value)->array_offset->renderASM(env,out);
				out << "\tmove    $8,$2" << std::endl;
				//$8 contains the index
				out << "\taddu    $fp,$fp,$8" << std::endl;
				out << "\tlw      $2," << env.symbol_table[((ID_Node*)value)->name]<<"($fp)" << std::endl;
				out << "\tsubu    $fp,$fp,$8" << std::endl;
			}
			else {
				out << "\tlw      $2," << env.symbol_table[((ID_Node*)value)->name]<<"($fp)" << std::endl;
			}
			
			if (value->is_negative)
				out << "\tsubu    $2,0,$2" << std::endl;
			out << "\tmove    $" << 4+env.arg_count << ",$2" << std::endl;
		}
		else {
			std::cerr << "Error: " << ((ID_Node*)value)->name << " undeclared" << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	else if (value->node_type == NODE_EXPR || value->node_type == NODE_CALL || value->node_type == NODE_TERNARY) {
			value->renderASM(env, out);
			out << "\tmove    $" << 4+env.arg_count << ",$2" << std::endl;
	}
	
	env.arg_count++;
	if (next != NULL) {
		next->renderASM(env, out);
	}

}



void ExprStatement_Node::renderASM(Environment& env, std::ostream& out) {
	expr->renderASM(env, out);
}


void IfStatement_Node::renderASM(Environment& env, std::ostream& out) {
	int old_count;
	env.if_count++;
	if (else_block == NULL) {
		expr->renderASM(env, out);
		out << "\tli      $3,1" << std::endl;
		out << "\tbne     $3,$2,$L" << env.label_count << std::endl;
		out << "\tnop" << std::endl << std::endl;
		old_count = env.label_count;
		env.label_count++;
		body->renderASM(env,out);
		env.label_count = old_count;
		out << "$L" << env.label_count << ":" << std::endl;
		env.label_count+=env.if_count;
		env.if_count = 0;
	}
	else {
		expr->renderASM(env, out);
		out << "\tli      $3,1" << std::endl;
		out << "\tbne     $3,$2,$L" << env.label_count << std::endl;
		out << "\tnop" << std::endl << std::endl;
		old_count = env.label_count;
		env.label_count+=2;
		body->renderASM(env, out);
		env.label_count = old_count;
		out << "\tb       $L" << env.label_count+1 << std::endl;
		out << "\tnop" << std::endl << std::endl;
		out << "$L" << env.label_count << ":" << std::endl;
		old_count = env.label_count;
		env.label_count+=2;
		else_block->renderASM(env, out);
		env.label_count = old_count;
		out << "$L" << env.label_count+1 << ":" << std::endl;
		env.label_count+=(2*env.if_count);
		env.if_count = 0;
	}
}


void WhileStatement_Node::renderASM(Environment& env, std::ostream& out) {
	int old_count, diff;
	out << "\tb       $L" << env.label_count << std::endl;
	out << "\tnop" << std::endl <<std::endl;
	out << "$L" << env.label_count+1 << ":" << std::endl;
	old_count = env.label_count;
	env.label_count+=2;
	body->renderASM(env, out);
	diff = env.label_count - old_count;
	env.label_count = old_count;
	out << "$L" << env.label_count << ":" << std::endl;
	expr->renderASM(env, out);
	out << "\tli      $3,0" << std::endl;
	out << "\tbne     $2,$3,$L" << env.label_count+1 << std::endl;
	out << "\tnop" << std::endl <<std::endl;
	env.label_count+=2+(2*diff);
}

void DoWhileStatement_Node::renderASM(Environment& env, std::ostream& out) {
	int old_count, diff;
	//out << "\tb       $L" << env.label_count << std::endl;
	//out << "\tnop" << std::endl <<std::endl;
	out << "$L" << env.label_count+1 << ":" << std::endl;
	old_count = env.label_count;
	env.label_count+=2;
	body->renderASM(env, out);
	diff = env.label_count - old_count;
	env.label_count = old_count;
	out << "$L" << env.label_count << ":" << std::endl;
	expr->renderASM(env, out);
	out << "\tli      $3,0" << std::endl;
	out << "\tbne     $2,$3,$L" << env.label_count+1 << std::endl;
	out << "\tnop" << std::endl <<std::endl;
	env.label_count+=2+(2*diff);
}

void ForStatement_Node::renderASM(Environment& env, std::ostream& out) {
	int old_count, diff;
	expr1->renderASM(env, out);
	out << "\tb       $L" << env.label_count << std::endl;
	out << "\tnop" << std::endl << std::endl;
	out << "$L" << env.label_count+1 << ":" << std::endl;
	//execute body and then expr3
	old_count = env.label_count;
	env.label_count += 2;
	body->renderASM(env,out);
	diff = env.label_count - old_count;
	env.label_count = old_count;
	expr3->renderASM(env,out);
	out << "$L" << env.label_count << ":" << std::endl;
	//check expr2
	expr2->renderASM(env, out);
	out << "\tli      $3,0" << std::endl;
	out << "\tbne     $2,$3,$L" << env.label_count+1 << std::endl;
	out << "\tnop" << std::endl <<std::endl;
	env.label_count+=2+(2*diff);
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
				//out << "\tlw      $2," << env.symbol_table[((ID_Node*)return_expr)->name]<<"($fp)" << std::endl;
				
				if (((ID_Node*)return_expr)->array_offset != NULL) {
					((ID_Node*)return_expr)->array_offset->renderASM(env,out);
					out << "\tmove    $8,$2" << std::endl;
					//$8 contains the index
					out << "\taddu    $fp,$fp,$8" << std::endl;
					out << "\tlw      $2," << env.symbol_table[((ID_Node*)return_expr)->name]<<"($fp)" << std::endl;
					out << "\tsubu    $fp,$fp,$8" << std::endl;
				}
				else {
					out << "\tlw      $2," << env.symbol_table[((ID_Node*)return_expr)->name]<<"($fp)" << std::endl;
				}
				
				if (return_expr->is_negative)
					out << "\tsubu    $2,0,$2" << std::endl;
			}
			else {
				std::cerr << "Error: " << ((ID_Node*)return_expr)->name << " undeclared" << std::endl;
				exit(EXIT_FAILURE);
			}
		}
		else {
			return_expr->renderASM(env, out);
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
	//assign a register
	if (size > 1) {
		env.addArraySymbol(id->name, size);
	}
	else {
		env.addSymbol(id->name);
	}
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
		else {
			//evaluate expression using $2 and $3 and store final result in $2
			//out << "EVALUATING EXPRESSION" <<std::endl;
			value->renderASM(env, out);
			//out << std::endl;
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
	//void restoreTable(const int& old_offset, const	std::map<std::string, int>& old_table);
	
	if (block_start != NULL) {
		int old_offset;
		std::map<std::string, int> old_table;
		env.saveTable(old_offset, old_table);
		block_start->renderASM(env,out);
		//remove symbols added by block (now out of scope)
		env.restoreTable(old_offset, old_table);
	}


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
	out << "\t.align  2" << std::endl;
	out << "\t.globl  ";
	f_name->getName(env,out);
	out << std::endl;
	out << "\t.set    nomips16" << std::endl;
        //out << "\t.set    nomicromips" << std::endl;
	out << "\t.ent    ";
	f_name->getName(env,out);
	out << std::endl;
	out << "\t.type\t" << ((ID_Node*)f_name)->name << ", @function" << std::endl;
	f_name->getName(env,out);
	out << ":" << std::endl;
	//std::cerr << "function has " << variable_count << " variables" << std::endl;
	
	variable_count += env.global_variable_count;
	
	if (variable_count >= 3) {
		env.scope_start += (variable_count*4);
	}
	else {
		env.scope_start += 4;
	}
	out << "\t.frame  $fp," << env.scope_start+4 << ",$31" << std::endl;
	out << "\t.mask   0x40000000,-4" << std::endl;
	out << "\t.fmask  0x00000000,0" << std::endl;
	out << "\t.set    noreorder" << std::endl;
	out << "\t.set    nomacro" << std::endl;
	out << "\taddiu   $sp,$sp,-" << env.scope_start+4 << std::endl;
	out << "\tsw      $fp," << env.scope_start << "($sp)" << std::endl;
	out << "\tmove    $fp,$sp" << std::endl;		
	
	//add function name to symbol table
	if (!env.findSymbol(((ID_Node*)f_name)->name)) {
		env.addSymbol(((ID_Node*)f_name)->name);
	}
	
	//save current symbol_table (todo)
	int old_offset;
	std::map<std::string, int> old_table;
	env.saveTable(old_offset, old_table);
	
	//add parameters (could be NULL) to symbol table
	//and store parameters onto stack (first four set to $4-$7)
	env.param_index = 0;
	if (parameters_start != NULL) {
		parameters_start->renderASM(env, out);
	}
        
	
	blk->renderASM(env, out);
	
	
	//remove parameters added by function from symbol table (todo)
	env.restoreTable(old_offset, old_table);
	
	
	out << "\tmove    $sp,$fp" << std::endl;
	out << "\tlw      $fp," << env.scope_start << "($sp)" << std::endl;	
	out << "\taddiu   $sp,$sp," << env.scope_start+4 << std::endl;
	out << "\tj       $31" << std::endl;
	out << "\tnop" << std::endl;
	out << std::endl;
	
	out << "\t.set    macro" << std::endl;
        out << "\t.set    reorder" << std::endl;
        out << "\t.end    ";
	f_name->getName(env,out);
	out << std::endl;
        out << "\t.size   ";
	f_name->getName(env,out);
	out << ", .-";
	f_name->getName(env,out);
	out << std::endl;
	
	//increment next fp start to not conflict during function calls
	env.scope_start += 20;
	
	
}


void File_Node::renderASM(Environment& env, std::ostream& out) {
	//out << "\t.file\t1 """ << file_name << """" << std::endl;
	out << "\t.section .mdebug.abi32" << std::endl;
        out << "\t.previous" << std::endl;
	//out << "\t.nan    legacy" << std::endl;
        //out << "\t.module fp=xx" << std::endl;
        //out << "\t.module nooddspreg" << std::endl;
	out << "\t.abicalls" << std::endl;
	out << "\t.text" << std::endl;
	
	
	for (int i=file_list.size()-1; i>=0; i--) {
		(file_list[i])->renderASM(env, out);
	}
	//out << "end" << std::endl;
}
