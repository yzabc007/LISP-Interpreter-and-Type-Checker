#include "Emptylistchecker.h"

int Emptylistchecker::Length(TreeNode * root)
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

TreeNode* Emptylistchecker::Car(TreeNode * InputTree)
{
	if(InputTree->Left != NULL  && InputTree->Right != NULL)
	{
		return InputTree->Left;
	}
	else
	{
		cout << "ERROR: CAR function is undefined -> Input of Car function contains only one node: ";
		//parse.ParserPrint(InputTree);
		ListNotationPrint(InputTree);
		cout << endl;
		exit(1);
	}
}

TreeNode* Emptylistchecker::Cdr(TreeNode * InputTree)
{
	if(InputTree->Left != NULL && InputTree->Right != NULL)
	{
		return InputTree->Right;
	}
	else
	{
		cout << "ERROR: CDR function is undefined -> Input of Cdr function contains only one node: ";
		//parse.ParserPrint(InputTree);
		ListNotationPrint(InputTree);
		cout << endl;
		exit(1);
	}
}

TreeNode* Emptylistchecker::CarType(TreeNode * InputTree)
{
	TreeNode * return_root = new TreeNode;
	if (InputTree->LowLenList == 0)
	{
		cout << "EMPTY LIST ERROR: The input of Car function could be empty. " << endl;
		exit(1);
	}
	else 
	{
		return_root->LowLenList = AnyNat;
		return return_root;
	}
}

TreeNode* Emptylistchecker::CdrType(TreeNode * InputTree)
{
	TreeNode* return_root = new TreeNode;
	if (InputTree->LowLenList == 0)
	{
		cout << "EMPTY LIST ERROR: The input of Cdr function could be empty. " << endl;
		exit(1);
	}
	else
	{
		return_root->LowLenList = InputTree->LowLenList - 1;
		return return_root;
	}
}

TreeNode* Emptylistchecker::Cons(TreeNode * InputTree1, TreeNode * InputTree2)
{
	TreeNode * return_root = new TreeNode;
	if (InputTree1->LowLenList != AnyNat)
	{
		cout << "EMPTY LIST ERROR: The abstract value of first input of Cons is not AnyNat. " << endl;
		exit(1);
	}
	else if (InputTree2->LowLenList < 0)
	{
		cout << "EMPTY LIST ERROR: The abstract value of second input of Cons is not List(>=k). " << endl;
		exit(1);
	}
	else
	{
		return_root->LowLenList = InputTree2->LowLenList + 1;
		return return_root;
	}
}

TreeNode* Emptylistchecker::Atom(TreeNode * InputTree)
{
	TreeNode* return_root = new TreeNode;
	if (InputTree->LowLenList == AbsTure || InputTree->LowLenList == AbsFalse || InputTree->LowLenList == AnyBool 
		|| InputTree->LowLenList == AnyNat)
	{
		return_root->LowLenList = AbsTure;
		return return_root;
	}
	else if (InputTree->LowLenList >= 0)
	{
		return_root->LowLenList = AbsFalse;
		return return_root;
	}
	else
	{
		cout << "EMPTY LIST ERROR: The input of Atom is illegal. " << endl;
		exit(1);
	}
}

TreeNode* Emptylistchecker::Int(TreeNode * InputTree)
{
	TreeNode* root = new TreeNode;
	if (InputTree->LowLenList == AnyNat)
	{
		root->LowLenList = AbsTure;
		return root;
	}
	else if(InputTree->LowLenList == AbsTure || InputTree->LowLenList == AbsFalse || InputTree->LowLenList == AnyBool 
		|| InputTree->LowLenList >= 0)
	{
		root->LowLenList = AbsFalse;
		return root;
	}
	else
	{
		cout << "EMPTY LIST ERROR: The input of Int is illegal." << endl;
		exit(1);
	}
}

