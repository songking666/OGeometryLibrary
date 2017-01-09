#ifndef OMIRTEX_H
#define OMIRTEX_H
template<class T = float> class OMirtex
{
public:
//	OMirtex(){
//		setDim(1, 1);
//		valid = false;
//	}
//	OMirtex(UINT w, UINT h){
//		rows = w;
//		cols = h;
//		for (int i = 0; i < w; i++)
//		{
//			vector<T> w_data;
//			w_data.assign(h, 0);
//			m_data.push_back(w_data);
//		}
//		valid = true;
//	}
//	OMirtex(int w,int h,float * data){
//		rows = w;
//		cols = h;
//		for (int i = 0; i < w; i++)
//		{
//			vector<T> w_data;
//			if (data == NULL)
//				w_data.assign(h,0);
//			else
//			{
//				for (int j = 0; j < h; j++)
//				{
//					//w_data.push_back(data[i][j]);
//				}
//			}
//			m_data.push_back(w_data);
//		}
//		valid = true;
//	}
//
//	//OMirtex(int w, int h, T data = 0){
//	//	rows = w;
//	//	cols = h;
//	//	for (int i = 0; i < w; i++)
//	//	{
//	//		vector<T> w_data;
//	//		w_data.assign(h, data);
//	//		m_data.push_back(w_data);
//	//	}
//	//	valid = true;
//	//}
//
//
//	~OMirtex(){}
//private:
//	T *arr;
//	int  rows;
//	int  cols;
//	bool valid;
//public:
//	void setDim(unsigned int row, unsigned int cow)
//	{
//		m_data.resize(row);
//		for (unsigned int i = 0; i < row; i++)
//		{
//			m_data[i].resize(cow);
//		}
//	}
//
//	int Rows(){ return rows; }
//	int Cols(){ return cols; }
//
//	void Set(int w, int h, T* data){
//		rows = w;
//		cols = h;
//		for (int i = 0; i < h; i++)
//		{
//			vector<T> w_data;
//			if (data == NULL)
//				w_data.push_back(0);
//			else
//			{
//				for (int j = 0; j < w, j++)
//				{
//					w_data.push_back(data[i][j]);
//				}
//			}
//			m_data.push_back(w_data);
//		}
//		valid = true;
//	}
//	
//	
//	void Set(int w, int h, T data){
//		rows = w;
//		cols = h;
//		for (int i = 0; i < h; i++)
//		{
//			vector<T> w_data;
//			w_data.assign(w, data);
//			m_data.push_back(w_data);
//		}
//		valid = true;
//	}
//
//	T& Get(int row, int col)
//	{
//		return m_data[row][col];
//	}
//	const vector<float>& operator[](unsigned int row) const
//	{
//		return m_data[row];
//	}
//	vector<float>& operator [](unsigned int row)
//	{
//		return m_data[row];
//	}
//	
//	OMirtex<T> RowsMat(unsigned int r)  const //取第r行向量
//	{
//		OMirtex<T> R(1, Cols());
//		for (unsigned i = 0; i < Cols(); i++)
//		{
//			R[0][i] = m_data[r - 1][i];
//		}
//		return R;
//	}
//	OMirtex<T> ColsMat(unsigned c)  const //取第c列向量
//	{
//		OMirtex<T> C(Rows(), 1);
//		for (unsigned i = 0; i < Rows(); i++)
//		{
//			C[i][0] = m_data[i][c - 1];
//		}
//		return C;
//	}
//
//	friend OMirtex<T>  operator+(const OMirtex<T>&A, const OMirtex< T>&B)     //矩阵加法
//	{
//		OMirtex<T> C(A.Rows(), A.Cols());
//
//		for (unsigned i = 0; i < C.Rows(); i++)
//		{
//			for (unsigned j = 0; j < C.Cols(); j++)
//			{
//				C[i][j] = A[i][j] + B[i][j];
//			}
//		}
//		return C;
//	}
//	friend OMirtex<T>  operator-(const OMirtex<T>&A, const OMirtex<T>&B)     //矩阵减法
//	{
//		OMirtex<T> C(A.Rows(), A.Cols());
//
//		for (unsigned i = 0; i <C.Rows(); i++)
//		{
//			for (unsigned j = 0; j < C.Cols(); j++)
//			{
//				C[i][j] = A[i][j] - B[i][j];
//			}
//		}
//		return C;
//	}
//	OMirtex<T>  operator*(const OMirtex<T>& B)   //矩阵乘法
//	{
//		unsigned i, j, k;
//		OMirtex<T> C(Rows(), B.Cols());
//		for (i = 0; i <Rows(); i++)
//		{
//			for (j = 0; j < B.Rows(); j++)
//			{
//				for (k = 0; k < Cols(); k++)
//				{
//					C[i][j] += m_data[i][k] * B[k][j];
//				}
//			}
//		}
//		return C;
//	}
//	friend OMirtex<T>  operator*(const T& e, const OMirtex<T>& A)     //矩阵数乘
//	{
//		OMirtex<T> C(A.Rows(), A.Cols());
//
//		for (unsigned i = 0; i < C.Rows(); i++)
//		{
//			for (unsigned j = 0; j < C.Cols(); j++)
//			{
//				C[i][j] = A[i][j] * e;
//			}
//		}
//		return C;
//	}
//	friend OMirtex<T>  operator/(const OMirtex<T>&A, const T& e)     //矩阵除以一个数
//	{
//		OMirtex<T> C(A.Rows(), A.Cols());
//
//		for (unsigned i = 0; i < C.Rows(); i++)
//		{
//			for (unsigned j = 0; j < C.Cols(); j++)
//			{
//				C[i][j] = A[i][j] / e;
//			}
//		}
//		return C;
//	}
//
//	bool isSquare() const  //判断是否为方阵
//	{
//		return rows == cols;
//	}
};

#endif