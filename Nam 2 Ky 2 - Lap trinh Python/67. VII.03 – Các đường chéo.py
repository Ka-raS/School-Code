def print_diagonal_matrix(size: int) -> None:
    for i in range(size):
        for j in range(size):
            print(abs(i - j), end=' ')
        print()

def main() -> None:
    matrix_size = int(input())
    print_diagonal_matrix(matrix_size)

if __name__ == '__main__':
    main()