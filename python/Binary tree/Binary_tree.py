def func(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return n*func(n-1)


a = func(5)
print(a)