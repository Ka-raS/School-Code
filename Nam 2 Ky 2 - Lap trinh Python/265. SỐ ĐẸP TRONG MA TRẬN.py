from typing import List, Tuple

def min_max_distance(matrix: List[List[int]]) -> int:
    min_number = float('inf')
    max_number = float('-inf')
    
    for row in matrix:
        min_number = min(min_number, min(row))
        max_number = max(max_number, max(row))
    
    return max_number - min_number

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

    distance = min_max_distance(matrix)
    positions = find_positions(matrix, distance)
    if positions:
        print(distance)
        for row, column in positions:
            print(f'Vi tri [{row}][{column}]')
    else:
        print('NOT FOUND')

if __name__ == '__main__':
    main()