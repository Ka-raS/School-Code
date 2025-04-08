import math
from typing import List

def find_primes(bound: int) -> List[int]:
    is_prime = [1] * bound
    is_prime[0] = is_prime[1] = 0
    for i in range(2, math.isqrt(bound)):
        if is_prime[i]:
            for j in range(i ** 2, bound, i):
                is_prime[j] = 0
    return is_prime

def sort_prime(matrix: List[List[int]], rows: int, cols: int) -> None:
    is_prime = find_primes(1001)
    for r in range(rows):
        for c in range(cols):
            matrix[r][c] = is_prime[matrix[r][c]]

def main() -> None:
    rows, cols = map(int, input().split())
    matrix = [list(map(int, input().split())) for _ in range(rows)]

    sort_prime(matrix, rows, cols)
    for row in matrix:
        print(*row)

if __name__ == '__main__':
    main()