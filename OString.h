#ifndef OSTRING_H
#define OSTRING_H
#include "OBase.h"
//template<class T = char>
class OString
{
public:
	OString();
	OString(OString& str);
	OString(char* buff, int len = -1);

	OString(int iv);
	OString(float iv);
	OString(double iv);
	~OString();
protected:
	UINT mlen;
	char* pdatabuff;
public:

	void operator = (OString& pcbuff);
	void operator =(char* pcbuff);
	void operator =(int num);
	bool operator ==(char* buff);
	bool operator ==(OString& buff);
	bool operator !=(char* buff);
	void operator +=(char* pcbuff);
	void operator +=(OString& pcbuff);
	char& operator [](UINT pos);
	OString operator +(char* pcbuff);
	OString operator +(OString& pcbuff);

	char* ToPChar();

	int Find(char* str, int startpos = 0);
	int rFind(char* str, int startpos = 0);

	UINT GetLen();

	int ToInt();
	float toFloat();
	double toDouble();

	OString SubStr(UINT start, UINT count);

	OString toUpper();
	OString toLower();

	void clear();

	void Format(const char * _Format, ...);
	
	void AddChar(char c);

	void Splite(char split, vector<OString>& ret);
};


//typedef OString<char> OStringC;
//typedef OString<wchar_t> OStringWC;
#endif