#include <iostream>
#include <cmath>

using namespace std;

pair<int, int> p[10001];

int main() 
{
	int n, a, b, r;
	int c = 0;
	cin >> n >> a >> b >> r;
	for (int i = 0; i < n; i++) 
	{
		cin >> p[i].first >> p[i].second;
	}
	for (int i = 0; i < n; i++)
	{
		if (pow(a-p[i].first, 2) + pow(b - p[i].second,2) <= r*r)
		{
			c++;
		}
	}
	cout << c << "\n";
	return 0;
}