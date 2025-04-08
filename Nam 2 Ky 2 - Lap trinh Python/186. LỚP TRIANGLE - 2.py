import sys
import math
from typing import List

class Vector2:
    def __init__(self, x: int, y: int) -> None:
        self.x = x
        self.y = y

    def distance(self) -> float:
        x, y = self.x, self.y
        return math.sqrt(x ** 2 + y ** 2)

class Triangle:
    def __init__(self, A: Vector2, B: Vector2, C: Vector2) -> None:
        self.A = A
        self.B = B
        self.C = C

    def __bool__(self) -> bool:
        A, B, C = self.A, self.B, self.C
        return A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y) != 0

    def heron_formula(self) -> float:
        A, B, C = self.A, self.B, self.C

        AB = Vector2(A.x - B.x, A.y - B.y).distance()
        AC = Vector2(A.x - C.x, A.y - C.y).distance()
        BC = Vector2(B.x - C.x, B.y - C.y).distance()

        S = (AB + AC + BC) / 2
        return math.sqrt(S * (S - AB) * (S - AC) * (S - BC))

def run_test(inputs: List[str]) -> None:
    Ax, Ay, Bx, By, Cx, Cy = map(float, inputs)
    A = Vector2(Ax, Ay)
    B = Vector2(Bx, By)
    C = Vector2(Cx, Cy)

    ABC = Triangle(A, B, C)
    if ABC:
        print(f'{ABC.heron_formula():.2f}')
    else:
        print('INVALID')

def main() -> None:
    inputs = sys.stdin.read().split()

    i = 1
    tests = int(inputs[0])
    for test in range(tests):
        run_test(inputs[i:i + 6])
        i += 6

if __name__ == '__main__':
    main()