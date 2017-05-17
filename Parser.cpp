#include "Parser.h"

void Parser::ParseExpr(TreeNode * root)
{
	TreeNode *LeftChild, *RightChild;
	// consume atom, set it as left child
	if (scan.GetCurrent().TokenType == LiteralAtom || scan.GetCurrent().TokenType == NumericAtom)
	{
		root->KeyValue = scan.GetCurrent().TokenString;
		scan.MoveToNext();
	}
	// consume open parenthesis, get next token
	else if (scan.GetCurrent().TokenType == OpenParenthesis)
	{
		scan.MoveToNext();
		TreeNode *cur_root = root;
		// if next token is not closing parenthesis, go subtree
		while (scan.GetCurrent().TokenType != ClosingParenthesis)
		{
			LeftChild = new TreeNode;
			RightChild = new TreeNode;

			cur_root->Left = LeftChild;
			cur_root->Right = RightChild;

			ParseExpr(LeftChild);
			cur_root = RightChild;
		}
		cur_root->KeyValue = "NIL";
		// consume closing parenthesis, get next token
		scan.MoveToNext();
	}
	else if(scan.GetCurrent().TokenType == ErrorToken)
	{
		cout << "ERROR: Invalid token " << scan.GetCurrent().TokenString << endl;
		exit(1);
	}
	// if open and closing parenthesis are not match, report error
	else if(scan.GetCurrent().TokenType == Eof)
	{
		cout << "ERROR: Missing a Closing Parenthesis " << endl;
		exit(1);
	}
	else if (scan.GetCurrent().TokenType == ClosingParenthesis)
	{
		cout << "ERROR: Missing a Opening Parenthesis " << endl;
		exit(1);
	}
	else
	{
		cout << "ERROR: Mismatching Parentheses " << endl;
		exit(1);
	}
}

void Parser::ParseStart()
{
	scan.Init();
	if (scan.GetCurrent().TokenType == Eof)
	{
		cout << "ERROR: Empty Input " << endl;
		exit(1);
	}
	do 
	{
		TreeNode * T = new TreeNode;
		ParseExpr(T);
		ParserPrint(T);
		cout << endl;
	} while (scan.GetCurrent().TokenType != Eof);
}

void Parser::ParserPrint(TreeNode * T)
{
	if (scan.IsLiteralAtom(T->KeyValue) || scan.IsNumericAtom(T->KeyValue))
	{
		cout << T->KeyValue;
	}
	else
	{
		cout << '(';
		ParserPrint(T->Left);
		cout << " . ";
		ParserPrint(T->Right);
		cout << ')';
	}
}
