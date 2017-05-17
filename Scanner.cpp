#include <iostream>
#include "Scanner.h"

using namespace std;
Tokenizer BufToken = {"", 0};

ifstream infile("inputfile.txt");
//#define infile cin

void Scanner::Init()
{
	current = getNextToken(infile);
}
// does not read anything from input
Tokenizer Scanner::GetCurrent()
{
	return current;
}
void Scanner::MoveToNext()
{
	current = getNextToken(infile);
}

void Scanner::ScannerPrint()
{
	Tokenizer token;
	int numLiteralAtom = 0;
	int numNumericAtom = 0;
	int sumNumericAtom = 0;
	int numOpenPar = 0;
	int numClosePar = 0;
	string AllLiteral = "";
	while (!infile.eof())
	{
		token = getNextToken(infile);
		int TokenType = token.TokenType;
		switch(TokenType)
		{
		case LiteralAtom:
			numLiteralAtom++;
			AllLiteral += ",";
			AllLiteral += token.TokenString;
			break;
		case NumericAtom:
			numNumericAtom++;
			sumNumericAtom += atoi(token.TokenString.c_str());
			break;
		case OpenParenthesis:
			numOpenPar++;
			break;
		case ClosingParenthesis:
			numClosePar++;
			break;
		}
	}
	cout << "LITERAL ATOMS: " <<  numLiteralAtom << AllLiteral << endl;
	cout << "NUMERIC ATOMS: " << numNumericAtom << "," << sumNumericAtom << endl;
	cout << "OPEN PARENTHESES: " << numOpenPar << endl;
	cout << "CLOSING PARENTHESES: " << numClosePar << endl;
}

Tokenizer Scanner::getNextToken(istream & inputFile)
{
	Tokenizer token;
	char CurChar;
	while (true)
	{
		if (!BufToken.TokenString.empty())
		{
			Tokenizer temp = BufToken;
			BufToken.TokenString = "";
			return temp;
		}
		CurChar = inputFile.get();
		switch (CurChar)
		{
			// check the string in TokenString
		case ' ': case '\r': case '\n': case -1:
			if (token.TokenString.empty())
			{
				//consume all white spaces
				if (CurChar == -1)
				{
					token.TokenString = "EOF";
					token.TokenType = Eof;
					return token;
				}
				continue;
			}
			else
			{
				if (IsLiteralAtom(token.TokenString))
				{
					token.TokenType = LiteralAtom;
				}
				else if (IsNumericAtom(token.TokenString))
				{
					token.TokenType = NumericAtom;
				}
				else
				{
					token.TokenType = ErrorToken;
					return token;
				}
			}
			return token;
		case '(':
			if (token.TokenString.empty())
			{
				token.TokenType = OpenParenthesis;
				token.TokenString = '(';
			}
			else
			{
				if (IsLiteralAtom(token.TokenString))
				{
					token.TokenType = LiteralAtom;
				}
				else if (IsNumericAtom(token.TokenString))
				{
					token.TokenType = NumericAtom;
				}
				BufToken.TokenString = '(';
				BufToken.TokenType = OpenParenthesis;
			}
			return token;
		case ')':
			if (token.TokenString.empty())
			{
				token.TokenType = ClosingParenthesis;
				token.TokenString = ')';
			}
			else
			{
				if (IsLiteralAtom(token.TokenString))
				{
					token.TokenType = LiteralAtom;
				}
				else if (IsNumericAtom(token.TokenString))
				{
					token.TokenType = NumericAtom;
				}
				BufToken.TokenString = ')';
				BufToken.TokenType = ClosingParenthesis;
			}
			return token;
		default:
			token.TokenString += CurChar;
		}
	}
}


bool Scanner::IsLiteralAtom(string S)
{
	// check if the string is empty
	if (S.empty())
		return false;
	// check the first character of the string
	else if (S[0] < 'A' || S[0] > 'Z')
		return false;
	else
	{
		// check other characters 
		for (int i = 1; (unsigned)i<S.size(); i++)
		{
			if ((S[i] < '0' || (S[i] > '9' && S[i] < 'A') || S[i] > 'Z'))
				return false;
		}
		return true;
	}
}

bool Scanner::IsNumericAtom(string S)
{
	if (S.empty())
		return false;
	else
	{
		for (int i = 0; (unsigned)i < S.size(); i++)
		{
			if (S[i] < '0' || S[i] > '9')
				return false;
		}
	}
	return true;
}