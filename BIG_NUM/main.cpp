#include <iostream>
#include <string>
using namespace std;
string mul_big_num(string, string);
string add_big_num(string num1, string num2);
string sub_big_num(string n, string m);
int main()
{
	string num1;
	string num2;
	while (cin >> num1 >> num2) {
		int num1_real_length = num1[0] == '-' ? num1.size() - 1 : num1.size();
		int num2_real_length = num2[0] == '-' ? num2.size() - 1 : num2.size();
		if (num1_real_length == num2_real_length)
			cout << mul_big_num(num1, num2) << endl;
		else cout << "size of num1 unequal to size of num2!!!" << endl;
		system("pause");
		system("cls");
	}
	return 0;
}
