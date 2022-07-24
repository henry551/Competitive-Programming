#include <bits/stdc++.h>
using namespace std;

int highest_bit(int num)
{
    return 32 - __builtin_clz(num);
}

int n;
int num[100005];
int psa[65];

// a and b inclusive (1-indexed)
int xor_range(int a, int b)
{
    return psa[a - 1] ^ psa[b];
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    int prev[3] = {-1, -1, -1};
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        prev[0] = prev[1];
        prev[1] = prev[2];
        prev[2] = highest_bit(num[i]);
        if (prev[0] == prev[1] && prev[1] == prev[2])
        {
            ans = 1;
            break;
        }
    }
    if (ans == INT_MAX)
    {
        for (int i = 0; i < n; i++)
        {
            psa[i + 1] = psa[i] ^ num[i];
        }
        for (int k = 2; k <= n; k++)
        {
            for (int i = 1; i < k; i++)
            {
                for (int j = k; j <= n; j++)
                {
                    if (xor_range(i, k - 1) > xor_range(k, j))
                    {
                        ans = min(ans, (j - k) + (k - 1 - i));
                    }
                }
            }
        }
    }
    if (ans == INT_MAX)
        printf("-1\n");
    else
        printf("%d\n", ans);
    return 0;
}