import sys

def count_collatz(number: int) -> int:
    count = 1
    while number > 1:
        count += 1
        if number % 2 == 0:
            number //= 2
        else:
            number = number * 3 + 1
    return count

def run_test(inputs: str) -> None:
    number = int(inputs)
    print(count_collatz(number))

def main() -> None:
    for inputs in sys.stdin:
        if inputs == '0\n':
            break
        run_test(inputs)

if __name__ == '__main__':
    main()