TreeNode* Emptylistchecker::Null(TreeNode * InputTree)
{
	TreeNode* return_root = new TreeNode;
	if (InputTree->LowLenList == 0)
	{
		return_root->LowLenList = AnyBool;
		return return_root;
	}
	else if (InputTree->LowLenList >= 1)
	{
		return_root->LowLenList = AbsFalse;
		return return_root;
	}
	else
	{
		cout << "EMPTY LIST ERROR: The abstract of value of the input of Null is not List(>=k). " << endl;
		exit(1);
	}
}

TreeNode* Emptylistchecker::Eq(TreeNode * InputTree1, TreeNode * InputTree2)
{
	TreeNode * root = new TreeNode;
	if (InputTree1->LowLenList == AnyNat && InputTree2->LowLenList == AnyNat)
	{
		root->LowLenList = AnyBool;
		return root;
	}
	else
	{
		cout << "EMPTY LIST ERROR: The inputs of Eq should be AnyNat. " << endl;
		exit(1);
	}
}

TreeNode* Emptylistchecker::Plus(TreeNode * InputTree1, TreeNode * InputTree2)
{
	TreeNode * root = new TreeNode;
	if (InputTree1->LowLenList == AnyNat && InputTree2->LowLenList == AnyNat)
	{
		root->LowLenList = AnyNat;
		return root;
	}
	else 
	{
		cout << "EMPTY LIST ERROR: The inputs of Plus should be AnyNat. " << endl;
		exit(1);
	}
}

TreeNode* Emptylistchecker::Less(TreeNode * InputTree1, TreeNode * InputTree2)
{
	TreeNode* root = new TreeNode;
	if (InputTree1->LowLenList == AnyNat && InputTree2->LowLenList == AnyNat)
	{
		root->LowLenList = AnyBool;
		return root;
	}
	else
	{
		cout << "EMPTY LIST ERROR: The inputs of Less should be AnyNat. " << endl;
		exit(1);
	}
}

