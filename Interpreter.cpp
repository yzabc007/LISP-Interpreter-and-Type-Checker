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
		ListNotationPrint(InputTree);
		//parse.ParserPrint(InputTree);
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
		//parse.ParserPrint(InputTree);
		ListNotationPrint(InputTree);
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
	if (InputTree->Left == NULL && InputTree->Right == NULL && parse.IsNumericAtom(InputTree->KeyValue))
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

TreeNode* Interpreter::Literal(TreeNode* InputTree)
{
	TreeNode * root = new TreeNode;
	if (InputTree->Left == NULL && InputTree->Right == NULL && parse.IsLiteralAtom(InputTree->KeyValue))
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
		ListNotationPrint(InputTree1);
		cout << endl;
		exit(1);
	}
	else if(!Atom(InputTree2)->KeyValue.compare("NIL"))
	{
		cout << "ERROR: EQ function is undefined -> The second input of Eq function has more than one node: ";
		//parse.ParserPrint(InputTree2);
		ListNotationPrint(InputTree2);
		cout << endl;
		exit(1);
	}
	else if (!InputTree1->KeyValue.compare(InputTree2->KeyValue) && parse.IsNumericAtom(InputTree1->KeyValue))
	{
		root->KeyValue = "T";
		return root;
	}
	else if (!InputTree1->KeyValue.compare(InputTree2->KeyValue) && parse.IsLiteralAtom(InputTree1->KeyValue))
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
	if (!Atom(InputTree1)->KeyValue.compare("NIL") || !parse.IsNumericAtom(InputTree1->KeyValue))
	{
		cout << "ERROR: PLUS function is undefined -> The first input of Plus function is not a numeric atom: ";
		//parse.ParserPrint(InputTree1);
		ListNotationPrint(InputTree1);
		cout << endl;
		exit(1);
	}
	else if (!Atom(InputTree2)->KeyValue.compare("NIL") || !parse.IsNumericAtom(InputTree2->KeyValue))
	{
		cout << "ERROR: PLUS function is undefined -> The second input of Plus function is not a numeric atom: ";
		//parse.ParserPrint(InputTree2);
		ListNotationPrint(InputTree2);
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
	if (!Atom(InputTree1)->KeyValue.compare("NIL") || !parse.IsNumericAtom(InputTree1->KeyValue))
	{
		cout << "ERROR: MINUS function is undefined -> The first input of Minus function is not a numeric atom: ";
		//parse.ParserPrint(InputTree1);
		ListNotationPrint(InputTree1);
		cout << endl;
		exit(1);
	}
	else if (!Atom(InputTree2)->KeyValue.compare("NIL") || !parse.IsNumericAtom(InputTree2->KeyValue))
	{
		cout << "ERROR: MINUS function is undefined -> The second input of Minus function is not a numeric atom: ";
		//parse.ParserPrint(InputTree2);
		ListNotationPrint(InputTree2);
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
	if (!Atom(InputTree1)->KeyValue.compare("NIL") || !parse.IsNumericAtom(InputTree1->KeyValue))
	{
		cout << "ERROR: TIMES function is undefined -> The first input of Times function is not a numeric atom: ";
		//parse.ParserPrint(InputTree1);
		ListNotationPrint(InputTree1);
		cout << endl;
		exit(1);
	}
	else if (!Atom(InputTree2)->KeyValue.compare("NIL") || !parse.IsNumericAtom(InputTree2->KeyValue))
	{
		cout << "ERROR: TIMES function is undefined -> The second input of Times function is not a numeric atom: ";
		//parse.ParserPrint(InputTree2);
		ListNotationPrint(InputTree2);
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
	if (!Atom(InputTree1)->KeyValue.compare("NIL") || !parse.IsNumericAtom(InputTree1->KeyValue))
	{
		cout << "ERROR: LESS function is undefined -> The first input of Less function is not a numeric atom: ";
		//parse.ParserPrint(InputTree1);
		ListNotationPrint(InputTree1);
		cout << endl;
		exit(1);
	}
	else if (!Atom(InputTree2)->KeyValue.compare("NIL") || !parse.IsNumericAtom(InputTree2->KeyValue))
	{
		cout << "ERROR: LESS function is undefined -> The second input of Less function is not a numeric atom: ";
		//parse.ParserPrint(InputTree2);
		ListNotationPrint(InputTree2);
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
	if (!Atom(InputTree1)->KeyValue.compare("NIL") || !parse.IsNumericAtom(InputTree1->KeyValue))
	{
		cout << "ERROR: GREATER function is undefined -> The first input of Greater function is not a numeric atom: ";
		//parse.ParserPrint(InputTree1);
		ListNotationPrint(InputTree1);
		cout << endl;
		exit(1);
	}
	else if (!Atom(InputTree2)->KeyValue.compare("NIL") || !parse.IsNumericAtom(InputTree2->KeyValue))
	{
		cout << "ERROR: GREATER function is undefined -> The second input of Greater function is not a numeric atom: ";
		//parse.ParserPrint(InputTree2);
		ListNotationPrint(InputTree2);
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

TreeNode* Interpreter::bound(TreeNode* x, TreeNode* z)
{
	TreeNode* root = new TreeNode;
	if (Null(z)->KeyValue == "T" || Atom(z)->KeyValue == "T")
	{
		root->KeyValue = "NIL";
		return root;
	}
	else
	{
		if (Eq(x, Car(Car(z)))->KeyValue == "T")
		{
			root->KeyValue = "T";
			return root;
		}
		else
		{
			return bound(x, Cdr(z));
		}
	}
}

TreeNode* Interpreter::getval(TreeNode* x, TreeNode* z)
{
	if (x->KeyValue == Car(Car(z))->KeyValue)
	{
		return Cdr(Car(z));
	}
	else
	{
		return getval(x, Cdr(z));
	}
}

TreeNode* Interpreter::addpairs(TreeNode* xlist, TreeNode* ylist, TreeNode* z)
{
	if (Null(xlist)->KeyValue == "T")
	{
		return z;
	}
	else
	{
		TreeNode* nil = new TreeNode;
		nil->KeyValue = "NIL";
		TreeNode* xi = Car(xlist);
		//TreeNode* yi = Cons(Car(ylist), nil);
		TreeNode* yi = Car(ylist);
		return Cons(Cons(xi, yi), addpairs(Cdr(xlist), Cdr(ylist), z));
	}
}
// evaluate condition
TreeNode* Interpreter::evcon(TreeNode* x, TreeNode* a, TreeNode* d)
{
	if (Null(x)->KeyValue == "T")
	{
		cout << "ERROR: COND of Eval function is undefined -> All conditions are NIL. " << endl;
		exit(1);
	}
	else if (Length(Car(x)) != 2)
	{
		cout << "ERROR: COND of Eval function is undefined -> The length of input ";
		//parse.ParserPrint(Car(x));
		ListNotationPrint(Car(x));
		cout <<" is " << Length(Car(x)) << " instead of 2.";
		cout << endl;
		exit(1);
	}
	else if (Eval(Car(Car(x)), a, d)->KeyValue != "NIL")
	{
		return Eval(Car(Cdr(Car(x))), a, d);
	}
	else
	{
		return evcon(Cdr(x), a, d);
	}
}

TreeNode* Interpreter::evlist(TreeNode* x, TreeNode* a, TreeNode*d)
{
	if (Null(x)->KeyValue == "T")
	{
		TreeNode* nil = new TreeNode;
		nil->KeyValue = "NIL";
		return nil;
	}
	else
	{
		TreeNode*  aa = Eval(Car(x), a, d);
		TreeNode* bb = evlist(Cdr(x), a, d);
		TreeNode* cc = Cons(aa, bb);
		return cc;
	}
}

TreeNode* Interpreter::apply(TreeNode* f, TreeNode* x, TreeNode* a, TreeNode* d)
{
	if (Atom(f)->KeyValue == "T")
	{
		// parameter 1
		if (f->KeyValue == "CAR")
		{
			if (Length(x) != 1)
			{
				cout << "ERROR: CAR of Apply function is undefined -> The length of the parameter list: ";
				//parse.ParserPrint(x);
				ListNotationPrint(x);
				cout <<" is " << Length(x) << " instead of 1.";
				cout << endl;
				exit(1);
			}
			else
			{
				return Car(Car(x));
			}
		}
		else if (f->KeyValue == "CDR")
		{
			if (Length(x) != 1)
			{
				cout << "ERROR: CDR of Apply function is undefined -> The length of the parameter list: ";
				//parse.ParserPrint(x);
				ListNotationPrint(x);
				cout <<" is " << Length(x) << " instead of 1.";
				cout << endl;
				exit(1);
			}
			else
			{
				return Cdr(Car(x));
			}
		}
		else if (f->KeyValue == "ATOM")
		{
			if (Length(x) != 1)
			{
				cout << "ERROR: ATOM of Apply function is undefined -> The length of the parameter list: ";
				//parse.ParserPrint(x);
				ListNotationPrint(x);
				cout <<" is " << Length(x) << " instead of 1.";
				cout << endl;
				exit(1);
			}
			else
			{
				return Atom(Car(x));
			}
		}
		else if (f->KeyValue == "INT")
		{
			if (Length(x) != 1)
			{
				cout << "ERROR: INT of Apply function is undefined -> The length of the parameter list: ";
				//parse.ParserPrint(x);
				ListNotationPrint(x);
				cout <<" is " << Length(x) << " instead of 1.";
				cout << endl;
				exit(1);
			}
			else
			{
				return Int(Car(x));
			}
		}
		else if (f->KeyValue == "NULL")
		{
			if (Length(x) != 1)
			{
				cout << "ERROR: NULL of Apply function is undefined -> The length of the parameter list: ";
				//parse.ParserPrint(x);
				ListNotationPrint(x);
				cout <<" is " << Length(x) << " instead of 1.";
				cout << endl;
				exit(1);
			}
			else
			{
				return Null(Car(x));
			}
		}
		// parameters 2
		else if (f->KeyValue == "CONS")
		{
			if (Length(x) != 2)
			{
				cout << "ERROR: CONS of Apply function is undefined -> The length of the parameter list: ";
				//parse.ParserPrint(x);
				ListNotationPrint(x);
				cout <<" is " << Length(x) << " instead of 2.";
				cout << endl;
				exit(1);
			}
			else
			{
				return Cons(Car(x), Car(Cdr(x)));
			}
		}
		else if (f->KeyValue == "EQ")
		{
			if (Length(x) != 2)
			{
				cout << "ERROR: EQ of Apply function is undefined -> The length of the parameter list: ";
				//parse.ParserPrint(x);
				ListNotationPrint(x);
				cout <<" is " << Length(x) << " instead of 2.";
				cout << endl;
				exit(1);
			}
			else
			{
				return Eq(Car(x), Car(Cdr(x)));
			}
		}
		else if (f->KeyValue == "PLUS")
		{
			if (Length(x) != 2)
			{
				cout << "ERROR: PLUS of Apply function is undefined -> The length of the parameter list: ";
				//parse.ParserPrint(x);
				ListNotationPrint(x);
				cout <<" is " << Length(x) << " instead of 2.";
				cout << endl;
				exit(1);
			}
			else
			{
				return Plus(Car(x), Car(Cdr(x)));
			}
		}
		else if (f->KeyValue == "MINUS")
		{
			if (Length(x) != 2)
			{
				cout << "ERROR: MINUS of Apply function is undefined -> The length of the parameter list: ";
				//parse.ParserPrint(x);
				ListNotationPrint(x);
				cout <<" is " << Length(x) << " instead of 2.";
				cout << endl;
				exit(1);
			}
			else
			{
				return Minus(Car(x), Car(Cdr(x)));
			}
		}
		else if (f->KeyValue == "TIMES")
		{
			if (Length(x) != 2)
			{
				cout << "ERROR: TIMES of Apply function is undefined -> The length of the parameter list: ";
				//parse.ParserPrint(x);
				ListNotationPrint(x);
				cout <<" is " << Length(x) << " instead of 2.";
				cout << endl;
				exit(1);
			}
			else
			{
				return Times(Car(x), Car(Cdr(x)));
			}
		}
		else if (f->KeyValue == "LESS")
		{
			if (Length(x) != 2)
			{
				cout << "ERROR: LESS of Apply function is undefined -> The length of the parameter list: ";
				//parse.ParserPrint(x);
				ListNotationPrint(x);
				cout <<" is " << Length(x) << " instead of 2.";
				cout << endl;
				exit(1);
			}
			else
			{
				return Less(Car(x), Car(Cdr(x)));
			}
		}
		else if (f->KeyValue == "GREATER")
		{
			if (Length(x) != 2)
			{
				cout << "ERROR: GREATER of Apply function is undefined -> The length of the parameter list: ";
				//parse.ParserPrint(x);
				ListNotationPrint(x);
				cout <<" is " << Length(x) << " instead of 2.";
				cout << endl;
				exit(1);
			}
			else
			{
				return Greater(Car(x), Car(Cdr(x)));
			}
		}
		else 
		{
			if (bound(f, d)->KeyValue == "NIL")
			{
				cout << "ERROR: Eval function is undefined -> Illegal function name: " << f->KeyValue <<endl;
				exit(1);
			}
			else if (Length(Car(getval(f, d))) != Length(x))
			{
				cout << "ERROR: The actual parameters ";
				ListNotationPrint(Car(getval(f, d)));
				cout << " are not equal to the formal parameters";
				ListNotationPrint(x);
				cout << endl;
				exit(1);
			}
			else
			{
				TreeNode* aa = Cdr(getval(f, d));
				TreeNode* bb = addpairs(Car(getval(f, d)), x, a);
				return Eval(aa, bb, d);
				//Eval(Cdr(getval(f, d)), addpairs(Car(getval(f, d)), x, a), d);
			}
		}
	}
	else
	{
		cout << "ERROR: Function name cannot be non-atomic expression: ";
		//parse.ParserPrint(f);
		ListNotationPrint(f);
		cout << endl;
		exit(1);
	}
}

TreeNode* Interpreter::Eval(TreeNode * exp, TreeNode * a_list, TreeNode * d_list)
{
	// exp is an atom
	if (exp->Left == NULL && exp->Right == NULL)
	{
		if (exp->KeyValue == "T" || exp->KeyValue == "NIL" || parse.IsNumericAtom(exp->KeyValue))
		{
			return exp;
		}
		else if (bound(exp, a_list)->KeyValue == "T")
		{
			return getval(exp, a_list);
		}
		else
		{
			cout << "ERROR: Eval function is undefined -> unbound literal: "<< exp->KeyValue << endl;
			exit(1);
		}
	}
// exp must be a list
	else
	{
		TreeNode * carTree = Car(exp);
		string funcName = carTree->KeyValue;
		if (Car(exp)->KeyValue == "QUOTE")
		{
			if (Length(exp) != 2)
			{
				cout << "ERROR: QUOTE of Eval function is undefined -> The length of input ";
				//parse.ParserPrint(exp);
				ListNotationPrint(exp);
				cout <<" is " << Length(exp) << " instead of 2.";
				cout << endl;
				exit(1);
			}
			else
			{
				return Car(Cdr(exp));
			}
		}
else if (Car(exp)->KeyValue == "COND")
		{
			return evcon(Cdr(exp), a_list, d_list);
			/*
			TreeNode * current = Cdr(exp);
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
					if (Eval(bi, a_list, d_list)->KeyValue.compare("NIL"))
					{
						return Eval(ei, a_list, d_list);
					}
					else
					{
						current = current->Right;
					}
				}
			}
			cout << "ERROR: COND of Eval function is undefined -> All conditions are NIL. " << endl;
			exit(1);
			*/
		}
		else if (Car(exp)->KeyValue == "DEFUN")
		{
			if (Length(exp) != 4)
			{
				cout << "ERROR: DEFUN of Eval function is undefined -> The length of input ";
				//parse.ParserPrint(exp);
				ListNotationPrint(exp);
				cout <<" is " << Length(exp) << " instead of 4.";
				cout << endl;
				exit(1);
			}
			else
			{
				// evaluate function name
				std::set<std::string>::iterator it = setOfBuiltinFunc.find(Car(Cdr(exp))->KeyValue);
				if (Atom(Car(Cdr(exp)))->KeyValue == "NIL")
				{
					cout << "ERROR: Function name ";
					//parse.ParserPrint(Car(Cdr(exp)));
					ListNotationPrint(Car(Cdr(exp)));
					cout <<" cannot be a list" << endl;
					exit(1);
				}
				else if (Int(Car(Cdr(exp)))->KeyValue == "T")
				{
					cout << "ERROR: Function name " << Car(Cdr(exp))->KeyValue <<" cannot be a numeric atom." << endl;
					exit(1);
				}
				else if (it != setOfBuiltinFunc.end())
				{
					cout << "ERROR: Function name " << Car(Cdr(exp))->KeyValue << " is overlapped with Build-in function names" << endl;
					exit(1);
				}
				// evaluate formal parameters
				else if (Null(Car(Cdr(Cdr(exp))))->KeyValue == "NIL" && Atom(Car(Cdr(Cdr(exp))))->KeyValue == "T")
				{
					cout << "ERROR: The formal parameters " << Car(Cdr(Cdr(exp)))->KeyValue <<" cannot be an atom." << endl;
					exit(1);
				}
				else
				{
					evaluateFormPara(Car(Cdr(Cdr(exp))));
					TreeNode* nil = new TreeNode;
					nil->KeyValue = "NIL";
					// make xi and yi to be a list
					TreeNode* x = Cons(Car(Cdr(exp)), nil);
					TreeNode* y = Cons(Cons(Car(Cdr(Cdr(exp))), Car(Cdr(Cdr(Cdr(exp))))), nil);
					//TreeNode* x = Car(Cdr(exp));
					//TreeNode* y = Cons(Car(Cdr(Cdr(exp))), Car(Cdr(Cdr(Cdr(exp)))));
					global_d_list = addpairs(x, y, d_list);
					//addpairs(Car(Cdr(exp)), Cons(Car(Cdr(Cdr(exp))), Car(Cdr(Cdr(Cdr(exp))))), d_list);
					return Car(Cdr(exp));
				}
			}
		}
		// apply function
		else
		{
			TreeNode* aa = Car(exp);
			TreeNode* bb = evlist(Cdr(exp), a_list, d_list);
			//TreeNode* cc = apply(Car(exp), evlist(Cdr(exp), a_list, d_list), a_list, d_list);
			TreeNode* cc = apply(aa, bb, a_list, d_list);
			return cc;
			//return apply(Car(exp), evlist(Cdr(exp), a_list, d_list), a_list, d_list);
		}
	}
}

void Interpreter::evaluateFormPara(TreeNode* x)
{
	std::set<std::string> setOfPara;
	TreeNode* currentNode = x;
	while (Null(currentNode)->KeyValue == "NIL")
	{
		std::set<std::string>::iterator it_rep = setOfPara.find(Car(currentNode)->KeyValue);
		std::set<std::string>::iterator it_buildin = setOfBuiltinFunc.find(Car(currentNode)->KeyValue);
		if (Literal(Car(currentNode))->KeyValue == "NIL")
		{
			cout << "ERROR: The formal parameter ";
			//parse.ParserPrint(Car(currentNode));
			ListNotationPrint(Car(currentNode));
			cout << " needs to be a literal atom." << endl;
			exit(1);
		}
		else if (it_buildin != setOfBuiltinFunc.end())
		{
			cout << "ERROR: The formal parameter "<< Car(currentNode)->KeyValue << " is overlapped with Build-in function names." << endl;
			exit(1);
		}
		else if (it_rep != setOfPara.end())
		{
			cout << "ERROR: The formal parameter " << Car(currentNode)->KeyValue <<" is repeated." << endl;
			exit(1);
		}
		else
		{
			setOfPara.insert(Car(currentNode)->KeyValue);
			currentNode = currentNode->Right;
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
	// Initialization
	TreeNode* a_list = new TreeNode;
	global_d_list = new TreeNode;
	CompleteSet();
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
		//cout << "Dot notation: ";
		//parse.ParserPrint(T);
		//cout << endl;
		//cout  << "->The length of parse tree is " <<Length(T) << endl;
		TreeNode* new_T = new TreeNode;
		new_T = Eval(T, a_list, global_d_list);
		//parse.ParserPrint(new_T);
		//cout << endl;
		cout << "List notation: ";
		ListNotationPrint(new_T);
		cout << endl;
	} while (parse.scan.GetCurrent().TokenType != Eof);
}

void Interpreter::CompleteSet()
{
	setOfBuiltinFunc.insert("T");
	setOfBuiltinFunc.insert("NIL");
	setOfBuiltinFunc.insert("CAR");
	setOfBuiltinFunc.insert("CDR");
	setOfBuiltinFunc.insert("CONS");
	setOfBuiltinFunc.insert("ATOM");
	setOfBuiltinFunc.insert("EQ");
	setOfBuiltinFunc.insert("NULL");
	setOfBuiltinFunc.insert("INT");
	setOfBuiltinFunc.insert("PLUS");
	setOfBuiltinFunc.insert("MINUS");
	setOfBuiltinFunc.insert("TIMES");
	setOfBuiltinFunc.insert("LESS");
	setOfBuiltinFunc.insert("GREATER");
	setOfBuiltinFunc.insert("COND");
	setOfBuiltinFunc.insert("QUOTE");
	setOfBuiltinFunc.insert("DEFUN");
}