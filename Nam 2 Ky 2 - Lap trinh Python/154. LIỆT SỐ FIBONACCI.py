from typing import List

def fibonacci_list() -> List[int]:
    fib = [0] * 93
    fib[1] = 1
    for i in range(2, 93):
        fib[i] = fib[i - 1] + fib[i - 2]
    return fib

def run_test(fibonacci_sequence: List[int]) -> None:
    begin, end = map(int, input().split())
    print(*fibonacci_sequence[begin:end + 1])

def main() -> None:
    fibonacci_sequence = fibonacci_list()
    tests = int(input())
    for test in range(tests):
        run_test(fibonacci_sequence)

if __name__ == '__main__':
    main()