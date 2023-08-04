// Read_Webcam_thread.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
#include <opencv2/opencv.hpp>
#include "ini_reader.h"
#include "config_reader.h"
#include "camloader.h"

using namespace std;
using namespace cv;

int main()
{
    std::cout << "Hello World!\n";
    int cam_num = configparameter.cam_num_;
    configparameter.print_cam_info();
    cout << "cam_num: " << cam_num << endl;
    int width = configparameter.width_;
    int height = configparameter.height_;
    LoadWebcam webcam(width, height, cam_num);
    vector<Mat> frames(cam_num);
    webcam.init();
    webcam.start();
    while (true)
    {
        webcam.next(frames);
        for (int i = 0; i < cam_num; ++i)
        {
            imshow("Webcam " + std::to_string(i), frames[i]);
        }
        if (waitKey(100) == 27)
            break;
    }
    webcam.stop();
    destroyAllWindows();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
