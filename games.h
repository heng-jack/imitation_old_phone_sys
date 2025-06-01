#pragma once
#include"head.h"

class Games : public Base_Show {
	int guess_number_points;			//猜数字游戏积分，存储在games.heng文件中，此文件在开始运行是判断存在，如果不在则创建
public:
	Games() {
		ifstream ifs;
		ifs.open(RS_FILE_NAME);
		string line;
		bool is = 0;
		while (getline(ifs, line)) {
			if (line.substr(0, 19) == GAME_01_PONIT) {
				guess_number_points = stoi(line.substr(20));
				is = 1;
				guess_number_str = GAME_01_PONIT;
				guess_number_str += " ";
				guess_number_str += to_string(guess_number_points);
				return;
			}
		}
		if (!is) {
			cout << "没有猜数游戏积分数据，赋默认值0" << endl;
			guess_number_points = 0;
			guess_number_str = GAME_01_PONIT;
			guess_number_str += " ";
			guess_number_str += to_string(guess_number_points);
			system("paulse");
			return;
		}
	}
	void show_type_01();
	void show_type_02();
	void show_type_03();
	void guess_number();			//在析构函数中调用，实现games.heng的更新重写
	~Games() { 
		str_00 = guess_number_str;
		str_00 += '\n';
		str_00 += is_airplane_str;
		str_00 += '\n';
		str_00 += show_style_id_str;
		write(str_00); 
	}
};
