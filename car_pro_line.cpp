#include <iostream>
using namespace std;

//
int min(int a, int b){
	return a < b? a: b;
}

void print(int l1[], int l2[], int n, int lx){
	if (n == 0) {
		cout << "line " << lx << " , station " << 1 << endl;
		return;
	}
	int lx1 = (lx == 1)? l1[n - 1]: l2[n - 1];
	print(l1, l2, n - 1, lx1);
	cout << "line " << lx << " , station " << n + 1 << endl;
}
int main (){
	//给定条件为生产汽车的两条装配线的每一步所需时间和转线的时间
	int n = 6;
	int s1[n] = {9, 9, 3, 4, 8, 4};
	int s2[n] = {12, 5, 6, 4, 5, 7};
	int a1[n - 1] = {2, 3, 1, 3, 4};
	int a2[n - 1] = {2, 1, 2, 2, 1};
	int e1 = 3, e2 = 2;
	//创建四个数组分别存放到s1,s2每个点的最短时间和到每个点最短路径的最近起点
	int f1[n], f2[n], l1[n - 1], l2[n - 1];//第一个点没有出发点
	f1[0] = s1[0], f2[0] = s2[0];
	for (int i = 1; i < n; i++){
		int a = f1[i - 1] + s1[i], b = f2[i - 1] + a2[i - 1] + s1[i];
		if (a < b){
			f1[i] = a;
			l1[i - 1] = 1;
		}
		else {
			f1[i] = b;
			l1[i - 1] = 2;
		}
		a = f2[i - 1] + s2[i], b = f1[i - 1] + a1[i - 1] + s2[i];
		if (a < b){
			f2[i] = a;
			l2[i - 1] = 2;
		}
		else{
			f2[i] = b;
			l2[i - 1] = 1;
		}
	}
	//此时已确定各个数组的值
	int a = f1[n - 1] + e1, b = f2[n - 1] + e2;
	int shortest = a < b? a: b;
	int lx = a < b? 1: 2;
	print(l1, l2, n - 1, lx);
}