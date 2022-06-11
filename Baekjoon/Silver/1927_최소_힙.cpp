#include <iostream>
using namespace std;

int heap[100001];
int heapSize=0;

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void push(int x)
{
	heap[++heapSize] = x;

	int child = heapSize;
	int parent = heapSize/2;

	while (child>1 && heap[child]<heap[parent])
	{
		swap(&heap[child],&heap[parent]);
		child = parent;
		parent = child/2;
	}
}

int pop(int x)
{
	if (heapSize == 0) return 0;

	int ret = heap[1];

	swap(&heap[1], &heap[heapSize]);
	heapSize--;

	int parent = 1;
	int child = parent * 2;

	if (child+1 <= heapSize){
		child = (heap[child]<heap[child+1]) ? child : child+1;
	}

	while (child<=heapSize && heap[child]<heap[parent])
	{
		swap(&heap[child], &heap[parent]);
		parent = child;
		child = parent * 2;

		if (child+1 <= heapSize){
		child = (heap[child]<heap[child+1]) ? child : child+1;
		}
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int N,tmp;
	cin >> N;
	for (int i=0; i<N; i++)
	{
		cin >> tmp;
		if (tmp == 0) cout << pop(tmp) << '\n';
		else push(tmp);
	}
	return 0;
}
