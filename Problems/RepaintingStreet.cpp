#include <bits/stdc++.h>
using namespace std;

int t;
int n, k;
int col[100005];

int main()
{
    cin >> t;
    for (int test = 0; test < t; test++)
    {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &col[i]);
        }
        int best = INT_MAX;
        for (int j = 1; j <= 100; j++)
        {
            int start = 0;
            int counter = 0;
            while (start < n)
            {
                if (col[start] == j)
                {
                    start++;
                    continue;
                }
                start += k;
                counter++;
            }
            best = min(best, counter);
        }
        printf("%d\n", best);
    }
}