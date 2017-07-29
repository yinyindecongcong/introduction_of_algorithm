#include <iostream>
using namespace std;
struct node{
	int p;
	char c;
	node * lchild, *rchild;
	node(int px = 0, char cx = '0'):p(px), c(cx), lchild(0), rchild(0){}
};
//快排
template <class T>
void Swap(T & a, T & b){
	T temp = a ;
	a = b;
	b = temp;
}
int partition(int p[], char c[], int s, int n){
	int q = s - 1, x = p[n];
	for (int i = s; i < n; i++)
		if (p[i] <= x){
			q++;
			Swap(p[i], p[q]);
			Swap(c[i], c[q]);
		}
	Swap(p[n], p[q + 1]);
	Swap(c[n], c[q + 1]);
	return q + 1;
}
void quick_sort(int p[], char c[], int s, int n){
	if (s > n) return;
	int q = partition(p, c, s, n);
	quick_sort(p, c, s, q - 1);
	quick_sort(p, c, q + 1, n);
}
//用最小堆实现优先级队列
void heapify(node * ALL[], int i, int &heapsize){
	int l = 2 * i + 1, r = l + 1;//左右孩子
	int smallest = i;
	if (l < heapsize && ALL[l]->p < ALL[i]->p) smallest = l;
	if (r < heapsize && ALL[r]->p < ALL[smallest]->p) smallest = r;
	if (smallest != i) {
		Swap(ALL[smallest], ALL[i]);
		heapify(ALL, smallest, heapsize);
	}
}
node * extract_min(node * ALL[], int &heapsize){
	node * N = ALL[0];
	heapsize--;
	ALL[0] = ALL[heapsize];
	heapify(ALL, 0, heapsize);
	return N;
}
void insert(node * ALL[], node * H, int &heapsize){
	heapsize++;
	int i = heapsize - 1;
	ALL[i] = H;
	while(i > 0 && ALL[i]->p < ALL[(i - 1) / 2]->p){
		Swap(ALL[i], ALL[(i - 1) / 2]);
		i = (i - 1) / 2;
	}
}
int main(){
	//给定条件为一组不同频率的字符
	char c[] = {"abcdef"};
	int p[] = {45, 13, 12, 16, 9, 5};
	quick_sort(p, c, 0, 5);
	int heapsize = 6;
	node * ALL[6];
	for (int i = 0; i < 6; i++) ALL[i] = new node(p[i], c[i]);
	node * root;
	while(heapsize > 0){
		node * n = new node();
		n->lchild = extract_min(ALL, heapsize);
		if (heapsize > 0) {
            n->rchild = extract_min(ALL, heapsize);
            n->p = n->lchild->p + n->rchild->p;
		}
		else n->p = n->lchild->p;
		cout << n->p << endl;
		if (heapsize > 0) insert(ALL, n, heapsize);
		else root = n;
	}
    cout << root->p << endl;

}
