from typing import List

def convert(matrix: List[List[int]], rows: int, columns: int) -> None:
    if rows > columns:
        new_row = 0
        remove = set(range(0, (rows - columns) * 2, 2))
        
        for row in range(rows):
            if row not in remove:
                matrix[new_row] = matrix[row]
                new_row += 1

        del matrix[new_row:]

    elif rows < columns:
        new_column = 0
        remove = set(range(1, (columns - rows) * 2, 2))
        
        for column in range(columns):
            if column not in remove:
                for row in matrix:
                    row[new_column] = row[column]
                new_column += 1
        
        for row in matrix:
            del row[new_column:]

def main() -> None:
    rows, columns = map(int, input().split())
    matrix = [
        list(map(int, input().split()))
        for row in range(rows)
    ]
    
    convert(matrix, rows, columns)
    for row in matrix:
        print(*row)


if __name__ == '__main__':
    main()