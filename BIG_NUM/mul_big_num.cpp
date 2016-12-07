#include <string>
using namespace std;
string add_big_num(string, string);
string sub_big_num(string, string);
string mul_big_num(string num1, string num2)
{
	if (num1[0] == '-'&&num1[1] == '-') num1.erase(0, 2);
	if (num2[0] == '-'&&num2[1] == '-') num2.erase(0, 2);
	if (num1[0] == '-')
	{
		if (num2[0] == '-')
			return mul_big_num(num1.erase(0, 1), num2.erase(0, 1));
		return "-" + mul_big_num(num1.erase(0, 1), num2);
	}
	if (num2[0] == '-') return "-" + mul_big_num(num1, num2.erase(0, 1));
	if (num1.size() == 1 && num2.size() != 1)
	{
		string a = mul_big_num(num1, num2.substr(0, num2.size() / 2));
		string b = mul_big_num(num1, num2.substr(num2.size() / 2));
		a.append((num2.size() + 1) / 2, '0');
		return add_big_num(a, b);
	}
	if (num1.size() != 1 && num2.size() == 1)
	{
		string a = mul_big_num(num2, num1.substr(0, num1.size() / 2));
		string b = mul_big_num(num2, num1.substr(num1.size() / 2));
		a.append((num1.size() + 1) / 2, '0');
		return add_big_num(a, b);
	}
	if (num1.size() == 1 && num2.size() == 1)
	{
		char buf[100];
		_itoa_s(stoi(num1)*stoi(num2), buf, 10);
		return string(buf);
	}
	string A = num1.substr(0, num1.size() / 2);//A
	string B = num1.substr(num1.size() / 2);//B
	string C = num2.substr(0, num2.size() / 2);//C
	string D = num2.substr(num2.size() / 2);//D
	string AC = mul_big_num(A, C);//A*C
	string BD = mul_big_num(B, D);//B*D
	string s1 = add_big_num(AC, BD);
	string s6 = sub_big_num(A, B);
	string s7 = sub_big_num(D, C);
	string s2 = mul_big_num(s6, s7);
	string s3 = add_big_num(s1, s2);
	s3 += string(B.size(), '0');
	string s4 = add_big_num(AC + string(B.size() + D.size(), '0'), BD);
	string s5= add_big_num(s4, s3);
	return s5;
}

