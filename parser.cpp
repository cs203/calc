#include"parser.h"
#include"symtab.h"
#include"store.h"
#include"tree.h"
#include"scan.h"
#include<iostream>

Parser::Parser(Scanner &scanner, Store &store, SymbolTable &symTab)
	:_scanner{scanner}, _store{store}, _symTab{symTab}, _pTree{nullptr}, _status{stOk}
{}

Parser::~Parser()
{
	delete _pTree;
}

Status Parser::Eval()
{
	Parse();
	if(_status == stOk)
		Execute();
	else
		_status = stQuit;
	return _status;
}

void Parser::Execute()
{
	if(_pTree)
	{ 
		double result = _pTree->Calc(); 
		std::cout <<"	" <<  result << std::endl;
	}
}

void Parser::Parse()
{
	_pTree = Expr();
}

Node * Parser::Expr()
{
	Node * pNode = Term();
	EToken token = _scanner.Token();
	if(token == tPlus)
	{
		_scanner.Accept();
		Node *pRight=Expr();
		pNode = new AddNode(pNode, pRight);
	}
	else if(token == tMinus)
	{
		_scanner.Accept();
		Node *pRight = Expr();
		pNode = new SubNode(pNode, pRight);
	}
	else if(token == tAssign)
	{
		_scanner.Accept();
		Node *pRight =Expr();
		if(pNode->IsLvalue())
		{
			pNode = new AssignNode(pNode, pRight);
		}
		else
		{
			_status = stError;
			delete pNode;
			pNode = Expr();
		}
	}
	return pNode;
}

Node* Parser::Term()
{
	Node * pNode = Factor();
	EToken token = _scanner.Token();
	if(token == tMult)
	{
		_scanner.Accept();
		Node *pRight = Term();
		pNode = new MultNode(pNode, pRight);
	}
	else if(token == tDivide)
	{
		_scanner.Accept();
		Node *pRight = Term();
		pNode = new DivideNode(pNode, pRight);
	}
	return pNode;
}

Node *Parser::Factor()
{
	Node *pNode;
	EToken token = _scanner.Token();
	switch(token)
	{
		case tLParen: 
		{ 
			_scanner.Accept(); 
			pNode = Expr(); 
			if(_scanner.Token() != tRParen) 
				_status = stError; 
			_scanner.Accept(); 
			break;
		}
		case tNumber: 
		{ 
			pNode = new NumNode(_scanner.Number()); 
			_scanner.Accept(); 
			break;
		} 
		case tIdent: 
		{ 
			char strSymbol[maxSymLen]; 
			int lenSym = maxSymLen; 
			_scanner.GetSymbolName(strSymbol, lenSym); 
			int id = _symTab.Find(strSymbol, lenSym); 
			_scanner.Accept(); 
			if(id == idNotFound) 
				id = _symTab.ForceAdd(strSymbol, lenSym); 
			pNode = new VarNode(id, _store); 
			break;
		}
		case tMinus: 
		{ 
			_scanner.Accept(); 
			pNode = new UMinusNode(Factor()); 
			break;
		}
		default: 
		{ 
			_scanner.Accept(); 
			_status = stError; 
			pNode = nullptr; 
			break;
		}
	}
	return pNode;
}





