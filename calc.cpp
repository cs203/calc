#include<iostream>
#include"symtab.h"
#include"parser.h"
#include"store.h"
#include"scan.h"

const int maxBuf = 100;
const int maxSymbols = 40;

int main()
{
	char buf[maxBuf];
	SymbolTable symTab{maxSymbols};
	Store store(maxSymbols, symTab);
	Status status{stOk};
	do
	{
		std::cout << "> ";
		std::cin.getline(buf,maxBuf); 
		Scanner scanner(buf);
		Parser parser(scanner, store,  symTab);
		status = parser.Eval();
	}while(status != stQuit);
}

