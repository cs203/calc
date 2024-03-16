#ifndef symtab_h
#define symtab_h
struct HTable
{
	HTable(int size);
private:
	int _size;
};

struct SymbolTable
{
	SymbolTable(int size);
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
