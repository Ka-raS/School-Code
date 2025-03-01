import math

def run_test() -> None:
    number = input()
    if math.gcd(int(number), int(number[::-1])) == 1:
        print('YES')
    else:
        print('NO')

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()