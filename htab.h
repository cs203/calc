#ifndef htab_h
#define htab_h
#include"vlist.h"

struct HTable
{
	HTable(int size);
	void Add(char const *str, int id);
	void Add(char const *str, int len, int id);
	List const & Find(char const* str) const;
	List const & Find(char const* str, int len) const;

private:
	int hash(char const * str, int len) const;
	List *_aList;
	int _size;
};


#endif
