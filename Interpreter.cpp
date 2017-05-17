#include "Interpreter.h"

int Interpreter::Length(TreeNode * root)
{
	int len;
	if (root != NULL)
	{
		if (root->Left == NULL && root->Right == NULL)
		{
			len = 1;
		}
		else
		{
			len = 1;
			TreeNode* current = root;
			while (current->Right->KeyValue.compare("NIL"))
			{
				len++;
				current = current->Right;
			}
		}
	}
	else
	{
		len = 0;
	}
	return len;
}

TreeNode* Interpreter::Car(TreeNode * InputTree)
{
	if(InputTree->Left != NULL  && InputTree->Right != NULL)
	{
		return InputTree->Left;
	}
	else
	{
		cout << "ERROR: CAR function is undefined -> Input of Car function contains only one node: ";
		parse.ParserPrint(InputTree);
		cout << endl;
		exit(1);
	}
}

TreeNode* Interpreter::Cdr(TreeNode * InputTree)
{
	if(InputTree->Left != NULL && InputTree->Right != NULL)
	{
		return InputTree->Right;
	}
	else
	{
		cout << "ERROR: CDR function is undefined -> Input of Cdr function contains only one node: ";
		parse.ParserPrint(InputTree);
		cout << endl;
		exit(1);
	}
}

TreeNode* Interpreter::Cons(TreeNode * InputTree1, TreeNode * InputTree2)
{
	TreeNode * root = new TreeNode;
	root->Left = InputTree1;
	root->Right = InputTree2;
	return root;
}

TreeNode* Interpreter::Atom(TreeNode * InputTree)
{
	TreeNode * root = new TreeNode;
	if(InputTree->Left == NULL && InputTree->Right == NULL)
	{
		root->KeyValue = "T";
		return root;
	}
	else
	{
		root->KeyValue = "NIL";
		return root;
	}
}

TreeNode* Interpreter::Int(TreeNode * InputTree)
{
	TreeNode * root = new TreeNode;
	if (InputTree->Left == NULL && InputTree->Right == NULL && parse.scan.IsNumericAtom(InputTree->KeyValue))
	{
		root->KeyValue = "T";
		return root;
	}
	else
	{
		root->KeyValue = "NIL";
		return root;
	}
}

TreeNode* Interpreter::Null(TreeNode * InputTree)
{
	TreeNode * root = new TreeNode;
	if (InputTree->Left == NULL && InputTree->Right == NULL && !InputTree->KeyValue.compare("NIL"))
	{
		root->KeyValue = "T";
		return root;
	}
	else
	{
		root->KeyValue = "NIL";
		return root;
	}
}

TreeNode* Interpreter::Eq(TreeNode * InputTree1, TreeNode * InputTree2)
{
	TreeNode * root = new TreeNode;
	if (!Atom(InputTree1)->KeyValue.compare("NIL"))
	{
		cout << "ERROR: EQ function is undefined -> The first input of Eq function has more than one node: ";
		parse.ParserPrint(InputTree1);
		cout << endl;
		exit(1);
	}
	else if(!Atom(InputTree2)->KeyValue.compare("NIL"))
	{
		cout << "ERROR: EQ function is undefined -> The second input of Eq function has more than one node: ";
		parse.ParserPrint(InputTree2);
		cout << endl;
		exit(1);
	}
	else if (!InputTree1->KeyValue.compare(InputTree2->KeyValue) && parse.scan.IsNumericAtom(InputTree1->KeyValue))
	{
		root->KeyValue = "T";
		return root;
	}
	else if (!InputTree1->KeyValue.compare(InputTree2->KeyValue) && parse.scan.IsLiteralAtom(InputTree1->KeyValue))
	{
		root->KeyValue = "T";
		return root;
	}
	else
	{
		root->KeyValue = "NIL";
		return root;
	}
}

TreeNode* Interpreter::Plus(TreeNode * InputTree1, TreeNode * InputTree2)
{
	TreeNode * root = new TreeNode;
	if (!Atom(InputTree1)->KeyValue.compare("NIL") || !parse.scan.IsNumericAtom(InputTree1->KeyValue))
	{
		cout << "ERROR: PLUS function is undefined -> The first input of Plus function is not a numeric atom: ";
		parse.ParserPrint(InputTree1);
		cout << endl;
		exit(1);
	}
	else if (!Atom(InputTree2)->KeyValue.compare("NIL") || !parse.scan.IsNumericAtom(InputTree2->KeyValue))
	{
		cout << "ERROR: PLUS function is undefined -> The second input of Plus function is not a numeric atom: ";
		parse.ParserPrint(InputTree2);
		cout << endl;
		exit(1);
	}
	else
	{
		int temp_int;
		string str;
		ostringstream temp;
		temp_int = atoi(InputTree1->KeyValue.c_str()) + atoi(InputTree2->KeyValue.c_str());
		temp << temp_int;
		root->KeyValue = temp.str();
		return root;
	}
}

