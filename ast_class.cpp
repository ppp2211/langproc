#include <iostream>
#include <string>
#include <map>
#include <list>
#include "ast_class.hpp"
using namespace std;


op_node::op_node(expr_node *L, string sign, expr_node *R){
	left = L;
	right = R;
	op = sign;
}

void op_node::print(){ 
	cout << "(";
	left->print();
	cout << " " << op << " ";
	right->print();
	cout << ")"; 
}

int op_node::evaluate(){
	int left_val, right_val;
	left_val = left->evaluate();
	right_val = right->evaluate();
	
	if (op == "+"){
		value = left_val + right_val;
		cout << "operator node: " << left_val << " "<< op << " " << right_val << " = " << value << endl;
	}	
	
	else if (op == "-"){
		value = left_val - right_val;
		cout << "operator node: " << left_val << " "<< op << " " << right_val << " = " << value << endl;
	}	
	
	else if (op == "/"){
		value = left_val / right_val;
		cout << "operator node: " << left_val << " "<< op << " " << right_val << " = " << value << endl;
	}	
	
	else if (op == "*"){
		value = left_val * right_val;
		cout << "operator node: " << left_val << " "<< op << " " << right_val << " = " << value << endl;
	}	
	
	else if (op == "%"){
		value = left_val % right_val;
		cout << "operator node: " << left_val << " "<< op << " " << right_val << " = " << value << endl;
	}	


	return value;
}

int_node::int_node(int number){
	value = number;
}

void int_node::print(){
	cout << value;
}

int int_node::evaluate(){
	cout << "int constant = " << value << endl;
	return value;
}

id_node::id_node(string ident){
	id = ident;
}

void id_node::print(){
	cout << id;
}

int id_node::evaluate(){
	cout << "id: " << " = " << idMap[id] << endl;
	return idMap[id];
}

/*assignment::assignment(string name, expr_node *expression){
	id = name;
	expr = expression;
}

void assignment::evaluate(){
	int result = expr->evaluate();
	cout << "assignment: " << id << " = " << result << endl;
	idTable[id] = result;
}

void assignment::print(){
	cout << id << " = ";
	exp->print();
	cout << endl;
}
*/

string declarations::eval_str(){
	return "invalid_type";
}

init::init(expr_node *expression){
	assign = expression;
}

void init::print(){
	assign->print();
}

int init::evaluate(){
	cout << "init: ";
	int tmp = assign->evaluate();
	return tmp;
}

dir_declr::dir_declr(string id){
	ident = id;
}

void dir_declr::print(){
	cout << ident;
}

int dir_declr::evaluate(){
	return 0;
}

string dir_declr::eval_str(){
	cout << "declr id: " << ident << " ";
	return ident;
}

init_declr::init_declr(declarations *dec, declarations *initzer){
	declarator = dec;
	initializer = initzer;
}

void init_declr::print(){
	declarator->print();
	cout << " = ";
	initializer->print();
}

int init_declr::evaluate(){
	string tmpid = declarator->eval_str();
	int tmpval = initializer->evaluate();
	idMap[tmpid] = tmpval;
	return tmpval;
}	

decln::decln (string typespec, declarations *decl){	
	type = typespec;
	declarator = decl;
}

void decln::print(){
	cout << type << " ";
	declarator->print();
	cout << endl;
}

int decln::evaluate(){
	cout << "declaration of type: " << type << " ";
	int tmp = declarator->evaluate();
	cout << endl;
	return tmp;
}	

trans_unit::trans_unit(declarations* T, declarations* D){
	translu = T;
	decl = D;
}

void trans_unit::print(){
	if(translu != NULL){	
		translu->print();
	}	
	decl->print();
}

int trans_unit::evaluate(){
	if(translu != NULL){
		translu->evaluate();
	}	
	return decl->evaluate();
	
}

comp_stmt::comp_stmt(declarations* D, stmt* S){
	declnlist = D;
	stmtlist = S;
}

void comp_stmt::print(){
	if(declnlist != NULL){
		declnlist->print();
	}
	if(stmtlist != NULL){
		stmtlist->print();
	}
}

int comp_stmt::evaluate(){
	if(declnlist != NULL){
		declnlist->evaluate();
	}
	if(stmtlist != NULL){
		stmtlist->evaluate();
	}
	return 0;
}

declnlist::declnlist(declarations* L, declarations* R){
	left = L;
	right = R;
}

void declnlist::print(){
	if(left != NULL){
		left->print();
	}
	if(right != NULL){
		right->print();
	}
}

int declnlist::evaluate(){
	if(left != NULL){
		left->evaluate();
	}
	if(right != NULL){
		right->evaluate();
	}
}

stmtlist::stmtlist(stmt* L, stmt* R){
	left = L;
	right = R;
}

void stmtlist::print(){
	if(left != NULL){
		left->print();
	}
	if(right != NULL){
		right->print();
	}
}

int stmtlist::evaluate(){
	if(left != NULL){
		left->evaluate();
	}
	if(right != NULL){
		right->evaluate();
	}
}

expr_stmt::expr_stmt(expr_node* exprnode){
	expr = exprnode;
}

void expr_stmt::print(){
	if(expr != NULL){
		expr->print();
	}
}


int expr_stmt::evaluate(){
	if(expr != NULL){
		expr->evaluate();
	}
}

fn_defn::fn_defn(declarations* declnlist, stmt* compstmt){
	decln_l = declnlist;
	comp_stmt = compstmt;
}

void fn_defn::print(){
	if(decln_l != NULL){
		decln_l->print();
	}
	comp_stmt->print();
}

int fn_defn::evaluate(){
	if(decln_l != NULL){
		decln_l->evaluate();
	}
	comp_stmt->evaluate();
	return 0;
}
map<string, int> idMap;

