while True:
    try:
        a10 = int(input('Целое число: '))
        system = int(input('Система счисления: '))
        break
    except(ValueError, TypeError):
        print('Введите другое значение')

def one(x):
    a2 = ''
    while x > 0:
        a2 = str(x%2) + a2
        x //= 2
    return a2

def two(x):
    a8 = ''
    while x > 0:
        a8 = str(x%8) + a8
        x//= 8
    return a8

if system == 2:
    print(a10, one(a10))
elif system == 8:
    print(a10, two(a10))
else:
    print('Неверная система счисления')