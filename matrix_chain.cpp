#include <iostream>
using namespace std;

void get_s_l(int p[], int s[][6], int l[][6], int n){
	for (int i = 0; i < n; i++) s[i][i] = 0;
	for (int k = 1; k < n; k++) {//k为区间端点的差
		for (int i = 0; i < n - k; i++){
			s[i][i + k] = s[i + 1][i + k] + p[i] * p[i + 1] * p[i + k + 1];
			l[i][i + k] = i;
			for (int j = i + 1; j < i + k; j++){
				int temp = s[i][j] + s[j + 1][i + k] + p[i] * p[j + 1] * p[i + k + 1];
				if (temp < s[i][i + k]) { s[i][i + k] = temp; l[i][i + k] = j; }
			}
		}
	}
}
//
int get_min(int p[], int s, int n){
	if (s == n) return 0;
	if (s == n - 1) return p[s] * p[s + 1] * p[n + 1];
	int min = get_min(p, s + 1, n) + p[s] * p[s + 1] * p[n + 1];
	for (int i = s + 1; i < n; i++){
		int temp = get_min(p, s, i) + get_min(p, i + 1, n) + p[s] * p[i + 1] * p[n + 1];
		if (temp < min) min = temp;
	} 
	return min;
}
void print(int l[][6], int s, int n){
    if (s == n) {
        cout << "A" << s;
        return;
    }
    cout << "(";
    print(l, s, l[s][n]);
    print(l, l[s][n] + 1, n);
    cout << ")";
}
int main (){
	//给定一组矩阵，Ai = P[i]*P[i+1]
	int n = 6;
	int p[7] = {30, 35, 15, 5, 10, 20, 25};
	//建两个二维数组，存放子矩阵链相乘最优方案和隔开的位置
	int s[6][6];
	int l[6][6];
	//
	cout << get_min(p, 0, 5) << endl;
	get_s_l(p, s, l, n);
	print(l, 0, 5);
	cout << endl << "最少需要乘法次数："<< s[0][5] << endl;
}
