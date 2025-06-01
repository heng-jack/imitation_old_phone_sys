#include"theme.h"

void Theme::setting_show_type_id() {
	cout << "01\t####\n";
	cout << "02\t****\n";
	cout << "03\t/-/-\n";
	cout << "ÇëÊäÈë£º" << endl;
	int show_type_id;
	cin >> show_type_id;
	Id::set_show_type_id(show_type_id);
}