import sys

def main() -> None:
    length = int(input())
    begin = end = None
    max_sum = current_sum = float('-inf')

    for i, num in enumerate(map(int, sys.stdin.read().split())):
        if current_sum + num < num:
            current_sum = num
            begin = i
        else:
            current_sum += num

        if max_sum < current_sum:
            max_sum = current_sum
            end = i

    print(begin + 1, end + 1, max_sum)

if __name__ == '__main__':
    main()