import math

def run_test() -> None:
    a = int(input())
    b = int(input())
    print(math.gcd(a, b))

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()