# learn_opencv_cpp
> 参考自 [OpenCV4 C++ 快速入门视频30讲 - 系列合集](https://www.bilibili.com/video/BV1i54y1m7tw/)

## 01 图像读取与显示
```cpp
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
```

## 02 图像色彩空间转换
```cpp
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
```

## 03 图像对象的创建与赋值
```cpp
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
```

## 04 图像像素的读写操作
```cpp
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
```

## 04 图像像素的算术操作
```cpp
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
```


