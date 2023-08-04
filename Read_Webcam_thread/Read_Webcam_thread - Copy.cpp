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

/*#include <NvInfer.h>
#include <memory>
#include <NvOnnxParser.h>
#include <vector>
#include <cuda_runtime_api.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core/cuda.hpp>
#include <opencv2/cudawarping.hpp>
#include <opencv2/core.hpp>
#include <opencv2/cudaarithm.hpp>
#include <algorithm>
#include <numeric>
*/
#define MAX_WEBCAM 2

using namespace std;
using namespace cv;
/*
// mutex mtx;
class LoadWebcam
{
private:
    // pthread_t t1;
    thread t1[MAX_WEBCAM];
    bool isRunning = false;
    int count = 0;
    int whidth;
    int height;
    int id = 0;
    // VideoCapture cap[MAX_WEBCAM];
    vector<Mat> frames;
    vector<VideoCapture> captures;
    mutex mtx;
    // Mat frame = Mat::zeros(480, 640, CV_8UC3);

public:
    // Mat frame = Mat::zeros(480, 640, CV_8UC3);
    LoadWebcam(int whidth, int height)
    {
        this->whidth = whidth;
        this->height = height;
        // for (int i = 0; i < MAX_WEBCAM; i++)
        // {
        frames.assign(MAX_WEBCAM, Mat::zeros(height, whidth, CV_8UC3));
        // }
        cout << "frame size" << frames.size() << endl;
    }
    ~LoadWebcam()
    {
        cout << "Destructor called" << endl;
    }
    void init();
    void run(int id);
    void start();
    void stop();
    void next(vector<Mat> &frames_retrive);
    // void next();
};

void LoadWebcam::init()
{
    for (int i = 0; i < MAX_WEBCAM; i++)
    {
        VideoCapture capture;
        int cam_id = 0;
        if (i == 0)
        {
            cam_id = 0;
        }
        if (i == 1)
        {
            cam_id = 2;
        }
        if (i == 2)
        {
            cam_id = 4;
        }
        capture.open(cam_id);
        captures.push_back(capture);
        captures[i].set(CAP_PROP_FRAME_WIDTH, whidth);
        captures[i].set(CAP_PROP_FRAME_HEIGHT, height);
    }
}

void LoadWebcam::start()
{
    isRunning = true;
    cout << "Start thread" << endl;
    // int rc = pthread_create(&t1, NULL, &LoadWebcam::run, NULL);
    for (int i = 0; i < MAX_WEBCAM; i++)
    {
        cout << "thread started id " << i << endl;
        t1[i] = thread(&LoadWebcam::run, this, i);
    }
    // t1 = thread(&LoadWebcam::run, this);
}

void LoadWebcam::stop()
{
    isRunning = false;
    // pthread_join(t1, NULL);
    cout << "Stop thread" << endl;
    for (int i = 0; i < MAX_WEBCAM; i++)
    {
        t1[i].join();
        captures[i].release();
        cout << "Stop thread " << i << endl;
    }
    captures.clear();
}

void LoadWebcam::run(int id)
{

    while (isRunning)
    {
        Mat frame;
        captures[id] >> frame;
        if (frame.empty())
        {
            cout << "Empty frame" << endl;
            //frame = Mat::zeros(height, whidth, CV_8UC3);
            captures[id].release();
            this_thread::sleep_for(chrono::milliseconds(100));
            int cam_id = 0;
            if (id == 0)
            {
                cam_id = 0;
            }
            if (id == 1)
            {
                cam_id = 2;
            }
            if (id == 2)
            {
                cam_id = 4;
            }
            captures[id].open(cam_id);
            captures[id].set(CAP_PROP_FRAME_WIDTH, whidth);
            captures[id].set(CAP_PROP_FRAME_HEIGHT, height);
            this_thread::sleep_for(chrono::milliseconds(100));

        }
        else
        {
            // mtx.lock();
            frames[id] = frame.clone();
            // mtx.unlock();
        }
        this_thread::sleep_for(chrono::milliseconds(5));
    }
}

void LoadWebcam::next(vector<Mat> &frames_retrive)
{
    // mtx.lock();
    // frames_retrive.clear();
    // lock_guard<mutex> lock(mtx); // Lock the mutex to protect access to the frames vector.
    // frames_retrieve.clear(); 

    // frames_retrive.clear();     // Clear the frames_retrieve vector before adding frames.

    for (int i = 0; i < MAX_WEBCAM; i++)
    {
        // frames_retrive.push_back(frames[i].clone());
        cout << "test"<< endl;
        // cout << frames[i] << endl;
        frames_retrive[i] = frames[i].clone();
        this_thread::sleep_for(chrono::milliseconds(5));
    }
}

*/
int main()
{
    std::cout << "Hello World!\n";
    // LoadWebcam webcam(640, 480);
    // vector<Mat> frames(MAX_WEBCAM);
    // webcam.init();
    // webcam.start();
    // while (true)
    // {
    //     webcam.next(frames);
    //     for (int i = 0; i < MAX_WEBCAM; ++i)
    //     {
    //         // {
    //         imshow("Webcam " + std::to_string(i), frames[i]);
    //         // }
            
    //     }
    //     if (waitKey(100) == 27)
    //         break;
    //     // cout << webcam.next() << endl;
    // }
    // webcam.stop();
    // destroyAllWindows();
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
