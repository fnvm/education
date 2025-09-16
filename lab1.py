import math

pi = float(input("Введите значение числа π: "))

x = float(input("Введите x: "))
y = float(input("Введите y: "))

numerator = math.cos(x - (pi / 6))
denominator = (1 / 2) + 2 * (math.sin(y) ** 2) 
s = (numerator / denominator) * (1 + (x ** 2) / (2 * pi))

print("Результат s =", s)
