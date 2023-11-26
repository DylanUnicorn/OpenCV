#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	Mat src = imread("D:\\e盘文件\\狼牙招新\\车牌3.png");
	Mat osrc, gray, bs, img_copy_cut,src_dilate;
	namedWindow("原图", 16);
	imshow("原图", src);
	Rect rect_roi = Rect(620, 650, 620, 550);
	img_copy_cut = src(rect_roi);
	imshow("img", img_copy_cut);

	cvtColor(img_copy_cut,gray,COLOR_BGR2GRAY);
	//inRange(hsv, Scalar(110, 43, 46), Scalar(115, 255, 255), bs);
		threshold(gray,bs, 115, 255,THRESH_BINARY);

	imshow("bs", bs);
	Mat kernal = getStructuringElement(MORPH_RECT, Size(25, 25));
	dilate(bs, src_dilate, kernal, Point(-1, -1), 2);
	imshow("膨胀", src_dilate);
	Mat foreground(img_copy_cut.size(), CV_8UC3, Scalar(255, 255, 255));
	img_copy_cut.copyTo(foreground, src_dilate);
	imshow("..", foreground);

	//imshow("最终", src_dilate);

	
	//cvtColor(src, osrc, COLOR_BGR2GRAY);

	//inRange(osrc, Scalar(200, 99, 75), Scalar(216, 150, 90), as);
	//namedWindow("zhanshi", 8);
	//imshow("zhanshi", as);
	


	//Mat foreground(src.size(), CV_8UC3, Scalar(255, 255, 255));
	//c.copyTo(foreground, result);//copyTo有两种形式，此形式表示result为mask
	//imshow("foreground", foreground);
	waitKey(0);
	return 0;
}