TreeNode* Interpreter::Minus(TreeNode * InputTree1, TreeNode * InputTree2)
{
	TreeNode * root = new TreeNode;
	if (!Atom(InputTree1)->KeyValue.compare("NIL") || !parse.scan.IsNumericAtom(InputTree1->KeyValue))
	{
		cout << "ERROR: MINUS function is undefined -> The first input of Minus function is not a numeric atom: ";
		parse.ParserPrint(InputTree1);
		cout << endl;
		exit(1);
	}
	else if (!Atom(InputTree2)->KeyValue.compare("NIL") || !parse.scan.IsNumericAtom(InputTree2->KeyValue))
	{
		cout << "ERROR: MINUS function is undefined -> The second input of Minus function is not a numeric atom: ";
		parse.ParserPrint(InputTree2);
		cout << endl;
		exit(1);
	}
	else
	{
		int temp_int;
		string str;
		ostringstream temp;
		temp_int = atoi(InputTree1->KeyValue.c_str()) - atoi(InputTree2->KeyValue.c_str());
		temp << temp_int;
		root->KeyValue = temp.str();
		return root;
	}
}

TreeNode* Interpreter::Times(TreeNode * InputTree1, TreeNode * InputTree2)
{
	TreeNode * root = new TreeNode;
	if (!Atom(InputTree1)->KeyValue.compare("NIL") || !parse.scan.IsNumericAtom(InputTree1->KeyValue))
	{
		cout << "ERROR: TIMES function is undefined -> The first input of Times function is not a numeric atom: ";
		parse.ParserPrint(InputTree1);
		cout << endl;
		exit(1);
	}
	else if (!Atom(InputTree2)->KeyValue.compare("NIL") || !parse.scan.IsNumericAtom(InputTree2->KeyValue))
	{
		cout << "ERROR: TIMES function is undefined -> The second input of Times function is not a numeric atom: ";
		parse.ParserPrint(InputTree2);
		cout << endl;
		exit(1);
	}
	else
	{
		int temp_int;
		string str;
		ostringstream temp;
		temp_int = atoi(InputTree1->KeyValue.c_str()) * atoi(InputTree2->KeyValue.c_str());
		temp << temp_int;
		root->KeyValue = temp.str();
		return root;
	}
}

TreeNode* Interpreter::Less(TreeNode * InputTree1, TreeNode * InputTree2)
{
	TreeNode * root = new TreeNode;
	if (!Atom(InputTree1)->KeyValue.compare("NIL") || !parse.scan.IsNumericAtom(InputTree1->KeyValue))
	{
		cout << "ERROR: LESS function is undefined -> The first input of Less function is not a numeric atom: ";
		parse.ParserPrint(InputTree1);
		cout << endl;
		exit(1);
	}
	else if (!Atom(InputTree2)->KeyValue.compare("NIL") || !parse.scan.IsNumericAtom(InputTree2->KeyValue))
	{
		cout << "ERROR: LESS function is undefined -> The second input of Less function is not a numeric atom: ";
		parse.ParserPrint(InputTree2);
		cout << endl;
		exit(1);
	}
	else
	{
		if(atoi(InputTree1->KeyValue.c_str()) < atoi(InputTree2->KeyValue.c_str()))
		{
			root->KeyValue = "T";
			return root;
		}
		else
		{
			root->KeyValue = "NIL";
			return root;
		}
	}
}

TreeNode* Interpreter::Greater(TreeNode * InputTree1, TreeNode * InputTree2)
{
	TreeNode * root = new TreeNode;
	if (!Atom(InputTree1)->KeyValue.compare("NIL") || !parse.scan.IsNumericAtom(InputTree1->KeyValue))
	{
		cout << "ERROR: GREATER function is undefined -> The first input of Greater function is not a numeric atom: ";
		parse.ParserPrint(InputTree1);
		cout << endl;
		exit(1);
	}
	else if (!Atom(InputTree2)->KeyValue.compare("NIL") || !parse.scan.IsNumericAtom(InputTree2->KeyValue))
	{
		cout << "ERROR: GREATER function is undefined -> The second input of Greater function is not a numeric atom: ";
		parse.ParserPrint(InputTree2);
		cout << endl;
		exit(1);
	}
	else
	{
		if(atoi(InputTree1->KeyValue.c_str()) > atoi(InputTree2->KeyValue.c_str()))
		{
			root->KeyValue = "T";
			return root;
		}
		else
		{
			root->KeyValue = "NIL";
			return root;
		}
	}
}

