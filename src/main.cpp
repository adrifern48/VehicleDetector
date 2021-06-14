#include <iostream>
#include <memory>
#include <sys/stat.h>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

#include "CarDetector.h"

// Helper function
int validateArgs(const std::string& imgPath, const std::string& cascadePath) {
    int retCode = 0;
    if (imgPath.empty()) {
        std::cout << "Please provide a valid input image path.\n";
        retCode = -1;
    }

    if (cascadePath.empty()) {
        std::cout << "Please provide a valid haar cascade file path.\n";
        retCode = -1;
    }

    struct stat st;
    if (!imgPath.empty() && stat(imgPath.c_str(), &st) != 0) {
        std::cout << "Input image file doesn't exist!\n";
        retCode = -1;
    }

    if (!cascadePath.empty() && stat(cascadePath.c_str(), &st) != 0) {
        std::cout << "Input cascade file doesn't exist!\n";
        retCode = -1;
    }

    return retCode;
}

int main(int argc, const char** argv) {
    cv::CommandLineParser parser(argc, argv, 
                                    "{help h usage ? ||Show help}"
                                    "{img i| <none> | Path to input image.}"
                                    "{cascade c| ../data/cascade_cars.xml | Path to cascade classifier file}");

    parser.about("\nThis program detects vehicles (just cars for now) in static images using OpenCV CascadeClassifiers and Haar-like features.\n");
    if (parser.has("help")) {
        parser.printMessage();
        return 0;
    }

    auto inputImgPath = parser.get<std::string>("i");
    auto cascadePath = parser.get<std::string>("c");
    auto validArgsCode = validateArgs(inputImgPath, cascadePath);

    if (validArgsCode != 0) 
        return validArgsCode;

    cv::Mat outputImg;
    std::unique_ptr<CarDetector> detector = std::make_unique<CarDetector>(cascadePath);
    detector->Detect(inputImgPath, outputImg);

    if (outputImg.data) {
        cv::namedWindow("Vehicle Detection", cv::WINDOW_AUTOSIZE);
        cv::imshow("Vehicle Detection", outputImg);
        cv::waitKey(0);
    } else {
        std::cout << "Error occurred during detection.\n";
        return -1;
    }

    return 0;
}