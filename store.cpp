#include"store.h"
#include"symtab.h"

Store::Store(int size, SymbolTable &symTab)
	:_size{size}
{
	_cells = new double[_size];
	_status = new unsigned char[_size];
	for(int i = 0; i < _size; ++i)
	{
		_status[i] = stNotInit;
	}
	int id = symTab.ForceAdd("pi", 2);
	SetValue(id, 3.14);
	id = symTab.ForceAdd("e",1);
	SetValue(id,2.718);
}

Store::~Store()
{
	delete [] _cells;
	delete [] _status;
}

void Store::SetValue(int id, double val)
{
	if(id < _size)
	{
		_status[id] = stInit;
		_cells[id] = val;
	}
}

double Store::Value(int id) const
{
	return _cells[id];
}

bool Store::IsInit(int id) const
{
	return (id < _size && _status[id] != stNotInit);
}
