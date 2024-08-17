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



