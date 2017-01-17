#ifndef ONUMBER_H
#define ONUMBER_H
template<class T = int> 
class ONumber
{
public:
	ONumber(){ num = 0; }
	ONumber(T n){ num = n; }
	~ONumber(){}
private:
	T num;
public:
	//void Show(){
	//	OString str = T;
	//	str.Show();
	//}
	//OString toString(){
	//	OString str = T;
	//	return str;
	//}

	///////////////////////////////////////////////////////////////
	void operator =(T n){
		num = n;
	}
	void operator =(ONumber<T> n){
		*this = n;
	}
	void operator =(OString n){
		num = n.toFloat();
	}
	//////////////////////////////////////////////////////////////
	T operator +(T n){
		return num + n;
	}
	T operator -(T n){
		return num - n;
	}
	T operator *(T n){
		return num * n;
	}
	T operator /(T n){
		return num / n;
	}
	T operator %(T n){
		return num % n;
	}
	/////////////////////////////////////////////////
	void operator +=(T n){
		num += n;
	}
	void operator -=(T n){
		num -= n;
	}
	void operator *=(T n){
		num *= n;
	}
	void operator /=(T n){
		num /= n;
	}
	void operator %=(T n){
		num %= n;
	}

	void operator ++(void){
		num++;
	}
	void operator --(void){
		num--;
	}
	/////////////////////////////////////////////////
	bool operator ==(T n){
		return num == n;
	}
	bool operator !=(T n){
		return num != n;
	}
	/////////////////////////////////////////////////
};
#endif