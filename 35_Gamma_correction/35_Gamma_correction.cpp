// 35_Gamma_correction.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{
	//��ȡ���ص�һ��ͼƬ����ͼƬ����gamma����������ʾ������
	cv::Mat srcMat = imread("C:/Users/lenovo/Desktop/��ͼͼƬ/face.jpg",0);

	uint8_t b[256] = { 0 };
	for (int t = 255; t > 0; t--)
	{
		float t_0_1 = t / 255.0;
		b[t] = (uint8_t)255 * pow(t_0_1, 0.5);
	}

	int height = srcMat.rows; //����
	int width = srcMat.cols; //ÿ��Ԫ�ص���Ԫ������
	for (int j = 0; j<height; j++)
	{
		for (int i = 0; i<width; i++)
		{
			//-----------------��ʼ����ÿ������-----------------
			uint8_t p = srcMat.at<uint8_t>(j, i);
			srcMat.at<uint8_t>(j, i) = b[p];

			//-------------�������ش���------------------------
		} //���д������
	}
	imshow("src", srcMat);
	//�ȴ��û�����
	waitKey(0);
	return 0;
}
