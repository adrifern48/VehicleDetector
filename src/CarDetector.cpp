#include <iostream>

#include <opencv2/objdetect.hpp>

#include "CarDetector.h"

CarDetector::CarDetector(const std::string cascadePath) 
    : m_cascadePath(cascadePath) { }

void CarDetector::Detect(const std::string& imgPath, cv::Mat& outputImg) {
    cv::Mat img = cv::imread(imgPath, 1);
    if (!img.data) {
        std::cout << "Invalid image data! Exiting...\n";
        return;
    }

    auto resized = ResizeImage(img, 200, 200);

    // Load Haar Cascade
    cv::CascadeClassifier carCascade;
    carCascade.load(m_cascadePath);

    // Convert resized input image to grayscale
    cv::Mat grayscale;
    cv::cvtColor(resized, grayscale, cv::COLOR_BGR2GRAY);

    // Car detection
    std::vector<cv::Rect> detectedCars;
    carCascade.detectMultiScale(grayscale, detectedCars, 1.1, 3, 0, cv::Size(30, 30));

    // draw bounding box on original resized image
    // may have to introduce scaling in the future to optimize performance
    outputImg = std::move(resized);
    for (auto& area : detectedCars) {
        cv::Scalar boxColor = cv::Scalar(200, 255, 0);
        cv::rectangle(outputImg, cv::Point(area.x, area.y), cv::Point(area.x + area.width, area.y + area.height), boxColor);
    }
}

cv::Mat CarDetector::ResizeImage(const cv::Mat& img
    , const unsigned int newHeight
    , const unsigned int newWidth) {
    cv::Size size(newHeight, newWidth);
    cv::Mat resizedImg;
    cv::resize(img, resizedImg, size);
    return resizedImg;
}