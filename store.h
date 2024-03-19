#ifndef store_h
#define store_h
struct SymbolTable;

enum {stNotInit, stInit};

struct Store
{
	Store(int size, SymbolTable &symTab);
	~Store();
	bool IsInit(int id) const;
	void SetValue(int id, double val);
	double Value(int id) const;
private:
	int _size;
	double * _cells;
	unsigned char * _status;
};



#endif
