#include "Parser.h"
#include <sstream>

#ifndef TYPECHECKER_H
#define TYPECHECKER_H

const int List_nat = 11, Nat = 22, Bool = 33;

class Typechecker
{
public:
	Parser parse2;
public:
	int Length(TreeNode * InputTree);
	TreeNode* Car(TreeNode * InputTree);
	TreeNode* CarType(TreeNode* InputTree);
	TreeNode* Cdr(TreeNode * InputTree);
	TreeNode* CdrType(TreeNode* InputTree);
	TreeNode* Cons(TreeNode * InputTree1, TreeNode * InputTree2);
	TreeNode* Atom(TreeNode * InputTree);
	TreeNode* Int(TreeNode * InputTree);
	TreeNode* Null(TreeNode * InputTree);
	TreeNode* Eq(TreeNode * InputTree1, TreeNode * InputTree2);
	TreeNode* Plus(TreeNode * InputTree1, TreeNode * InputTree2);
	TreeNode* Minus(TreeNode * InputTree1, TreeNode * InputTree2);
	TreeNode* Times(TreeNode * InputTree1, TreeNode * InputTree2);
	TreeNode* Less(TreeNode * InputTree1, TreeNode * InputTree2);
	TreeNode* Greater(TreeNode * InputTree1, TreeNode * InputTree2);
	TreeNode* Eval(TreeNode * T);
	void EvalStart();
	void ListNotationPrint(TreeNode * T);
};

#endif