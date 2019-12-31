#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>



// Read the image as gray-scale
img = imread("circles.png", IMREAD_COLOR);
// Convert to gray-scale
gray = cvtColor(img, COLOR_BGR2GRAY);
// Blur the image to reduce noise
Mat img_blur;
medianBlur(gray, img_blur, 5);
// Create a vector for detected circles
vector<Vec3f>  circles;
// Apply Hough Transform
HoughCircles(img_blur, circles, HOUGH_GRADIENT, 1, img.rows/64, 200, 10, 5, 30);
// Draw detected circles
for(size_t i=0; i<circles.size(); i++) {
    Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
    int radius = cvRound(circles[i][2]);
    circle(img, center, radius, Scalar(255, 255, 255), 2, 8, 0);
}
