from typing import List

def find_discrepancy(matrix: List[List[int]], length: int) -> int:
    sum_up = sum_down = 0

    for r in range(length):
        bound = length - r - 1

        for c in range(length):
            if c > bound:
                sum_up += matrix[r][c]
            elif c < bound:
                sum_down += matrix[r][c]

    return abs(sum_up - sum_down)

def main() -> None:
    length = int(input())
    matrix = [list(map(int, input().split())) for _ in range(length)]
    balance_threshold = int(input())

    discrepancy = find_discrepancy(matrix, length)
    is_balanced = discrepancy <= balance_threshold
    if is_balanced:
        print('YES')
    else:
        print('NO')
    print(discrepancy)

if __name__ == '__main__':
    main()