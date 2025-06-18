#include"theme.h"

void Theme::setting_show_type_id() {
	cout << "01\t####\n";
	cout << "02\t****\n";
	cout << "03\t/-/-\n";
	cout << "请输入：" << endl;
	int show_type_id;
	cin >> show_type_id;
	if (show_type_id < 1 || show_type_id > 3) {
		cout << "索引不在有效范围内，将自动注销本次更改………………" << endl;
		system("pause");
		return;

	}
	Id::set_show_type_id(show_type_id);
}