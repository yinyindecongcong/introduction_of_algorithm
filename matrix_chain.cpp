#include <iostream>
using namespace std;

void get_s_l(int p[], int s[][6], int l[][6], int n){
	for (int i = 0; i < n; i++) s[i][i] = 0;
	for (int k = 1; k < n; k++) {//kΪ����˵�Ĳ�
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
	//����һ�����Ai = P[i]*P[i+1]
	int n = 6;
	int p[7] = {30, 35, 15, 5, 10, 20, 25};
	//��������ά���飬����Ӿ�����������ŷ����͸�����λ��
	int s[6][6];
	int l[6][6];
	//
	get_s_l(p, s, l, n);
	print(l, 0, 5);
	cout << endl << "������Ҫ�˷�������"<< s[0][5] << endl;
}
