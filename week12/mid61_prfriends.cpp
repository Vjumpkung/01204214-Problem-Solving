#include <iostream>
#include <vector>

using namespace std;

// int power(int x, int y, int p)
// {
//     int ans = 1;
//     while (y > 0)
//     {
//         if (y & 1)
//         {
//             ans = (ans * x) % p;
//         }
//         y >>= 1;
//         x = (x * x) % p;
//     }
//     return ans;
// }

// int gcd(int x, int y)
// {
//     if (x < y)
//     {
//         return gcd(y, x);
//     }
//     else if (x % y == 0)
//     {
//         return y;
//     }
//     else
//     {
//         return gcd(y, x % y);
//     }
// }

// bool miillerTest(int d, int n)
// {
//     int a = 2 + rand() % (n - 4);
//     int x = power(a, d, n);
//     if (x == 1 || x == n - 1)
//     {
//         return true;
//     }
//     while (d != n - 1)
//     {
//         x = (x * x) % n;
//         d *= 2;

//         if (x == 1)
//         {
//             return false;
//         }
//         if (x == n - 1)
//         {
//             return true;
//         }
//     }
//     return false;
// }

// bool is_prime(int n, int k)
// {
//     if (n <= 1 || n == 4)
//     {
//         return false;
//     }
//     if (n <= 3)
//     {
//         return true;
//     }
//     for (int i = 0; i < k; i++)
//     {
//         if (!miillerTest(n - 1, n))
//         {
//             return false;
//         }
//     }
//     return true;
// }

// simple is prime in sqrt(n)
bool is_prime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<int> vec;
    int l, r;
    cin >> l >> r;
    int count = 0;
    for (int i = l; i <= r; i++)
    {
        if (is_prime(i))
        {
            vec.push_back(i);
        }
    }
    for (int i = 1; i < vec.size(); i++)
    {
        if (abs(vec[i] - vec[i - 1]) == 2)
        {
            count++;
        }
    }
    cout << count << "\n";
    return 0;
}