// 10_Histogram_calculation_rendering.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdlib.h"
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;

int main()
{
	//读取本地的一张图片，记录直方图数组并绘制直方图。
	cv::Mat srcMat = imread("C:/Users/lenovo/Desktop/推文/1.jpg");
	cv::Mat Histogram_Mat = imread("C:/Users/lenovo/Desktop/推文/0.png");

	//记录直方图数组
	int height = srcMat.rows; //行数
	int width = srcMat.cols; //每行元素的总元素数量
	int total = height * width;//总元素数量
	float histgram[256] = { 0 };
	for (int j = 0; j<height; j++)
	{
		for (int i = 0; i<width; i++)
		{
			//-----------------开始处理每个像素-----------------
			uchar average = (srcMat.at<Vec3b>(j, i)[0] + srcMat.at<Vec3b>(j, i)[1] +srcMat.at<Vec3b>(j, i)[2]) / 3;
			histgram[average]++;//记录个数
			//-------------结束像素处理------------------------
		} //单行处理结束
	}
	for (int k = 0; k<256; k++)
	{
		histgram[k] = histgram[k] / total * 100 * 20;//计算百分比
	}

	//绘制直方图
	//坐标轴
	cv::Point  pt_x1, pt_x2, pt_y1, pt_y2;
	pt_x1.x = 10; pt_x1.y = 110;
	pt_x2.x = 10; pt_x2.y = 10;
	pt_y1.x = 10; pt_y1.y = 110;
	pt_y2.x = 265; pt_y2.y = 110;

	line(Histogram_Mat, pt_x1, pt_x2, CV_RGB(0, 0, 0), 1, 8, 0);
	line(Histogram_Mat, pt_y1, pt_y2, CV_RGB(0, 0, 0), 1, 8, 0);

	//内容
	cv::Point  pt1,pt2;

	for (int m = 0; m<256; m++)
	{
		pt1.x = 10 + m; pt1.y = 110;
		pt2.x = 10 + m; pt2.y = 110 - histgram[m];
		line(Histogram_Mat, pt1, pt2, CV_RGB(0, 0, 0), 1, 8, 0);
	}

	imshow("src", srcMat);
	imshow("Histogram", Histogram_Mat);
	//等待用户按键
	waitKey(0);
	return 0;
}


