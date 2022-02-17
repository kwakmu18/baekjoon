#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	char arr[11] = {};
	cin >> arr;
	int len = strlen(arr);
	sort(arr, arr + len);
	for (int i = len-1; i > -1; i--)
	{
		cout << arr[i];
	}
}