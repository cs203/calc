#include"symtab.h"

HTable::HTable(int size)
	: _size{size}
{}

SymbolTable::SymbolTable(int size)
	: _size{size}, _curId{0}, _curOffStr{0}, _htab{size+1}
{
	_offStr = new int[_size];
	_bufSize = _size * 10;
	_strBuf = new char[_bufSize];
}
