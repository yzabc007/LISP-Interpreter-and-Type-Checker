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
private:
	Scanner scan;
public:
	void ParseExpr(TreeNode * root);
	void ParseStart();
	void ParserPrint(TreeNode * T);
};

#endif