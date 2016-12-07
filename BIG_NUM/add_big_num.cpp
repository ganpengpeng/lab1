#include <string>
using namespace std;
string sub_big_num(string n, string m);
string add_big_num(string num1, string num2)
{
	if (num1[0] == '-'&&num1[1] == '-') num1.erase(0, 2);
	if (num2[0] == '-'&&num2[1] == '-') num2.erase(0, 2);
	if (num1[0] == '-') return sub_big_num(num2, num1.erase(0, 1));
	if (num2[0] == '-') return sub_big_num(num1, num2.erase(0, 1));
	while (num1[0] == '0'&&num1 != "0")
		num1.erase(0, 1);
	while (num2[0] == '0'&&num2 != "0")
		num2.erase(0, 1);
	string result;
	string::reverse_iterator i = num1.rbegin(), j = num2.rbegin();
	int carry = 0;
	while (i != num1.rend() && j != num2.rend())
	{
		result += (*i - '0' + *j -'0' + carry) % 10 +'0';
		carry = (*i - '0' + *j - '0' + carry) / 10;
		i += 1;
		j += 1;
	}
	if (i == num1.rend())
	{
		while (j != num2.rend())
		{
			result += (*j - '0' + carry) % 10 + '0';
			carry = (*j - '0' + carry) / 10;
			j += 1;
		}
		if (carry)
			result += '1';
	}
	else
	{
		while (i != num1.rend())
		{
			result += (*i - '0' + carry) % 10 + '0';
			carry = (*i - '0' + carry) / 10;
			i += 1;
		}
		if (carry)
			result += '1';
	}
	for (int i = 0, j = result.size() - 1; i < j; ++i, --j)
	{
		auto temp = result[i];
		result[i] = result[j];
		result[j] = temp;
	}
	return result;
}