#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	
	long long sum = 0;

	int n = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		long long a = 0, b = 0;
		cin >> a >> b;
		sum += (b + 1) * b / 2 - a  * (a - 1) / 2;
	}
	cout << sum << "\n";
	return 0;
}