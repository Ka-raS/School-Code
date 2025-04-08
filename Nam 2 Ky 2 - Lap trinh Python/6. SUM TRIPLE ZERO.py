import typing

def sum_triple_zero(array: typing.List[int], length: int) -> int:
    count: int = 0
    map: typing.Dict[int, int] = {}

    for i in range(length - 1):
        for j in range(i + 1, length):
            value = -(array[i] + array[j])
            count += map.get(value, 0)

        map[array[i]] = map.get(array[i], 0) + 1
    
    return count

def run_test() -> None:
    length: int = int(input())
    array: typing.List[int] = list(map(int, input().split()))
    print(sum_triple_zero(array, length))

def main() -> None:
    tests: int = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()