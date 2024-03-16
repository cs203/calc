#ifndef store_h
#define store_h
struct SymbolTable;

enum unsigned char {stNotInit, stInit};

struct Store
{
	Store(int size, SymboleTable &symTab);
private:
	int _size;
	double * _cells;
	unsigned char * _status;
};


#endif
