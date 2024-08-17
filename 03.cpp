#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

void matCreate() {
    cv::Mat mat_1 = cv::Mat::ones(cv::Size(32, 32), CV_8UC3); // cv::Mat::zeros
    cout << mat_1 << endl;
    cout << mat_1.channels() << " * " << mat_1.cols << " * " << mat_1.rows << endl;

    cv::Mat mat_2 = mat_1;
    mat_2 = cv::Scalar(0, 0, 255);  // 赋值 ==> 对 mat_2 的修改就是对 mat_1 的修改

    cv::namedWindow("mat_2", cv::WINDOW_FREERATIO);
    cv::imshow("mat_2", mat_2);

    // 可使用 (1) mat_2 = mat_1.clone();   (2) mat_1.copyTo(mat_2);
}

int main(int argc, char **argv) {
    matCreate();

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}