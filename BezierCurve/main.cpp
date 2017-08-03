#ifdef _DEBUG
//Debugモードの場合
#pragma comment(lib,"C:\\opencv\\build\\x86\\vc12\\lib\\opencv_world300d.lib")            // opencv_core
#else
//Releaseモードの場合
#pragma comment(lib,"C:\\opencv\\build\\x86\\vc12\\lib\\opencv_world300.lib") 
#endif

#include "beziercurve.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui_c.h"
#include "complex.h"

using namespace std;
using namespace cv;

int main(){
	BezierCurve curve;

	vector<Point2d> src_points;
	vector<Point2d> dst_points;

	double lx = 20;
	double ly = 1;

	//src_points.push_back(Point2d(0, 0));
	//src_points.push_back(Point2d(0.25 * lx, 0       ));
	//src_points.push_back(Point2d(0.5  * lx, 0.25 * ly));
	//src_points.push_back(Point2d(0.75 * lx, 0.5   * ly));
	//src_points.push_back(Point2d(1    * lx, 0.5   * ly));

	//src_points.push_back(Point2d(1.25 * lx, 0.75 * ly));
	//src_points.push_back(Point2d(1.5  * lx, 1    * ly));
	//src_points.push_back(Point2d(1.75 * lx, 1    * ly));

	src_points.push_back(Point2d(1023*3/100.0, 511*3/100.0));
	//src_points.push_back(Point2d(1003*3/100.0, 531*3/100.0));
	//src_points.push_back(Point2d(983*3/100.0, 531*3/100.0));
	//src_points.push_back(Point2d(963*3/100.0, 551*3/100.0));
	//src_points.push_back(Point2d(943*3/100.0, 551*3/100.0));
	//src_points.push_back(Point2d(923*3/100.0, 551*3/100.0));
	src_points.push_back(Point2d(903*3/100.0, 551*3/100.0));
	//src_points.push_back(Point2d(883*3/100.0, 551*3/100.0));
	//src_points.push_back(Point2d(863*3/100.0, 551*3/100.0));
	//src_points.push_back(Point2d(843*3/100.0, 551*3/100.0));
	//src_points.push_back(Point2d(823*3/100.0, 571*3/100.0));
	//src_points.push_back(Point2d(803*3/100.0, 591*3/100.0));
	src_points.push_back(Point2d(803*3/100.0, 611*3/100.0));
	//src_points.push_back(Point2d(803*3/100.0, 631*3/100.0));
	//src_points.push_back(Point2d(783*3/100.0, 651*3/100.0));
	//src_points.push_back(Point2d(763*3/100.0, 651*3/100.0));
	//src_points.push_back(Point2d(743*3/100.0, 651*3/100.0));
	//src_points.push_back(Point2d(723*3/100.0, 651*3/100.0));
	src_points.push_back(Point2d(703*3/100.0, 651*3/100.0));
	//src_points.push_back(Point2d(683*3/100.0, 651*3/100.0));
	//src_points.push_back(Point2d(663*3/100.0, 651*3/100.0));
	//src_points.push_back(Point2d(643*3/100.0, 651*3/100.0));
	//src_points.push_back(Point2d(623*3/100.0, 651*3/100.0));
	//src_points.push_back(Point2d(603*3/100.0, 651*3/100.0));
	src_points.push_back(Point2d(583*3/100.0, 631*3/100.0));
	//src_points.push_back(Point2d(583*3/100.0, 611*3/100.0));
	//src_points.push_back(Point2d(563*3/100.0, 591*3/100.0));
	//src_points.push_back(Point2d(543*3/100.0, 591*3/100.0));
	//src_points.push_back(Point2d(523*3/100.0, 571*3/100.0));
	//src_points.push_back(Point2d(503*3/100.0, 571*3/100.0));
	src_points.push_back(Point2d(483*3/100.0, 571*3/100.0));
	//src_points.push_back(Point2d(463*3/100.0, 571*3/100.0));
	//src_points.push_back(Point2d(443*3/100.0, 571*3/100.0));
	//src_points.push_back(Point2d(423*3/100.0, 571*3/100.0));
	//src_points.push_back(Point2d(403*3/100.0, 571*3/100.0));
	//src_points.push_back(Point2d(383*3/100.0, 571*3/100.0));
	src_points.push_back(Point2d(363*3/100.0, 571*3/100.0));
	//src_points.push_back(Point2d(343*3/100.0, 571*3/100.0));
	//src_points.push_back(Point2d(323*3/100.0, 571*3/100.0));
	//src_points.push_back(Point2d(303*3/100.0, 571*3/100.0));
	//src_points.push_back(Point2d(283*3/100.0, 571*3/100.0));
	//src_points.push_back(Point2d(263*3/100.0, 571*3/100.0));
	src_points.push_back(Point2d(243*3/100.0, 571*3/100.0));


	curve.Create(src_points, dst_points, 100);
	curve.PrintCurve();
	curve.CsvOut("C:\\Users\\0133752\\Desktop\\bezier.csv");

	return 0;
}