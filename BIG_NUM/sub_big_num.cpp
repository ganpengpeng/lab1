#include <string>
using namespace std;
string add_big_num(string num1, string num2);
string sub_big_num(string n, string m)
{
	if (n[0] == '-'&&n[1] == '-') n.erase(0, 2);
	if (m[0] == '-'&&m[1] == '-') m.erase(0, 2);
	if (n[0] == '-') return "-" + add_big_num(n.erase(0, 1), m);
	if (m[0] == '-') return add_big_num(n, m.erase(0, 1));
	while (n[0] == '0'&&n != "0")
		n.erase(0, 1);
	while (m[0] == '0'&&m != "0")
		m.erase(0, 1);
	string result, num1, num2;
	int carry = 0;
	if (n.size() < m.size())
	{
		num1 = m;
		num2 = n;
	}
	else if (n.size() == m.size() && n < m)
	{
		num1 = m;
		num2 = n;
	}
	else
	{
		num1 = n;
		num2 = m;
	}
	string::reverse_iterator i = num1.rbegin(), j = num2.rbegin();
	while (j != num2.rend())
	{
		result += (*i - *j - carry) < 0 ? (*i - *j - carry + 10 + '0') : (*i - *j - carry + '0');
		carry = (*i - *j - carry) < 0 ? 1 : 0;
		i += 1;
		j += 1;
	}
	while (i != num1.rend())
	{
		result += (*i - '0' - carry + 10) % 10 + '0';
		carry = 0;
		i += 1;
	}
	for (int i = 0, j = result.size() - 1; i < j; ++i, --j)
	{
		auto temp = result[i];
		result[i] = result[j];
		result[j] = temp;
	}
	if (num1 != n)
		result = "-" + result;
	return result;
}