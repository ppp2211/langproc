#ifndef AST_CLASS_HPP
#define AST_CLASS_HPP

#include <iostream>
#include <string>
#include <list>
#include <map>

using namespace std;

class expr_node{
	public:
		virtual void print() = 0;
		virtual int evaluate() = 0;
};

class op_node : public expr_node {
	protected:
		int value;	
		expr_node *left;
		expr_node *right;
		string op;
	public:
		op_node(expr_node *L, string sign, expr_node *R);
		void print();
		int evaluate();
};

class int_node : public expr_node{
	protected:	
		int value;
	public:
		int_node(int number);
		void print();
		int evaluate();
};

class id_node : public expr_node{
	protected:
		string id;
	public:
		id_node(string ident);
		void print();
		int evaluate();
};

/*class stmt{
	public:
		virtual void print() = 0;
		virtual void evaluate() = 0;
};

class assignment : public statement{
	protected:
		string id;
		expr_node *expr;
	public:
		assignment(string name, expr_node *expression);
		void print();
		void evaluate();
};
*/

class declarations{
	public:
		virtual void print() = 0;
		virtual void evaluate() = 0;
};

class dir_declr : public declarations{
	protected:
		string ident;
	public:
		dir_declr(string id);
		void print();
		void evaluate();
};

class init : public declarations{
	protected:
		expr_node *assign;
	public:
		init(expr_node *expression);
		void print();
		void evaluate();
};

class init_declr : public declarations{
	protected:
		declarations *declarator;
		declarations *initializer;
	public:
		init_declr(declarations *dec, declarations *initzer);
		void print();
		void evaluate();
};

class decln : public declarations{
	protected:
		string type;
		declarations *declarator;
	public:
		decln(string typespec, declarations *decl);
		void print();
		void evaluate();
};	


extern map<string, int> idMap;


#endif
