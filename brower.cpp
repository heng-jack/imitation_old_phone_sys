#include"brower.h"


void Brower::open_default_brower() {
	//先读取飞行模式是否开启
	if (Id::get_is_airplane_mode()) {
		cout << "飞行模式已开，无法打开浏览器\n" << "............" << endl;
		system("pause");
		return;
	}
	string url;
	cout << "网址：" << endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清理缓冲区，避免输入url时因为缓冲区有'\n'而直接跳过 
	getline(cin,url);
	string cmd = "start http://";
	cmd += url;
	system(cmd.c_str());						//string转为const char*
	system("pause");
}