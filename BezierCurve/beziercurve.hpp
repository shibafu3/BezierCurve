#ifndef BEZIERCURVE_HPP
#define BEZIERCURVE_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include "opencv2/opencv.hpp"
#include "complex.h"


class BezierCurve{
	std::vector<cv::Point2d> dst_points;

	long double BinomialCoefficients(int n, int k){
		int i;
		long double p = 1;

		for (i = 1; i <= k; i++){
			p = p*(n - i + 1) / i;
		}
		return p;
	}

public:
	int Create(std::vector<cv::Point2d> &input_points, std::vector<cv::Point2d> &output_points, int points_num){
		if (input_points.empty() || points_num <= 0){ return 1; }
		points_num--;

		size_t n = input_points.size() - 1;

		long double t = 0.0;
		long double k = 0.0;
		long double tempX = 0.0;
		long double tempY = 0.0;

		std::vector<cv::Point2d>::iterator pathItr = input_points.begin();
		for (t = 0; t <= points_num; t++){
			tempX = 0.0;
			tempY = 0.0;
			k = 0;
			for (pathItr = input_points.begin(); pathItr < input_points.end(); pathItr++){
				tempX += BinomialCoefficients(n, k) * powl(t / points_num, k) * powl((1 - (t / points_num)), n - k) * pathItr->x;
				tempY += BinomialCoefficients(n, k) * powl(t / points_num, k) * powl((1 - (t / points_num)), n - k) * pathItr->y;
				k++;
			}
			dst_points.push_back(cv::Point2d(tempX, tempY));
		}
		output_points = dst_points;
		return 0;
	}
	int Create(std::vector<cv::Point2d> &input_points, int points_num){
		if (input_points.empty() || points_num <= 0){ return 1; }
		points_num--;

		size_t n = input_points.size() - 1;

		long double t = 0.0;
		long double k = 0.0;
		long double tempX = 0.0;
		long double tempY = 0.0;

		std::vector<cv::Point2d>::iterator pathItr = input_points.begin();
		for (t = 0; t <= points_num; t++){
			tempX = 0.0;
			tempY = 0.0;
			k = 0;
			for (pathItr = input_points.begin(); pathItr < input_points.end(); pathItr++){
				tempX += BinomialCoefficients(n, k) * powl(t / points_num, k) * powl((1 - (t / points_num)), n - k) * pathItr->x;
				tempY += BinomialCoefficients(n, k) * powl(t / points_num, k) * powl((1 - (t / points_num)), n - k) * pathItr->y;
				k++;
			}
			dst_points.push_back(cv::Point2d(tempX, tempY));
		}
		return 0;
	}
	int CsvOut(char *file_name){
		std::ofstream ofs(file_name);
		double theta;
		double length;
		ofs << dst_points[0].x << "," << dst_points[0].y << std::endl;
		for (int i = 1; i < dst_points.size() - 2; i++){
			theta = atan2(dst_points[i + 2].y - dst_points[i].y, dst_points[i + 2].x - dst_points[i].x) - atan2(dst_points[i + 1].y - dst_points[i - 1].y, dst_points[i + 1].x - dst_points[i - 1].x);
			length = sqrt(pow(dst_points[i + 1].x - dst_points[i].x, 2) + pow(dst_points[i + 1].y - dst_points[i].y, 2));
			ofs << dst_points[i].x << "," << dst_points[i].y << "," << theta / length << std::endl;
		}
		ofs << dst_points[dst_points.size() - 2].x << "," << dst_points[dst_points.size() - 2].y << std::endl;
		ofs << dst_points[dst_points.size() - 1].x << "," << dst_points[dst_points.size() - 1].y << std::endl;
		return 0;
	}
	int PrintCurve(){
		std::cout << dst_points << std::endl;
		return 0;
	}
};

#endif