TreeNode* Interpreter::Eval(TreeNode * root)
{
	// exp is an atom
	if (root->Left == NULL && root->Right == NULL)
	{
		if (!root->KeyValue.compare("T") || !root->KeyValue.compare("NIL") || parse.scan.IsNumericAtom(root->KeyValue))
		{
			return root;
		}
		else
		{
			cout << "ERROR: Eval function is undefined -> unbound literal: "<< root->KeyValue << endl;
			exit(1);
		}
	}
	// exp must be a list
	else
	{
		TreeNode * carTree = Car(root);
		string funcName = carTree->KeyValue;
		if (!funcName.compare("PLUS"))
		{
			if (Length(root) != 3)
			{
				cout << "ERROR: PLUS of Eval function is undefined -> The length of input ";
				parse.ParserPrint(root);
				cout <<" is " << Length(root) << " instead of 3.";
				cout << endl;
				exit(1);
			}
			else
			{
				TreeNode * s1 = Car(Cdr(root));
				TreeNode * s2 = Car(Cdr(Cdr(root)));
				return Plus(Eval(s1),Eval(s2));
			}
		}
		else if (!funcName.compare(("MINUS")))
		{
			if (Length(root) != 3)
			{
				cout << "ERROR: MINUS of Eval function is undefined -> The length of input ";
				parse.ParserPrint(root);
				cout <<" is " << Length(root) << " instead of 3.";
				cout << endl;
				exit(1);
			}
			else
			{
				TreeNode * s1 = Car(Cdr(root));
				TreeNode * s2 = Car(Cdr(Cdr(root)));
				return Minus(Eval(s1),Eval(s2));
			}
		}
		else if(!funcName.compare("TIMES"))
		{
			if (Length(root) != 3)
			{
				cout << "ERROR: TIMES of Eval function is undefined -> The length of input ";
				parse.ParserPrint(root);
				cout <<" is " << Length(root) << " instead of 3.";
				cout << endl;
				exit(1);
			}
			else
			{
				TreeNode * s1 = Car(Cdr(root));
				TreeNode * s2 = Car(Cdr(Cdr(root)));
				return Times(Eval(s1),Eval(s2));
			}
		}
		else if (!funcName.compare("LESS"))
		{
			if (Length(root) != 3)
			{
				cout << "ERROR: LESS of Eval function is undefined -> The length of input ";
				parse.ParserPrint(root);
				cout <<" is " << Length(root) << " instead of 3.";
				cout << endl;
				exit(1);
			}
			else
			{
				TreeNode * s1 = Car(Cdr(root));
				TreeNode * s2 = Car(Cdr(Cdr(root)));
				return Less(Eval(s1),Eval(s2));
			}
		}
		else if (!funcName.compare("GREATER"))
		{
			if (Length(root) != 3)
			{
				cout << "ERROR: GREATER of Eval function is undefined -> The length of input ";
				parse.ParserPrint(root);
				cout <<" is " << Length(root) << " instead of 3.";
				cout << endl;
				exit(1);
			}
			else
			{
				TreeNode * s1 = Car(Cdr(root));
				TreeNode * s2 = Car(Cdr(Cdr(root)));
				return Greater(Eval(s1),Eval(s2));
			}
		}
		else if (!funcName.compare("EQ"))
		{
			if (Length(root) != 3)
			{
				cout << "ERROR: EQ of Eval function is undefined -> The length of input ";
				parse.ParserPrint(root);
				cout <<" is " << Length(root) << " instead of 3.";
				cout << endl;
				exit(1);
			}
			else
			{
				TreeNode * s1 = Car(Cdr(root));
				TreeNode * s2 = Car(Cdr(Cdr(root)));
				return Eq(Eval(s1),Eval(s2));
			}
		}
		else if (!funcName.compare("ATOM"))
		{
			if (Length(root) != 2)
			{
				cout << "ERROR: ATOM of Eval function is undefined -> The length of input ";
				parse.ParserPrint(root);
				cout <<" is " << Length(root) << " instead of 2.";
				cout << endl;
				exit(1);
			}
			else
			{
				TreeNode * s = Car(Cdr(root));
				return Atom(Eval(s));
			}
		}
		else if (!funcName.compare("INT"))
		{
			if (Length(root) != 2)
			{
				cout << "ERROR: INT of Eval function is undefined -> The length of input ";
				parse.ParserPrint(root);
				cout <<" is " << Length(root) << " instead of 2.";
				cout << endl;
				exit(1);
			}
			else
			{
				TreeNode * s = Car(Cdr(root));
				return Int(Eval(s));
			}
		}
		else if (!funcName.compare("NULL"))
		{
			if (Length(root) != 2)
			{
				cout << "ERROR: NULL of Eval function is undefined -> The length of input ";
				parse.ParserPrint(root);
				cout <<" is " << Length(root) << " instead of 2.";
				cout << endl;
				exit(1);
			}
			else
			{
				TreeNode * s = Car(Cdr(root));
				return Null(Eval(s));
			}
		}
		else if (!funcName.compare("CAR"))
		{
			if (Length(root) != 2)
			{
				cout << "ERROR: CAR of Eval function is undefined -> The length of input ";
				parse.ParserPrint(root);
				cout <<" is " << Length(root) << " instead of 2.";
				cout << endl;
				exit(1);
			}
			else
			{
				TreeNode * s = Car(Cdr(root));
				return Car(Eval(s));
			}
		}
		else if (!funcName.compare("CDR"))
		{
			if (Length(root) != 2)
			{
				cout << "ERROR: CDR of Eval function is undefined -> The length of input ";
				parse.ParserPrint(root);
				cout <<" is " << Length(root) << " instead of 2.";
				cout << endl;
				exit(1);
			}
			else
			{
				TreeNode * s = Car(Cdr(root));
				return Cdr(Eval(s));
			}
		}
		else if (!funcName.compare("CONS"))
		{
			if (Length(root) != 3)
			{
				cout << "ERROR: CONS of Eval function is undefined -> The length of input ";
				parse.ParserPrint(root);
				cout <<" is " << Length(root) << " instead of 3.";
				cout << endl;
				exit(1);
			}
			else
			{
				TreeNode * s1 = Car(Cdr(root));
				TreeNode * s2 = Car(Cdr(Cdr(root)));
				return Cons(Eval(s1),Eval(s2));
			}
		}
		else if (!funcName.compare("QUOTE"))
		{
			if (Length(root) != 2)
			{
				cout << "ERROR: QUOTE of Eval function is undefined -> The length of input ";
				parse.ParserPrint(root);
				cout <<" is " << Length(root) << " instead of 2.";
				cout << endl;
				exit(1);
			}
			else
			{
				TreeNode * s1 = Car(Cdr(root));
				return s1;
			}
		}
		else if (!funcName.compare("COND"))
		{
			TreeNode * current = Cdr(root);
			while (current->Right != NULL)
			{
				TreeNode * si = Car(current);
				if (Length(si) != 2)
				{
					cout << "ERROR: COND of Eval function is undefined -> The length of input ";
					parse.ParserPrint(si);
					cout <<" is " << Length(si) << " instead of 2.";
					cout << endl;
					exit(1);
				}
				else
				{
					TreeNode * bi = Car(si);
					TreeNode * ei = Car(Cdr(si));
					if (Eval(bi)->KeyValue.compare("NIL"))
					{
						return Eval(ei);
					}
					else
					{
						current = current->Right;
					}
				}
			}
			cout << "ERROR: Cond of Eval function is undefined -> All conditions are NIL. " << endl;
			exit(1);

		}
		else
		{
			cout << "ERROR: Eval function is undefined -> Illegal function name: " << carTree->KeyValue <<endl;
			exit(1);
		}
	}
}

