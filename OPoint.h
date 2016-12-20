#ifndef OPOINT_H
#define OPOINT_H

template<class T = float> class OPoint
{
public:

	OPoint(){ x = 0; y = 0; z = 0; m_bAvailable = true; };
	OPoint(T px, T py, T pz = 0){
		x = px;
		y = py;
		z = pz;
		m_bAvailable = true;
	}
	OPoint(bool bAvailable){ m_bAvailable = bAvailable; }
	~OPoint(){};

public:
	T x;
	T y;
	T z;
	bool m_bAvailable;
public:
	T& X(){ return x; };
	T& Y(){ return y; };
	T& Z(){ return z; };

	T GetX(){ return x; };
	T GetY(){ return y; };
	T GetZ(){ return z; };

	void SetX(T px){ x = px; };
	void SetY(T py){ y = py; };
	void SetZ(T pz){ z = pz; };

	void SetXYZ(T px, T py, T pz){
		x = px;
		y = py;
		z = pz;
	};

	OPoint<T> operator +(OPoint<T>& pt){
		OPoint<T> retpt(x+pt.GetX(),y+pt.GetY(),z+pt.GetZ());
		return retpt;
	};
	OPoint<T> operator +(T tv){
		OPoint<T> retpt(x + tv, y + tv, z + tv);
		return retpt;
	};
	OPoint<T> operator -(OPoint<T>& pt){
		OPoint<T> retpt(x - pt.GetX(), y - pt.GetY(), z - pt.GetZ());
		return retpt;
	};
	OPoint<T> operator -(T tv){
		OPoint<T> retpt(x - tv, y - tv, z - tv);
		return retpt;
	};
	OPoint<T> operator *(T fv){
		OPoint<T> retpt(x * fv, y  * fv, z  * fv);
		return retpt;
	};
	OPoint<T> operator /(T fv){
		OPoint<T> retpt(x / fv, y / fv, z / fv);
		return retpt;
	};
	void operator +=(OPoint<T>& pt){
		x += pt.GetX();
		y += pt.GetY();
		z += pt.GetZ();
	}
	void operator -=(OPoint<T>& pt){
		x -= pt.GetX();
		y -= pt.GetY();
		z -= pt.GetZ();
	}
	void operator *=(T tv){
		x *= tv;
		y *= tv;
		z *= tv;
	}
	void operator /=(T tv){
		x /= tv;
		y /= tv;
		z /= tv;
	}
	
	bool operator ==(OPoint<T> pt){
		return (x = pt.x && y = pt.y && z == pt.z);
	}
	bool operator != (OPoint<T> pt){
		if (x = pt.x && y = pt.y && z == pt.z)
			return false;
		return true;
	}

	OPoint<T> Mirror(OPoint<T>& pt){
		T vecx = pt.x - x;
		T vecy = pt.y - y;
		T vecz = pt.z - z;

		return OPoint<T>(pt.x - vecx, pt.y - vecy, pt.z - vecz);
	}

#ifdef _AFX
	CPoint toMFCCPoint(){
		return CPoint(x,y);
	}
#endif
};





#endif //OPOINT_H