import sys

def bruh(number: int) -> int:
    for step in range(1000):
        if number % 7 == 0:
            return number
        number += int(f'{number}'[::-1])
    return -1

def run_test(inputs: str) -> None:
    number = int(inputs)
    print(bruh(number))

def main() -> None:
    sys.stdin.readline()
    for inputs in sys.stdin:
        run_test(inputs)

if __name__ == '__main__':
    main()