TreeNode* Emptylistchecker::Eval(TreeNode * root)
{
	// exp is an atom
	if (root->Left == NULL && root->Right == NULL)
	{
		if (root->KeyValue == "NIL")
		{
			root->LowLenList = 0;
			return root;
		}
		else if (root->KeyValue == "T")
		{
			root->LowLenList = AbsTure;
			return root;
		}
		else if (root->KeyValue == "F")
		{
			root->LowLenList = AbsFalse;
			return root;
		}
		else if (parse1.IsNumericAtom(root->KeyValue))
		{
			root->LowLenList = AnyNat;
			return root;
		}
		else
		{
			cout << "ERROR: Unbound literal -> "<< root->KeyValue << endl;
			exit(1);
		}
	}
	// exp must be a list
	else
	{
		TreeNode * carTree = Car(root);
		string funcName = carTree->KeyValue;
		if (funcName == "PLUS")
		{
			if (Length(root) != 3)
			{
				cout << "ERROR: PLUS of Eval function is undefined -> The length of input ";
				//parse.ParserPrint(root);
				ListNotationPrint(root);
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
		else if (funcName == "LESS")
		{
			if (Length(root) != 3)
			{
				cout << "ERROR: LESS of Eval function is undefined -> The length of input ";
				//parse.ParserPrint(root);
				ListNotationPrint(root);
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
		else if (funcName == "EQ")
		{
			if (Length(root) != 3)
			{
				cout << "ERROR: EQ of Eval function is undefined -> The length of input ";
				//parse.ParserPrint(root);
				ListNotationPrint(root);
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
		else if (funcName == "CONS")
		{
			if (Length(root) != 3)
			{
				cout << "ERROR: CONS of Eval function is undefined -> The length of input ";
				//parse.ParserPrint(root);
				ListNotationPrint(root);
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
		else if (funcName == "ATOM")
		{
			if (Length(root) != 2)
			{
				cout << "ERROR: ATOM of Eval function is undefined -> The length of input ";
				//parse.ParserPrint(root);
				ListNotationPrint(root);
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
		else if (funcName == "INT")
		{
			if (Length(root) != 2)
			{
				cout << "ERROR: INT of Eval function is undefined -> The length of input ";
				//parse.ParserPrint(root);
				ListNotationPrint(root);
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
		else if (funcName == "NULL")
		{
			if (Length(root) != 2)
			{
				cout << "ERROR: NULL of Eval function is undefined -> The length of input ";
				//parse.ParserPrint(root);
				ListNotationPrint(root);
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
		else if (funcName == "CAR")
		{
			if (Length(root) != 2)
			{
				cout << "ERROR: CAR of Eval function is undefined -> The length of input ";
				//parse.ParserPrint(root);
				ListNotationPrint(root);
				cout <<" is " << Length(root) << " instead of 2.";
				cout << endl;
				exit(1);
			}
			else
			{
				TreeNode * s = Car(Cdr(root));
				return CarType(Eval(s));
			}
		}
		else if (funcName == "CDR")
		{
			if (Length(root) != 2)
			{
				cout << "ERROR: CDR of Eval function is undefined -> The length of input ";
				//parse.ParserPrint(root);
				ListNotationPrint(root);
				cout <<" is " << Length(root) << " instead of 2.";
				cout << endl;
				exit(1);
			}
			else
			{
				TreeNode * s = Car(Cdr(root));
				return CdrType(Eval(s));
			}
		}
		else if (funcName == "COND")
		{
			TreeNode* return_root = new TreeNode;
			TreeNode* current = Cdr(root);
			int minlength = Eval(Car(Cdr(Car(current))))->LowLenList;
			while (current->Right != NULL)
			{
				TreeNode * si = Car(current);
				if (Length(si) != 2)
				{
					cout << "ERROR: COND of Eval function is undefined -> The length of input ";
					//parse.ParserPrint(si);
					ListNotationPrint(si);
					cout <<" is " << Length(si) << " instead of 2.";
					cout << endl;
					exit(1);
				}
				else
				{
					TreeNode * bi = Car(si);
					TreeNode * ei = Car(Cdr(si));
					if (Eval(ei)->LowLenList == AnyNat)
					{
						return_root->LowLenList = AnyNat;
						return return_root;
					}
					else if (Eval(ei)->LowLenList == AbsTure || Eval(ei)->LowLenList == AbsFalse || Eval(ei)->LowLenList == AnyBool)
					{
						return_root->LowLenList = AnyBool;
						return return_root;
					}
					else
					{
						if (Eval(ei)->LowLenList < minlength)
						{
							minlength = Eval(ei)->LowLenList;
						}
						current = current->Right;
					}
				}
			}
			return_root->LowLenList = minlength;
			return return_root;
			//cout << "ERROR: COND of Eval function is undefined -> All conditions are NIL. " << endl;
			//exit(1);
		}
		else
		{
			cout << "ERROR: Illegal function name -> " << carTree->KeyValue <<endl;
			exit(1);
		}
	}
}

void Emptylistchecker::ListNotationPrint(TreeNode * T)
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

void Emptylistchecker::EvalStart()
{
	parse1.scan.Init();
	if (parse1.scan.GetCurrent().TokenType == Eof)
	{
		cout << "ERROR: Empty Input " << endl;
		exit(1);
	}
	do 
	{
		TreeNode * T = new TreeNode;
		parse1.ParseExpr(T);
		//cout << "Dot notation: ";
		//parse.ParserPrint(T);
		//cout << endl;
		//cout  << "->The length of parse tree is " <<Length(T) << endl;
		TreeNode* new_T = new TreeNode;
		new_T = Eval(T);
		//parse.ParserPrint(new_T);
		//cout << endl;
		cout << "->List notation: ";
		ListNotationPrint(T);
		cout << endl;
	} while (parse1.scan.GetCurrent().TokenType != Eof);
}