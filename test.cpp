// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "OBase.h"


int _tmain(int argc, _TCHAR* argv[])
{
	//OPoint<float> pt1(0,0,0), pt2(1,2,3), pt3(4,3,6), pt4(8,9,88),pt5(100,100,100);
	//OPoint<float> ptres = pt1+1;
	//vector<OPoint3f> vtpt;
	//vtpt.push_back(pt1);
	//vtpt.push_back(pt2);
	//vtpt.push_back(pt3);

	//OVector<float> vectortest(pt3);
	//OVector<float> vectortest2(pt2);

	//float retvec = vectortest*vectortest2;
	//float angle = vectortest.GetAngle(vectortest2);

	//OLine<float> linetest(pt1, pt5);
	//float linelen = linetest.GetLen();
	//OPoint<float> midpt = linetest.GetMidpt();

	//vector< OPoint<float> > retvtpt;
	//OLine<float> linetest3(OPoint<float>(100, 100), OPoint<float>(200, 200));
	//linetest3.Splite(4, retvtpt);

	//OPoint3f pt10(100, 50, 0), pt11(200, 50, 0),pt12(150,90,0);
	//OLine<float> linetest2(pt10,pt11);
	//OPoint3f outpt;
	//linetest2.GetVerticalPoint2D(pt12,outpt);

	//OPolygon<float> poly(vtpt);
	//bool b1 = poly.PtInPoly(OPoint<float>(0,0,1));

	//bool b2 = poly.PtInPoly(OPoint<float>(0, 1, 1));

	//OCircle<float> circle(OPoint<float>(100, 100),50);

	//OPolygon<float> circlepoly =  circle.ToPolygon(360);

	//


	//OPoint<float> pt20(50.1, 50.1);
	//printf(pt20.toString().c_str());
	//OPoint<float> pt21(250, 250);

	//OPoint<float> retpt20,retpt21;

	//circle.CutLine(OLine<float>(pt20, pt21), retpt20, retpt21);

	//circle.CutCircle(OCircle<float>(OPoint<float>(110,150),50), retpt20, retpt21);

	//float f1[] = {
	//	1, 2, 3,
	//	4, 5, 6,
	//	7, 8, 9
	//};
	//float f2[] = {
	//	9, 2, 3,
	//	3, 4, 2,
	//	6, 8, 5
	//};

	//float f3[] = {
	//	9, 3, 6
	//};

	//OMirtex<float> m1(3, 3, f1);
	//OMirtex<float> m2(3, 3, f2);
	//OMirtex<float> m3(1, 3, f3);

	//OMirtex<float> mret = m1*m2;

	//mret = m2*m3;


	////////////////////////////////////////
	////////////////OString test
	{
		OString str1("this is a test");
	//	OString str2("is");
	//	OString str3(" add a string");

	//	OString str13 = 1;

	//	str2 += "1234";
	//	str2 += str3;
	//	
	//	OString tr10 = str1;
	//	str1 += "fffff";

	//	OString str4(str1 + "1234");
	//	OString str6 = str4 + "64444";
	//	OString str5 = str1 + str3;
	//	int pos1 = str1.Find("is");
	//	int pos2 = str1.Find("is", 4);

	//	char testc = str5[0];

	//	str5[1] = '1';

	//	OString str15;
	//	str15.Format("%d %d %f", 1, 2, 3.4);

		OSet<OString> splitedata;
		str1.Splite(' ', splitedata);
		for (int i = 0; i < splitedata.GetLen(); i++)
			printf("%s\n", splitedata[i].ToPChar());

	//	//str1.DelChar('i');

	//	OString stris("is");
	//	OString str444("444");
	//	str1.Replace(stris, str444);
	//	
	}
	/////////////////////////////////////OBox test
	{
		OPoint3f pt(0, 0, 0);
		OBox<float> box(pt, 1);

		box.RotateZ(45);

		box.SaveToObj("G:\\testout.obj");
	}
	{
		float f[] = {
			1, 2, 3,
			4, 5, 6,
			7, 8, 9
		};
		float f2[] = {
			4, 3, 7,
			9, 0, 4,
			9, 3, 0
		};

		OMirtex<float> m1(f, 3, 3);
		OMirtex<float> m2(f2, 3, 3);

		OMirtex<float> m3 = m1 + m2;

		m3.Show();

		//OMirtex<float> m4 = m3.GetRows(1);
		//m4.Show();

		OMirtex<float> m7 = m3.GetCols(0);
		OMirtex<float> m5 = m3.GetCols(1);
		OMirtex<float> m6 = m3.GetCols(2);
		m7.Show();
		m5.Show();
		m6.Show();


		OMirtex<float> m8 = m3.GetRows(0);
		OMirtex<float> m9 = m3.GetRows(1);
		OMirtex<float> m10 = m3.GetRows(2);
		m8.Show();
		m9.Show();
		m10.Show();
		printf("\n\n\n\n");
		m3.Transpose();
		m3.Show();


		/*
输入一个n*n的字符矩阵，把它逆时针旋转90度后输出：

经计算n*n方阵旋转90度的变换矩阵为:
0, 1, 0,               0,  -1,  0
-1, 0, 0,  其逆矩阵为,    1,   0,  0
n-1, 0, 1                0, n-1,  1
*/
		float f3[] = {
			0, 1, 0,
			-1, 0, 0,
			-1, 0, 1
		};
		OMirtex<float> mr(f3, 3, 3);

		OPoint3f rp(1, 0, 0);
		OPoint3f p = rp * mr;
		p.Show();


		OMirtexF m20;
		m20.CreateIdentityMatrix(5, 5);
		m20.Show();
	}
	//////////////////////////////////////////////////////////////////////////////
	{
		//OSet<float> tempset;
		//tempset.Add(1.0f);
		//tempset.Add(2.0f);
		//tempset.Add(3.0f);
		//tempset.Add(4.0f);

		//tempset.Delete(1);

		//printf("%f %f %f", tempset[0], tempset[1], tempset[2]);
		//printf("%f", tempset[3]);


		OSet<OString> strset;
		
		OString str1 = "aaaaaaaaaaaaa";
		OString str2 = "bbbbbbbbbbbbbb";
		strset.Add(OString("this is a test!"));
		strset.Add(str1);
		strset.Add(str2);
		printf("%s\n", strset[0].ToPChar());
		printf("%s\n", strset[1].ToPChar());
		printf("%s\n", strset[2].ToPChar());
	}
	getchar();
	return 0;
}

