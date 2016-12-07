#include "Point.h"
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
extern double_point p;
bool compare_y(const point a, const point b)
{
	if (a.y < b.y) return true;
	if (a.y > b.y) return false;
	if (a.x < b.x) return true;
	return false;
}
double distance(const point a, const point b)
{
	double i = b.x - a.x;
	double j = b.y - a.y;
	return sqrt(i*i + j*j);
}
double min_point_distance(const vector<point> v, int l, int r)
{
	if (r - l == 1)
		return distance(v[l], v[r]);
	if (r - l == 0)
		return INT_MAX;
	int pivot = l + (r - l) / 2;
	double min_l_dis = min_point_distance(v, l, pivot);
	double min_r_dis = min_point_distance(v, pivot + 1, r);
	double min_dis = min_l_dis < min_r_dis ? min_l_dis : min_r_dis;
	int i = pivot, j = pivot;
	while (i && v[pivot].x - v[i - 1].x < min_dis)
		i -= 1;
	while (j <= r - 1 && v[j + 1].x - v[pivot].x < min_dis)
		j += 1;
	vector<point> t;
	for (int k = i; k <= j; ++k)
		t.push_back(v[k]);
	sort(t.begin(), t.end(), compare_y);
	for (auto a = t.begin(); a != t.end(); ++a)
		for (auto b = a + 1; b != t.end(); ++b)
		{
			if (b->y - a->y > min_dis)
				break;
			if (distance(*a, *b) <= min_dis)
			{
				min_dis = distance(*a, *b);
				p.a = *a;
				p.b = *b;
				p.distance = min_dis;
			}
		}
	return min_dis;
}
