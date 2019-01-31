//
// Created on 31.01.19.
//

#include "../headers/videoStream.h"
#include <opencv2/imgproc.hpp>
#include <opencv/cv.hpp>
#include "cv.h"
#include "highgui.h"
using namespace cv;

int main()
{
    VideoCapture cap(0);
    if (!cap.isOpened())
    {
        printf("camera error");
        getchar();
        exit(-1);
    }

    Mat edges;
    cvNamedWindow("edges",1);
    for(;;)
    {
        Mat frame;
        cap >> frame; // get a new frame from camera
                                                        /*cvtColor(frame, edges, CV_BGR2GRAY);
                                                        GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
                                                        Canny(edges, edges, 0, 30, 3);*/
        imshow("edges", frame);
        if(waitKey(30) >= 0) break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    printf("hello");
    return 0;
};