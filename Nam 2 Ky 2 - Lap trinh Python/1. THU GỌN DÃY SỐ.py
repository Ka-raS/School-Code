import typing

def get_input_array() -> typing.List[int]:
    length: int = int(input())
    return list(map(int, input().split()))

def find_reduce_array(array: typing.List[int]) -> typing.List[int]:
    reduced_array: typing.List[int] = []

    for number in array:
        if not reduced_array or (reduced_array[-1] + number) % 2 != 0:
            reduced_array.append(number)
        else:
            reduced_array.pop()

    return reduced_array

def main() -> None:
    input_array: typing.List[int] = get_input_array()
    reduced_array: typing.List[int] = find_reduce_array(input_array)
    print(len(reduced_array))

if __name__ == '__main__':
    main()