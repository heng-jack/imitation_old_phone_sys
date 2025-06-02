#pragma once
#include"head.h"

//联系人结构体
struct member {
public:
	string name;
	string phone;
	string sex;
	string address;
	string email;
	//string operator<<(member);//重载<<运算符，实现联系人信息的写入
	//member operator>>(string);//重载>>运算符，实现联系人信息的读出
};

//通讯录类
class address_book {
public:
	member *mum_arr;
	int mum_size;
	address_book() :mum_arr(new member[MAX_ADDRESS_BOOK_NUMBER]), mum_size(0) {}
	~address_book() { delete[] mum_arr; }
};

//不能写在头文件里

/*ofstream&*/void operator<<(ofstream& ofs, address_book*);

void operator>>(ifstream&, address_book*);

class Address_Book :public Base_Show {
	address_book* abs;
public:
	Address_Book() :abs(new address_book) {
		ifstream ifs(AB_FILE_NAME);
		ifs >> abs;
		ifs.close();
	}
	void show_type_01();
	void show_type_02();
	void show_type_03();
	//重写dial()
	void dial(string);
	void addMum();
	void showAdd();
	void deleteMum();
	void find_and_dial();
	void modifyMum();
	void clearAll();

	~Address_Book() { 
		ofstream ofs(AB_FILE_NAME);
		ofs << abs;					//重载<<运算符，实现写入
		ofs.close();
		delete abs; 
	}
};
