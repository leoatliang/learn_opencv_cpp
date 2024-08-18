#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void pixelVisitByArray(Mat &image) {
    int width = image.cols;
    int height = image.rows;
    int channel = image.channels();

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if (channel == 1) {
                uchar pv = image.at<uchar>(row, col);
                image.at<uchar>(row, col) = 255 - static_cast<int>(pv);
            } else if (channel == 3) {
                Vec3b bgr = image.at<Vec3b>(row, col);
                image.at<Vec3b>(row, col)[0] = 255 - bgr[0];
                image.at<Vec3b>(row, col)[1] = 255 - bgr[1];
                image.at<Vec3b>(row, col)[2] = 255 - bgr[2];
            }
        }
    }
}

void pixelVisitByPointer(Mat &image) {
    int width = image.cols;
    int height = image.rows;
    int channel = image.channels();

    for (int row = 0; row < height; row++) {
        uchar *cur_row = image.ptr<uchar>(row);

        for (int col = 0; col < width; col++) {
            if (channel == 1) {
                *cur_row++ = 255 - *cur_row;
            } else if (channel == 3) {
                *cur_row++ = 255 - *cur_row;
                *cur_row++ = 255 - *cur_row;
                *cur_row++ = 255 - *cur_row;
            }
        }
    }
}


int main(int argc, char **argv) {
    Mat image = imread("../images/lena.jpg", IMREAD_GRAYSCALE);

    Vec3b bgr = image.at<cv::Vec3b>(0, 0);
    cout << "BGR values at (0, 0): "
         << "B = " << static_cast<int>(bgr[0]) << ", "
         << "G = " << static_cast<int>(bgr[1]) << ", "
         << "R = " << static_cast<int>(bgr[2]) << endl;

    pixelVisitByPointer(image);

    imshow("Lena", image);
    waitKey(0);
    destroyAllWindows();

    return 0;
}