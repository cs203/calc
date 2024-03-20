#include<iostream>
#include"tree.h"
#include"store.h"
const int maxBuf = 100;
const int maxSymbols = 40;

int main()
{
	NumNode *pn{new NumNode{3.14}};
	UMinusNode mn{pn};
	Store store;
	VarNode * pv{new VarNode{3, store}};
	pv->Assign(25);
	std::cout << pv->Calc() << std::endl;
	if(pv->IsLvalue())
		std::cout << "ok it is variable\n";

}

