#include<iostream>
#include"scan.h"
const int maxBuf = 100;
const int maxSymbols = 40;

int main()
{
	char buf[maxBuf];
	std::cout << "> ";
	std::cin.getline(buf,maxBuf); 
	Scanner scanner(buf);
	/*
	char buf[maxBuf];
	SymbolTable symTab;
	Store store(maxSymbols, symTab);
	do
	{
		std::cout << "> ";
		std::cin.getline(buf,maxBuf); 
		Scanner scanner(buf);
		Parser parser(scanner, store,  symTab);
		status = status.Eval();
	}while(status != stQuit);
	*/
}

