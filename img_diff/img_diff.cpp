#include "opencv2/core.hpp"
#include <opencv2/video.hpp>
#include "opencv2/opencv.hpp"  
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;
int wid;
int hgt;

double moveDetect(Mat &cur, Mat &last,int wid,int hgt)
{
	cv::Mat frame_cur_gray, frame_last_gray;
	cv::Mat diff(cv::Size(wid, hgt), CV_8UC1);
	cvtColor(cur, frame_cur_gray, CV_BGR2GRAY);
	cvtColor(last, frame_last_gray, CV_BGR2GRAY);
	absdiff(frame_cur_gray, frame_last_gray, diff);
	int blockSize = 25;
	int constValue = 10;
	cv::Mat diff_thresh;
	cv::adaptiveThreshold(diff, diff_thresh, 255, CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_BINARY_INV, blockSize, constValue);
	Mat element = getStructuringElement(MORPH_RECT, Size(2, 2));
	//medianBlur(src, dst, 7);
	//GaussianBlur(dst, dst, Size(3, 1), 0.0);
	erode(diff_thresh, diff_thresh, element);
	dilate(diff_thresh, diff_thresh, element);

	//calc white percent
	Mat diff01;
	normalize(diff_thresh, diff01, 0, 1, cv::NORM_MINMAX);
	double sum_diff_roi = countNonZero(diff01);
	double percent = sum_diff_roi / ((double)wid * hgt);
	return percent;

}

int main(int argc, char* argv[])
{
	bool first = true;
	Mat frame_cur,frame_last;
	
	VideoCapture video("../test1.avi");
	//isOpen
	if (!video.isOpened())
	{
		cout << "Movie open Error" << endl;
		return -1;
	}
	video.set(CV_CAP_PROP_POS_FRAMES, 0);

	//VideoCapture video(0);
	//video.set(CV_CAP_PROP_FRAME_WIDTH, 640);
	//video.set(CV_CAP_PROP_FRAME_HEIGHT, 480);

    std::cout<<"\033[33mHello \033[34mworld!\033[0m"<<std::endl;
	if(!video.isOpened())
	{
		cout << "open video file failed. " << endl;
		return -1;
	}

	wid = video.get(CV_CAP_PROP_FRAME_WIDTH);
	hgt = video.get(CV_CAP_PROP_FRAME_HEIGHT);

	while(true)
	{
		
		video >> frame_cur;
		if (first)
		{
			frame_last = frame_cur.clone();
			first = !first;
			continue;
		}

		double percent = moveDetect(frame_cur, frame_last, wid, hgt);
		cout << percent << endl;

		frame_last = frame_cur.clone();

		waitKey(30);

	}
	video.release();
    return 0;
}

