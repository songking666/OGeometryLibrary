#ifndef OVECTOR_H
#define OVECTOR_H

template<class T = float> class OVector
{
public:
	OVector(OPoint<T>& pt){
		m_pt = pt;
	}
	OVector(OPoint<T>& pt1, OPoint<T>& pt2){
		m_pt = pt2 - pt1;
	}
	OVector();
	~OVector(){

	}

private:
	OPoint<T> m_pt;

public:
	
	OPoint<T> GetPoint(){
		return m_pt;
	}
	T x(){
		return m_pt.x;
	}
	T y(){
		return m_pt.y;
	}
	T z(){
		return m_pt.z;
	}
	//求向量的模
	T Norm(){
		return sqrt(pow(m_pt.x, 2) + pow(m_pt.y, 2) + pow(m_pt.z, 2));
	}
	//求向量的单位向量
	OVector<T> UnitVector(){
		T norm = Norm();
		OVector<T> ret(m_pt / norm);
		return ret;
	}
	
	OVector<T> operator +(OVector<T>& vt){
		OPoint<T> pt = m_pt + vt.GetPoint();
		OVector<T> vec(pt);
		return vec;
	}
	
	OVector<T> operator -(OVector<T>& vt){
		OPoint<T> pt = m_pt - vt.GetPoint();
		OVector<T> vec(pt);
		return vec;
	}
	//向量点积
	T operator *(OVector<T>& vt){
		T ret = m_pt.x * vt.GetPoint().x + 
			    m_pt.y * vt.GetPoint().y + 
				m_pt.z * vt.GetPoint().z;
		return ret;
	}

	OVector<T> operator *(float fv){
		OPoint<T> pt = m_pt * fv;
		OVector<T> ret(pt);
		return ret;
	}

	OVector<T> operator /(float fv){
		OPoint<T> pt = m_pt / fv;
		OVector<T> ret(pt);
		return ret;
	}

	T Dot(OVector<T>& vt)
	{
		T = m_pt.x * vt.GetPoint().x + m_pt.y *.GetPoint().y + m_pt.z *.GetPoint().z;
		return T;
	}
	//向量内积
	OVector<T> Inner3D(OVector<T>& vt){
		OPoint<T> pt;
		pt.x = m_pt.y*vt.GetPoint().z - m_pt.z*vt.GetPoint().y;//计算三阶行列式
		pt.y = m_pt.z*vt.GetPoint().x - m_pt.x*vt.GetPoint().z;
		pt.z = m_pt.x*vt.GetPoint().y - m_pt.y*vt.GetPoint().x;
		OVector<T> ret(pt);
		return ret;
	}
	
	void operator += (OVector<T>& vt){
		m_pt += vt.GetPoint();
	}
	void operator -= (OVector<T>& vt){
		m_pt -= vt.GetPoint();
	}
	void operator -(void){
		m_pt.x = -m_pt.x;
		m_pt.y = -m_pt.y;
		m_pt.z = -m_pt.z;
	}
	void operator *= (OVector<T>& vt){
		m_pt = m_pt * vt.GetPoint();
	}
	//向量夹角
	T GetAngle(OVector<T>& vt){
		T px = m_pt.x * vt.GetPoint().y - vt.GetPoint().x * m_pt.y;
		T py = m_pt.x * vt.GetPoint().x + m_pt.y * vt.GetPoint().y;

		//float angle = (pt1.x*pt2.x + pt1.y*pt2.y) / (sqrt(pow(pt1.x, 2) + pow(pt1.y, 2))*sqrt(pow(pt2.x, 2) + pow(pt2.y, 2)));
		return atan2(px, py);
	}
};



#endif