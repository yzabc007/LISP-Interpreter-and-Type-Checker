#include "Parser.h"
#include <sstream>

#ifndef INTERPRETER_H
#define INTERPRETER_H

class Interpreter
{
public:
	Parser parse;
	TreeNode * global_d_list;
	std::set<std::string> setOfBuiltinFunc;
public:
	int Length(TreeNode * InputTree);
	TreeNode* Car(TreeNode * InputTree);
	TreeNode* Cdr(TreeNode * InputTree);
	TreeNode* Cons(TreeNode * InputTree1, TreeNode * InputTree2);
	TreeNode* Atom(TreeNode * InputTree);
	TreeNode* Int(TreeNode * InputTree);
	TreeNode* Literal(TreeNode* InputTree);
	TreeNode* Null(TreeNode * InputTree);
	TreeNode* Eq(TreeNode * InputTree1, TreeNode * InputTree2);
	TreeNode* Plus(TreeNode * InputTree1, TreeNode * InputTree2);
	TreeNode* Minus(TreeNode * InputTree1, TreeNode * InputTree2);
	TreeNode* Times(TreeNode * InputTree1, TreeNode * InputTree2);
	TreeNode* Less(TreeNode * InputTree1, TreeNode * InputTree2);
	TreeNode* Greater(TreeNode * InputTree1, TreeNode * InputTree2);
	TreeNode* Eval(TreeNode * T, TreeNode * a, TreeNode * d);
	void EvalStart();
	void ListNotationPrint(TreeNode * T);

	TreeNode* apply(TreeNode* f, TreeNode* x, TreeNode* a, TreeNode* d);
	// helper function
	TreeNode* bound(TreeNode* x, TreeNode* z);
	TreeNode* getval(TreeNode* x, TreeNode* z);
	TreeNode* addpairs(TreeNode* xlist, TreeNode* ylist, TreeNode* z);
	TreeNode* evcon(TreeNode* x, TreeNode* a, TreeNode* d);
	TreeNode* evlist(TreeNode* x, TreeNode* a, TreeNode*d);
	void CompleteSet();
	void evaluateFormPara(TreeNode* x);
	TreeNode* GenerateLongList(int num_list);
};

#endif