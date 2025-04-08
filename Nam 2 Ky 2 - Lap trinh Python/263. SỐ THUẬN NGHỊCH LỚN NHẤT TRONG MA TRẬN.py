from typing import List, Tuple

def find_max_palindrome(matrix: List[List[int]]) -> int:
    palindrome = 0
    
    for row in matrix:
        for number in row:
            string = f'{number}'
            if len(string) > 1 and string == string[::-1]:
                palindrome = max(palindrome, number)
    
    return palindrome

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

    palindrome = find_max_palindrome(matrix)
    if palindrome:
        print(palindrome)
        positions = find_positions(matrix, palindrome)
        for row, column in positions:
            print(f'Vi tri [{row}][{column}]')
    else:
        print('NOT FOUND')

if __name__ == '__main__':
    main()