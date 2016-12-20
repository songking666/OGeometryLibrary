#ifndef OLINE_H
#define OLINE_H

template<class T = float> class OLine
{
public:
	OLine(){
	};
	OLine(OPoint<T>& pt1, OPoint<T>& pt2){
		m_pt1 = pt1;
		m_pt2 = pt2;
	};
	~OLine(){

	}
private:
	OPoint<T> m_pt1;
	OPoint<T> m_pt2;

public:
	T x1(){
		return m_pt1.GetX();
	}
	T y1(){
		return m_pt1.GetY();
	}
	T x2(){
		return m_pt2.GetX();
	}
	T y2(){
		return m_pt2.GetY();
	}
	OPoint<T>& GetPt1()
	{
		return m_pt1;
	}
	OPoint<T>& GetPt2()
	{
		return m_pt2;
	}
	T GetLen(){
		return sqrt(pow(m_pt2.GetX() - m_pt1.GetX(), 2) +
			pow(m_pt2.GetY() - m_pt1.GetY(), 2) + 
			pow(m_pt2.GetZ() - m_pt1.GetZ(), 2));
	}


	//线外一点求垂线交点
	bool GetVerticalPoint2D(OPoint<T>& inpt,OPoint<T>& outpt)
	{
		T t = ((m_pt1.y - inpt.y)*(m_pt2.y - m_pt1.y) - 
					(m_pt1.x - inpt.x)*(m_pt1.x - m_pt2.x)) / 
				   ((m_pt1.x - m_pt2.x)*(m_pt1.x - m_pt2.x) - 
				    (m_pt1.y - m_pt2.y)*(m_pt2.y - m_pt1.y));
		T ansx = (m_pt1.x - m_pt2.x)*t + m_pt1.x;
		T ansy = (m_pt1.y - m_pt2.y)*t + m_pt1.y;

		if (ansx<m_pt1.x || ansx>m_pt2.x) 
			return false;
		else if (ansy<m_pt1.y || ansy>m_pt2.y) 
			return false;
		else
		{
			outpt = OPoint<T>(ansx,ansy,0);
		}
		return true;
	}
	T GetVerticalLength2D(OPoint<T>& inpt)
	{
		OPoint<T> outpt;
		if (!GetVerticalPoint2D(inpt, outpt))
			return 0;

		OPoint<T> newpt = outpt - inpt;
		return sqrt(pow(newpt.x, 2) + pow(newpt.y, 2));
	}
	bool between(T a, T X0, T X1)
	{
		T temp1 = a - X0;
		T temp2 = a - X1;
		if ((temp1<1e-8 && temp2>-1e-8) || (temp2<1e-6 && temp1>-1e-8))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool detectIntersect(OPoint<T> p3, OPoint<T> p4,OPoint<T>& ret)
	{
		//T x, y; //交点  
		if ((fabs(m_pt1.x - m_pt2.x)<1e-6) && (fabs(p3.x - p4.x)<1e-6))
		{
			return false;
		}
		else if ((fabs(m_pt1.x - m_pt2.x)<1e-6)) //如果直线段p1p2垂直与y轴  
		{
			if (between(m_pt1.x, p3.x, p4.x))
			{
				T k = (p4.y - p3.y) / (p4.x - p3.x);
				ret.x = m_pt1.x;
				ret.y = k*(ret.x - p3.x) + p3.y;

				if (between(ret.y, m_pt1.y, m_pt2.y))
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else if ((fabs(p3.x - p4.x)<1e-6)) //如果直线段p3p4垂直与y轴  
		{
			if (between(p3.x, m_pt1.x, m_pt2.x))
			{
				T k = (m_pt2.y - m_pt1.y) / (m_pt2.x - m_pt1.x);
				ret.x = p3.x;
				ret.y = k*(ret.x - m_pt2.x) + m_pt2.y;

				if (between(ret.y, p3.y, p4.y))
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			T k1 = (m_pt2.y - m_pt1.y) / (m_pt2.x - m_pt1.x);
			T k2 = (p4.y - p3.y) / (p4.x - p3.x);

			if (fabs(k1 - k2)<1e-6)
			{
				return false;
			}
			else
			{
				ret.x = ((p3.y - m_pt1.y) - (k2*p3.x - k1*m_pt1.x)) / (k1 - k2);
				ret.y = k1*(ret.x - m_pt1.x) + m_pt1.y;
			}

			if (between(ret.x, m_pt1.x, m_pt2.x) && between(ret.x, p3.x, p4.x))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}

	OPoint<T> GetMidpt()
	{
		OPoint<T> pt = m_pt2 - m_pt1;
		return m_pt1 + (pt / 2);
	}
	
	void Splite(int seg, vector< OPoint<T> >& retvt)
	{
		OVector<T> vec(m_pt1, m_pt2);
		seg--;
		
		T mo = vec.Norm();
		OVector<T> unitNormal = vec.UnitVector();

		T segment = mo / seg;

		for (int i = 0; i<seg + 1; i++)
		{
			OPoint<T> tempPt(m_pt1.x + unitNormal.x() * segment * i,
				m_pt1.y + unitNormal.y() * segment * i,
				m_pt1.z + unitNormal.z() * segment * i);
			
			retvt.push_back(tempPt);
		}
	}
	void Swip()
	{

	}
	void Rotate(T angle,int id)
	{
		//x' = (x - x0)*cosA - (y - y0)*sinA
		//y' = (y - y0)*cosA + (x - x0)*sinA
	}
};



#endif