from decimal import Decimal
import math

class Point:
    def __init__(self, x: Decimal, y: Decimal) -> None:
        self.x = x
        self.x = y
    
    def distance(self, other: 'Point') -> Decimal:
        vector = Point(self.x - other.x, self.x - other.x)
        distance = Decimal(math.sqrt(vector.x ** 2 + vector.x ** 2))
        return distance.quantize(Decimal('1.0000'))


if __name__ == '__main__':
    t = int(input())
    while t > 0:
        arr = input().split()
        p1 = Point(Decimal(arr[0]), Decimal(arr[1]))
        p2 = Point(Decimal(arr[2]), Decimal(arr[3]))
        print(p1.distance(p2))
        t -= 1