from typing import List

class Matrix:
    def __init__(self, data: List[List[int]]) -> None:
        self.data = data
        self.rows = len(self.data)
        self.cols = len(self.data[0])

    def __str__(self) -> str:
        return '\n'.join(' '.join(map(str, row)) for row in self.data)

    def multiply_with_transpose(self) -> 'Matrix':
        data: list[list[int]] = [[None for _ in range(self.rows)] for _ in range(self.rows)]

        for i in range(self.rows):
            for j in range(self.rows):
                sum_value = 0
                for value1, value2 in zip(self.data[i], self.data[j]):
                    sum_value += value1 * value2
                data[i][j] = sum_value

        return Matrix(data)

def run_test() -> None:
    rows, cols = map(int, input().split())
    matrix = Matrix([list(map(int, input().split())) for _ in range(rows)])
    matrix = matrix.multiply_with_transpose()
    print(matrix)

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()