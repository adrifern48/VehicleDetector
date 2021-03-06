# CPPND: Capstone - Vehicle Detector Using OpenCV

The template for this repo came from the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213).

## Purpose
This project leverages OpenCV Cascade Classifiers & Haar-like features to detect vehicles (just cars for now) in static images and draw a bounding box over the detected object(s). 

## Details
The *VehicleDetector* class serves as a base class for derived classes (such as *CarDetector*) that implement the functionality to detect various types of vehicles given a pre-trained Haar cascade and input image. The *main()* method in `main.cpp` validates the input arguments, instantiates a *CarDetector* and leverages OpenCV's *imshow()* method to display the output image generated by the CarDetector's *Detect()* method. The output image is a resized version of the original input image with the addition of bounding boxes drawn over the cars that were detected by the Haar cascade classifier.

For this project, a custom-trained Haar cascade classifier was used. The training dataset consisted of a subset of images taken from the [Vehicle Database provided by Grupo de Tratamiento de Imágenes](https://www.gti.ssr.upm.es/data/Vehicle_database.html). This set comprised of both 100 positive and 100 negative classification images, each 64x64 pixels in size. Training the Haar cascade classifier took approximately 6 hours of time.

The custom-trained classifier works best when the input image are oriented toward the rear of the car(s) because those were the types of images that the cascade classifier was trained on.

## Results
### Single Car in Image
![Single Car](/data/output/car_single_detect.jpg)

### Multiple Cars (with oncoming)
![Multiple Cars](/data/output/cars_multi_detect.jpg)<br />
In this output image, we can observe a false positive classification denoted by the bounding box drawn toward the center of the image.

### Multiple Cars
![Multiple Cars #2](/data/output/cars_multi_2_detect.jpg)

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* OpenCV >= 2.0
  * Linux: [Installation](https://docs.opencv.org/3.4/d7/d9f/tutorial_linux_install.html)
  * Mac: [Installation](https://docs.opencv.org/3.4/d0/db2/tutorial_macos_install.html)
  * Windows: [Installation](https://docs.opencv.org/3.4/d3/d52/tutorial_windows_install.html)

## Build/Run Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./VehicleDetector -i=<path_to_input_image> [-c=<path_to_cascade_xml_file>]`. <br /> **Note:** The default cascade classifier to be used is currently set to `data/cascade_cars.xml`.

## Rubric Targets
### Loops, Functions, I/O
1. The project demonstrates an understanding of C++ functions and control structures.
	- Selection statements, such as *if/if-else* are used throughout `main.cpp` and in the *CarDetector::Detect()* method (`CarDetector.cpp` L.12)
	- A *for* loop is used to iterate over the detected cars in the *CarDetector::Detect()* and draw the bounding boxes (`CarDetector.cpp` L.34)
	- Functions have their inputs/outputs clearly defined and are implemented in `main.cpp` and `CarDetector.cpp`
2. The project reads data from a file and process the data, or the program writes data to a file.
	- This program reads from 2 files: one being the input image, and the other being the Haar cascade classifier XML file.
		- The input image is read on L.11 of `CarDetector.cpp`
		- The Haar cascade file is loaded on L.21 of `CarDetector.cpp`
3. The project accepts user input and processes the input.
	- The path to the input image is a required command line argument (`main.cpp` L.48).
	- The path to the Haar cascade is an optional command line argument (`main.cpp` L.49).
	- After the program displays the output image, it waits for the user to press a key before exiting (`main.cpp` L.62).
### Object Oriented Programming
4. The project uses Object Oriented Programming techniques.
	- The *CarDetector*'s sole purpose is to detect cars in an input image, so that functionality was encapsulated into a class.
5. Classes use appropriate access specifiers for class members.
	- The *VehicleDetector* class only has one public method, and that is the *Detect()* method that all derived classes must override (`VehicleDetector.h` L.12).
	- The *CarDetector* class has both public and private functions/members.
6. Class constructors utilize member initialization lists.
	- The *CarDetector* constructor uses an initialization list to set the path to the Haar cacade (`CarDetector.cpp` L.7)
7. Classes abstract implementation details from their interfaces.
	- The *CarDetector::Detect()* method takes an image path string and produces an output image containing a resized version of the input with bounding boxes drawn on the detected objects. Member function documentation is available (`CarDetector.h` L.17)
8. Classes follow an appropriate inheritance hierarchy.
	- *VehicleDetector* is the base class for all derived classes responsible for detecting various vehicle types in a static image. *CarDetector* inherits from *VehicleDetector*.
	- *VehicleDetector* is an abstract class composed of a pure virtual *Detect()* function (`VehicleDetector.h` L.12)
	- Override functions are specified (`CarDetector.h` L.17)
9. Derived class functions override virtual base class functions.
	- One member function (*CarDetector::Detect()*) in an inherited class overrides a virtual base class member function (*VehicleDetector::Detect()*) - this is achieved on L.10 of `CarDetector.cpp`. 
10. The project makes use of references in function declarations. 
	- The following functions contain pass-by-reference arguments:
		- *VehicleDetector::Detect()* - `VehicleDetector.h` L.12
		- *CarDetector::Detect()* - `CarDetector.h` L.17
		- *CarDetector::ResizeImage()* - `CarDetector.h` L.27
		- *validateArgs()* - `main.cpp` L.10
11. The project uses move semantics to move data, instead of copying it, where possible.
	- Using move sematics in *CarDetector::Detect()* in order to reuse memory from resized image as the preliminary output image, right before the bounding boxes are drawn (`CarDetector.cpp` L.33)
### Memory Management
12. The project uses smart pointers instead of raw pointers.
	- Using a *unique_ptr* to a *CarDetector* object (`main.cpp` L.56)

## Lessons Learned/Future Enhancements
- The `data/cascade_cars.xml` Haar cascade classifier yields decent results given how relatively small the training dataset was. Haar cascades are known for their high false positive rates, however this one seems to work pretty well with input images containing one to a few cars.
- Training the Haar cascade classifier is a time-consuming activity. With more time, one can replicate the training process with different sets of images and input parameters in order to strengthen the cascade's classification ability.
- This project can be further extended to include the ability to detect other types of vehicles, such as motorcycles, buses, semi-trucks, etc.
- This project could be extended to handle video input, either from a real-time webcam feed or a video encoded file. 