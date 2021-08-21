#include <iostream>
using namespace std;

typedef struct tree{
	char ch;
	struct tree *left;
	struct tree *right;
}tree;

int N;
tree t[30];

void input()
{
	cin >> N;
	for (int i=0; i<N; i++)
	{
		char ctmp;
		cin >> ctmp;
		int cur = ctmp - 'A';
		t[cur].ch = ctmp;

		cin >> ctmp;
		if (ctmp == '.')
			t[cur].left = NULL;
		else t[cur].left = &t[ctmp - 'A'];

		cin >> ctmp;
		if (ctmp == '.')
			t[cur].right = NULL;
		else t[cur].right = &t[ctmp - 'A'];
	}
}

void preTr(int curr)
{
	cout << t[curr].ch;

	int next;
	if (t[curr].left != NULL){
		next = (t[curr].left->ch) - 'A';
		preTr(next);
	}
	if (t[curr].right != NULL){
		next = (t[curr].right->ch) - 'A';
		preTr(next);
	}
}

void inTr(int curr)
{
	int next;
	if (t[curr].left != NULL){
		next = (t[curr].left->ch) - 'A';
		inTr(next);
	}

	cout << t[curr].ch;

	if (t[curr].right != NULL){
		next = (t[curr].right->ch) - 'A';
		inTr(next);
	}
}

void postTr(int curr)
{
	int next;
	if (t[curr].left != NULL){
		next = (t[curr].left->ch) - 'A';
		postTr(next);
	}

	if (t[curr].right != NULL){
		next = (t[curr].right->ch) - 'A';
		postTr(next);
	}

	cout << t[curr].ch;
}


int main()
{
	input();

	preTr(0); cout << '\n';
	inTr(0); cout << '\n';
	postTr(0); cout << '\n';

	return 0;
}
