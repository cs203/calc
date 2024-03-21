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
