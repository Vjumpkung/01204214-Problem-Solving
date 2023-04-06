#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void LIS(vector<int> &a,vector<int> &memo)
{
	int n = a.size();
	int k = 0;
	vector<int> l(n,0);
	for(int i=0;i<n;i++)
	{
		int pos = lower_bound(l.begin(),l.begin()+k,a[i]) - l.begin();
		l[pos] = a[i];
		if(pos==k)
		{
			k++;
		}
		memo[i] = pos+1;
	}
}

int main()
{
	int n;
	while(cin >> n)
	{
		vector<int> vec(n);
		for(int i=0;i<n;i++)
		{
			cin >> vec[i];
		}
		vector<int> dp1(n),dp2(n);
		LIS(vec,dp1);
		reverse(vec.begin(),vec.end());
		LIS(vec,dp2);
		reverse(dp2.begin(), dp2.end());
		int res = 1;
		for(int i=0;i<n;i++)
		{
			res = max(res, 2*min(dp1[i],dp2[i]) - 1);
		}
		cout << res << "\n";
	}
	return 0;
}
