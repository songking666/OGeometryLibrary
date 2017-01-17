#ifndef OSET_H
#define OSET_H
template<class T = int> class OSet
{
public:
	OSet(){ 
		pbuff = NULL;
		len = 0;
	}
	~OSet(){
		if (pbuff != NULL)
			delete[] pbuff;
	}
private:
	UINT len;
	T* pbuff;
public:
	T* GetFirst(){
		return pbuff;
	}
	UINT GetLen(){
		return len;
	}
	void operator = (OSet& tv){
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
	void Add(T t){
		T* tempbuff = new T[len+1];
		for (int i = 0; i < len;i++)
			tempbuff[i] = pbuff[i];
		tempbuff[len] = t;
		len++;
		
		if (pbuff != NULL)
			delete[] pbuff;
		pbuff = tempbuff;
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
	///交集
	void Intersection(OSet& set){

	}
	///并集
	void AndSet(OSet& set){

	}
	///差集
	void DifferenceSet(OSet& set){

	}
	void push_back(T t){
		Add(t);
	}
};
#endif