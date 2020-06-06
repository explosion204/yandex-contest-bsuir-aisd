N = int(input())
A = list(map(int, input().split()))
A.sort()
print(max(A[0] * A[1], A[N-2] * A[N-1]))