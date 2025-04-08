from typing import List, Tuple

def prime_map(limit: int) -> List[bool]:
    is_prime = [True] * limit
    is_prime[0] = is_prime[1] = False

    for i in range(2, int(limit ** 0.5) + 1):
        if is_prime[i]:
            for j in range(i ** 2, limit, i):
                is_prime[j] = False
    
    return is_prime

def find_max_prime(matrix: List[List[int]]) -> int:
    prime = 0
    IS_PRIME = prime_map(1001)
    
    for row in matrix:
        for number in row:
            if IS_PRIME[number]:
                prime = max(prime, number)
    
    return prime

def find_positions(matrix: List[List[int]], target: int) -> List[Tuple[int, int]]:
    positions: List[Tuple[int, int]] = []
    rows = len(matrix)
    columns = len(matrix[0])

    for row in range(rows):
        for column in range(columns):
            if matrix[row][column] == target:
                positions.append((row, column))
    
    return positions

def main() -> None:
    rows, columns = map(int, input().split())
    matrix = [
        list(map(int, input().split()))
        for row in range(rows)
    ]

    prime = find_max_prime(matrix)
    if prime:
        print(prime)
        positions = find_positions(matrix, prime)
        for row, column in positions:
            print(f'Vi tri [{row}][{column}]')
    else:
        print('NOT FOUND')

if __name__ == '__main__':
    main()