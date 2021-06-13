#pragma once

#include <opencv2/opencv.hpp>

#include "VehicleDetector.h"

class CarDetector : VehicleDetector {
public:
    CarDetector(const std::string cascadePath);

    void Detect(const std::string& imgPath, cv::Mat& outputImg);

private:
    cv::Mat ResizeImage(const cv::Mat& img
        , const unsigned int newHeight
        , const unsigned int newWidth);

    std::string m_cascadePath;
};