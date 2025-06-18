#include"color.h"

void Console_Color::setting_console_color_id() {
	cout << "0 = 黑色       8 = 灰色\n";
	cout << "1 = 蓝色       9 = 淡蓝色\n";
	cout << "2 = 绿色       10= 淡绿色\n";
	cout << "3 = 浅绿色     11= 淡浅绿色\n";
	cout << "4 = 红色       12= 淡红色\n";
	cout << "5 = 紫色       13= 淡紫色\n";
	cout << "6 = 黄色       14= 淡黄色\n";
	cout << "7 = 白色       15= 亮白色\n";
/*0 = 黑色       8 = 灰色
  1 = 蓝色       9 = 淡蓝色
  2 = 绿色       A = 淡绿色
  3 = 浅绿色     B = 淡浅绿色
  4 = 红色       C = 淡红色
  5 = 紫色       D = 淡紫色
  6 = 黄色       E = 淡黄色
  7 = 白色       F = 亮白色*/
	int bid = 0;
	int tid = 7;
	cout << "请输入背景颜色代号:\t";
	cin >> bid;
	cout << "请输入字体颜色代号:\t";
	cin >> tid;
	//如果背景颜色和字体颜色是相同的将无法正常阅读，给出错误提示，并结束
	if (bid == tid) {
		cout << "背景颜色和字体颜色一致，将自动注销本次更改…………" << endl;
		system("pause");
		return;
	}
	//判断颜色序号是否在选择范围内
	else if (bid < 0 || bid > 0xF || tid < 0 || tid > 0xF) {
		cout << "背景颜色或字体颜色不在范围内，将自动注销本次更改…………" << endl;
		system("pause");
		return;
	}
	//给出是否确认修改的提示

	cout << "是否确定一下更改\n";
	cout << "背景颜色:\t";
	switch (bid) {
	case 0:
		cout << "黑色\n";
		break;
	case 1:
		cout << "蓝色\n";
		break;
	case 2:
		cout << "绿色\n";
		break;
	case 3:
		cout << "浅绿色\n";
		break;
	case 4:
		cout << "红色\n";
		break;
	case 5:
		cout << "紫色\n";
		break;
	case 6:
		cout << "黄色\n";
		break;
	case 7:
		cout << "白色\n";
		break;
	case 8:
		cout << "灰色\n";
		break;
	case 9:
		cout << "淡蓝色\n";
		break;
	case 0xA:
		cout << "淡绿色\n";
		break;
	case 0xB:
		cout << "淡浅绿色\n";
		break;
	case 0xC:
		cout << "淡红色\n";
		break;
	case 0xD:
		cout << "淡紫色\n";
		break;
	case 0xE:
		cout << "淡黄色\n";
		break;
	case 0xF:
		cout << "亮白色\n";
		break;
	default:
		break;
	}
	cout << "字体颜色:\t";
	switch (tid) {
	case 0:
		cout << "黑色\n";
		break;
	case 1:
		cout << "蓝色\n";
		break;
	case 2:
		cout << "绿色\n";
		break;
	case 3:
		cout << "浅绿色\n";
		break;
	case 4:
		cout << "红色\n";
		break;
	case 5:
		cout << "紫色\n";
		break;
	case 6:
		cout << "黄色\n";
		break;
	case 7:
		cout << "白色\n";
		break;
	case 8:
		cout << "灰色\n";
		break;
	case 9:
		cout << "淡蓝色\n";
		break;
	case 0xA:
		cout << "淡绿色\n";
		break;
	case 0xB:
		cout << "淡浅绿色\n";
		break;
	case 0xC:
		cout << "淡红色\n";
		break;
	case 0xD:
		cout << "淡紫色\n";
		break;
	case 0xE:
		cout << "淡黄色\n";
		break;
	case 0xF:
		cout << "亮白色\n";
		break;
	default:
		break;
	}
	cout << "1 = 是		0 = 否\n";
	int temp = 1;
	cin >> temp;
	if (temp == 1) {
		Id::set_background_color_id(bid);
		Id::set_text_color_id(tid);
	}
	else if (temp == 0) return;
	else {
		cout << "输入错误，将自动注销更改…………" << endl;
		return;
	}

}