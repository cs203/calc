#include<iostream>
#include"scan.h"
const int maxBuf = 100;

enum Status{
	stOk, stError, stQuit};

int main()
{
	char buf[maxBuf];
	std::cout << "> ";
	std::cin.getline(buf, maxBuf);
	Scanner scanner{buf};
	Status status=stOk;
	do
	{ 
		switch(scanner.Token()) 
		{
		case tNumber:
			std::cout << "Number "<< scanner.Number() <<std::endl;
			break;
		case tPlus:
			std::cout << "token Plus\n";
			break;
		case tMinus:
			std::cout << "toekn Minus\n";
			break; 
		case tDivide:
			std::cout << "Divinde\n";
			break;
		case tMult:
			std::cout << "Multiply\n";
			break;
		case tAssign:
			std::cout << " Assign \n";
			break;
		case tLParen:
			std::cout << "( \n";
			break;
		case tRParen:
			std::cout << ") \n";
			break;
		case tIdent:
			{
				char name[maxSymLen+1];
				int len;
				scanner.GetSymbolName(name, len);
				std::cout << "Identifyer " << name << std::endl;
				break;
			}
		case tEnd:
			status = stQuit;
			break;
		case tError:
			status = stQuit;
			break;
		}
		scanner.Accept();
	}while(status != stQuit);

}
