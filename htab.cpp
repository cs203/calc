#include"htab.h"
#include<cstring>

HTable::HTable(int size)
	: _size{size}
{
	_aList = new List[size];
}

void HTable::Add(char const *str, int len, int id)
{
	int i = hash(str, len);
	_aList[i].Add(id);
}

void HTable::Add(char const *str, int id)
{
	int len = strlen(str);
	Add(str, len, id);
}

List const & HTable::Find(char const* str, int len) const
{
	int i = hash(str, len);
	return _aList[i];
}

int HTable::hash(char const *str, int len) const
{
	unsigned int  h = str[0];
	for(int i = 1; i < len; ++i)
	{
		h = (h << 4) + str[i];
	}
	return h % _size;
}


