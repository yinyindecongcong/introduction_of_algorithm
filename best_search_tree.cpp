#include <iostream>
using namespace std;
//自底而上动态规划
void get_e_w_r(double e[][6], double w[][6], int root[][6], double p[], double q[], int n){
	//确定空树情况
	for (int i = 1; i < n + 2; i++) w[i][i - 1] = e[i][i - 1] = q[i - 1];
	for (int l = 0; l < n; l++){
		for (int i = 1; i < n - l + 1; i++){
			int j = i + l;
			w[i][j] = w[i][j - 1] + p[j] + q[j];
			//先确定第一种情况
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
void print(int root[][6], int n, int s, int t, int status = 1, int p = 0){//1表示根，2表示左孩子，3表示右孩子
	static int dx = 0;
	if (s == t + 1){
		cout << 'd' << dx++ << "是";
		switch(status){
			case 1: cout << "根" << endl; break;
			case 2: cout << 'k' << p << "的左孩子" << endl; break;
			case 3: cout << 'k' << p << "的右孩子" << endl;
		}
		return;
	}
	cout << 'k' << root[s][t] << "是";
	switch(status){
			case 1: cout << "根" << endl; break;
			case 2: cout << 'k' << p << "的左孩子" << endl; break;
			case 3: cout << 'k' << p << "的右孩子" << endl;
	}
	print(root, n, s, root[s][t] - 1, 2, root[s][t]);
	print(root, n, root[s][t] + 1, t, 3, root[s][t]);

}
int main (){
	//给出k和d的频率，和为1
	double p[6] = {0, 0.15, 0.10, 0.05, 0.10, 0.20};//5个数据的频率,加个0使数据下标为1-5
	double q[6] = {0.05, 0.10, 0.05, 0.05, 0.05, 0.10};//di表示ki到ki+1的数
	//创建三数组，分别存放搜索代价、频率和、树根

	double e[7][6];
	/*e[i][j]表示ki到kj的搜索代价,其中五个数据的下标为1-5
	为包括e[1][0]和e[6][5]的空树的情况，设置数组大小为[7][6]
	*/
	double w[7][6];
	//表示ki到kj形成的树的节点频率和，w[i][j] = S(x = i~j)(p[x]) + S(x = i - 1 ~ j)(q[x])
	int root[6][6];
	//root[i][j]表示ki到kj构成的最佳搜索二叉树的树根

	get_e_w_r(e, w, root, p, q, 5);
	cout << root[1][5] << endl;
	cout << e[1][5] << endl;
	print(root, 5, 1, 5);
}