#include "Scanner.h"

#ifndef PARSER_H
#define PARSER_H

class TreeNode
{
public:
	TreeNode(): Left(NULL), Right(NULL)
	{}
	string KeyValue;
	int Type;
	int LowLenList;
	TreeNode * Left;
	TreeNode * Right;
} ;

class Parser {
public:
	Scanner scan;
public:
	void ParseExpr(TreeNode * root);
	void ParseStart();
	// dot notation print
	void ParserPrint(TreeNode * T);
	bool IsNumericAtom(string S);
	bool IsLiteralAtom(string S);
};

#endif