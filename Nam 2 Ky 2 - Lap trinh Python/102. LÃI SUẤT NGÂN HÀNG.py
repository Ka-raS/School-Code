import math

def years_taken(deposit: float, interest: float, target: float) -> int:
    ratio = target / deposit
    percentage = interest / 100 + 1
    return math.ceil(math.log(ratio) / math.log(percentage))

def run_test() -> None:
    deposit, interest, target = map(float, input().split())
    print(years_taken(deposit, interest, target))

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()