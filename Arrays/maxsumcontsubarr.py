A = [-2, 1, -3, 4, -1, 2, 1, -5, 4]


accs = []
acc = 0
i = 0
while i < len(A):
    acc += A[i]
    accs.append(acc)
    if acc < 0:
        acc = 0
    i += 1

print(max(accs))

