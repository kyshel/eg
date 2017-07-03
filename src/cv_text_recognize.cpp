#include  "opencv2/text.hpp"
#include  "opencv2/highgui.hpp"
#include  "opencv2/imgproc.hpp"

#include  <vector>
#include  <iostream>
#include  <iomanip>

using namespace std;
using namespace cv;
using namespace cv::text;



int main(int argc, const char * argv[])
{
	Mat img;
	img = imread("word_remember.jpg");
	if (img.empty())
	{
		cout << "no img data";
		return -1;
	}

	namedWindow("window_a", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("window_a", img);

	std::string output_string;
	Mat mask;

	Ptr<OCRTesseract> ocr = OCRTesseract::create();
	
	ocr->run(img, output_string);
	cout << output_string;
	

	waitKey(0);

	return 0;
}
