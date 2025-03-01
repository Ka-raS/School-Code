def fractions_sum(n: int) -> float:
    return sum(1 / i for i in range(2 - (n & 1), n + 1, 2))

def run_test() -> None:
    n = int(input())
    print(f"{fractions_sum(n):.6f}")

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()