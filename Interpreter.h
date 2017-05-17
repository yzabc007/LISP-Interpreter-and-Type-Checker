#include "Parser.h"
#include "TypeChecker.h"
#include "Emptylistchecker.h"
#include <sstream>

#ifndef INTERPRETER_H
#define INTERPRETER_H

class Interpreter
{
public:
	Parser parse;
	Typechecker typechecker;
	Emptylistchecker empthlistchecker;

public:
	int Length(TreeNode * InputTree);
	TreeNode* Car(TreeNode * InputTree);
	TreeNode* Cdr(TreeNode * InputTree);
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