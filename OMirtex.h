#ifndef OMIRTEX_H
#define OMIRTEX_H
template<class T = float> class OMirtex
{
public:
	int m_Rows;
	int m_Cols;
	T *m_P;
public:
	OMirtex(const UINT rows = 0, const  UINT cols = 0){
			int m, n;
			m_P = 0;
			if (rows<0 || cols<0)
				return;
			m_Rows = rows;
			m_Cols = cols;
			m_P = new T[m_Rows*m_Cols];

			for (m = 0; m<rows; m++)
			for (n = 0; n<cols; n++)
				m_P[m*cols + n] = 0;
		
	}
	OMirtex(const OMirtex &rc){
		int i, j;
		m_Rows = rc.m_Rows;
		m_Cols = rc.m_Cols;
		int size = m_Rows*m_Cols;
		m_P = new T[size];
		memcpy(m_P, rc.m_P, sizeof(T)*size);
	}
	OMirtex(T* farr, int rows, int cols){
		m_Rows = rows;
		m_Cols = cols;
		int size = m_Rows*m_Cols;
		m_P = new T[size];
		memcpy(m_P, farr, sizeof(T)*size);
	}
	~OMirtex(){
		if (m_P != 0)
			delete[]m_P;
	}

	void Show(){
		int i, j;
		for (i = 0; i<m_Rows; i++)
		{
			for (j = 0; j<m_Cols; j++)
				printf(" %f",m_P[i*m_Cols + j]);
			printf("\n");
		}
	}
	///////////////////////////////////////////////////////////////////////////////////////////
	OMirtex operator+(OMirtex &rc){
		if (m_Rows != rc.m_Rows || m_Cols != rc.m_Cols)
			return OMirtex();
		OMirtex r(m_Rows, m_Cols);
		for (int i = 0; i<m_Rows; i++)
		for (int j = 0; j<rc.m_Cols; j++)
			r.m_P[i*m_Cols + j] = m_P[i*m_Cols + j] + rc.m_P[i*m_Cols + j];
		return r;
	}
	OMirtex operator*(OMirtex &rc){
		int i, j, k;
		if (m_Cols != rc.m_Rows)
			return OMirtex();
		OMirtex r(m_Rows, rc.m_Cols);
		for (i = 0; i<m_Rows; i++)
		for (j = 0; j<rc.m_Cols; j++)
		for (k = 0; k<m_Cols; k++)
			r.m_P[i*rc.m_Cols + j] += m_P[i*m_Cols + k] * rc.m_P[k*rc.m_Cols + j];
		return r;
	}
	OMirtex operator-(OMirtex &rc){
		if (m_Rows != rc.m_Rows || m_Cols != rc.m_Cols)
			return OMirtex();
		OMirtex r(m_Rows, m_Cols);
		for (int i = 0; i<m_Rows; i++)
		for (int j = 0; j<rc.m_Cols; j++)
			r.m_P[i*m_Cols + j] = m_P[i*m_Cols + j] - rc.m_P[i*m_Cols + j];
		return r;
	}
	/////////////////////////////////////////////////////////////////////////////
	OMirtex operator+(T tv){
		OMirtex r(m_Rows, m_Cols);
		int size = m_Rows * m_Cols;
		for (int i = 0; i<size; i++)
			r.m_P[i] = m_P[i] + tv;
		return r;
	}
	OMirtex operator*(T tv){
		OMirtex r(m_Rows, m_Cols);
		int size = m_Rows * m_Cols;
		for (int i = 0; i<size; i++)
			r.m_P[i] = m_P[i] * tv;
		return r;
	}
	OMirtex operator-(T tv){
		OMirtex r(m_Rows, m_Cols);
		int size = m_Rows * m_Cols;
		for (int i = 0; i<size; i++)
			r.m_P[i] = m_P[i] - tv;
		return r;
	}
	OMirtex operator/(T tv){
		OMirtex r(m_Rows, m_Cols);
		int size = m_Rows * m_Cols;
		for (int i = 0; i<size; i++)
			r.m_P[i] = m_P[i] / tv;
		return r;
	}
	////////////////////////////////////////////////////////////////////////////////////
	OMirtex & operator=(OMirtex &rc){
		if (m_P != 0)
			delete m_P;
		m_Rows = rc.m_Rows;
		m_Cols = rc.m_Cols;
		m_P = new T[m_Rows*m_Cols];
		for (int i = 0; i<m_Rows*m_Cols; i++)
			m_P[i] = rc.m_P[i];
		return *this;
	}

	////////////////////////////////////////////////////////////
	void operator+=(T tv){
		int size = m_Rows * m_Cols;
		for (int i = 0; i<size; i++)
			m_P[i] += tv;
	}
	void operator*=(T tv){
		int size = m_Rows * m_Cols;
		for (int i = 0; i<size; i++)
			m_P[i] *= tv;
	}
	void operator-=(T tv){
		int size = m_Rows * m_Cols;
		for (int i = 0; i<size; i++)
			m_P[i] -= tv;
	}
	void operator/=(T tv){
		int size = m_Rows * m_Cols;
		for (int i = 0; i<size; i++)
			m_P[i] /= tv;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	OMirtex GetRows(const int rows){
		if (rows > m_Rows)
			return OMirtex();

		OMirtex r(1, m_Cols);
		for (int i = 0; i<m_Cols; i++)
			r.m_P[i] = m_P[rows * m_Rows + i];
		return r;
	}
	OMirtex GetCols(const int cols){
		if (cols > m_Cols)
			return OMirtex();

		OMirtex r(m_Rows, 1);
		for (int j = 0; j<m_Rows; j++)
			r.m_P[j] = m_P[j*m_Cols + cols];
		return r;
	}
	/////////////////////////////////////////////////////////////////////////////////////////
	void operator+=(OMirtex &rc){
		if (m_Rows != rc.m_Rows || m_Cols != rc.m_Cols)
			return;
		
		for (int i = 0; i<m_Rows; i++)
		for (int j = 0; j<rc.m_Cols; j++)
			m_P[i*m_Cols + j] = m_P[i*m_Cols + j] + rc.m_P[i*m_Cols + j];
		
	}
	void operator*=(OMirtex &rc){
		int i, j, k;
		if (m_Cols != rc.m_Rows)
			return;
	
		for (i = 0; i<m_Rows; i++)
		for (j = 0; j<rc.m_Cols; j++)
		for (k = 0; k<m_Cols; k++)
			m_P[i*rc.m_Cols + j] += m_P[i*m_Cols + k] * rc.m_P[k*rc.m_Cols + j];
		
	}
	void operator-=(OMirtex &rc){
		if (m_Rows != rc.m_Rows || m_Cols != rc.m_Cols)
			return;
		
		for (int i = 0; i<m_Rows; i++)
		for (int j = 0; j<rc.m_Cols; j++)
			m_P[i*m_Cols + j] = m_P[i*m_Cols + j] - rc.m_P[i*m_Cols + j];

	}
	/////////////////////////////////////////////////////////////////////////////////////
	//~
	void Transpose(){
		T* tempbuff = new T[m_Rows * m_Cols];

		for (int i = 0; i<m_Rows; i++)
		for (int j = 0; j < m_Cols; j++)
			tempbuff[i*m_Rows + j] = m_P[j*m_Cols+i];

		int tempv = m_Rows;
		m_Rows = m_Cols;
		m_Cols = tempv;

		delete[] m_P;
		m_P = tempbuff;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////
	T operator [](const UINT index){
		return m_P[index];
	}
	////////////////////////////////////////////////////////////////////////////////////////////
	//旋转矩阵4X4
	void CreateRotateX4X4(T ang){
		T arc = ANG2ARC(ang);
		m_Rows = 4;
		m_Cols = 4;
		int size = m_Rows*m_Cols;
		if (m_P != 0)
			delete[]m_P;
		m_P = new T[size];

		T arr[] = {
			1, 0, 0, 0,
			0, cos(arc), -sin(arc), 0,
			0, sin(arc), cos(arc), 0,
			0, 0, 0, 1
		};

		memcpy(m_P, arr, sizeof(T)*size);
	}

	void CreateRotateY4X4(T ang){
		T arc = ANG2ARC(ang);
		m_Rows = 4;
		m_Cols = 4;
		int size = m_Rows*m_Cols;
		if (m_P != 0)
			delete[]m_P;
		m_P = new T[size];

		T arr[] = {
			cos(arc), 0, sin(arc), 0,
			0, 1, 0, 0,
			-sin(arc), 0, cos(arc), 0,
			0, 0, 0, 1
		};

		memcpy(m_P, arr, sizeof(T)*size);
	}
	void CreateRotateZ4X4(T ang){
		T arc = ANG2ARC(ang);
		m_Rows = 4;
		m_Cols = 4;
		int size = m_Rows*m_Cols;

		if (m_P != 0)
			delete[]m_P;
		m_P = new T[size];

		T arr[] = {
			cos(arc), -sin(arc), 0, 0,
			sin(arc), cos(arc), 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		};
		
		memcpy(m_P, arr, sizeof(T)*size);
	}
	///////////////////////////////////////////////////////////////////////////
	//旋转矩阵3X3
	void CreateRotateX3X3(T ang){
		T arc = ANG2ARC(ang);
		m_Rows = 3;
		m_Cols = 3;
		int size = m_Rows*m_Cols;
		if (m_P != 0)
			delete[]m_P;
		m_P = new T[size];

		T arr[] = {
			cos(tr), 0, -sin(tr),
			0, 1, 0,
			sin(tr), 0, cos(tr)
		};

		memcpy(m_P, arr, sizeof(T)*size);
	}

	void CreateRotateY3X3(T ang){
		T arc = ANG2ARC(ang);
		m_Rows = 3;
		m_Cols = 3;
		int size = m_Rows*m_Cols;
		if (m_P != 0)
			delete[]m_P;
		m_P = new T[size];

		T arr[] = {
			1, 0, 0,
			0, cos(tr), sin(tr),
			0, -sin(tr), cos(tr)
		};

		memcpy(m_P, arr, sizeof(T)*size);
	}
	void CreateRotateZ3X3(T ang){
		T arc = ANG2ARC(ang);
		m_Rows = 3;
		m_Cols = 3;
		int size = m_Rows*m_Cols;

		if (m_P != 0)
			delete[]m_P;
		m_P = new T[size];

		T arr[] = {
			cos(tr), sin(tr), 0
			- sin(tr), cos(tr), 0,
			0, 0, 1
		};

		memcpy(m_P, arr, sizeof(T)*size);
	}
	////////////////////////////////////////////////////////////////////////
	//单位矩阵
	void CreateIdentityMatrix(const UINT rows,T v = 1){

		m_Rows = rows;
		m_Cols = rows;
		m_P = new T[m_Rows*m_Cols];

		for (int m = 0; m<m_Rows; m++)
		for (int n = 0; n<m_Cols; n++)
		if (m==n)
			m_P[m*rows + n] = v;
		else
			m_P[m*rows + n] = 0;
	}

};

#endif