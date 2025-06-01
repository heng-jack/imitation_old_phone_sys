#include"addressbook.h"


void Address_Book::show_type_01() {
	cout << "#############################################" << endl;
	cout << "                   通讯录                    " << endl;
	cout << "#############################################" << endl;
	cout << "##############   01--添加     ###############" << endl;
	cout << "##############   02--查看     ###############" << endl;
	cout << "##############   03--删除     ###############" << endl;
	cout << "##############   04--查找拨号 ###############" << endl;
	cout << "##############   05--更改     ###############" << endl;
	cout << "##############   06--清除     ###############" << endl;
	cout << "##############   00--返回     ###############" << endl;
	cout << "#############################################" << endl;
	cout << "#############################################" << endl;
	cout << "请键入:" << endl;
}

void Address_Book::show_type_02() {
	cout << "*********************************************" << endl;
	cout << "                   通讯录                    " << endl;
	cout << "*********************************************" << endl;
	cout << "**************   01--添加     ***************" << endl;
	cout << "**************   02--查看     ***************" << endl;
	cout << "**************   03--删除     ***************" << endl;
	cout << "**************   04--查找拨号 ***************" << endl;
	cout << "**************   05--更改     ***************" << endl;
	cout << "**************   06--清除     ***************" << endl;
	cout << "**************   00--返回     ***************" << endl;
	cout << "*********************************************" << endl;
	cout << "*********************************************" << endl;
	cout << "请键入:" << endl;
}

void Address_Book::show_type_03() {
	cout << "/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/" << endl;
	cout << "                   通讯录                    " << endl;
	cout << "/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/" << endl;
	cout << "/-/-/-/-/-/-/-   01--添加     /-/-/-/-/-/-/-/" << endl;
	cout << "/-/-/-/-/-/-/-   02--查看     /-/-/-/-/-/-/-/" << endl;
	cout << "/-/-/-/-/-/-/-   03--删除     /-/-/-/-/-/-/-/" << endl;
	cout << "/-/-/-/-/-/-/-   04--查找拨号 /-/-/-/-/-/-/-/" << endl;
	cout << "/-/-/-/-/-/-/-   05--更改     /-/-/-/-/-/-/-/" << endl;
	cout << "/-/-/-/-/-/-/-   06--清除     /-/-/-/-/-/-/-/" << endl;
	cout << "/-/-/-/-/-/-/-   00--返回     /-/-/-/-/-/-/-/" << endl;
	cout << "/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/" << endl;
	cout << "/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/" << endl;
	cout << "请键入:" << endl;
}

void Address_Book::addMum() {
	//判断通讯录是否已满
	if (abs->mum_size >= MAX_ADDRESS_BOOK_NUMBER) {
		cout << "警告：通讯录已满！！";
		return;
	}
	cout << "请输入用户姓名：" << endl;
	string name;
	cin >> name;
	abs->mum_arr[abs->mum_size].name = name;
	cout << "请输入用户电话号码：" << endl;
	while (true) {
		string phone;
		cin >> phone;
		if (size(phone) == 11) {
			abs->mum_arr[abs->mum_size].phone = phone;
			break;
		}
		cout << "请输入正确格式的11位电话号码：";
	}
	cout << "请输入用户性别：" << endl;
	string sex;
	cin >> sex;
	abs->mum_arr[abs->mum_size].sex = sex;
	cout << "请输入用户住址：" << endl;
	string address;
	cin >> address;
	abs->mum_arr[abs->mum_size].address = address;
	cout << "请输入用户邮箱：" << endl;
	string email;
	cin >> email;
	abs->mum_arr[abs->mum_size].email = email;
	abs->mum_size++;													//用户人数+1
	cout << "添加成功" << endl;
	system("pause");
	system("cls");
}
void Address_Book::showAdd() {
	for (int i = 0; i < abs->mum_size; i++) {
		cout << "姓名:" << abs->mum_arr[i].name << "\t";
		cout << "电话:" << abs->mum_arr[i].phone << "\t";
		cout << "性别:" << abs->mum_arr[i].sex << "\t";
		cout << "住址:" << abs->mum_arr[i].address << "\t";
		cout << "邮箱:" << abs->mum_arr[i].email << "\n";
	}
	system("pause");
	system("cls");
}

void Address_Book::deleteMum() {
	cout << "请输入用户姓名：\n";
	string name;
	cin >> name;
	for (int i = 0; i < abs->mum_size; i++) {
		if (abs->mum_arr[i].name == name) {
			cout << "找到一个用户\n";
			cout << "姓名:" << abs->mum_arr[i].name << "\t";
			cout << "电话:" << abs->mum_arr[i].phone << "\t";
			cout << "性别:" << abs->mum_arr[i].sex << "\t";
			cout << "住址:" << abs->mum_arr[i].address << "\t";
			cout << "邮箱:" << abs->mum_arr[i].email << "\n";
			cout << "是否确认删除？(0 or 1)";
			bool b;
			cin >> b;
			if (b) {
				for (int j = i; j < abs->mum_size; j++) {
					abs->mum_arr[j] = abs->mum_arr[j + 1];
				}
				abs->mum_size--;											//用户数-1
				cout << "删除成功" << endl;
			}
		}
	}
}

