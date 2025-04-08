from typing import List

def potential_cases(case_matrix: List[List[int]], rows: int, columns: int) -> int:
    infected: list[tuple[int, int]] = []

    for row in range(rows):
        for column in range(columns):
            if case_matrix[row][column] == -1:
                infected.append((row, column))

    case_count = 0    
    DIRECTIONS = ((-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1))

    for infected_row, infected_column in infected:
        for direction_row, direction_column in DIRECTIONS:
            row = infected_row + direction_row
            column = infected_column + direction_column

            if row >= 0 and column >= 0 and row < rows and column < columns:
                case_count += case_matrix[row][column]
                case_matrix[row][column] = 0

    return case_count

def main() -> None:
    rows, columns = map(int, input().split())
    case_matrix = [
        list(map(int, input().split()))
        for row in range(rows)
    ]
    print(potential_cases(case_matrix, rows, columns))

if __name__ == '__main__':
    main()