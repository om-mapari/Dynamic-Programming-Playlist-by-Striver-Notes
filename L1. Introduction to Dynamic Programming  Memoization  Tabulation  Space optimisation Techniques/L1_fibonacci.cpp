#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int fibo(int n) // Normal recursion
{
    if (n <= 1) return n;
    return fibo(n - 1) + fibo(n - 2);
}

int fibo_dp(int n, vector<int> &dp)
{
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n]; // (3) return if previously solved
    return dp[n] = fibo_dp(n - 1, dp) + fibo_dp(n - 2, dp); // (2)store values
}

int fibo_tab(int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0; dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int fibo_final(int n)
{
    int prev2 = 0;
    int prev = 1;
    for (int i = 2; i <= n; i++)
    {
        int curi = prev + prev2;
        prev2 = prev;
        prev = curi;
    }
    return prev;
}

int main()
{
    int n = 5 ;
    vector<int> dp(n + 1, -1); // (1) declear dp
    cout << fibo_dp(n, dp) << endl;
    cout << fibo_tab(5) << endl;
    cout << fibo_final(5) << endl;
    return 0;
}