//Entity.cpp
#include "Entity.h"
#include "opencv2/ximgproc/segmentation.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <ctime>

using namespace cv;
using namespace cv::ximgproc::segmentation;

namespace CoreXimgprocSeg
{
	Entity::Entity()
	{
		//std::cout << "Created the Entity object!" << std::endl;
	}

	std::vector<CoreXimgprocSeg::RectCLR> Entity::Move(const char* fileName, const char* strategyType)
	{
		//std::cout << std::endl << "Start.." << std::endl;		

		Mat img = imread(fileName);

		Ptr<SelectiveSearchSegmentation> gs = createSelectiveSearchSegmentation();
		gs->setBaseImage(img);

		if (strategyType[0] == 's') {
			gs->switchToSingleStrategy();
		}		
		else if (strategyType[0] == 'q') {
			gs->switchToSelectiveSearchQuality();
		}
		else {
			gs->switchToSelectiveSearchFast();
		}

		std::vector<cv::Rect> rects;
		gs->process(rects);

		std::vector<CoreXimgprocSeg::RectCLR> rectsCLR;
		//rectsCLR.reserve(rects.size());

		
		for (std::vector<cv::Rect>::iterator it = rects.begin(); it != rects.end(); ++it) {
					
			rectsCLR.push_back(RectCLR((*it).x, (*it).y, (*it).width, (*it).height));
		}	
		

		/*int nb_rects = 10;

		std::cout << std::endl <<
			"Use a to display less rects, d to display more rects, q to quit" << std::endl;

		char c = (char)waitKey();

		while (c != 'q') {

			Mat wimg = img.clone();

			int i = 0;

			for (std::vector<Rect>::iterator it = rects.begin(); it != rects.end(); ++it) {
				if (i++ < nb_rects) {
					rectangle(wimg, *it, Scalar(0, 0, 255));
				}
			}

			imshow("Output", wimg);
			c = (char)waitKey();

			if (c == 'd') {
				nb_rects += 10;
			}

			if (c == 'a' && nb_rects > 10) {
				nb_rects -= 10;
			}
		}*/

		return rectsCLR;
	}
}