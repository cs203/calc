#include"symtab.h"
#include<cstring>



SymbolTable::SymbolTable(int size)
	: _size{size}, _curId{0}, _curStrOff{0}, _htab{size+1}
{
	_offStr = new int[_size];
	_bufSize = _size * 10;
	_strBuf = new char[_bufSize];
}

SymbolTable::~SymbolTable()
{
	delete [] _strBuf;
	delete [] _offStr;
}


int SymbolTable::ForceAdd(char const *str, int len)
{
	if(_curId == _size || _curStrOff + len + 1 >= _bufSize)
		return idNotFound;
	strncpy(&_strBuf[_curStrOff], str, len);
	_offStr[_curId] = _curStrOff;
	_htab.Add(str, len, _curId);
	++_curId;
	_curStrOff += len;
	_strBuf[_curStrOff] = '\0';
	++_curStrOff;
	return _curId - 1;
}


int SymbolTable::Find(char const *str, int len) const
{
	List const & list = _htab.Find(str, len);
	for(Link const * pLink{list.GetHead()}; pLink != nullptr; pLink = pLink->Next())
	{
		int id = pLink->Id();
		int offStr = _offStr[id];
		char const * strStored = _strBuf + offStr;
		if(strncmp(str, strStored, len) == 0)
			return id;
	}
	return idNotFound;
}


char const * SymbolTable::GetString(int id) const
{
	int offStr = _offStr[id];
	return _strBuf + offStr;
}
