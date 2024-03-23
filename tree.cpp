#include"tree.h"
#include"store.h"
#include<iostream>

Node::~Node(){}

bool Node::IsLvalue() const
{
	return false;
}

NumNode::NumNode(double num) 
	:_num{num}{}


double NumNode::Calc() const
{
	return _num;
}

UMinusNode::UMinusNode(Node *pNode)
	: _pNode{pNode}{}

UMinusNode::~UMinusNode()
{
	delete _pNode;
}

double UMinusNode::Calc() const
{
	return -_pNode->Calc();
}

VarNode::VarNode(int id, Store &store)
	:_id{id}, _store{store}
{}

bool VarNode::IsLvalue() const
{
	return true;
}

void VarNode::Assign(double val)
{
	_store.SetValue(_id, val);
}

double VarNode::Calc() const
{
	double x = 0.0;
	if(_store.IsInit(_id)) 
		x = _store.Value(_id);
	else
		std::cout <<"Use of undefined variable\n";
	return x;
}

BinNode::BinNode(Node *pLeft, Node *pRight)
	:_pLeft{pLeft}, _pRight{pRight}
{}

BinNode::~BinNode()
{
	delete _pLeft;
	delete _pRight;
}

AddNode::AddNode(Node *pLeft, Node *pRight)
	:BinNode(pLeft, pRight){}

double AddNode::Calc() const 
{
	return _pLeft->Calc() + _pRight->Calc();
}


SubNode::SubNode(Node *pLeft, Node *pRight)
	:BinNode(pLeft, pRight)
{}

double SubNode::Calc() const 
{
	return _pLeft->Calc() - _pRight->Calc();
}

MultNode::MultNode(Node *pLeft, Node *pRight)
	:BinNode(pLeft, pRight)
{}

double MultNode::Calc() const 
{
	return _pLeft->Calc() * _pRight->Calc();
}

DivideNode::DivideNode(Node *pLeft, Node *pRight)
	:BinNode(pLeft, pRight)
{}

double DivideNode::Calc() const 
{
	return _pLeft->Calc() / _pRight->Calc();
}

AssignNode::AssignNode(Node *pLeft, Node *pRight)
	:BinNode(pLeft, pRight)
{}

double AssignNode::Calc() const 
{
	double x = _pRight->Calc();
	_pLeft->Assign(x);
	return x;
}