void Interpreter::ListNotationPrint(TreeNode * T)
{
	if (T->Left == NULL && T->Right ==NULL)
	{
		cout << T->KeyValue;
	}
	else
	{
		cout << '(';
		TreeNode * current = T;
		while (current->Right != NULL && current->Left != NULL)
		{
			ListNotationPrint(current->Left);
			current = current->Right;
			if (current->Right != NULL && current->Left != NULL)
			{
				cout << ' ';
			}
		}
		if (!current->KeyValue.compare("NIL"))
		{
			cout << ')';
		}
		else
		{
			cout << " . ";
			cout << current->KeyValue;
			cout << ')';
		}
	}

}

void Interpreter::EvalStart()
{
	parse.scan.Init();
	if (parse.scan.GetCurrent().TokenType == Eof)
	{
		cout << "ERROR: Empty Input " << endl;
		exit(1);
	}
	do 
	{
		TreeNode * T = new TreeNode;
		parse.ParseExpr(T);
		cout << "Dot notation: ";
		parse.ParserPrint(T);
		cout << endl;
		//cout  << "->The length of parse tree is " <<Length(T) << endl;
		TreeNode* new_T = new TreeNode;
		new_T = Eval(T);
		//parse.ParserPrint(new_T);
		//cout << endl;
		cout << "->List notation: ";
		ListNotationPrint(new_T);
		cout << endl;
	} while (parse.scan.GetCurrent().TokenType != Eof);
}