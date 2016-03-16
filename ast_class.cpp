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

init::init(expr_node *expression){
	assign = expression;
}

void init::print(){
	assign->print();
}

void init::evaluate(){
	cout << "init: " << assign->evaluate();
}

dir_declr::dir_declr(string id){
	ident = id;
}

void dir_declr::print(){
	cout << ident;
}

void dir_declr::evaluate(){
	cout << "declr id: " << ident << " ";
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

void init_declr::evaluate(){
	declarator->evaluate();
	initializer->evaluate();
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

void decln::evaluate(){
	cout << "declaration of type: " << type << " ";
	declarator->evaluate();
	cout << endl;
}	

map<string, int> idMap;

