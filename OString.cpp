#include "stdafx.h"
#include <stdarg.h>   
#include "OString.h"


OString::OString()
{
	pdatabuff = NULL;
	mlen = 0;
}
OString::OString(OString& str)
{
	mlen = str.GetLen();
	pdatabuff = new char[mlen + 1];
	pdatabuff[mlen] = 0;
	memcpy(pdatabuff, str.ToPChar(), mlen);
}
OString::OString(char* buff, int len)
{
	if (len == -1)
		mlen = strlen(buff);
	else
		mlen = len;
	pdatabuff = new char[mlen + 1];
	pdatabuff[mlen] = 0;
	memcpy(pdatabuff, buff, mlen);
}

OString::OString(int iv)
{
	char buff[256] = { 0 };
	_itoa(iv, buff, 10);
	mlen = strlen(buff);
	pdatabuff = new char[mlen + 1];
	pdatabuff[mlen] = 0;
	memcpy(pdatabuff, buff, mlen);
}
OString::OString(float iv)
{
	char buff[256] = { 0 };
	sprintf(buff, "%f", iv);
	mlen = strlen(buff);
	pdatabuff = new char[mlen + 1];
	pdatabuff[mlen] = 0;
	memcpy(pdatabuff, buff, mlen);
}
OString::OString(double iv)
{
	char buff[256] = { 0 };
	sprintf(buff, "%lf", iv);
	mlen = strlen(buff);
	pdatabuff = new char[mlen + 1];
	pdatabuff[mlen] = 0;
	memcpy(pdatabuff, buff, mlen);
}
OString::~OString()
{
	clear();
}
char* OString::ToPChar()
{
	return pdatabuff;
}
int OString::Find(char* str, UINT startpos)
{
	if (startpos >= mlen)
		return -1;

	for (UINT i = startpos; i < mlen; i++)
	{
		if (str[0] == pdatabuff[i])
		{
			bool bisDiff = false;
			int len2 = strlen(str);
			for (int j = 1; j < len2; j++)
			{
				if (i + j >= mlen)
				{
					bisDiff = true;
					break;
				}
				if (pdatabuff[i + j] != str[j])
				{
					bisDiff = true;
					break;
				}
			}
			if (!bisDiff)
				return i;
		}
	}
	return -1;
}
int OString::rFind(char* str, UINT startpos)
{
	if (startpos >= mlen || startpos < 0)
		return -1;

	for (UINT i = startpos; i >= 0; i--)
	{
		if (str[0] == pdatabuff[i])
		{
			bool bisDiff = false;
			int len2 = strlen(str);
			for (int j = 1; j < len2; j++)
			{
				if (i + j >= mlen)
				{
					bisDiff = true;
					break;
				}
				if (pdatabuff[i + j] != str[j])
				{
					bisDiff = true;
					break;
				}
			}
			if (!bisDiff)
				return i;
		}
	}
	return -1;
}

void OString::operator =(OString& pcbuff)
{
	clear();
	int datalen = pcbuff.GetLen();
	pdatabuff = new char[datalen + 1];
	pdatabuff[datalen] = 0;
	memcpy(pdatabuff, pcbuff.ToPChar(), datalen);
	mlen = datalen;
	//return *this;
}
void OString::operator =(char* pcbuff)
{
	clear();
	int datalen = strlen(pcbuff);
	pdatabuff = new char[datalen + 1];
	pdatabuff[datalen] = 0;
	memcpy(pdatabuff, pcbuff, datalen);
	mlen = datalen;
}
void OString::operator =(int num)
{
	clear();
	char buff[256] = { 0 };
	_itoa(num, buff, 10);
	mlen = strlen(buff);
	pdatabuff = new char[mlen + 1];
	pdatabuff[mlen] = 0;
	memcpy(pdatabuff, buff, mlen);
}
bool OString::operator ==(char* buff)
{
	if (strcmp(buff, pdatabuff) == 0)
		return true;
	return false;
}
bool OString::operator !=(char* buff)
{
	if (strcmp(buff, pdatabuff) == 0)
		return false;
	return true;
}
OString OString::operator +(char* pcbuff)
{
	int newcharlen = strlen(pcbuff);
	char* tempbuff = new char[mlen + newcharlen + 1];
	tempbuff[mlen + newcharlen] = 0;
	memcpy(tempbuff, pdatabuff, mlen);
	char* newpos = tempbuff + mlen;
	memcpy(newpos, pcbuff, newcharlen);

	OString newstr;
	newstr = tempbuff;

	delete[] tempbuff;
	return newstr;
}
OString OString::operator +(OString& pcbuff)
{
	OString newstr = pdatabuff;
	OString new2;
	new2 = newstr + pcbuff.ToPChar();
	return new2;
}
void OString::operator +=(char* pcbuff)
{
	int newcharlen = strlen(pcbuff);
	char* tempbuff = new char[mlen + newcharlen + 1];
	tempbuff[mlen + newcharlen] = 0;
	memcpy(tempbuff, pdatabuff, mlen);
	char* newpos = tempbuff + mlen;
	memcpy(newpos, pcbuff, newcharlen);

	clear();
	pdatabuff = tempbuff;
	mlen = mlen + newcharlen;
}
void OString::operator +=(OString& pcbuff)
{
	int newcharlen = pcbuff.GetLen();
	char* tempbuff = new char[mlen + newcharlen + 1];
	tempbuff[mlen + newcharlen] = 0;
	memcpy(tempbuff, pdatabuff, mlen);
	char* newpos = tempbuff + mlen;
	memcpy(newpos, pcbuff.ToPChar(), newcharlen);

	clear();
	pdatabuff = tempbuff;
	mlen = mlen + newcharlen;
}
bool OString::operator ==(OString& buff)
{
	if (strcmp(buff.ToPChar(), pdatabuff) == 0)
		return true;
	return false;
}
char& OString::operator [](UINT pos)
{
	return pdatabuff[pos];
}

