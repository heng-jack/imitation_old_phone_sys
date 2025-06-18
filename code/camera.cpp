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
	cout << "退格键删除照片" << endl;
	system("pause");
	int existence_size = existence.size();
	int realnum = existence_size;
	int last_i = 0;
	for (int i = 0; i < existence_size; ) {
		//已删除就不再播放
		bool is_del = false;
		for (int j = 0; j < del.size(); j++) {
			if (i == del[j]) is_del = true;
		}
		if (is_del) {
			if (i < last_i) i -= 1;
			else i += 1;
			continue;
		}
		last_i = i;
		string directory_name = PIC_FILE_NAME;
		string window_name = to_string(i + 1);
		imshow("index:" + window_name + '/' + "real num:" + to_string(realnum), imread(directory_name + '\\' + existence[i]));
		//根据按键实现图片轮播
		int chr = waitKey(0);
		if ((chr == 'a' || chr == 'w') && i > 0) i -= 1;
		else if ((chr == 's' || chr == 'd') /*&& i < (existence_size - 1)*/) i += 1;
		else if (chr == 27) {				//esc键
			destroyAllWindows();
			break;
		}
		//删除图片功能
		//记录在existencez中的索引与del数组中，在此函数结束运行时实现删除
		else if (chr == 8) {//退格键
			del.push_back(i);
			realnum--;
			i += 1;
		}
		destroyAllWindows();
		
	}
	cout << "播放结束" << endl;
	system("pause");

	//实现删除
	bool is_suc_del = 0;//记录是否成功删除，成功就清空del
	for (int i = 0; i < del.size(); i++) {
		string directory_name = PIC_FILE_NAME;
		// 调用 Windows API 删除文件
		if (DeleteFileA((directory_name + "\\" + existence[del[i]]).c_str())/*c API 需要用c风格字符数组*/) {
			//std::cout << "文件删除成功：" << directory_name + "\\" + existence[del[i]] << std::endl;
			//同时在两数组中分别删除
			is_suc_del = true;
			for (int j = del[i] + 1; j < existence.size(); j++) {
				existence[j - 1] = existence[j];
			}
			existence.pop_back();
		}
		else {
			DWORD error = GetLastError();
			std::cout << "文件删除失败，错误码：" << error << std::endl;

			switch (error) {
			case ERROR_FILE_NOT_FOUND:
				std::cout << "错误原因：文件不存在。" << std::endl;
				break;
			case ERROR_ACCESS_DENIED:
				std::cout << "错误原因：权限不足或文件被占用。" << std::endl;
				break;
			default:
				std::cout << "其他错误。" << std::endl;
				break;
			}
			system("pause");
		}
	}
	if (is_suc_del) del.clear();
}