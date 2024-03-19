#ifndef symtab_h
#define symtab_h
struct Link
{
	Link(Link *pNext, int id);
	~Link();
	Link *Next() const;
	int Id() const;
private:
	Link *_pNext;
	int _id;
};

struct List
{
	List();
	~List();
	void Add(int id);
	Link const * GetHead() const;
private:
	Link *_pHead;
};

struct HTable
{
	HTable(int size);
	void Add(char const *str, int id);
	void Add(char const *str, int len, int id);
	List const & Find(char const* str) const;
	List const & Find(char const* str, int len) const;

private:
	int hash(char const * str, int len) const;
	List *_aList;
	int _size;
};

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
