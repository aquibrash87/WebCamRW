#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/utility.hpp>

#include <stdio.h>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <fstream>

using namespace std;
using namespace cv;

static void help()
{
	cout
		<< "------------------------------------------------------------------------------" << endl
		<< "This program shows how to write video files." << endl
		<< "You can extract the R or G or B color channel of the input video." << endl
		<< "Usage:" << endl
		<< "./video-write inputvideoName [ R | G | B] [Y | N]" << endl
		<< "------------------------------------------------------------------------------" << endl
		<< endl;
}
int main(int argc, char** argv)
{
	Mat image, src_gray;
	VideoCapture cap;	// For Video Input

	bool WebCamFlag = true;	// Choosing video from Camera or files

	std::vector<KeyPoint> keypoints;

	/// Global Variables
	int DELAY_CAPTION = 1500;
	int DELAY_BLUR = 100;
	int MAX_KERNEL_LENGTH = 9;//31;
	Mat dst;



	//-- ORB Parameters
	int OrbFeatures = 300;
	float OrbScaleFac = 1.2;//1.2;
	int OrbLevels = 8;//8;
	int OrbEdgeThresh = 10;
	int OrbPatchSize = 10;

	Mat showkeypoints;//  Image with detected features


	if (WebCamFlag)

		cap.open(3);	// Accesses webcamera 

	else
		cap.open("scaleRotation.avi");//backSide //scaleRotation //illuminationVariation
									  // Utilizes video file in the same folder as source code, 
	/*if (!cap.isOpened())  // if not success, exit program
	{
		cout << "Cannot open the video file" << endl;

		return -1;
	}6644

	// writing Video file

	const string NAME = "Output.avi";
	int ex = -1;      // Get Codec Type- Int form
	

	
	// Transform from int to char via Bitwise operators
	char EXT[] = { (char)(ex & 0XFF), (char)((ex & 0XFF00) >> 8), (char)((ex & 0XFF0000) >> 16), (char)((ex & 0XFF000000) >> 24), 0 };

	Size S = Size((int)cap.get(CV_CAP_PROP_FRAME_WIDTH),    // Acquire input size
		(int)cap.get(CV_CAP_PROP_FRAME_HEIGHT));
	VideoWriter outputVideo;							 // Open the output
	outputVideo.open(NAME, ex, 12, S, true);  //cap.get(CV_CAP_PROP_FPS)

	if (!outputVideo.isOpened())
	{
		cout << "Could not open the output video for write: " << endl;
		return -1;
	}


*/

	double fps = cap.get(CV_CAP_PROP_FPS); //get the frames per seconds of the video

	cout << "Frame per seconds : " << fps << endl;

	//FeatureDetector* detector = NULL;
	// Choose between the detector by commenting out the other
	
		//detector = new ORB(OrbFeatures, OrbScaleFac, OrbLevels, OrbEdgeThresh, 0, 2, ORB::HARRIS_SCORE, OrbPatchSize);

	


	while (1) {


		cap >> image;
		//dst = image.clone();
		/*
		for (int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2)
		{
		GaussianBlur(image, dst, Size(i, i), 1.6, 1.6);
		}
		*/
		//detector->detect(image, keypoints);// features detected and saved in keypoints vector

										   //myBlobDetector.detect(dst, myBlobs); // detecting blobs

		//cv::drawKeypoints(image, keypoints, showkeypoints);// draws keypoints on image and stores result in matric showkeypoints

														   //cv::drawKeypoints(image, myBlobs, showkeypoints);// draws keypoints on image and stores result in matric showkeypoints

		imshow("Visualizer", image);


		
		//outputVideo << image;
				if (waitKey(30) == 27) //wait for 'esc' key press for 30 ms. If 'esc' key is pressed, break loop
				{
					break;
					return 0;
				}


				}

	
}
