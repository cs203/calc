#ifndef symtab_h
#define symtab_h
#include"htab.h"

constexpr int idNotFound = -1;

struct SymbolTable
{
	SymbolTable(int size);
	~SymbolTable();
	int ForceAdd(char const *str, int len);
	int Find(char const *str, int len) const;
	char const * GetString(int id) const;

private:
	HTable _htab;
	const int _size;
	int _curId;
	int *_offStr;
	int _bufSize;
	int _curStrOff;
	char * _strBuf;
};

#endif
