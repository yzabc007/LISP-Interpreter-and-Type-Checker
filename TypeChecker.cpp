#include "TypeChecker.h"

int Typechecker::Length(TreeNode * root)
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

TreeNode* Typechecker::Car(TreeNode * InputTree)
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

TreeNode* Typechecker::Cdr(TreeNode * InputTree)
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

TreeNode* Typechecker::CarType(TreeNode * InputTree)
{
	TreeNode* return_root = new TreeNode;
	if (InputTree->Type != List_nat)
	{
		cout << "TYPE ERROR: The type of the input of Car function should be List(Nat). " << endl;
		exit(1);
	}
	else
	{
		return_root->Type = Nat;
		return return_root;
	}
}

TreeNode* Typechecker::CdrType(TreeNode * InputTree)
{
	TreeNode* return_root = new TreeNode;
	if (InputTree->Type != List_nat)
	{
		cout << "TYPE ERROR: The type of the input of Cdr function should be List(Nat). " << endl;
		exit(1);
	}
	else
	{
		return_root->Type = List_nat;
		return return_root;
	}
}

TreeNode* Typechecker::Cons(TreeNode * InputTree1, TreeNode * InputTree2)
{
	TreeNode* return_root = new TreeNode;
	if (InputTree1->Type != Nat)
	{
		cout << "TYPE ERROR: The type of the first input of Cons function should be Nat. " << endl;
		exit(1);
	}
	else if (InputTree2->Type != List_nat)
	{
		cout << "TYPE ERROR: The type of the second input of Car function should be List(Nat)" << endl;
		exit(1);
	}
	else
	{
		return_root->Type = List_nat;
		return return_root;
	}
}

TreeNode* Typechecker::Atom(TreeNode * InputTree)
{
	TreeNode* return_root = new TreeNode;
	if (InputTree->Type == Nat || InputTree->Type == Bool || InputTree->Type == List_nat)
	{
		return_root->Type = Bool;
		return return_root;
	}
	else
	{
		cout << "TYPE ERROR: The Atom function is undefined. " << endl;
		exit(1);
	}
}

TreeNode* Typechecker::Int(TreeNode * InputTree)
{
	TreeNode* return_root = new TreeNode;
	if (InputTree->Type == Nat || InputTree->Type == List_nat || InputTree->Type == Bool)
	{
		return_root->Type = Bool;
		return return_root;
	}
	else
	{
		cout << "TYPE ERROR: The Int function is undefined: the input is an illegal type " << InputTree->Type << endl;
		exit(1);
	}
}

TreeNode* Typechecker::Null(TreeNode * InputTree)
{
	TreeNode* return_root = new TreeNode;
	if (InputTree->Type == List_nat)
	{
		return_root->Type = Bool;
		return return_root;
	}
	else	
	{
		cout << "TYPE ERROR: The Null function is undefined: the type of the input is not List(Nat)" << endl;
		exit(1);
	}
}

TreeNode* Typechecker::Eq(TreeNode * InputTree1, TreeNode * InputTree2)
{
	TreeNode * return_root = new TreeNode;
	if (InputTree1->Type != Nat)
	{
		cout << "TYPE ERROR: The first input of Eq is not a Nat. " << endl;
		exit(1);
	}
	else if (InputTree2->Type != Nat)
	{
		cout << "TYPE ERROR: The second input of Eq is not a Nat. " << endl;
		exit(1);
	}
	else
	{
		return_root->Type = Bool;
		return return_root;
	}
}

TreeNode* Typechecker::Plus(TreeNode * InputTree1, TreeNode * InputTree2)
{
	TreeNode * return_root = new TreeNode;
	if (InputTree1->Type != Nat)
	{
		cout << "TYPE ERROR: The first input of Plus is not a Nat. " << endl;
		exit(1);
	}
	else if (InputTree2->Type != Nat)
	{
		cout << "TYPE ERROR: The second input of Plus is not a Nat. " << endl;
		exit(1);
	}
	else
	{
		return_root->Type = Nat;
		return return_root;
	}
}

TreeNode* Typechecker::Less(TreeNode * InputTree1, TreeNode * InputTree2)
{
	TreeNode * return_root = new TreeNode;
	if (InputTree1->Type != Nat)
	{
		cout << "TYPE ERROR: The first input of Less is not a Nat. " << endl;
		exit(1);
	}
	else if (InputTree2->Type != Nat)
	{
		cout << "TYPE ERROR: The second input of Less is not a Nat. " << endl;
		exit(1);
	}
	else
	{
		return_root->Type = Bool;
		return return_root;
	}
}

TreeNode* Typechecker::Eval(TreeNode * root)
{
	// exp is an atom
	if (root->Left == NULL && root->Right == NULL)
	{
		//cout << root->KeyValue << " !!! "<< parse2.IsNumericAtom(root->KeyValue) << endl;
		if (root->KeyValue == "NIL")
		{
			root->Type = List_nat;
			return root;
		}
		else if (root->KeyValue == "T" || root->KeyValue == "F")
		{
			root->Type = Bool;
			return root;
		}
		else if (parse2.IsNumericAtom(root->KeyValue))
		{
			root->Type = Nat;
			return root;
		}
		else
		{
			cout << "TYPE ERROR: Unbound literal -> "<< root->KeyValue << endl;
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
			TreeNode * current = Cdr(root);
			int First_type =  Eval(Car(Cdr(Car(current))))->Type;
			while (current->Right != NULL)
			{
				TreeNode * si = Car(current);
				if (Length(si) != 2)
				{
					cout << "ERROR: COND of Eval function is undefined -> The length of input ";
					ListNotationPrint(si);
					cout <<" is " << Length(si) << " instead of 2.";
					cout << endl;
					exit(1);
				}
				else
				{
					TreeNode * bi = Car(si);
					TreeNode * ei = Car(Cdr(si));
					if (Eval(bi)->Type != Bool)
					{
						cout << "TYPE ERROR: The type of bi should be Bool. " << endl;
						exit(1);
					}
					else if (Eval(ei)->Type != First_type)
					{
						cout << "TYPE ERROR: COND should have the same type for all ei" << endl;
						exit(1);
					}
					else
					{
						current = current->Right;
					}
				}
			}
			TreeNode* return_root = new TreeNode;
			return_root->Type = First_type;
			return return_root;
		}
		else
		{
			cout << "TYPE ERROR: Illegal function name -> " << carTree->KeyValue <<endl;
			exit(1);
		}
	}
}

void Typechecker::ListNotationPrint(TreeNode * T)
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

void Typechecker::EvalStart()
{
	parse2.scan.Init();
	if (parse2.scan.GetCurrent().TokenType == Eof)
	{
		cout << "ERROR: Empty Input " << endl;
		exit(1);
	}
	do 
	{
		TreeNode * T = new TreeNode;
		parse2.ParseExpr(T);
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
	} while (parse2.scan.GetCurrent().TokenType != Eof);
}