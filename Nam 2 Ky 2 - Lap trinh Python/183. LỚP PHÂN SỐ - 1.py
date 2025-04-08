import math

class Fraction:
    def __init__(self, string: str) -> None:
        self.dividend, self.divisor = map(int, string.split())

    def __str__(self) -> str:
        return f'{self.dividend}/{self.divisor}'
    
    def simplify(self) -> None:
        common_divisor = math.gcd(self.dividend, self.divisor)
        self.dividend //= common_divisor
        self.divisor //= common_divisor

def main() -> None:
    fraction = Fraction(input())
    fraction.simplify()
    print(fraction)

if __name__ == '__main__':
    main()