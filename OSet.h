#ifndef OSET_H
#define OSET_H
template<class T> class OSet
{
public:
	OSet(){ 
		pbuff = NULL;
		len = 0;
		hotindex = -1;
	}
	OSet(OSet<T>& set){
		*this = set;
	}
	OSet(T raa[], int plen){
		pbuff = new T[plen];
		for (int i = 0; i < plen; i++)
			pbuff[i] = raa[i];
		len = plen;
	}
	~OSet(){
		if (pbuff != NULL)
			delete[] pbuff;
		len = 0;
	}
private:
	UINT len;
	int hotindex;
	T* pbuff;
public:
	T* GetFirst(){
		hotindex = 0;
		return pbuff;
	}
	T* GetNext(){
		hotindex++;
		if (hotindex == len || hotindex == -1)
		{
			hotindex = -1;
			return NULL;
		}
		return pbuff + hotindex;
	}
	UINT GetLen(){
		return len;
	}
	void operator =(OSet<T>& tv){
		Clear();
		len = tv.GetLen();
		pbuff = new T[len];
		for (int i = 0; i < len; i++)
			pbuff[i] = tv[i];
	}
	T& operator [](const UINT id){
		return pbuff[id];
	}
	void operator +=(T t){
		T* tempbuff = new T[len + 1];
		for (int i = 0; i < len; i++)
			tempbuff[i] = pbuff[i];
		tempbuff[len] = t;
		len++;

		if (pbuff != NULL)
			delete[] pbuff;
		pbuff = tempbuff;
	}
	void operator +=(OSet& t){
		T* tempbuff = new T[len + t.GetLen()];
		UINT i = 0;
		for (i = 0; i < len; i++)
			tempbuff[i] = pbuff[i];
		for (UINT j = 0; j < t.GetLen(); i++, j++)
			tempbuff[i] = t[j];
		tempbuff[len] = t;
		len++;
		if (pbuff != NULL)
			delete[] pbuff;
		pbuff = tempbuff;
	}
	OSet<T> operator +(OSet<T>& t){
		OSet<T> temp = *this;
		for (int i = 0; i < t.GetLen(); i++)
		{
			int id = IsExist(t[i]);
			if (id==-1)
			{
				temp.Add(t[i]);
			}
		}
		return temp;
	}
	OSet<T> operator -(OSet<T>& set){
		OSet<T> temp;
		for (int i = 0; i < len; i++)
		{
			int id = set.IsExist(pbuff[i]);
			if (id == -1){
				temp.Add(pbuff[i]);
			}
		}
		return temp;
	}

	OSet<T> operator ^(OSet<T>& set){
		OSet<T> temp;
		for (UINT i = 0; i < len; i++)
		{
			for (UINT j = 0; j < set.GetLen(); j++)
			{
				if (pbuff[i] == set[j])
				{
					temp.Add(set[j]);
				}
			}
		}
		return temp;
	}

	int Add(T t){
		T* tempbuff = new T[len+1];
		for (UINT i = 0; i < len;i++)
			tempbuff[i] = pbuff[i];
		tempbuff[len] = t;
		len++;
		
		if (pbuff != NULL)
			delete[] pbuff;
		pbuff = tempbuff;
		return len;
	}
	int AddNoExist(T t){
		if (IsExist(t) != -1)
			return -1;

		T* tempbuff = new T[len + 1];
		for (int i = 0; i < len; i++)
			tempbuff[i] = pbuff[i];
		tempbuff[len] = t;
		len++;

		if (pbuff != NULL)
			delete[] pbuff;
		pbuff = tempbuff;
		return len;
	}
	void Delete(const UINT id){
		T* tempbuff = new T[len - 1];
		memcpy(tempbuff, pbuff, id * sizeof(T));
		memcpy(tempbuff+id, pbuff+id+1, (len-(id+1)) * sizeof(T));
		len--;
		if (pbuff != NULL)
			delete[] pbuff;
		pbuff = tempbuff;
	}
	void Clear(){
		if (pbuff != NULL)
		{
			delete[] pbuff;
		}	
		len = 0;
	}
	T& Get(const UINT id){
		return pbuff[id];
	}
	int IsExist(T& t){
		for (UINT i = 0; i < len; i++)
		{
			if (pbuff[i] == t)
				return i;
		}
		return -1;
	}
	///交集
	OSet<T> Intersection(OSet<T>& set){
		OSet<T> temp;
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < set.GetLen(); j++)
			{
				if (pbuff[i] == set[j])
				{
					temp.Add(set[j]);
				}
			}
		}
		return temp;
	}
	///并集
	OSet<T> AndSet(OSet<T>& set){
		OSet<T> temp;
		for (int i = 0; i < set.GetLen(); i++)
		{
			int id = IsExist(set[i]);
			if (id == -1)
			{
				temp.Add(set[i]);
			}
		}
		return *this + temp;
	}
	///差集
	OSet<T> DifferenceSet(OSet<T>& set){
		OSet<T> temp;
		for (int i = 0; i < len; i++)
		{
			int id = set.IsExist(set[i]);
			if (id == -1){
				temp.Add(set[i]);
			}
		}
		return temp;
	}

	void DeleteDuplicate(){
		OSet<int> id;
		for (int i = 0; i < len; i++)
		{
			for (int j = i + 1; j < len; j++)
			{
				if (pbuff[i] == pbuff[j])
				{
					newset.push_back(pbuff[j]);
					id.Add(j);
				}
			}
		}

		OSet<T> setnew;
		for (int i = 0; i < len; i++)
		{
			int iid = id.IsExist(i);
			if (iid == -1)
				setnew.Add(pbuff[i]);
		}
	}

	void push_back(T t){
		Add(t);
	}

	UINT GetCount(T& t){
		UINT retcount = 0;
		for (int i = 0; i < len;i++)
		if (t == pbuff[i])
			retcount++;
		return retcount;
	}
};
#endif