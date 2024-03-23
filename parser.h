#ifndef parser_h
#define parser_h
enum Status{
	stOk,
	stQuit,
	stError
};

struct Scanner;
struct Store;
struct SymbolTable;
struct Node;

struct Parser
{
	Parser(Scanner &scanner, Store &store, SymbolTable &symTab);
	~Parser();
	Status Eval();
private:
	void Parse();
	Node *Expr();
	Node *Term();
	Node *Factor();
	void Execute();


	Scanner &_scanner;
	Store &_store;
	Node *_pTree;
	SymbolTable &_symTab;
	Status _status;
};

#endif
