#ifndef OBASE_H
#define OBASE_H
#include <math.h>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
using namespace std;

#define EPS (2 ^ (-52))

#ifndef MPI
#define MPI 3.1415926
#endif

#ifndef M_PI
#define M_PI 3.1415926
#endif

#ifndef PI
#define PI 3.1415926
#endif


#ifndef UINT
#define UINT unsigned int
#endif



#define ANG2ARC(I) (M_PI /180*I)
#define ARC2ANG(I) (180.0 / M_PI * I)


enum TRIANGLE_TYPE
{
	TRIANGLE_TYPE_Acute, //Èñ½Ç
	TRIANGLE_TYPE_Right, //Ö±½Ç
	TRIANGLE_TYPE_Obtuse //
};

enum BOX_SIDE
{
	BOX_SIDE_TOP,
	BOX_SIDE_BOTTOM,
	BOX_SIDE_LEFT,
	BOX_SIDE_RIGHT,
	BOX_SIDE_FRONT,
	BOX_SIDE_BACK
};

template<class T = float> class OPoint;
template<class T = float> class OLine;
template<class T = float> class OPolygon;
template<class T = float> class OTriangle;
template<class T = float> class OVector;
template<class T = float> class OCircle;
template<class T = float> class OMirtex;
template<class T = float> class OBox;
class OString;

#include "OPoint.h"
#include "OLine.h"
#include "OVector.h"
#include "ORectangle.h"
#include "OTriangle.h"
#include "OCircle.h"
#include "OPolygon.h"
#include "OMirtex.h"
#include "OBox.h"
#include "OString.h"

typedef OPoint<float> OPoint3f;
typedef OPoint<double> OPoint3d;
typedef OPoint<int> OPoint3i;

typedef OLine<float> OLineF;
typedef OLine<double> OLineD;
typedef OLine<int> OLineI;

typedef OVector<float> OVectorF;
typedef OVector<double> OVectorD;
typedef OVector<int> OVectorI;

typedef ORectangle<float> ORectangleF;
typedef ORectangle<double> ORectangleD;
typedef ORectangle<int> ORectangleI;

typedef OCircle<float> OCircleF;
typedef OCircle<double> OCircleD;
typedef OCircle<int> OCircleI;

typedef OTriangle<float> OTriangleF;
typedef OTriangle<double> OTriangleD;
typedef OTriangle<int> OTriangleI;

typedef OPolygon<float> OPolygonF;
typedef OPolygon<double> OPolygonD;
typedef OPolygon<int> OPolygonI;

typedef vector<OPolygonF> VTPOLYF;
typedef vector<OPolygonD> VTPOLYD;
typedef vector<OPolygonI> VTPOLYI;




#endif