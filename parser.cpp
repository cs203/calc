#include"parser.h"
#include"symtab.h"
#include"stroe.h"
#include"tree.h"

Parser::Parse(Scanner &scanner, Store &store, SymbolTable &symTab)
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

void Parser::Exectue()
{
	if(_Tree)
	{ 
		double result = _pTree->Calc(); 
		std::cout <<"> " <<  result;
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
	it(token == tMult)
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
	if(token == tLParen)
	{
		_scanner.Accept();
		pNode = Exrpr();
		if(_scanner.Token() != tRParen)
			_status = stError;
		_scanner.Accept();
	}
	else if(toekn == tNumber)
	{
		pNode = new NumNode(_scanner.Number());
		_scanner.Accept();
	}
	else if(token == tIdent)
	{
		char strSymbol[maxSymLen];
		int senSym = maxSymLen;
		_scanner.GetSymbolName(strSymbol, lenSym);
		int id = _symTab.Find(strSymbol, lenSym);
		_scanner.Accept();
		if(id == idNotFound)
			id = _symTab.ForceAdd(strSymbol, lenSym);
		pNode = new VarNode(id, _store);
	}
	else if(token == tMinus)
	{
		_scanner.Accept();
		pNode = new UMinusNode(Factor());
	}
	else
	{
		_scanner.Accept();
		_status = stError;
		pNode = nullptr;
	}
	return pNode;
}





