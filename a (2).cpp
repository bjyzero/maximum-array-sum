//�����Ժ��������ı�ʯ��������һ��
//����ֱ�����
//������������Ҫ��while(t--)ѭ�����棬Ƕ��һ��sort()��while(k--)
//��while(k--)�����erase()-->ʱ�临�Ӷ�Ϊ O(n)
//k �ķ�ΧΪ 1 <= k <= 99999,����д�ᳬʱ

//ǰ׺�Ϳ��Խ���������
//��ʱ�临�Ӷ�Ϊ O(n log n)
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

    //����ע��ǰ׺�ʹ� 1 ��ʼ������ n ������
    vector<ll> pre(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        pre[i] = pre[i - 1] + a[i - 1];
    }

    //ö��
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