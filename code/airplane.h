#pragma once
#include"head.h"

//飞行模式
// 下无法拨号
// 无法打开浏览器

class Airplane_Mode: public Base_Show {
public:
	void show_type_01() {}
	void show_type_02() {}
	void show_type_03() {}
	Airplane_Mode() {
		ifstream ifs;
		ifs.open(RS_FILE_NAME);
		string line;
		bool is = 0;
 		while (getline(ifs, line)) {
			if (line.substr(0, 11) == AIRPLANE_MODE) {				//substr的后一个参数是字符个数，不包括'\0'
				Id::set_is_airplane_mode(stoi(line.substr(12)));
				is = 1;
				is_airplane_str = AIRPLANE_MODE;
				is_airplane_str += ' ';
				is_airplane_str += to_string(Id::get_is_airplane_mode());
				return;
			}
		}
		if (!is) {
			cout << "没有飞行模式数据，赋默认值0" << endl;
			Id::set_is_airplane_mode(0);
			is_airplane_str = AIRPLANE_MODE;
			is_airplane_str += ' ';
			is_airplane_str += to_string(Id::get_is_airplane_mode());//需要转为string再接上去
			system("pause");
			return;
		}
	}
	void setting_airplane_mode();
	//void write_str();
	~Airplane_Mode() {
		str_00 = guess_number_str;
		str_00 += '\n';
		str_00 += is_airplane_str;
		str_00 += '\n';
		str_00 += show_style_id_str;
		write(str_00);
	}
};
