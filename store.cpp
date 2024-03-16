#include"store.h"
#include"symtab.h"

Store::Store(int size, SymbolTable &symtab)
	:_size{size}
{
	_cells = new double[_size];
	_status = new unsigned char[_size];
}
