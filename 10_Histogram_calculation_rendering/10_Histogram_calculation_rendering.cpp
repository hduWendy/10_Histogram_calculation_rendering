// 10_Histogram_calculation_rendering.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "stdlib.h"
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;

int main()
{
	//��ȡ���ص�һ��ͼƬ����¼ֱ��ͼ���鲢����ֱ��ͼ��
	cv::Mat srcMat = imread("C:/Users/lenovo/Desktop/����/1.jpg");
	cv::Mat Histogram_Mat = imread("C:/Users/lenovo/Desktop/����/0.png");

	//��¼ֱ��ͼ����
	int height = srcMat.rows; //����
	int width = srcMat.cols; //ÿ��Ԫ�ص���Ԫ������
	int total = height * width;//��Ԫ������
	float histgram[256] = { 0 };
	for (int j = 0; j<height; j++)
	{
		for (int i = 0; i<width; i++)
		{
			//-----------------��ʼ����ÿ������-----------------
			uchar average = (srcMat.at<Vec3b>(j, i)[0] + srcMat.at<Vec3b>(j, i)[1] +srcMat.at<Vec3b>(j, i)[2]) / 3;
			histgram[average]++;//��¼����
			//-------------�������ش���------------------------
		} //���д������
	}
	for (int k = 0; k<256; k++)
	{
		histgram[k] = histgram[k] / total * 100 * 20;//����ٷֱ�
	}

	//����ֱ��ͼ
	//������
	cv::Point  pt_x1, pt_x2, pt_y1, pt_y2;
	pt_x1.x = 10; pt_x1.y = 110;
	pt_x2.x = 10; pt_x2.y = 10;
	pt_y1.x = 10; pt_y1.y = 110;
	pt_y2.x = 265; pt_y2.y = 110;

	line(Histogram_Mat, pt_x1, pt_x2, CV_RGB(0, 0, 0), 1, 8, 0);
	line(Histogram_Mat, pt_y1, pt_y2, CV_RGB(0, 0, 0), 1, 8, 0);

	//����
	cv::Point  pt1,pt2;

	for (int m = 0; m<256; m++)
	{
		pt1.x = 10 + m; pt1.y = 110;
		pt2.x = 10 + m; pt2.y = 110 - histgram[m];
		line(Histogram_Mat, pt1, pt2, CV_RGB(0, 0, 0), 1, 8, 0);
	}

	imshow("src", srcMat);
	imshow("Histogram", Histogram_Mat);
	//�ȴ��û�����
	waitKey(0);
	return 0;
}


