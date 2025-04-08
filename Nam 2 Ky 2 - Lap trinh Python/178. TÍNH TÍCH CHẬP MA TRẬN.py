from typing import List

def convolution_sum(image: List[List[int]], kernel: List[List[int]]) -> int:
    result = 0
    
    image_rows = len(image)
    image_cols = len(image[0])

    for i in range(image_rows - 2):
        for j in range(image_cols - 2):
            for ker_col in range(3):
                for ker_row in range(3):
                    result += image[i + ker_row][j + ker_col] * kernel[ker_row][ker_col]

    return result

def run_test() -> None:
    image_rows, image_cols = map(int, input().split())
    image = [list(map(int, input().split())) for _ in range(image_rows)]
    kernel = [list(map(int, input().split())) for _ in range(3)]

    print(convolution_sum(image, kernel))

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()