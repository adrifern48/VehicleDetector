#include <iostream>
#include <fstream>
#include <vector>

#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>

// TODO: 
// 1. train custom cascade classifier model

int main(int argc, const char** argv) {

    cv::CommandLineParser parser(argc, argv, 
                                    "{help ||Show help}"
                                    "{@input_image |<none> | Path to input image.}");

    parser.about("\nThis program detects vehicles in static images using cv::CascadeClassifiers and Haar-like features");
    if (parser.has("help")) {
        parser.printMessage();
        return 0;
    }

    std::ifstream file;
    auto inputImage = parser.get<cv::String>(0);
    // std::cout << "input_image: " << input_image << "\n";

    if (inputImage.empty()) {
        std::cout << "Please provide a a valid input image path.\n";
        return -1;
    }

    file.open(inputImage);
    if (!file) {
        std::cout << "Input image file doesn't exist! Exiting...\n";
        return -1;
    }
    file.close();

    cv::Mat img = cv::imread(inputImage, 1);

    if (!img.data) {
        std::cout << "Invalid image data!\n";
        return -1;
    }

    // use this to initialize model once you have a trained model
    // cv::CascadeClassifier vehicleCascade;
    // vehicleCascade.load("");

    // convert input image to grayscale
    cv::Mat grayscale;
    cv::cvtColor(img, grayscale, cv::COLOR_BGR2GRAY);

    // vehicle detection
    // std::vector<cv::Rect> vehicles;
    // vehicleCascade.detectMultiScale(grayscale, vehicles, 1.1, 3, 0, cv::Size(30, 30));

    // draw bounding box in original image
    // may have to introduce scaling to optimize performance
    // for (auto& area : vehicles) {
    //     cv::Scalar boxColor = cv::Scalar(255, 0, 0);
    //     cv::rectangle(img, cv::Point(area.x, area.y), cv::Point(area.x + area.width, area.y + area.height), boxColor);
    // }

    cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE);
    cv::imshow("Display Image", img);

    cv::waitKey(0);

    return 0;
}