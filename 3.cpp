#include <iostream>
#include <vector>
#include <bits/stdc++.h>

#define MOD 1000000007

int main()
{
    int N, K;
    std::cin >> N >> K;

    std::vector<long long> seq;
    long long buffer;
    for (int i = 0; i < N; i++)
    {
        std::cin >> buffer;
        seq.push_back(buffer);
    }

    std::sort(seq.begin(), seq.end());

    long long result = 1;

    // all numbers are non-negative
    if (seq[0] >= 0)
    {
        for (int i = 0; i < K; i++)
        {
            result *= seq[N - 1 - i];
            result %= MOD;
        }
    }
    // all numbers are non-positive
    else if (seq[N - 1] <= 0)
    {
        if (K % 2 == 0)
        {
            for (int i = 0; i < K; i++)
            {
                result *= seq[i];
                result %= MOD;
            }
        }
        else
        {
            for (int i = 0; i < K; i++)
            {
                result *= seq[N - 1 - i];
                result %= MOD;
            }
        }
    }
    // mixed
    else
    {
        int i = 0, j = N - 1;

        while (K > 0)
        {
            if (K >= 2 && seq[i] * seq[i + 1] >= seq[j - 1] * seq[j])
            {
                result *= (seq[i] * seq[i + 1]) % MOD;
                result %= MOD;
                i += 2; K -= 2;
            }
            else
            {
                result *= seq[j];
                result %= MOD;
                j--; K--;
            }
        }
    }

    std::cout << (result + MOD) % MOD;

    return 0;
}
