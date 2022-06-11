#include <iostream>
#include <vector>
using namespace std;

int ar[14];
int sel[6];
int cmd;

void lotto(int arIdx, int selIdx)
{
	if (selIdx == 6)
	{
		for (int i=0; i<6; i++)
		{
			cout << sel[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i=arIdx+1; i<cmd; i++)
	{
		sel[selIdx] = ar[i];
		lotto(i,selIdx+1);
	}
}

int main()
{
	while (1)
	{
		cin >> cmd;

		if (cmd == 0) break;

		for (int i=0; i<cmd; i++)
			cin >> ar[i];
		
		lotto(-1,0);
		cout << '\n';
	}
	return 0;
}
