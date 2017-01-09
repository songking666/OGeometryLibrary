#ifndef OPOLYGON_H
#define OPOLYGON_H


template<class T = float> class OPolygon
{
public:
	OPolygon(){

	}
	OPolygon(vector < OPoint<T> >& vtpt)
	{
		m_vtpt = vtpt;
	}

	OPolygon(OTriangle<T>& tri)
	{
		for (int i = 0; i < 3;i++)
			m_vtpt.push_back(tri.GetPT(i));
	}
	OPolygon(ORectangle<T>& rc)
	{
		m_vtpt.push_back(OPoint<T>(rc.Left(),rc.Top()));
		m_vtpt.push_back(OPoint<T>(rc.Right(), rc.Top()));
		m_vtpt.push_back(OPoint<T>(rc.Right(), rc.Bottom()));
		m_vtpt.push_back(OPoint<T>(rc.Left(), rc.Bottom()));
	}

	~OPolygon(){

	}
private:
	vector< OPoint<T> >  m_vtpt;
	vector< OLine<T> > m_vtline;
public:
	void AddPT(OPoint<T>& pt){
		m_vtpt.push_back(pt);
	}
	void SetPT(vector< OPoint<T> >& vtpt)
	{
		m_vtpt = vtpt;
	}
	UINT GetCount()
	{
		return m_vtpt.size();
	}
	OPoint<T> GetPT(int id){
		return m_vtpt[id];
	}
	bool PtInPoly(OPoint<T> pt)
	{
		UINT i, j = m_vtpt.size() - 1;
		bool  oddNodes = false;

		for (i = 0; i<m_vtpt.size(); i++) {
			if ((m_vtpt[i].y< pt.y && m_vtpt[j].y >= pt.y
				|| m_vtpt[j].y<pt.y && m_vtpt[i].y >= pt.y)
				&& (m_vtpt[i].x <= pt.x || m_vtpt[j].x <= pt.x)) {
				oddNodes ^= (m_vtpt[i].x + (pt.y - m_vtpt[i].y) / (m_vtpt[j].y - m_vtpt[i].y)*(m_vtpt[j].x - m_vtpt[i].x)<pt.x);
			}
			j = i;
		}

		return oddNodes;
	}

	T Det(OPoint<T>& p0, OPoint<T>& p1, OPoint<T>& p2)
	{
		return (p1.x - p0.x)*(p2.y - p0.y) - (p1.y - p0.y)*(p2.x - p0.x);
	}

	T ploygonArea()
	{
		T s = 0;
		for (UINT i = 1; i < m_vtpt.size() - 1; i++)
			s += Det(m_vtpt[0], m_vtpt[i], m_vtpt[i + 1]);
		return 0.5*abs(s);
	}

	void operator -=(OLine<T>& line)
	{
		OPolygon<T> poly1; //剩下的
		OPolygon<T> poly2; //切角

		bool bfind1 = false;
		bool bfind2 = false;
		for (int i = 0; i < m_vtpt.size() - 1; i++)
		{
			OPoint<T> retpt;
			if (line.detectIntersect(m_vtpt[i], m_vtpt[i + 1], retpt))
			{
				if (!bfind1)
				{
					bfind1 = true;
					poly1.push_back(m_vtpt[i]);
					poly1.push_back(retpt);
					poly2.push_back(retpt);
				}
				else
				{
					bfind2 = true;

					poly1.push_back(retpt);
					poly2.push_back(m_vtpt[i]);
					poly2.push_back(retpt);

				}
				continue;
			}

			if (!bfind1 || bfind2)
			{
				poly1.push_back(m_vtpt[i]);
			}
			else
			{
				poly2.push_back(m_vtpt[i]);
			}
		}

		if (bfind1 && !bfind2)
		{
			OPoint<T> retpt;
			if (line.detectIntersect(m_vtpt[m_vtpt.size() - 1], m_vtpt[0], retpt))
			{
				poly1.push_back(retpt);
				poly2.push_back(m_vtpt[m_vtpt.size() - 1]);
				poly2.push_back(retpt);
			}
		}
		else
		{
			poly1.push_back(m_vtpt[m_vtpt.size() - 1]);
		}


		if (poly1.size() > poly2.size())
			m_vtpt = poly1;
		else
			m_vtpt = poly2;
	}
	OPolygon<T> operator -(OLine<T>& line)
	{
		vector< OPoint<T> >  vtpt = m_vtpt;

		OPolygon<T> poly1; //剩下的
		OPolygon<T> poly2; //切角

		bool bfind1 = false;
		bool bfind2 = false;
		for (int i = 0; i < vtpt.size() - 1; i++)
		{
			OPoint<T> retpt;
			if (line.detectIntersect(vtpt[i], vtpt[i + 1], retpt))
			{
				if (!bfind1)
				{
					bfind1 = true;
					poly1.push_back(vtpt[i]);
					poly1.push_back(retpt);
					poly2.push_back(retpt);
				}
				else
				{
					bfind2 = true;

					poly1.push_back(retpt);
					poly2.push_back(vtpt[i]);
					poly2.push_back(retpt);

				}
				continue;
			}

			if (!bfind1 || bfind2)
			{
				poly1.push_back(vtpt[i]);
			}
			else
			{
				poly2.push_back(vtpt[i]);
			}
		}

		if (bfind1 && !bfind2)
		{
			OPoint<T> retpt;
			if (line.detectIntersect(vtpt[vtpt.size() - 1], vtpt[0], retpt))
			{
				poly1.push_back(retpt);
				poly2.push_back(vtpt[vtpt.size() - 1]);
				poly2.push_back(retpt);
			}
		}
		else
		{
			poly1.push_back(vtpt[vtpt.size() - 1]);
		}


		if (poly1.size() > poly2.size())
			vtpt = poly1;
		else
			vtpt = poly2;
		return vtpt;
	}
	
	OPolygon<T> operator -(ORectangle<T>& rc)
	{
		;
	}
	void operator =(ORectangle<T>& rc)
	{
		;
	}
	void operator =(OCircle<T>& rc)
	{
		;
	}
	OPolygon<T> operator -(OPolygon<T>& poly){

	}
	bool IsInPoly(ORectangle<T>& rc){
		return IsInPoly(rc.toPolygon());
	}
	bool IsInPoly(OPolygon<T>& poly){
		
		for (int i = 0; i < 4; i++)
		{
			if (!PtInPoly(rc.GetPT(i)))
				return false;
		}

		return true;
	}
	bool IsInPoly(OCircle<T>& cir)
	{
		return IsInPoly(cir.ToPolygon(180));
	}
};



#endif