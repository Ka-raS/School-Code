import sys

def main() -> None:
    upper_bound = int(sys.stdin.readline())
    not_visited = [True] * (upper_bound + 1)
    for _ in range(upper_bound - 1):
        not_visited[int(sys.stdin.readline())] = False

    for number in range(1, upper_bound + 1):
        if not_visited[number]:
            print(number, end=' ')

if __name__ == '__main__':
    main()