#pragma once
#include"head.h"

using namespace cv;				//opencv的命名空间

class Camera /*:public Base_Show*/ {
	vector<string> existence;
	vector<int> del;
public:
	Camera();
	void take_picture();
	void show_picture();
	//在析构函数中删除时，如果用户在不退出系统的情况下可在此浏览已删除的照片
	//~Camera() {
	//	for (int i = 0; i < del.size(); i++) {
 //           string directory_name = PIC_FILE_NAME;
 //           // 调用 Windows API 删除文件
 //           if (DeleteFileA((directory_name + "\\" + existence[del[i]]).c_str())/*c API 需要用c风格字符数组*/) {
 //               //std::cout << "文件删除成功：" << directory_name + "\\" + existence[del[i]] << std::endl;
 //           }
 //           else {
 //               DWORD error = GetLastError();
 //               std::cout << "文件删除失败，错误码：" << error << std::endl;

 //               switch (error) {
 //               case ERROR_FILE_NOT_FOUND:
 //                   std::cout << "错误原因：文件不存在。" << std::endl;
 //                   break;
 //               case ERROR_ACCESS_DENIED:
 //                   std::cout << "错误原因：权限不足或文件被占用。" << std::endl;
 //                   break;
 //               default:
 //                   std::cout << "其他错误。" << std::endl;
 //                   break;
 //               }
 //               system("pause");
 //           }
	//	}
 //       //system("pause");
	//}
};
