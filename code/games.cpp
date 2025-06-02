#include"games.h"

void Games::show_type_01() {
	cout << "#############################################" << endl;
	cout << "                   游戏                      " << endl;
	cout << "#############################################" << endl;
	cout << "##############   00--返回     ###############" << endl;
	cout << "##############   01--猜数字   ###############" << endl;
	cout << "#############################################" << endl;
	cout << "#############################################" << endl;
	cout << "请键入:" << endl;
}
void Games::show_type_02() {
	cout << "*********************************************" << endl;
	cout << "                   游戏                      " << endl;
	cout << "*********************************************" << endl;
	cout << "**************   00--返回     ***************" << endl;
	cout << "**************   01--猜数字   ***************" << endl;
	cout << "*********************************************" << endl;
	cout << "*********************************************" << endl;
	cout << "请键入:" << endl;
}
void Games::show_type_03() {
	cout << "/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/" << endl;
	cout << "                   游戏                      " << endl;
	cout << "/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/" << endl;
	cout << "/-/-/-/-/-/-/-   00--返回     /-/-/-/-/-/-/-/" << endl;
	cout << "/-/-/-/-/-/-/-   01--猜数字   /-/-/-/-/-/-/-/" << endl;
	cout << "/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/" << endl;
	cout << "/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/" << endl;
	cout << "请键入:" << endl;
}
void Games::guess_number() {
	srand((unsigned int)time(NULL));
	while (true) {
		cout << "积分:\t" << guess_number_points << endl;
		int rand_num = rand() % 100;
		int guess = -1;
		int add_points = 0;
		bool is_success = false;		//记录猜测的状态
		for (int i = 0; i < 5; i++) {
			cout << "您有5次机会，数的范围是0~99" << endl;
			cout << "您的第" << i + 1 << "次猜测是：" << endl;
			cin >> guess;
			if (guess == rand_num) {
				is_success = true;
				add_points = 5 - i;
				cout << "恭喜您猜对了" << endl;
				cout << "奖励" << add_points << "分" << endl;
				guess_number_points += add_points;
				break;					//猜对了就跳出来
			}
			else if(guess > rand_num){
				cout << "有点点猜大了哟 \n >_< \n加油鸭\n@..@\n" << endl;
				//system("pause");
			}
			else if(guess < rand_num){
				cout << "有点点猜小了哟 \n >_< \n加油鸭\n@..@\n" << endl;
				//system("pause");
			}
		}
		if (!is_success) {
			system("cls");
			cout << "机会已用完，但不要气馁，下次就会成功的\n" << endl;
		}
		cout << "________________________________" << endl;
		cout << "积分:\t" << guess_number_points << endl;
		cout << "________________________________" << endl;
		cout << "是否还要继续游戏" << endl;
		bool temp = false;
		cout << "0 = 否\t1 = 是" << endl;
		cin >> temp;
		if (!temp) break;
		else system("cls");

	}
	//更改game.heng文件中积分
	//把所有的文件内容统一处理
	guess_number_str = GAME_01_PONIT;
	guess_number_str += " ";
	guess_number_str += to_string(guess_number_points);
	//str_00 = guess_number_str;
	//str_00 += is_airplane_str;//得写在析构函数里，避免没有调用此两个函数而写入空的东西
}

