#ifndef OBOX_H
#define OBOX_H
/*
-0.5f, -0.5f, -0.5f,
0.5f, -0.5f, -0.5f,
-0.5f, 0.5f, -0.5f,
0.5f, 0.5f, -0.5f,
-0.5f, -0.5f, 0.5f,
0.5f, -0.5f, 0.5f,
-0.5f, 0.5f, 0.5f,
0.5f, 0.5f, 0.5f,


*/
template<class T = float>
class OBox
{
public:
	OBox(void){
		InitIndex();
	}
	OBox(OPoint<T> centerpt, T radius){
		Create(centerpt, radius);
		InitIndex();
	}
	~OBox(){}
private:
	OPoint<T>	vertex[8];
	int face[8][4];
	
	T m_radius;
protected:
	void InitIndex(){
		face[0][0] = 0;
		face[0][1] = 1;
		face[0][2] = 2;
		face[0][3] = 3;

		face[1][0] = 7;
		face[1][1] = 6;
		face[1][2] = 5;
		face[1][3] = 4;

		face[2][0] = 4;
		face[2][1] = 5;
		face[2][2] = 1;
		face[2][3] = 0;

		face[3][0] = 5;
		face[3][1] = 6;
		face[3][2] = 2;
		face[3][3] = 1;

		face[4][0] = 6;
		face[4][1] = 7;
		face[4][2] = 3;
		face[4][3] = 2;

		face[5][0] = 7;
		face[5][1] = 4;
		face[5][2] = 0;
		face[5][3] = 3;
	}
public:
	void Create(OPoint<T>& centerpt, T radius){
		m_radius = radius;
		vertex[0] = OPoint<T>(centerpt.x - radius, centerpt.y - radius, centerpt.z - radius);
		vertex[1] = OPoint<T>(centerpt.x - radius, centerpt.y + radius, centerpt.z - radius);
		vertex[2] = OPoint<T>(centerpt.x + radius, centerpt.y + radius, centerpt.z - radius);
		vertex[3] = OPoint<T>(centerpt.x + radius, centerpt.y - radius, centerpt.z - radius);
		vertex[4] = OPoint<T>(centerpt.x - radius, centerpt.y - radius, centerpt.z + radius);
		vertex[5] = OPoint<T>(centerpt.x - radius, centerpt.y + radius, centerpt.z + radius);
		vertex[6] = OPoint<T>(centerpt.x + radius, centerpt.y + radius, centerpt.z + radius);
		vertex[7] = OPoint<T>(centerpt.x + radius, centerpt.y - radius, centerpt.z + radius);
	}
	ORectangle<T> GetSide(BOX_SIDE side){
		
		ORectangle<T> rc();

		return rc;
	}

	void Move(OPoint<T>& pt){
		for (int i = 0; i < BOX_VERTEX_COUNT; i++)
			vertex[i] += tv;
	}


	bool PtIn(OPoint<T>& pt){

	}

	void RotateX(T r){
		//float tr = ANG2ARC(r);
		//T rm[] = {
		//	cos(tr), 0, -sin(tr),
		//	0, 1, 0,
		//	sin(tr), 0, cos(tr)
		//};
		OMirtex<T> m;
		m.CreateRotateX(r);
		for (int i = 0; i < 8; i++)
			vertex[i] *= m;
	}
	void RotateY(T rx){
		//float tr = ANG2ARC(r);
		//T rm[] = {
		//	1, 0, 0,
		//	0, cos(tr), sin(tr),
		//	0, -sin(tr), cos(tr)
		//};

		OMirtex<T> m(rm, 3, 3);
		m.CreateRotateY(rx);
		for (int i = 0; i < 8; i++)
			vertex[i] *= m;
	}
	void RotateZ(T r){
		//float tr = ANG2ARC(r);
		//T rm[] = {
		//	cos(tr), sin(tr), 0
		//	- sin(tr), cos(tr), 0,
		//	0, 0, 1
		//};

		OMirtex<T> m;
		m.CreateRotateZ4X4(r);
		for (int i = 0; i < 8; i++)
			vertex[i] *= m;
	}

	bool SaveToObj(OString strFileName){
		FILE* fp = fopen(strFileName.ToPChar(), "wt");
		if (!fp)
			return false;

		for (int i = 0; i < BOX_VERTEX_COUNT; i++)
			fprintf(fp,"v %f %f %f\n", vertex[i].x, vertex[i].y, vertex[i].z);

		for (int i = 0; i < BOX_FACE_COUNT; i++)
		{
			fprintf(fp, "f");
			for (int j = 0; j < BOX_FACE_VERTEX_COUNT; j++)
				fprintf(fp, " %d",face[i][j]+1);
			fprintf(fp, "\n");
		}

		fclose(fp);
		return true;
	}

	void operator *(T tv){
		for (int i = 0; i < BOX_VERTEX_COUNT; i++)
			vertex[i] *= tv;
		m_radius *= tv;
	}
	void operator /(T tv){
		for (int i = 0; i < BOX_VERTEX_COUNT; i++)
			vertex[i] /= tv;
		m_radius /= tv;
	}
	void operator +(T tv){
		for (int i = 0; i < BOX_VERTEX_COUNT; i++)
			vertex[i] += tv;
	}
	void operator -(T tv){
		for (int i = 0; i < BOX_VERTEX_COUNT; i++)
			vertex[i] -= tv;
	}
	void operator +(OPoint<T>& tv){
		for (int i = 0; i < BOX_VERTEX_COUNT; i++)
			vertex[i] += tv;
	}
	void operator -(OPoint<T>& tv){
		for (int i = 0; i < BOX_VERTEX_COUNT; i++)
			vertex[i] -= tv;
	}
#ifdef OPENGL
	void OpenGLDraw(){
		glBegin(GL_QUADS);
		for(int i = 0;i<6;i++)
		{
			for(int j = 0;j<4;j++)
				glVertex3f(vertex[face[i][j]].x,
				vertex[face[i][j]].y,
				vertex[face[i][j]].z
				);
		}
		glEnd();
	}
#endif
};

#endif
