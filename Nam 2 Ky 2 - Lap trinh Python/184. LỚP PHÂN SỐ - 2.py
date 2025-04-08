import math

class Fraction:
    def __init__(self, dividend: int, divisor: int) -> None:
        self.dividend = dividend
        self.divisor = divisor

    def __str__(self) -> str:
        return f'{self.dividend}/{self.divisor}'
    
    def __add__(self, other: 'Fraction') -> 'Fraction':
        dividend = self.dividend * other.divisor + self.divisor * other.dividend
        divisor = self.divisor * other.divisor
        result = Fraction(dividend, divisor)
        result.simplify()
        return result

    def simplify(self) -> None:
        common_divisor = math.gcd(self.dividend, self.divisor)
        self.dividend //= common_divisor
        self.divisor //= common_divisor

def main() -> None:
    inputs = list(map(int, input().split()))
    a = Fraction(inputs[0], inputs[1])
    b = Fraction(inputs[2], inputs[3])
    print(a + b)

if __name__ == '__main__':
    main()