void Address_Book::find_and_dial() {
	cout << "请输入用户姓名：\n";
	string name;
	cin >> name;
	vector<int> index;
	for (int i = 0; i < abs->mum_size; i++) {
		if (abs->mum_arr[i].name == name) {
			index.push_back(i);
			cout << "姓名:" << abs->mum_arr[i].name << "\t";
			cout << "电话:" << abs->mum_arr[i].phone << "\t";
			cout << "性别:" << abs->mum_arr[i].sex << "\t";
			cout << "住址:" << abs->mum_arr[i].address << "\t";
			cout << "邮箱:" << abs->mum_arr[i].email << "\n";
		}

	}
	if (index.size() == 0) {
		cout << "查无此人" << endl;
	}
	else {
		cout << "是否拨号：\n0 = 否\t1 = 是" << endl;
		int i = 0;
		cin >> i;
		if (i == 1) {
			if (index.size() == 1) dial(abs->mum_arr[index[0]].phone);
			else if (index.size() > 1) {
				cout << "呼叫第几个：" << endl;
				int r = 0;
				cin >> r;
				dial(abs->mum_arr[index[r - 1]].phone);
			}
		}
	}
	system("pause");
	system("cls");
}
void Address_Book::modifyMum() {
	cout << "请输入用户姓名：\n";
	string name;
	cin >> name;
	for (int i = 0; i < abs->mum_size; i++) {
		if (abs->mum_arr[i].name == name) {
			cout << "找到一个用户\n";
			cout << "姓名:" << abs->mum_arr[i].name << "\t";
			cout << "电话:" << abs->mum_arr[i].phone << "\t";
			cout << "性别:" << abs->mum_arr[i].sex << "\t";
			cout << "住址:" << abs->mum_arr[i].address << "\t";
			cout << "邮箱:" << abs->mum_arr[i].email << "\n";
			cout << "是否确认修改？(0 or 1)";
			bool b;
			cin >> b;
			if (b) {
				cout << "请输入用户姓名：" << endl;
				string name;
				cin >> name;
				abs->mum_arr[i].name = name;
				cout << "请输入用户电话号码：" << endl;
				while (true) {
					string phone;
					cin >> phone;
					if (size(phone) == 11) {
						abs->mum_arr[i].phone = phone;
						break;
					}
					cout << "请输入正确格式的11位电话号码：";
				}
				cout << "请输入用户性别：" << endl;
				string sex;
				cin >> sex;
				abs->mum_arr[i].sex = sex;
				cout << "请输入用户住址：" << endl;
				string address;
				cin >> address;
				abs->mum_arr[i].address = address;
				cout << "请输入用户邮箱：" << endl;
				string email;
				cin >> email;
				abs->mum_arr[i].email = email;
				cout << "修改成功" << endl;
			}
		}
		else cout << "查无此人" << endl;

	}
	system("pause");
	system("cls");
}
void Address_Book::clearAll() {
	//m_size=0即可
	cout << "是否确认清空通讯录？（0 or 1）";
	bool b;
	cin >> b;
	if (b) {
		abs->mum_size = 0;
	}
}

/*ofstream&*/void operator<<(ofstream& ofs ,address_book* abs) {
	if (abs->mum_size == 0) {
		ofs << " ";
		return /*ofs*/;
	}

	for (int i = 0; i < abs->mum_size; i++) {
		ofs << abs->mum_arr[i].name + '|' + abs->mum_arr[i].phone + '|' + abs->mum_arr[i].sex + '|' + abs->mum_arr[i].address + '|' + abs->mum_arr[i].email + '|' + '\n';
	}
	//return ofs;
}


void operator>>(ifstream& ifs, address_book* abs) {
	string linestr;
	int mem_i = 0;
	while (getline(ifs, linestr)) {
		int index = 0;
		int start = 0;
		for (int i = 0; i < linestr.size(); i++) {
			if (linestr[i] == '|') {
				switch (index++) {
				case 0:
					abs->mum_arr[mem_i].name = linestr.substr(start, i - start);
					abs->mum_size++;
					break;
				case 1:
					abs->mum_arr[mem_i].phone = linestr.substr(start, i - start);
					break;
				case 2:
					abs->mum_arr[mem_i].sex = linestr.substr(start, i - start);
					break;
				case 3:
					abs->mum_arr[mem_i].address = linestr.substr(start, i - start);
					break;
				case 4:
					abs->mum_arr[mem_i].email = linestr.substr(start, i - start);
					break;
				default:
					break;
				}
				start = i + 1;
			}
		}
		mem_i++;
	}
}


void Address_Book::dial(string phone){
	if (Id::get_is_airplane_mode()) {
		cout << "飞行模式已开，无法使用拨号功能" << endl;
		return;
	}
	else {
		cout << "正在呼叫：";
		for (int i = 0; i < abs->mum_size; i++) {
			if (abs->mum_arr[i].phone == phone) {
				cout << "姓名:" << abs->mum_arr[i].name << "\t";
				cout << "电话:" << abs->mum_arr[i].phone << "\t";
				cout << "性别:" << abs->mum_arr[i].sex << "\t";
				cout << "住址:" << abs->mum_arr[i].address << "\t";
				cout << "邮箱:" << abs->mum_arr[i].email << "\n";
			}
		}
	}
}