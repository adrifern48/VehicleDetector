#pragma once

#include <opencv2/opencv.hpp>

class VehicleDetector {
public:
    virtual void Detect(const std::string& imgPath, cv::Mat& outputImg) = 0;
};