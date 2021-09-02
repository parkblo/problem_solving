#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 왜 R을 N으로 설정할 때는 되고 N-1일때는 안되는지?

int N,M;
vector<int> num;
vector<int> fnd;

bool compare(int a, int b)
{
	return a<b;
}

int lowerBound(int target)
{
	int L = 0;
	int R = N;

	while (L<R)
	{
		int mid = (L+R)/2;

		if (num[mid] < target)
		{
			L = mid + 1;
		}
		else
		{
			R = mid;
		}
	}

	return R;
}

// 0 1 2 3 4 5 6 7 7 7 8 (FIND LOWERBOUND 7) L=0 R=11
// |0 1 2 3 4 [5] 6 7 7 7 8| L=0 R=11 M=5
// 0 1 2 3 4 5 |6 7 [7] 7 8| L=6 R=11 M=8
// 0 1 2 3 4 5 |6 [7] 7| 7 8
// 0 1 2 3 4 5 |[6] 7| 7 7 8
// 0 1 2 3 4 5 6 |[7]| 7 7 8 (BREAK)

int upperBound(int target)
{
	int L = 0;
	int R = N;

	while (L<R)
	{
		int mid = (L+R)/2;

		if (num[mid] <= target)
		{
			L = mid + 1;
		}
		else
		{
			R = mid;
		}
	}

	return R;
}

// 0 1 2 3 4 5 6 7 7 7 8 (FIND UPPERBOUND 7)
// |0 1 2 3 4 [5] 6 7 7 7 8|
// 0 1 2 3 4 5 |6 7 [7] 7 8|
// 0 1 2 3 4 5 6 7 7 |[7] 8|
// 0 1 2 3 4 5 6 7 7 7 |[8]|
// 0 1 2 3 4 5 6 7 7 7 |[8]| (BREAK)

int main()
{
	cin >> N;
	for (int i=0;i<N;i++)
	{
		int tmp;
		cin >> tmp;
		num.push_back(tmp);
	}

	sort(num.begin(),num.end(),compare);

	cin >> M;
	for (int i=0;i<M;i++)
	{
		int tmp;
		cin >> tmp;
		fnd.push_back(tmp);
	}

	for (int i=0;i<M;i++)
		cout << upperBound(fnd[i]) - lowerBound(fnd[i]) << ' ';

	return 0;
}
