#ifndef ORECTANGLE_H
#define ORECTANGLE_H

template<class T = float> class ORectangle
{
public:
	ORectangle(OPoint<T>& pt1, OPoint<T>& pt2){
		float left = pt1.x < pt2.x ? pt1.x : pt2.x;
		float right = pt1.x > pt2.x ? pt1.x : pt2.x;
		float top = pt1.y < pt2.y ? pt1.y : pt2.y;
		float bottom = pt1.y > pt2.y ? pt1.y : pt2.y;

		m_lefttop = OPoint<T>(left, top);
		m_rightbottom = OPoint<T>(right, bottom);
	}
	ORectangle(OPoint<T>& pt, T radius){
		m_lefttop = pt - radius;
		m_rightbottom = pt + radius;
	}
	ORectangle(){}
	~ORectangle(){}
private:
	OPoint<T> m_lefttop;
	OPoint<T> m_rightbottom;
public:
	OPoint<T> GetPT(int id)
	{
		switch (id)
		{
		case 0: return OPoint<T>(m_lefttop.x, m_lefttop.top);
		case 1: return OPoint<T>(m_rightbottom.x, m_lefttop.top);
		case 2: return OPoint<T>(m_rightbottom.x, m_rightbottom.bottom);
		case 3: return OPoint<T>(m_lefttop.x, m_rightbottom.bottom);
		}

	}

	T Left(){
		return m_lefttop.GetX();
	}

	T Right(){
		return m_rightbottom.GetX();
	}

	T Top(){
		return m_lefttop.GetY();
	}

	T Bottom(){
		return m_rightbottom.GetY();
	}

	OPoint<T> GetMidPt(){
		return m_lefttop + (m_rightbottom - m_lefttop) / 2;
	}

	bool PtInRect(OPoint<T>& pt){
		double xl, xr, yt, yb;

		xl = m_lefttop.x;
		xr =m_rightbottom.x;
		
		yt =m_rightbottom.y;
		yb = m_lefttop.y;
		
		return ((pt.x >= xl && pt.x <= xr) && (pt.y >= yb && pt.y <= yt));
	}

	T GetWidth(){
		return m_rightbottom.X() - m_lefttop.X();
	}
	T GetHeight(){
		return m_rightbottom.Y() - m_lefttop.Y();
	}
	T Area(){
		return GetWidth() * GetHeight();
	}

	void Rotate(T angle){
		//x' = (x - x0)*cosA - (y - y0)*sinA
		//y' = (y - y0)*cosA + (x - x0)*sinA
	}

	void Translate(OPoint<T>& transpt){
		m_lefttop += transpt;
		m_rightbottom += transpt;
	}

	void operator += (OPoint<T> tv){
		m_lefttop += tv;
		m_rightbottom += tv;
	}
	void operator -= (OPoint<T> tv){
		m_lefttop -= tv;
		m_rightbottom -= tv;
	}
	void operator += (T tv){
		m_lefttop += tv;
		m_rightbottom += tv;
	}
	void operator -= (T tv){
		m_lefttop -= tv;
		m_rightbottom -= tv;
	}
	void operator *= (T tv){
		m_lefttop *= tv;
		m_rightbottom *= tv;
	}
	void operator /= (T tv){
		m_lefttop /= tv;
		m_rightbottom /= tv;
	}

	bool IsRectIntersect(ORectangle& rc){
		return ((max(m_lefttop.x, m_rightbottom.x) >= min(rc.GetLeft(), rc.GetRight()))
			&& (max(rc.GetLeft(), rc.GetRight()) >= min(m_lefttop.x, m_rightbottom.x))
			&& (max(m_lefttop.y, m_rightbottom.y) >= min(rc.GetTop(), rc.GetButtom))
			&& (max(rc.GetTop(), rc.GetButtom) >= min(m_lefttop.y, m_rightbottom.y)));
	}

	OPolygon<T> toPolygon()
	{
		OPolygon<T> poly;
		poly.AddPT(OPoint<T>(m_lefttop.x,m_lefttop.top));
		poly.AddPT(OPoint<T>(m_rightbottom.x, m_lefttop.top));
		poly.AddPT(OPoint<T>(m_rightbottom.x, m_rightbottom.bottom));
		poly.AddPT(OPoint<T>(m_lefttop.x, m_rightbottom.bottom));
		return poly;
	}
#ifdef _AFX
	//void Draw(HDC dc);
#endif

};


#endif