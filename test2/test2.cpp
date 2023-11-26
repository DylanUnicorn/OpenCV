#include<opencv2/opencv.hpp>
#include<iostream>
#include<time.h>
#include<string>
#include<vector>
using namespace std;
using namespace cv;

void Rgb2Hsv(float R, float G, float B, float& H, float& S, float& V)
{
	// r,g,b values are from 0 to 1
	// h = [0,360], s = [0,1], v = [0,1]
	// if s == 0, then h = -1 (undefined)
	float min, max, delta, tmp;
	tmp = R > G ? G : R;
	min = tmp > B ? B : tmp;
	tmp = R > G ? R : G;
	max = tmp > B ? tmp : B;
	V = max / 255 * 100; // v
	delta = max - min;
	if (max != 0)
		S = delta / max * 100; // s
	else
	{
		// r = g = b = 0 // s = 0, v is undefined
		S = 0;
		H = 0;
		return;
	}
	if (delta == 0)
	{
		H = 0;
		return;
	}
	else if (R == max)
	{
		if (G >= B)
			H = (G - B) / delta; // between yellow & magenta
		else
			H = (G - B) / delta + 6.0;
	}
	else if (G == max)
		H = 2.0 + (B - R) / delta; // between cyan & yellow
	else if (B == max)
		H = 4.0 + (R - G) / delta; // between magenta & cyan

	H *= 60.0; // degrees

}
int main()
{
	Mat srcImage = imread("D:\\e盘文件\\狼牙招新\\车牌3.png", 1);

	if (!srcImage.data)
		return 0;

	int row = srcImage.rows;
	int col = srcImage.cols;
	Mat hsvimg = Mat(row, col, CV_8UC3);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			float b = srcImage.at<Vec3b>(i, j)[0];
			float g = srcImage.at<Vec3b>(i, j)[1];
			float r = srcImage.at<Vec3b>(i, j)[2];
			float h, s, v;

			Rgb2Hsv(r, g, b, h, s, v);
			hsvimg.at<Vec3b>(i, j)[0] = h;//h数值若大于255会自动减去255，推荐在ImageWatch模式下查看结果
			hsvimg.at<Vec3b>(i, j)[1] = s;
			hsvimg.at<Vec3b>(i, j)[2] = v;
		}
	}
	namedWindow("zhanshi", WINDOW_NORMAL);
		imshow("zhanshi",srcImage);

	waitKey(0);
	return 0;
}
