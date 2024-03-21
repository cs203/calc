#include<iostream>
#include"tree.h"
#include"store.h"
const int maxBuf = 100;
const int maxSymbols = 40;

int main()
{
	Node *pn{new NumNode{3.14}};
	Node *pmn{new UMinusNode{pn}};
	Store store;
	Node *pv{new VarNode{3, store}};
	Node *pa{new AssignNode(pv, pmn)};
	Node *padd{new DivideNode(pn, pn)};
	std::cout << padd->Calc() << std::endl;
}

