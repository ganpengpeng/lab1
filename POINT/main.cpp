#include <iostream>
#include <vector>
#include "Point.h"
#include <algorithm>
using namespace std;
double min_point_distance(const vector<point>, int, int);
bool compare(const point a, const point b)
{
	if (a.x > b.x)
		return false;
	if (a.x < b.x)
		return true;
	if (a.y > b.y)
		return false;
	return true;
}
double_point p;
int main(int argc, char* argv[])
{
	vector<point> v = { {0,0},{0,4},{1,2},{1,3},{1,4},{2,0},{3,0},{4.1,1.4},{3,1},{3,4},{4,1},{4,2} };
	sort(v.begin(), v.end(), compare);
	for (const point& v1 : v)
		cout << v1 << " ";
	cout << endl;
	cout << min_point_distance(v, 0, v.size() - 1) << endl;
	cout << p << endl;
	system("pause");
}
