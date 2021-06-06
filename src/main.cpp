#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "usage: ./VehicleDetector <path/to/image>\n";
        return -1;
    }

    cv::Mat img;
    img = cv::imread(argv[1], 1);

    if (!img.data) {
        std::cout << "Invalid image data!\n";
        return -1;
    }

    cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE);
    cv::imshow("Display Image", img);

    cv::waitKey(0);

    return 0;
}