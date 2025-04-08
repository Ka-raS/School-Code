from typing import Iterable

def find_winner(contestants: Iterable[int]) -> int:
    max_count = 0
    winner = float('inf')
    counter = [0] * 1001

    for contestant in contestants:
        counter[contestant] += 1
        count = counter[contestant]

        if max_count < count or max_count == count and winner > contestant:
            winner = contestant
            max_count = count
    
    return winner

def run_test() -> None:
    count = int(input())
    contestants = [int(input()) for _ in range(count)]
    print(find_winner(contestants))

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()