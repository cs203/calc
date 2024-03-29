#ifndef vlist_h
#define vlist_h

struct Link
{
	Link(Link *pNext, int id);
	~Link();
	Link *Next() const;
	int Id() const;
private:
	Link *_pNext;
	int _id;
};

struct List
{
	List();
	~List();
	void Add(int id);
	Link const * GetHead() const;
private:
	Link *_pHead;
};

#endif
