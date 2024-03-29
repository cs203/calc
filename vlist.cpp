#include"vlist.h"

Link::Link(Link *pNext, int id)
	:_pNext{pNext}, _id{id}
{}

Link::~Link()
{
	delete _pNext;
}

Link * Link::Next() const
{
	return _pNext;
}

int Link::Id() const
{
	return _id;
}

List::List()
	:_pHead{nullptr}
{}

List::~List()
{
	delete _pHead;
}


void List::Add(int id)
{
	Link *pLink = new Link(_pHead, id);
	_pHead = pLink;
}

Link const * List::GetHead() const
{
	return _pHead;
}


