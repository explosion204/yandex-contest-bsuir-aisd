N = int(input())
seq = list()
for i in range(N):
    seq.append(input().strip())

flag = False
if '1087388483' in seq:
    flag = True
elif '1052651' in seq and '1033' in seq:
    flag = True
elif '1054693' in seq and '1031' in seq:
    flag = True
elif '1065023' in seq and '1021' in seq:
    flag = True
elif '1033' in seq and '1031' in seq and '1021' in seq:
    flag = True 

if flag:
    print('YES')
else:
    print('NO')