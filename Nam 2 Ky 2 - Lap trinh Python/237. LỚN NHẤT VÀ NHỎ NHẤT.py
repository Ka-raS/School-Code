def main() -> None:
    while True:
        length = int(input())
        if length == 0:
            break

        numbers = tuple(int(input()) for _ in range(length))
        min_number = min(numbers)
        max_number = max(numbers)

        if min_number != max_number:
            print(min_number, max_number)
        else:
            print('BANG NHAU')

if __name__ == '__main__':
    main()