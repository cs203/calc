#ifndef store_h
#define store_h
struct SymbolTable;

enum {stNotInit, stInit};

struct Store
{
	Store(int size, SymbolTable &symTab);
private:
	int _size;
	double * _cells;
	unsigned char * _status;
};


#endif
