#include<iostream>
#include"symtab.h"
#include"store.h"
const int maxBuf = 100;
const int maxSymbols = 40;

int main()
{
	SymbolTable symTab{maxSymbols};
	Store store{maxSymbols, symTab};
	int id = symTab.Find("pi", 2);
	std::cout << store.Value(id) << std::endl;

}
