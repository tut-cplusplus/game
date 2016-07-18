#include <iostream>
#include <vector>
#include <fstream>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

bool checkSize(const Mat* images, int n)
{
	int rows, cols;
	rows = images[0].rows;
	cols = images[0].cols;
	for (int i = 1; i < n; i++) {
		const Mat& image = images[i];
		if (rows != image.rows || cols != image.cols)
			return false;
	}
	return true;
}

int main(int argc, char** argv)
{
	if (argc <= 1) {
		cerr << argv[0] << " filepath1 filepath2 ..." << endl;
		return 1;
	}

	vector<string> fpaths;
	for (int i = 1; i < argc; i++)
		fpaths.push_back(argv[i]);

	int n = fpaths.size();
	Mat* images = new Mat[n];

	for (int i = 0; i < n; i++) {
		const string& fpath = fpaths[i];
		images[i] = imread(fpath);
	}

	if (!checkSize(images, n)) {
		cerr << "invalid image size" << endl;
		return 1;
	}

	int rows = images[0].rows;
	int cols = images[0].cols;

	Mat image = Mat::zeros(rows, cols * n, CV_8UC3);
	Rect roi_rect;
	roi_rect.width = cols;
	roi_rect.height = rows;
	for (int i = 0; i < n; i++) {
		const Mat& image1 = images[i];
		Mat roi(image, roi_rect);
		image1.copyTo(roi);
		roi_rect.x += image1.cols;
	}
	delete[] images;

	imwrite("output.ppm", image);

	ofstream ofs("output.ani");
	ofs << "output.ppm" << endl;
	ofs << 1 << " " << n << endl;
	ofs << 1 << endl;

	return 0;
}

