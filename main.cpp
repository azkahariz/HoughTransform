#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>

using namespace std;
using namespace cv;
int main()
{
    Mat img, gray, img_blur;
    VideoCapture cap;
    cap.open(1);
    namedWindow("Image",WINDOW_KEEPRATIO);
    for(;;)
    {
        cap >> img;
        // Read the image as gray-scale
        //img = imread("circles.png", IMREAD_COLOR);
        // Convert to gray-scale
        cvtColor(img, gray, CV_BGR2GRAY);
        // Blur the image to reduce noise
        medianBlur(gray, img_blur, 3);
        // Create a vector for detected circles
        vector<Vec3f>  circles;
        // Apply Hough Transform
        HoughCircles(img_blur, circles, HOUGH_GRADIENT, 1, img.rows/8, 200, 50, 200, 270);
        // Draw detected circles
        cout << circles.size() << endl;
        for(size_t i=0; i<circles.size(); i++) {
            Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
            int radius = cvRound(circles[i][2]);
            circle(img, center, radius, Scalar(255, 255, 255), 2, 8, 0);
        }
        imshow("Image",img);
        waitKey(33);
    }

}
