from math import comb
from typing import List

def pairs(matrix: List[List[int]], length: int) -> int:
    result = 0

    for row in matrix:
        count = row.count('C')
        result += comb(count, 2)

    for col in range(length):
        count = 0
        for row in range(length):
            count += matrix[row][col] == 'C'
        result += comb(count, 2)

    return result

def main() -> None:
    length = int(input())
    matrix = [input() for _ in range(length)]
    print(pairs(matrix, length))

if __name__ == '__main__':
    main()