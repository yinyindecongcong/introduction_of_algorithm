#include <iostream>
using namespace std;

void get_c_b(int c[][6], int b[][6], string s1, string s2){
	c[0][0] = (s1[0] == s2[0]);
	for (int i = 1; i < s1.size(); i++) b[i][0] = c[i][0] = c[i - 1][0] || s1[i] == s2[0];
	for (int i = 1; i < s2.size(); i++) b[0][i] = c[0][i] = c[0][i - 1] || s1[0] == s2[i];
	for (int j = 1; j < s2.size(); j++){
		for (int i = 1; i < s1.size(); i++){
			if (s1[i] == s2[j]) { c[i][j] = 1 + c[i - 1][j - 1]; b[i][j] = 1; }
			else if (c[i - 1][j] > c[i][j - 1]) { c[i][j] = c[i - 1][j]; b[i][j] = 2; }
			else { c[i][j] = c[i][j - 1]; b[i][j] = 3; } 
		}
	}
}
void print(int c[][6], int b[][6], string s1, string s2, int m, int n){
	if (m < 0 || n < 0) return;
	if (m == 0){
		if (b[m][n] == 1) cout << s1[0];
		return;
	}
	if (n == 0){
		if (b[m][n] == 1) cout << s2[n];
		return;
	}
	if (b[m][n] == 1){
		print(c, b, s1, s2, m - 1, n - 1);
		cout << s1[m];
	}
	else if (b[m][n] == 2) print(c, b, s1, s2, m - 1, n);
	else print(c, b, s1, s2, m, n - 1); 
}
//
int LCS(string s1, string s2, int i, int j){
	if (i < 0 || j < 0) return 0;
	if (s1[i] == s2[j]) return 1 + LCS(s1, s2, i - 1, j - 1);
	else return LCS(s1, s2, i, j- 1) > LCS(s1, s2, i - 1, j)?LCS(s1, s2, i, j- 1) : LCS(s1, s2, i - 1, j);
}
int main(){
	//要比较的两个串
	string s1 = "ABCBDAB";
	string s2 = "BDCABA";
	//创建两个数组，存放子串的LCS和取的方向
	int c[7][6];
	int b[7][6];
	get_c_b(c, b, s1, s2);
	cout << c[6][5] << endl;

	print(c, b, s1, s2, 6, 5);

	cout << LCS(s1, s2, 6, 5);
}