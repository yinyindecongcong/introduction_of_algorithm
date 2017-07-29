#include <iostream>
#include <vector>
using namespace std;
//choice已按期限从小到大排序
bool judge_alone(int d[], int choice[], int n, int di){
	for (int i = 0; i < n; i++)
		if (d[choice[i]] >= di && i + 2 > d[choice[i]]) return 0;
	return 1;
}
//按升序插入一个数
void insert(int d[], int choice[], int i, int &n){
	int j = n - 1;
	while(j >= 0 && d[choice[j]] > d[i]){
		choice[j + 1] = choice[j];
		j--;
	}
	choice[j + 1] = i;
	n++;
}
int main(){
	//给定条件,任务的期限和惩罚,假设已按惩罚从大到小排序
	int d[] = {4, 2, 4, 3, 1, 4, 6};
	int w[] = {70, 60,50, 40, 30, 20, 10};
	//已证该问题为加权拟阵，可用拟阵的贪心算法
	int choice[7];
	int n = 0;
	for (int i = 0; i < 7; i++){
		if (judge_alone(d, choice, n, d[i])) insert(d, choice, i, n);
	}
	for (int i = 0; i < n; i++) cout << choice[i] << ' ';
}