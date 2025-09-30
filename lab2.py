import math

x = float(input("Введите x: "))
y = float(input("Введите y: "))

print("Выберите функцию f(x):")
print("1: f(x) = cos(y)")
print("2: f(x) = e^(cos(x))")
print("3: f(x) = log10(x)")
choice = int(input("Ваш выбор (1/2/3): "))

if choice == 1:
    f = math.cos(y)
    print(f"\nВыбрана функция: f(x) = cos(y)")
elif choice == 2:
    f = math.e ** math.cos(x)
    print(f"\nВыбрана функция: f(x) = e^(cos(x))")
elif choice == 3:
    f = math.log10(x) if x > 0 else float('nan')
    print(f"\nВыбрана функция: f(x) = lg10(x)")
else:
    raise ValueError("Некорректный выбор функции")

if f > 0:
    d = (x**2 + f**2) / y
    print("D(f): f(x) > 0")
elif f < 0:
    d = math.log(abs(f**3)) + math.cos(f)
    print("D(f): f(x) < 0")
else:
    d = (math.sin(x)**2) ** (1/3)
    print("D(f): f(x) = 0")


print(f"Результат d = {d}")
