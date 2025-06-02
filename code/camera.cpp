#include"camera.h"

Camera::Camera() {
	//在构造函数中读取已有的所有图片的名字
	std::string search_path = PIC_FILE_NAME;
	search_path += "\\*";
	WIN32_FIND_DATA find_file_data;
	HANDLE hFind = FindFirstFile(search_path.c_str(), &find_file_data);

	if (hFind == INVALID_HANDLE_VALUE) {
		std::cerr << "无法打开目录: " << PIC_FILE_NAME << std::endl;
		return;
	}

	do {
		std::string file_name = find_file_data.cFileName;

		// 忽略 . 和 ..
		if (file_name == "." || file_name == "..") {
			continue;
		}
		//读入图片的文件名
		string exstension = file_name.substr(file_name.size() - 4);
		if (exstension == ".jpg" || exstension == ".png" || exstension == ".bmp") existence.push_back(file_name);
	} while (FindNextFile(hFind, &find_file_data) != 0);
	FindClose(hFind);

}


void Camera::take_picture() {
	cout << "空格拍照，esc退出" << endl;
	system("pause");
	VideoCapture cap(0);
	Mat img;
	string pic_path = PIC_FILE_NAME;
	pic_path += '\\';
	while (true) {
		cap >> img;
		if (img.empty()) {
			cout << "都无法打开摄像头" << endl;
			break;
		}
		imshow("img", img);
		if (waitKey(1) == ' ') {									//0将无限期的等待用户输入
			//获取时间，用于命名文件
			//pic_path += time(0);									//time(0)返回从19700101到现在已经过的秒数
			string t = to_string(time(0));
			imwrite(pic_path + t + ".jpg", img);
			destroyWindow("img");
			imshow("已拍", img);
			existence.push_back(t + ".jpg");
			waitKey(0);
			break;
		}
		else if (waitKey(1) == 27) break;
	}

	cap.release();
	cv::destroyAllWindows();
}
void Camera::show_picture() {
	cout << "将展示所有的图片,按esc键退出" << endl;
	cout << "wasd键来控制" << endl;
	system("pause");
	int existence_size = existence.size();
	for (int i = 0; i < existence_size; ) {
		string directory_name = PIC_FILE_NAME;
		string window_name = to_string(i + 1);
		imshow(window_name + '/' + to_string(existence_size), imread(directory_name + '\\' + existence[i]));
		//根据按键实现图片轮播
		if ((waitKey(0) == 'a' || waitKey(0) == 'w') && i > 0) i -= 1;
		else if ((waitKey(0) == 's' || waitKey(0) == 'd') /*&& i < (existence_size - 1)*/) i += 1;
		else if (waitKey(0) == 27) {				//esc键
			destroyAllWindows();
			break;
		}
		destroyAllWindows();
	}
	cout << "播放结束" << endl;
	system("pause");
}