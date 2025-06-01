#include<iostream>
#include"head.h"
#include"desktop.h"
#include"menu.h"
#include"setting.h"
#include"theme.h"
#include"color.h"
#include"airplane.h"
#include"games.h"
#include"brower.h"
#include"camera.h"
#include"addressbook.h"

using namespace std;

int Id::show_type_id = 1;
//int show_type_id = 1;
int Id::text_color_id = 7;
int Id::background_color_id = 0;
bool Id::is_airplane_mode = 0;
string Id::guess_number_str = "";
string Id::is_airplane_str = "";
string Id::show_style_id_str = "";
string Id::str_00 = "";

//检测配置运行的必要文件
void file_check_make();

int main() {
	//检测配置文件
	file_check_make();
	/*所有的对象*/
	Desktop desktop;
	Menu menu;
	Setting setting;
	Theme theme;
	Console_Color console_color;
	Airplane_Mode airplane_mode;
	Games games;
	Brower brower;
	Camera camera;
	Address_Book ab;
	
	while (true) {
		desktop.show();		//显示桌面选项
		int desktop_index = 0;							//储存选项
		cin >> desktop_index;
		desktop.set_index(desktop_index);
		switch (desktop.get_index())
		{
		case 1://菜单
			while (true) {
				menu.show();
				int menu_index = 0;							//储存菜单选项
				cin >> menu_index;
				menu.set_index(menu_index);
				//用if可以break while
				if (!menu.get_index()) break;
				else {
					switch (menu.get_index()) {
					case 1://brower
						brower.open_default_brower();
						break;
					case 2://games
						while (true) {
							games.show();
							int games_index = 0;							//储存游戏选项
							cin >> games_index;
							games.set_index(games_index);
							if (games.get_index() == 0) break;				//实现返回上一级
							else {
								switch (games.get_index()) {
								case 1://猜数字
									games.guess_number();
									break;
								default:
									break;
								}
							}
						}
						break;
					case 3://setting
						while (true) {
							setting.show();
							int setting_index;				//储存设置选项
							cin >> setting_index;
							setting.set_index(setting_index);
							//使用if可以break while实现返回
							if (!setting.get_index()) break;
							else {
								switch (setting.get_index()) {
								case 1://更改主题
									theme.setting_show_type_id();
									break;
								case 2://更改控制台颜色
									console_color.setting_console_color_id();
									break;
								case 3://飞行模式
									airplane_mode.setting_airplane_mode();
									break;
								default:
									break;
								}
							}
						}
						break;
					case 4://phone
						while (true) {
							ab.show();
							int ab_index;				//储存通讯录选项
							cin >> ab_index;
							ab.set_index(ab_index);
							//使用if可以break while实现返回
							if (!ab.get_index()) break;
							else {
								switch (ab.get_index()) {
								case 1://添加联系人
									ab.addMum();
									break;
								case 2://查看联系人
									ab.showAdd();
									break;
								case 3://删除联系人
									ab.deleteMum();
									break;
								case 4://查找联系人
									ab.find_and_dial();
									break;
								case 5://更改联系人
									ab.modifyMum();
									break;
								case 6://清除通讯录
									ab.clearAll();
									break;
								default:
									break;
								}
							}
						}
						break;
					case 5://camera
						camera.take_picture();
						break;
					case 6://photo
						camera.show_picture();
						break;
					default:
						break;
					}
				}
			}
			break;
		case 2://联系人
			while (true) {
				ab.show();
				int ab_index;				//储存通讯录选项
				cin >> ab_index;
				ab.set_index(ab_index);
				//使用if可以break while实现返回
				if (!ab.get_index()) break;
				else {
					switch (ab.get_index()) {
					case 1://添加联系人
						ab.addMum();
						break;
					case 2://查看联系人
						ab.showAdd();
						break;
					case 3://删除联系人
						ab.deleteMum();
						break;
					case 4://查找和拨号
						ab.find_and_dial();
						break;
					case 5://更改联系人
						ab.modifyMum();
						break;
					case 6://清除通讯录
						ab.clearAll();
						break;
					default:
						break;
					}
				}
			}
			break;
		case 3://拨号
			ab.find_and_dial();
			break;
		case 0:
			return 0;
			break;
		default:
			cout << "索引错误" << endl;
			system("pause");
			break;
		}
		
	}

	return 0;
}

