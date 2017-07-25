#include <iostream>
using namespace std;
//�Ե׶��϶�̬�滮
void get_e_w_r(double e[][6], double w[][6], int root[][6], double p[], double q[], int n){
	//ȷ���������
	for (int i = 1; i < n + 2; i++) w[i][i - 1] = e[i][i - 1] = q[i - 1];
	for (int l = 0; l < n; l++){
		for (int i = 1; i < n - l + 1; i++){
			int j = i + l;
			w[i][j] = w[i][j - 1] + p[j] + q[j];
			//��ȷ����һ�����
			e[i][j] = e[i][i - 1] + e[i + 1][j] + w[i][j];
			root[i][j] = i;
			for (int k = i + 1; k <= j; k++){
				double temp = e[i][k - 1] + e[k + 1][j] + w[i][j];
				if (temp < e[i][j]) { e[i][j] = temp; root[i][j] = k; }
			}
		}
	}
}
//
void print(int root[][6], int n, int s, int t, int status = 1, int p = 0){//1��ʾ����2��ʾ���ӣ�3��ʾ�Һ���
	static int dx = 0;
	if (s == t + 1){
		cout << 'd' << dx++ << "��";
		switch(status){
			case 1: cout << "��" << endl; break;
			case 2: cout << 'k' << p << "������" << endl; break;
			case 3: cout << 'k' << p << "���Һ���" << endl;
		}
		return;
	}
	cout << 'k' << root[s][t] << "��";
	switch(status){
			case 1: cout << "��" << endl; break;
			case 2: cout << 'k' << p << "������" << endl; break;
			case 3: cout << 'k' << p << "���Һ���" << endl;
	}
	print(root, n, s, root[s][t] - 1, 2, root[s][t]);
	print(root, n, root[s][t] + 1, t, 3, root[s][t]);

}
int main (){
	//����k��d��Ƶ�ʣ���Ϊ1
	double p[6] = {0, 0.15, 0.10, 0.05, 0.10, 0.20};//5�����ݵ�Ƶ��,�Ӹ�0ʹ�����±�Ϊ1-5
	double q[6] = {0.05, 0.10, 0.05, 0.05, 0.05, 0.10};//di��ʾki��ki+1����
	//���������飬�ֱ����������ۡ�Ƶ�ʺ͡�����

	double e[7][6];
	/*e[i][j]��ʾki��kj����������,����������ݵ��±�Ϊ1-5
	Ϊ����e[1][0]��e[6][5]�Ŀ�������������������СΪ[7][6]
	*/
	double w[7][6];
	//��ʾki��kj�γɵ����Ľڵ�Ƶ�ʺͣ�w[i][j] = S(x = i~j)(p[x]) + S(x = i - 1 ~ j)(q[x])
	int root[6][6];
	//root[i][j]��ʾki��kj���ɵ��������������������

	get_e_w_r(e, w, root, p, q, 5);
	cout << root[1][5] << endl;
	cout << e[1][5] << endl;
	print(root, 5, 1, 5);
}