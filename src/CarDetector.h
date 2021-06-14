#pragma once

#include <opencv2/opencv.hpp>

#include "VehicleDetector.h"

class CarDetector : VehicleDetector {
public:
    // Constructor
    CarDetector(const std::string cascadePath);

    /**
     * Detect car(s) in a static image and draws bounding boxes if any were detected.
     * @param imgPath the path to the image
     * @param outputImg the output image, potentially containing bounding boxes
    */ 
    void Detect(const std::string& imgPath, cv::Mat& outputImg) override;

private:
    /**
     * Resize an image by specifying new height & width 
     * @param img original input image
     * @param newHeight height of resized image
     * @param newWidth width of resized image
     * @return resized image
    */
    cv::Mat ResizeImage(const cv::Mat& img
        , const unsigned int newHeight
        , const unsigned int newWidth);

    /* Path to Haar Cascade Classifier XML file */
    std::string m_cascadePath;
};