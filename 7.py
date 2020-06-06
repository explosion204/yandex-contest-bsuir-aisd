N, M, x1, y1, x2, y2 = list(map(int, input().split()))

if abs(x1 - x2) == abs(y1 - y2):
    print('NO')
else:
    print('YES')
