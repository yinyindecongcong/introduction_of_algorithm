#include <iostream>
#include <vector>
using namespace std;
//递归实现
void get_set(int s[], int f[], vector<int> &set, int t, int n){
	int m = t + 1;
	while (m <= n && s[m] < f[t]) m++;
	if (m <= n){
		set.push_back(m);
		get_set(s, f, set, m, n);
	}
}
//迭代实现
int get_set_for(int s[], int f[], int t, int n){
	int c = 0;
	int m = t + 1;
	while (m <= n){
		while (m <= n && s[m] < f[t]) m++;
		if (m <= n) { c++; t = m; }
	}
	return c;
}
int main (){
	//给定条件为十一个事件的开始时间和结束时间，假设已按结束时间排序
	int s[] = {0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};//11个事件，大小为12
	int f[] = {0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
	//创建一个数组，存放选择的事件
	vector <int> set;
	//调用贪心算法的实现
	get_set(s, f, set, 0, 11);//ak属于set，当f0 <= sk < fk <= f11
	cout  << set.size() << endl;

	cout << get_set_for(s, f, 0, 11) << endl;
}