OString OString::operator -(OString& buff){
	OString str;
	OString src = *this;
	src.Replace(buff, str);
	return src;
}
OString OString::operator -(char* buff){
	OString str;
	OString src = *this;
	src.Replace(buff, str.ToPChar());
	return src;
}
void OString::operator -=(OString& buff){
	OString str;
	Replace(buff, str);
}
void OString::operator -=(char* buff){
	OString str;
	Replace(buff, str.ToPChar());
}



UINT OString::GetLen()
{
	return mlen;
}
OString OString::SubStr(UINT spos,UINT ncount)
{
	OString ret;
	if (spos + ncount > mlen)
	{
		ncount = mlen - spos;
	}
	char* tempbuff = new char[ncount+1];
	tempbuff[ncount + 1] = 0;

	for (UINT i = 0; i < ncount; i++)
		tempbuff[i] = pdatabuff[spos + i];

	ret = tempbuff;
	delete[] tempbuff;

	return ret;
}
int OString::ToInt()
{
	return atoi(pdatabuff);
}
float OString::toFloat()
{
	return atof(pdatabuff);
}
double OString::toDouble(){
	return atof(pdatabuff);
}
OString OString::toUpper()
{
	OString ret = pdatabuff;
	for (UINT i = 0; i < ret.GetLen(); i++)
	{
		if (ret[i] >= 'a'&&ret[i] <= 'z')
			ret[i] -= 32;
	}
	return ret;
}
OString OString::toLower()
{
	OString ret = pdatabuff;
	for (UINT i = 0; i < ret.GetLen(); i++)
	{
		if (ret[i] >= 'A'&&ret[i] <= 'Z')
			ret[i] += 32;
	}
	return ret;
}
void OString::clear()
{
	if (pdatabuff != NULL)
	{
		delete[] pdatabuff;
		pdatabuff = NULL;
	}
	mlen = 0;
}
void OString::Splite(char split, OSet<OString>& ret)
{
	OString strtempchar;
	for (UINT i = 0; i < mlen; i++)
	{
		if (pdatabuff[i] == split)
		{
			ret.Add(strtempchar);
			strtempchar.clear();
		}
		else
		{
			strtempchar.AddChar(pdatabuff[i]);
		}
	}
	if (strtempchar.GetLen() != 0)
		ret.Add(strtempchar);
}
void OString::Format(const char * _Format, ...)
{
	clear();
	//mlen = strlen(_Format);
	pdatabuff = new char[1024 + 1];
	//pdatabuff[mlen] = 0;
	
	va_list arg_ptr;
	va_start(arg_ptr, _Format);

	_vsnprintf(pdatabuff, 1024, _Format, arg_ptr);
	mlen = strlen(pdatabuff);
}
void OString::AddChar(char c)
{
	UINT templen = mlen;
	char* newdatabuff = new char[mlen + 2];
	if (pdatabuff)
		memcpy(newdatabuff, pdatabuff, mlen);
	newdatabuff[mlen] = c;
	newdatabuff[mlen+1] = 0;
	
	clear();
	
	pdatabuff = newdatabuff;

	mlen = templen + 1;
}
string OString::toStdstring()
{
	string strret = pdatabuff;
	return strret;
}
void OString::DelChar(char c)
{
	char* tempbuff = new char[mlen+1];
	for (UINT i = 0, j = 0; i < mlen; i++)
	{
		if (pdatabuff[i] != c)
		{
			tempbuff[j] = pdatabuff[i];
			j++;
		}
	}
	clear();
	pdatabuff = tempbuff;
}

void OString::Replace(OString& str, OString& tarStr)
{
	OString strbuff;
	for (UINT i = 0, j = 0; i < mlen; i++)
	{
		if (pdatabuff[i] == str[0])
		{
			bool bfind = true;
			//OString tempbuff;
			int k = i + 1;
			for (UINT j = 1; j < str.GetLen() && k < mlen; j++, k++)
			{
				if (pdatabuff[k] != str[j])
				{
					bfind = false;
					break;
				}	
			}
			if (bfind)
			{
				//strbuff += tarStr;
				i += str.GetLen() - 1;
			}
		}
		else
		{
			strbuff.AddChar(pdatabuff[i]);
		}
	}
	clear();
	*this = strbuff;
}

void OString::Replace(char* srcStr, char* tarStr){
	OString str1(srcStr);
	OString str2(tarStr);

	Replace(str1,str2);
}

void OString::Show()
{
	printf("%s", pdatabuff);
}

