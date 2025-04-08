import sys
from typing import List

class Complex:
    def __init__(self, a: int, b: int):
        self.a = a
        self.b = b

    def __str__(self) -> str:
        a, b = self.a, self.b
        if b < 0:
            return f'{a} - {-b}i'
        return f'{a} + {b}i'
    
    def __add__(self, other: 'Complex') -> 'Complex':
        a, b = self.a, self.b
        c, d = other.a, other.b
        return Complex(a + c, b + d)
    
    def __mul__(self, other: 'Complex') -> 'Complex':
        a, b = self.a, self.b
        c, d = other.a, other.b
        return Complex(a * c - b * d, a * d + b * c)

def main() -> None:
    inputs = sys.stdin.read().split()
    tests = int(inputs[0])
    i = 1

    for test in range(tests):
        a, b, c, d = map(int, inputs[i:i + 4])
        i += 4

        num1 = Complex(a, b)
        num2 = Complex(c, d)
        sum_value = num1 + num2

        ans1 = sum_value * num1
        ans2 = sum_value * sum_value
        print(f'{ans1}, {ans2}')        

if __name__ == '__main__':
    main()