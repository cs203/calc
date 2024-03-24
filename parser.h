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
	void Execute();
	Node *Expr();
	Node *Term();
	Node *Factor();

	SymbolTable &_symTab;
	Store &_store;
	Scanner &_scanner;
	Node *_pTree;
	Status _status;
};

#endif