void file_check_make() {
	//先创建必要的文件夹
	if (CreateDirectory(CREATE_RESOURCE_FILE_NAME, NULL)) {}
	else {
		DWORD error = GetLastError();
		if (error == ERROR_ALREADY_EXISTS) {}
		else if (error == ERROR_PATH_NOT_FOUND) {
			std::cout << "路径中某一级目录不存在。\n";
			system("pause");
		}
		else {
			std::cout << "文件夹创建失败，错误代码: " << error << "\n";
			system("pause");
		}
	}
	if (CreateDirectory(CREATE_RS_FILE_NAME, NULL)) {}
	else {
		DWORD error = GetLastError();
		if (error == ERROR_ALREADY_EXISTS) {}
		else if (error == ERROR_PATH_NOT_FOUND) {
			std::cout << "g路径中某一级目录不存在。\n";
			system("pause");
		}
		else {
			std::cout << "文件夹创建失败，错误代码: " << error << "\n";
			system("pause");
		}
	}
	if (CreateDirectory(CREATE_PIC_FILE_NAME, NULL)) {}
	else {
		DWORD error = GetLastError();
		if (error == ERROR_ALREADY_EXISTS) {}
		else if (error == ERROR_PATH_NOT_FOUND) {
			std::cout << "p路径中某一级目录不存在。\n";
			system("pause");
		}
		else {
			std::cout << "文件夹创建失败，错误代码: " << error << "\n";
			system("pause");
		}
	}
	/*if (CreateDirectory(CREATE_VIDEO_FILE_NAME, NULL)) {}
	else {
		DWORD error = GetLastError();
		if (error == ERROR_ALREADY_EXISTS) {}
		else if (error == ERROR_PATH_NOT_FOUND) {
			std::cout << "v路径中某一级目录不存在。\n";
			system("pause");
		}
		else {
			std::cout << "文件夹创建失败，错误代码: " << error << "\n";
			system("pause");
		}
	}*/
	//配置资源文件
	ifstream ifs;
	ifs.open(RS_FILE_NAME);
	if (ifs) {
		ifs.close();
	}
	else {
		ifs.close();
		ofstream ofs(RS_FILE_NAME);
		ofs << "GUESS_NUMBER_POINTS " << 0 << '\n';
		ofs << "IS_AIRPLANE " << 0 << '\n';
		ofs.close();
	}
	//配置通讯录文件
	ifs.open(AB_FILE_NAME);
	if (ifs) {
		ifs.close();
	}
	else {
		ifs.close();
		ofstream ofs(AB_FILE_NAME);
		ofs.close();
	}
}


/*0 = 黑色       8 = 灰色
  1 = 蓝色       9 = 淡蓝色
  2 = 绿色       A = 淡绿色
  3 = 浅绿色     B = 淡浅绿色
  4 = 红色       C = 淡红色
  5 = 紫色       D = 淡紫色
  6 = 黄色       E = 淡黄色
  7 = 白色       F = 亮白色


键位对应waitKey()的返回值
LEFT (左箭头)	2424832	左方向键
RIGHT (右箭头)	2555904	右方向键
UP (上箭头)	2490368	上方向键
DOWN (下箭头)	2621440	下方向键
F1	65360	功能键 F1
F2	65361	
F3	65362	
F4	65363	
F5	65364	
F6	65365	
F7	65366	
F8	65367	
F9	65368	
F10	65369	
F11	65370	
F12	65371	
Page Up	65365	在某些系统中与 F6 冲突
Page Down	65366	在某些系统中与 F7 冲突
Home	65360	在某些系统中与 F1 冲突
End	65367	在某些系统中与 F8 冲突
Insert	65379	插入键
Delete	65535	删除键*/