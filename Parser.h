#include "Scanner.h"
#ifndef PARSER_H
#define PARSER_H

class TreeNode
{
public:
	TreeNode(): Left(NULL), Right(NULL)
	{}
	string KeyValue;
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
};

#endif