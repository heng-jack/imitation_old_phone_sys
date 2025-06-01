#pragma once
#include<iostream>
#include<Windows.h>											//通过Windows提供的API更改字体颜色和背景颜色等
#include<string>
#include<opencv2/opencv.hpp>
#include<ctime>
#include<fstream>
#include<vector>


#define CREATE_RESOURCE_FILE_NAME "D:\\resource"
#define CREATE_RS_FILE_NAME "D:\\resource\\rs"		//前面加L转为  宽字符字符串 适应Create_Directory()的参数要求
#define CREATE_PIC_FILE_NAME "D:\\resource\\pic"
#define RS_FILE_NAME "D:\\resource\\rs\\00.heng"
#define PIC_FILE_NAME "D:\\resource\\pic"
#define AB_FILE_NAME "D:\\resource\\rs\\addressbook.heng"
#define GAME_01_PONIT "GUESS_NUMBER_POINTS"
#define AIRPLANE_MODE "IS_AIRPLANE"
#define SHOW_STYLE "SHOW_STYLE_ID"
#define MAX_ADDRESS_BOOK_NUMBER 1000



using namespace std;
//void* h = GetStdHandle(STD_OUTPUT_HANDLE);
static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);					//获取标准输出句柄


class Theme;
class Console_Color;
class Airplane_Mode;

void write(string);
class Id {
	static int show_type_id;								//所有子类共享，在下面给默认初值
	static int text_color_id;								
	static int background_color_id;
	static bool is_airplane_mode;
private:
	static void set_show_type_id(int i) { 
		show_type_id = i;
		show_style_id_str = SHOW_STYLE;
		show_style_id_str += " ";
		show_style_id_str += to_string(show_type_id);
		show_style_id_str += " ";
		show_style_id_str += to_string(text_color_id);
		show_style_id_str += " ";
		show_style_id_str += to_string(background_color_id);
	}		//提供隐私接口
	static void set_text_color_id(int i) { 
		text_color_id = i;
		show_style_id_str = SHOW_STYLE;
		show_style_id_str += " ";
		show_style_id_str += to_string(show_type_id);
		show_style_id_str += " ";
		show_style_id_str += to_string(text_color_id);
		show_style_id_str += " ";
		show_style_id_str += to_string(background_color_id);
	}		//提供隐私接口
	static void set_background_color_id(int i) { 
		background_color_id = i;
		show_style_id_str = SHOW_STYLE;
		show_style_id_str += " ";
		show_style_id_str += to_string(show_type_id);
		show_style_id_str += " ";
		show_style_id_str += to_string(text_color_id);
		show_style_id_str += " ";
		show_style_id_str += to_string(background_color_id);
	}		//提供隐私接口
	static void set_is_airplane_mode(bool i) { is_airplane_mode = i; }		//提供隐私接口
protected:
	//需要共享数据
	static string guess_number_str;
	static string is_airplane_str;			//需要在构造函数中赋值
	static string show_style_id_str;
	static string str_00;					//记录写入文档的内容
public:
	friend Theme;
	friend Console_Color;
	friend Airplane_Mode;
	friend void write(string);	//用于将数据写入00.heng

	Id() {						//文件里读取show_type_id，text_color_id，background_color_id
		ifstream ifs;
		ifs.open(RS_FILE_NAME);
		string line;
		bool is = 0;
		while (getline(ifs, line)) {
			if (line.substr(0, 13) == SHOW_STYLE) {
				int start = 14;
				int index = 0;
				for (int i = 14; i < line.size(); i++) {
					if (line[i] == ' ') {
						switch (index++) {
						case 0:
							show_type_id = stoi(line.substr(start, i - start));
							break;
						case 1:
							text_color_id = stoi(line.substr(start, i - start));
							break;
						case 2:
							background_color_id = stoi(line.substr(start, i - start));
							break;
						default:
							break;
						}
						start = i + 1;
					}
				}
				is = 1;
				show_style_id_str = SHOW_STYLE;
				show_style_id_str += " ";
				show_style_id_str += to_string(show_type_id);
				show_style_id_str += " ";
				show_style_id_str += to_string(text_color_id);
				show_style_id_str += " ";
				show_style_id_str += to_string(background_color_id);
				return;
			}
		}
		if (!is) {
			cout << "没有显示风格数据，已显示默认风格" << endl;
			show_style_id_str = SHOW_STYLE;
			show_style_id_str += " ";
			show_style_id_str += to_string(show_type_id);
			show_style_id_str += " ";
			show_style_id_str += to_string(text_color_id);
			show_style_id_str += " ";
			show_style_id_str += to_string(background_color_id);
			system("paulse");
			return;
		}
	}
	int get_show_type_id();
	int get_text_color_id();
	int get_background_color_id();
	static bool get_is_airplane_mode();			//设置静态，实现通过类名调用
	~Id() {
		str_00 = guess_number_str;
		str_00 += '\n';
		str_00 += is_airplane_str;
		str_00 += '\n';
		str_00 += show_style_id_str;
		write(str_00);
	}
};

//int show_type_id = 1;
//int Id::show_type_id = 1;
//需要在主函数文件中赋初值？？？

class Base_Show :  public Id {						
protected:
	int index;
public:
	Base_Show() : index(0) {}
	virtual void show_type_01() = 0;
	virtual void show_type_02() = 0;
	virtual void show_type_03() = 0;
	void setConsoleColor(int text_color, int background_color);
	void show();
	void set_index(int i) { index = i; }
	int get_index() { return index; }
};