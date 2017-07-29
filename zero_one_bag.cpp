#include <iostream>
using namespace std;
//
int WWW;

int max(int a, int b){
	return a > b? a: b;
}
void get_V(int W, int n, int m[], int w[], int V[][103]){
	for (int i = 0; i <= n; i++) V[i][0] = 0;
	for (int i = 1; i <= W; i++) V[0][i] = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= W; j++){
			if (j >= w[i]) V[i][j] = max(V[i - 1][j], V[i - 1][j - w[i]] + m[i]);
			else V[i][j] = V[i - 1][j];
		}
	}
}
int main(){
	//给定条件为价格和重量
	int m[] = {0, 100, 200, 50, 500, 20, 10};
	int w[] = {0, 20, 30, 40, 50, 1, 2};
	//创建二维数组V[n][W]表示可以取前n件，最大重量为W的最优选择
	int V[7][103];
	get_V(102, 6, m, w, V);
	cout << V[6][102] << endl;

}