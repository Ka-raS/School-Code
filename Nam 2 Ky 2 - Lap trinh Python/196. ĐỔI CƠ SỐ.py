NUMS = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'

def convert(decimal: int, to_base: int) -> str:
    result = ''
    while decimal != 0:
        result += NUMS[decimal % to_base]
        decimal //= to_base
    return result[::-1]

def run_test() -> None:
    decimal, to_base = map(int, input().split())
    print(convert(decimal, to_base))

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()