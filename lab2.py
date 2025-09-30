import math

x = float(input("Введите x: "))
y = float(input("Введите y: "))

print("Выберите функцию f(x):")
print("1: f(x) = sh(x)")
print("2: f(x) = e^x")
print("3: f(x) = x^2")
choice = int(input("Ваш выбор (1/2/3): "))

if choice == 1:
    f = math.sinh(x)
    print("\nВыбрана функция: f(x) = sh(x)")
elif choice == 2:
    f = math.exp(x)
    print("\nВыбрана функция: f(x) = e^x")
elif choice == 3:
    f = x**2
    print("\nВыбрана функция: f(x) = x^2")

if y == 0:
    e = 0
    print("Случай: y = 0")
elif x == 0:
    e = (f**2 + y)**3
    print("Случай: x = 0")
elif (x / y) > 0:
    e = math.log(f) + (f**2 + y)**3
    print("Случай: x/y > 0")
elif (x / y) < 0:
    e = math.log(abs(f / y)) + (f + y)**3
    print("Случай: x/y < 0")

print(f"Результат e = {e}")
