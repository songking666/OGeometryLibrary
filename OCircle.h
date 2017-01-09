#ifndef OCIRCLE_H
#define OCIRCLE_H

template<class T = float> class OCircle
{
public:
	OCircle(OPoint<T>& pt,float r){
		m_midpt = pt;
		m_r = r;
	}
	OCircle(){}
	~OCircle(){}
private:
	OPoint<T> m_midpt;
	T m_r;

public:
	OPoint<T> GetMidPt(){
		return m_midpt;
	}
	//取得
	T GetRadio()
	{
		return m_r;
	}
	//取得与线段的交点
	bool CutLine(OLine<T>& line, OPoint<T>& pt1, OPoint<T>& pt2){
		pt1.x = pt2.x = 65536.0f;
		pt1.y = pt2.y = 65536.0f;
		float fDis = line.GetLen();
		OPoint<T> d;
		d = (line.GetPt2() - line.GetPt1()) / fDis;
		
		OPoint<T> E;
		E = m_midpt - line.GetPt1();
		
		float a = E.X() * d.X() + E.Y() * d.Y();
		float a2 = a * a;
		float e2 = E.X() * E.X() + E.Y() * E.Y();
		if ((m_r - e2 + a2) < 0)
		{
			return false;
		}
		else
		{
			float f = (float)sqrt(m_r - e2 + a2);
			float t = a - f;
			if (((t - 0.0) > -EPS) && (t - fDis) < EPS)
			{
				pt1.x = line.GetPt1().x + t * d.X();
				pt1.y= line.GetPt1().y + t * d.Y();
			}
			t = a + f;
			if (((t - 0.0) > -EPS) && (t - fDis) < EPS)
			{
				pt2.x = line.GetPt1().x + t * d.X();
				pt2.y = line.GetPt1().y + t * d.Y();
			}
			return true;
		}
	}
	//圆与圆的交点
	bool CutCircle(OCircle<T>& cir1, OPoint<T>& pt1, OPoint<T>& pt2)
	{
		T x1, x2, y1, y2;
		if (cir1.m_midpt.y != m_midpt.y)
		{
			T m, k, a, b, c;
			m = (cir1.m_midpt.x - m_midpt.x) / (m_midpt.y - cir1.m_midpt.y);
			k = (pow(cir1.m_r, 2) - pow(m_r, 2) + pow(m_midpt.x, 2) - pow(cir1.m_midpt.x, 2) + pow(m_midpt.y, 2) - pow(cir1.m_midpt.y, 2)) / (2 * (m_midpt.y - cir1.m_midpt.y));
			a = 1 + pow(m, 2);
			b = 2 * (k*m - m_midpt.x - m*m_midpt.y);
			c = pow(m_midpt.x, 2) + pow(m_midpt.y, 2) + pow(k, 2) - 2 * k*m_midpt.y - pow(m_r, 2);
			if (b*b - 4 * a*c >= 0)
			{
				x1 = ((-b) + sqrt(b*b - 4 * a*c)) / (2 * a);
				y1 = m*x1 + k;
				x2 = ((-b) - sqrt(b*b - 4 * a*c)) / (2 * a);
				y2 = m*x2 + k;//y=mx+k
				if (b*b - 4 * a*c > 0)
				{
					//printf("The cross points are (%lf,%lf) and (%lf,%lf).\n", x1, y1, x2, y2);
					pt1 = OPoint<T>(x1, y1);
					pt2 = OPoint<T>(x2, y2);
					return true;
				}
				else
				{
					//printf("The cross points are (%lf,%lf).\n", x1, y1);
					pt1 = OPoint<T>(x1, y1);
					return true;
				}

			}
			else
				return false;
		}
		else if ((cir1.m_midpt.y == m_midpt.y))
		{
			T a, b, c;
			x1 = -(pow(cir1.m_midpt.x, 2) - pow(m_midpt.x, 2) - pow(cir1.m_r, 2) + pow(m_r, 2)) / (2 * m_midpt.x - 2 * cir1.m_midpt.x);
			x2 = x1;
			a = 1;
			b = -2 * cir1.m_midpt.y;
			c = pow(x1, 2) + pow(cir1.m_midpt.x, 2) - 2 * cir1.m_midpt.x*x1 + pow(cir1.m_midpt.y, 2) - pow(cir1.m_r, 2);
			if (b*b - 4 * a*c >= 0)
			{
				y1 = ((-b) + sqrt(b*b - 4 * a*c)) / (2 * a);
				y2 = ((-b) - sqrt(b*b - 4 * a*c)) / (2 * a);
				if (b*b - 4 * a*c > 0)
				{
					//printf("The cross points are (%lf,%lf) and (%lf,%lf).\n", x1, y1, x1, y2);
					pt1 = OPoint<T>(x1, y1);
					pt2 = OPoint<T>(x2, y2);
					return true;
				}

				else
				{
					//printf("The cross points are (%lf,%lf).\n", x1, y1);
					pt1 = OPoint<T>(x1, y1);
					return true;
				}

			}
			else
				return false;
		}
		return false;
	}
	//取得面积
	T GetArea(){
		return MPI * m_r * m_r;
	}
	//取得周长
	T GetRoundLen()
	{
		return MPI * m_r * 2;
	}

	OPolygon<T> ToPolygon(int segment)
	{
		float startangle = 0;
		vector< OPoint<T> > vtpt;

		float oneseg = (MPI * 2)/ segment;

		for (int i = 0; i < segment; i++)
		{
			T tempX = cos(startangle) * m_r + m_midpt.GetX();
			T tempY = sin(startangle) * m_r + m_midpt.GetY();

			vtpt.push_back(OPoint<T>(tempX,tempY));
			startangle += oneseg;
		}
		OPolygon<T> retpoly(vtpt);
		return retpoly;
	}
};



#endif