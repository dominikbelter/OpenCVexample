/** @file main.cpp
 *
 * This example shows how to use openCV library
 *
 * @author Dominik Belter
 */
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <memory>

using namespace std;

int main()
{
    try {
        cv::Mat image;
        image = cv::imread("../../resources/messor2.jpg", CV_LOAD_IMAGE_COLOR);
        imshow("image", image);

        cv::GaussianBlur( image, image, cv::Size( 21, 21 ), 5, 5 );
        cv::namedWindow( "Gaussian Blur", cv::WINDOW_AUTOSIZE );// Create a window for display.
        cv::imshow( "Gaussian Blur", image );

        cv::Mat gray;
        /// Convert the image to grayscale
        cv::cvtColor( image, gray, CV_BGR2GRAY );

        cv::namedWindow( "Gray", cv::WINDOW_AUTOSIZE );// Create a window for display.
        cv::imshow( "Gray", gray );

        cv::Mat detectedEdges;

        int lowThreshold=10;
        int ratio = 3;
        int kernel_size = 3;

        cv::Canny( gray, detectedEdges, lowThreshold, lowThreshold*ratio, kernel_size );
        cv::namedWindow( "edges", cv::WINDOW_AUTOSIZE );// Create a window for display.
        cv::imshow( "edges", detectedEdges );                   // Show our image inside it.

        cv::waitKey(0);
    }
	catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
		return 1;
	}

	return 0;
}
