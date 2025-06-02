#pragma once
#include"head.h"

using namespace cv;				//opencvµÄÃüÃû¿Õ¼ä

class Camera /*:public Base_Show*/ {
	vector<string> existence;
public:
	Camera();
	void take_picture();
	void show_picture();
};
