#ifndef ORANGE_H
#define ORANGE_H
template<class T>
class ORange
{
public:
	ORange(){ max = min = 0; }
	ORange(T pmin, T pmax){
		max = pmax;
		min = pmin;
		Fix();
	}
	~ORange(){}
private:
	T max;
	T min;
public:
	void Fix(){
		if (min > max)
		{
			T tv = min;
			min = max;
			max = tv;
		}
	}
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
	T& GetMin(){
		return min;
	}
	T& GetMax(){
		return max;
	}
	///交集
	ORange<T> Intersection(ORange<T>& set){
		bool bmax = false;
		bool bmin = false;
		if (In(set.GetMax()))
			bmax = true;
		if (In(set.GetMin()))
			bmin = true;

		if (bmax && bmin)
		{
			return set;
		}
		else if (bmax && !bmin)
		{
			return ORange<T>(min,set.GetMax());
		}
		else if (!bmax && bmin)
		{
			return ORange<T>(set.GetMin(), max);
		}
		return ORange<T>();
	}
	///并集
	OSet< ORange<T> > AndSet(ORange<T>& set){
		OSet< ORange<T> > ret;

		bool bmax = false;
		bool bmin = false;
		if (In(set.GetMax()))
			bmax = true;
		if (In(set.GetMin()))
			bmin = true;

		if (bmax && bmin)
		{
			ORange<T> temp = *this;
			ret.Add(temp);
			return ret;
		}
		else if (bmax && !bmin)
		{
			ret.Add(ORange<T>(set.GetMin(), max));
			return ret;

		}
		else if (!bmax && bmin)
		{
			ret.Add(ORange<T>(min, set.GetMax()));
			return ret;
		}
		else
		{
			ret.Add(*this);
			ret.Add(set);
			return ret;
		}

		
	}
	///差集
	OSet<ORange<T> > DifferenceSet(ORange<T>& set){

		OSet< ORange<T> > ret;

		bool bmax = false;
		bool bmin = false;
		if (In(set.GetMax()))
			bmax = true;
		if (In(set.GetMin()))
			bmin = true;

		if (bmax && bmin)
		{
			ret.Add(ORange<T>(min,set.GetMin()));
			ret.Add(ORange<T>(max, set.GetMax()));
			return ret;
		}
		else if (bmax && !bmin)
		{
			ret.Add(ORange<T>(set.GetMax(), max));
			return ret;
		}
		else if (!bmax && bmin)
		{
			ret.Add(ORange<T>(min, set.GetMin()));
			return ret;
		}
		return ret;
	}
};
#endif