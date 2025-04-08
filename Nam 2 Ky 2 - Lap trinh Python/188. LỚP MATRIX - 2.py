import sys
from typing import List

class Matrix:
    def __init__(self, data: List[int], rows: int, cols: int) -> None:
        self.data = data
        self.rows = rows
        self.cols = cols

    def multiply_with_transpose(self) -> 'Matrix':
        data: list[int] = []

        for row1 in range(self.rows):
            for row2 in range(self.rows):
                sum_value = 0
                for col in range(self.cols):
                    value1 = self.data[row1 * self.cols + col]
                    value2 = self.data[row2 * self.cols + col]
                    sum_value += value1 * value2
                data.append(sum_value)

        return Matrix(data, self.rows, self.rows)
    
    def print(self) -> None:
        for row in range(self.rows):
            for col in range(self.cols):
                value = self.data[row * self.cols + col]
                print(value, end=' ')
            print()

def main() -> None:
    inputs = sys.stdin.read().split()
    tests = int(inputs[0])
    i = 1

    for test in range(tests):
        rows, cols = map(int, inputs[i:(i + 2)])
        i += 2

        data = list(map(int, inputs[i: (i + rows * cols)]))
        matrix = Matrix(data, rows, cols)
        i += rows * cols

        matrix = matrix.multiply_with_transpose()
        matrix.print()

if __name__ == '__main__':
    main()