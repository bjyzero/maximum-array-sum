//排序以后，留下来的宝石是连续的一段
//不能直接求和
//如果暴力解决需要在while(t--)循环里面，嵌套一个sort()和while(k--)
//在while(k--)里进行erase()-->时间复杂度为 O(n)
//k 的范围为 1 <= k <= 99999,这样写会超时

//前缀和可以解决这个问题
//其时间复杂度为 O(n log n)
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(const int &Case)
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());

    //这里注意前缀和从 1 开始，共有 n 个数据
    vector<ll> pre(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        pre[i] = pre[i - 1] + a[i - 1];
    }

    //枚举
    ll ans = 0;
    for (int i = 0; i <= k; ++i)
    {
        ans = max(ans, pre[n - (k - i)] - pre[2 * i]);
    }
    cout << ans << '\n';
}

int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve(t);
    return 0;
}