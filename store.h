#ifndef store_h
#define store_h
struct SymbolTable;

enum {stNotInit, stInit};

struct Store
{
	Store(): _size{3}, _cells{new double[3]}, _status{new unsigned char[2]}{};
	void SetValue(int id, double val){}
	bool IsInit(int id){return true;}
	double Value(int id) const
	{
		return 13;
	}
private:
	int _size;
	double * _cells;
	unsigned char * _status;
};


#endif
