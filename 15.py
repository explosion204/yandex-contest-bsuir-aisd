def get_operations_count(seq):
    operations_count = 0
    max_value = seq[0]

    for i in range(1, len(seq)):
        if seq[i] > max_value:
            operations_count += seq[i] - max_value
            max_value = seq[i]

        elif seq[i] < seq[i - 1]:
            operations_count += seq[i - 1] - seq[i]

        seq[i - 1] = seq[i]

    return operations_count

N = int(input())
seq = list(map(int, input().split()))

print(get_operations_count(seq))