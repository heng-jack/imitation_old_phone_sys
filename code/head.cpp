#include"head.h"

void Base_Show::setConsoleColor(int text_color_id, int background_color_id) {
    // 计算颜色属性值
    int color = (background_color_id << 4) | text_color_id;
    SetConsoleTextAttribute(h, color);
}

void Base_Show::show() {
	system("cls");				//展示前清屏
	setConsoleColor(get_text_color_id(), get_background_color_id());
	switch (get_show_type_id())
	{
	case 1:
		show_type_01();
		break;
	case 2:
		show_type_02();
		break;
	case 3:
		show_type_03();
		break;
	default:
		cout << "索引错误" << endl;
		break;
	}
}

void write(string str_00) {
	ofstream ofs(RS_FILE_NAME);
	if (ofs.is_open()) {
		ofs << str_00;
		ofs.close();
	}
	else cout << "文件无法打开" << endl;
}


int Id::get_show_type_id() { return show_type_id; }
int Id::get_text_color_id() { return text_color_id; }
int Id::get_background_color_id() { return background_color_id; }
bool Id::get_is_airplane_mode() { return is_airplane_mode; }