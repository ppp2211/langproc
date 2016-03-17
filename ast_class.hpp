#ifndef AST_CLASS_HPP
#define AST_CLASS_HPP

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>

using namespace std;

class expr_node{
	public:
		virtual void print() = 0;
		virtual int evaluate() = 0;
		virtual string eval_str();
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
		string eval_str();
};


class declarations{
	public:
		virtual void print() = 0;
		virtual int evaluate() = 0;
		virtual string eval_str();
};

class dir_declr : public declarations{
	protected:
		string ident;
	public:
		dir_declr(string id);
		void print();
		int evaluate();
		string eval_str();
};

class init : public declarations{
	protected:
		expr_node *assign;
	public:
		init(expr_node *expression);
		void print();
		int evaluate();
};

class init_declr : public declarations{
	protected:
		declarations *declarator;
		declarations *initializer;
	public:
		init_declr(declarations *dec, declarations *initzer);
		void print();
		int evaluate();
};

class decln : public declarations{
	protected:
		string type;
		declarations *declarator;
	public:
		decln(string typespec, declarations *decl);
		void print();
		int evaluate();
};	

class trans_unit : public declarations{
	protected:	
		declarations* translu;
		declarations* decl;

	public:
		trans_unit(declarations* T, declarations* D);
		void print();
		int evaluate();
};

class stmt{
	public:
		virtual void print() = 0;
		virtual int evaluate() = 0;
};

class comp_stmt : public stmt{
	protected:
		declarations* declnlist;
		stmt* stmtlist;
	public:
		comp_stmt(declarations* D, stmt* S);
		void print();
		int evaluate();	
};

class declnlist : public declarations{
	protected:
		declarations* left;
		declarations* right;
	public:
	 	declnlist(declarations* L, declarations* R);
		void print();
		int evaluate();
};	

class stmtlist : public stmt{
	protected:
		stmt* left;
		stmt* right;
	public:
		stmtlist(stmt* L, stmt* R);
		void print();
		int evaluate();
};

class expr_stmt : public stmt{
	protected:
		expr_node* expr;
	public:
		expr_stmt(expr_node* exprnode);
		void print();
		int evaluate();
};

class fn_defn : public declarations{
	protected:
		string type;
		declarations* decln_l;
		stmt* comp_stmt;
	public:
		fn_defn(string typespec, declarations* declnlist, stmt* compstmt);
		void print();
		int evaluate();
};

extern map<string, int> idMap;

class assign_expr : public expr_node{
	protected:
		expr_node* id;
		expr_node* val;

	public:
		assign_expr(expr_node* ident, expr_node* value);
		void print();
		int evaluate();	
};

class return_stmt : public stmt{
	protected:
		expr_node* return_expr;
	public:
		return_stmt(expr_node* expr);
		void print();
		int evaluate();	
};

#endif
