import collections

def run_test() -> None:
    length, rotations = map(int, input().split())
    numbers = collections.deque(map(int, input().split()))
    
    for rotation in range(rotations):
        numbers.append(numbers.popleft())

    print(*numbers)

def main() -> None:
    tests: int = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()