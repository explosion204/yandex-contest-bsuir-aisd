#include <iostream>
#include <vector>

#define MOD 1000000007

typedef std::vector<std::vector<long long>> Matrix;

Matrix multiply_matrices(Matrix A, Matrix B)
{
    int length = A.size();
    Matrix result = Matrix(length, std::vector<long long>(length, 0));

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            for (int k = 0; k < length; k++)
            {
                result[i][j] += (A[i][k] * B[k][j]) % MOD;
                result[i][j] %= MOD;
            }
        }
    }

    return result;
}

Matrix binary_power(Matrix matrix, long long power)
{
    int length = matrix.size();
    Matrix result = Matrix(length, std::vector<long long>(length, 0));

    for (int i = 0; i < length; i++)
    {
        result[i][i] = 1;
    }

    while (power > 0)
    {
        if (power % 2 == 1)
        {
            result = multiply_matrices(result, matrix);
            power -= 1;
        }
        else
        {
            matrix = multiply_matrices(matrix, matrix);
            power /= 2;
        }
    }

    return result;
}

int main()
{
    int N, M, U, V, A, B;
    long long L;

    std::cin >> N >> M;
    std::cin >> U >> V >> L;

    Matrix adjacency_matrix = Matrix(N, std::vector<long long>(N, 0));

    for (int i = 0; i < M; i++)
    {
        std::cin >> A >> B;

        if (A == B)
        {
            adjacency_matrix[A - 1][B - 1] += 2;
        }
        else
        {
            adjacency_matrix[A - 1][B - 1] += 1;
            adjacency_matrix[B - 1][A - 1] += 1;
        }
    }

    std::cout << binary_power(adjacency_matrix, L)[U - 1][V - 1];

    return 0;
}