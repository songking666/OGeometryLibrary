#ifndef ORANGE_H
#define ORANGE_H
template<class T = int>
class ORange
{
public:
	ORange(){}
	~ORange(){}
private:
	T max;
	T min;
public:
	void Set(T tmax,T tmin){
		max = tmax; 
		min = tmin;
	}

	void operator += (T tv){
		max += tv;
		min += tv;
	}
	void operator -= (T tv){
		max -= tv;
		min -= tv;
	}
	void operator *= (T tv){
		max *= tv;
		min *= tv;
	}
	void operator /= (T tv){
		max /= tv;
		min /= tv;
	}

	bool Inclusion(T tv){
		return tv < max && tv > min;
	}
	bool UnInclusion(T tv){
		return tv > max || tv < min;
	}
	bool In(T tv){
		return tv < max && tv > min;
	}
	bool Out(T tv){
		return tv > max || tv < min;
	}
	///����
	ORange Intersection(ORange& set){

	}
	///����
	ORange AndSet(ORange& set){

	}
	///�
	ORange DifferenceSet(ORange& set){

	}

};
#endif