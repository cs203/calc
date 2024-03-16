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

struct Parser
{
	Parse(Scanner &scanner, Store &store, SymbolTable &symTab);
	Status Eval();
private:
	Scanner &_scanner;
	Store &_store;
	SymbolTable &_symTab;
};

#endif
