import collections

def most_frequent(array, length) -> str:
    counter = collections.Counter(array)
    value, count = counter.most_common(1)[0]
    if count > length // 2:
        return value
    return 'NO'

def run_test() -> None:
    length = int(input())
    array = input().split()
    print(most_frequent(array, length))

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()