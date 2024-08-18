#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void arithmeticOperation(Mat &image) {
    // Mat dst = image + Scalar(2, 2, 2);
    Mat dst;
    Mat m = Mat::zeros(image.size(), image.type());
    m = Scalar(5, 5, 5);

    // add(image, m, dst);
    // subtract(image, m, dst);
    // multiply(image, m, dst);
    divide(image, m, dst);

    imshow("dst", dst);
}

int main(int argc, char **argv) {
    Mat image = imread("../images/lena.jpg");
    imshow("Lena", image);

    arithmeticOperation(image);

    waitKey(0);
    destroyAllWindows();

    return 0;
}