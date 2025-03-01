import typing
import heapq

def sum_three_mins(array: typing.List[int]) -> int:
    three_mins: typing.List[int] = heapq.nsmallest(3, array)
    return sum(three_mins)

def run_test() -> None:
    length: int = int(input())
    array: typing.List[int] = list(map(int, input().split()))
    print(sum_three_mins(array))

def main() -> None:
    for _ in range(int(input())):
        run_test()

if __name__ == '__main__':
    main()