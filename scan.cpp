#include"scan.h"
#include<cstdlib>
#include<cstring>
#include<cctype>

Scanner::Scanner(char const *const buf)
	:_buf{buf}, _iCurr{0}
{
	Accept();
}

EToken Scanner::Accept()
{
	EatWhite();
	switch(_buf[_iCurr])
	{ 
		case '+':
			_token = tPlus;
			++_iCurr;
			break;
		case '-':
			_token = tMinus;
			++_iCurr;
			break;
		case '=':
			++_iCurr;
			_token = tAssign;
			break;
		case '*':
			++_iCurr;
			_token = tMult;
			break;
		case '/':
			++_iCurr;
			_token = tDivide;
			break;
		case '(':
			_token = tLParen;
			++_iCurr;
			break;
		case ')':
			_token = tRParen;
			++_iCurr;
			break;
		case '\0':
			_token = tEnd;
			break;
		case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
			{
				_token = tNumber;
				char *p;
				_number = strtod(&_buf[_iCurr], &p);
				_iCurr = p - _buf;
				break;
			}
		default:
			if(isalpha(_buf[_iCurr]) || _buf[_iCurr] == '_')
			{
				_token = tIdent;
				_iSymbol = _iCurr;
				do
				{
					++_iCurr;
				}
				while(isalnum(_buf[_iCurr]) || _buf[_iCurr] == '_');
				_lenSymbol = _iCurr - _iSymbol;
				if(_lenSymbol >= maxSymLen) _lenSymbol = maxSymLen - 1;
			} 
			else 
				_token = tError;

			break;
	}
	return _token;
}

EToken Scanner::Token() const
{
	return _token;
}


void Scanner::GetSymbolName(char *strOut, int &len) const
{
	strncpy(strOut, &_buf[_iSymbol], _lenSymbol); 
	strOut[_lenSymbol] = '\0';
	len = _lenSymbol;
}

double Scanner::Number() const
{
	return _number;
}

void Scanner::EatWhite()
{
	while(isspace(_buf[_iCurr])) ++_iCurr; 
}
