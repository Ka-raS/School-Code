import sys

def main() -> None:
    max_first = max_second = float('-inf')
    
    contestant_count = int(sys.stdin.readline())
    for test in range(contestant_count):
        contestant_score = int(sys.stdin.readline())

        if contestant_score <= max_second:
            continue
        if contestant_score >= max_first:
            max_first, max_second = contestant_score, max_first
        else:
            max_second = contestant_score

    print(f'Silver = max_second')

if __name__ == '__main__':
    main()