#ifndef OBOX_H
#define OBOX_H
template<class T = float>
class OBox
{
public:
	OBox();
	//OBox(OPoint<T>& ptarr[], int ptcount){

	//}
	~OBox();
private:
	OPoint<T>	vertex[8];
	vector< vector<int> > vtface;

	ORectangle<T>	rect[6];

public:
	ORectangle<T> GetSide(BOX_SIDE side){

	}

	
};

#endif
