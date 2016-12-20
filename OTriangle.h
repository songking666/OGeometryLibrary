#ifndef OTRIGANLE_H
#define OTRIGANLE_H


template<class T = float> class OTriangle
{
public:
	OTriangle(){}
	OTriangle(OPoint<T>& pt1, OPoint<T>& pt2, OPoint<T>& pt3){
		m_pt[0] = pt1;
		m_pt[1] = pt2;
		m_pt[2] = pt3;
	}
private:
	OPoint<T> m_pt[3];


public:
	OPoint<T> GetPT(int id){
		m_pt[id];
	}


	OTriangle<T> operator +(OPoint<T>& pt){
		OTriangle<T> ret(m_pt[0] + pt, m_pt[1] + pt, m_pt[2] + pt);
		return ret;
	};
	OTriangle<T> operator +(T tv){
		OTriangle<T> ret(m_pt[0] + tv, m_pt[1] + tv, m_pt[2] + tv);
		return ret;
	};
	OTriangle<T> operator -(OPoint<T>& pt){
		OTriangle<T> ret(m_pt[0] - pt, m_pt[1] - pt, m_pt[2] - pt);
		return ret;
	};
	OTriangle<T> operator -(T tv){
		OTriangle<T> ret(m_pt[0] - tv, m_pt[1] - tv, m_pt[2] - tv);
		return ret;
	};
	OTriangle<T> operator *(T tv){
		OTriangle<T> ret(m_pt[0] * tv, m_pt[1] + tv, m_pt[2] + tv);
		return ret;
	};
	OTriangle<T> operator /(T tv){
		OTriangle<T> ret(m_pt[0] / tv, m_pt[1] / tv, m_pt[2] / tv);
		return ret;
	};
	
	void operator *=(T tv){
		m_pt[0] *= tv;
		m_pt[1] *= tv;
		m_pt[2] *= tv;
	}
	void operator /=(T tv){
		m_pt[0] /= tv;
		m_pt[1] /= tv;
		m_pt[2] /= tv;
	}

	TRIANGLE_TYPE GetType(){

	}
};


#endif