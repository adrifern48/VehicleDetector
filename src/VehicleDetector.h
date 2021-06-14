#pragma once

#include <opencv2/opencv.hpp>

class VehicleDetector {
public:
    /**
     * Detect vehicle(s) in a static image and draws bounding boxes if any were detected.
     * @param imgPath the path to the image
     * @param outputImg the output image, potentially containing bounding boxes
    */ 
    virtual void Detect(const std::string& imgPath, cv::Mat& outputImg) = 0;
};