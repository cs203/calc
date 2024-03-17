#ifndef scan_h
#define scan_h

enum EToken
{ 
	tPlus,
	tMinus,
	tMult,
	tDivide,
	tAssign,
	tNumber,
	tLParen,
	tRParen,
	tIdent,
	tEnd,
	tError
};

int const maxSymLen = 80;

struct Scanner
{
	Scanner(char const * const buf);
	EToken Token() const;
	EToken Accept();
	double Number() const;
	void GetSymbolName(char *strOut, int &len) const;

private:
	void EatWhite();
	int _iCurr;
	char const * const _buf;
	EToken _token;
	int _iSymbol;
	int _lenSymbol;
	double _number;
};

#endif
