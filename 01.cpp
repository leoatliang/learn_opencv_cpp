#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    cv::Mat image = cv::imread("../images/lena.jpg", cv::IMREAD_GRAYSCALE);

    if (image.empty()) {
        cout << "Error: No images" << endl;
        return -1;
    }

    cv::Size imgSize = image.size();
    cout << "Image size: " << image.channels() << " * " << imgSize.width << " * " << imgSize.height << endl;

    cv::namedWindow("Lena", cv::WINDOW_FREERATIO);
    cv::imshow("Lena", image);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}