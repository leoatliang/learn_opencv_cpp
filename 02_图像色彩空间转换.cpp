#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

class QuickStart {
public:
    void colorConvert(cv::Mat &image);
};

void QuickStart::colorConvert(cv::Mat &image) {
    cv::Mat gray, hsv;

    cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    cvtColor(image, hsv, cv::COLOR_BGR2HSV);

    cv::imshow("Gray", gray);
    cv::imshow("HSV", hsv);

    cv::imwrite("../images/gray.png", gray);
    cv::imwrite("../images/hsv.png", hsv);
}

int main(int argc, char **argv) {
    cv::Mat image = cv::imread("../images/lena.jpg");

    QuickStart qs;
    qs.colorConvert(image);

    cv::imshow("Lena", image);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}