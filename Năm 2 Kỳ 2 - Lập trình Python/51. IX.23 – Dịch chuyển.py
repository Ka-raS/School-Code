import typing

def input_from_file(input_file: typing.TextIO) -> typing.List[typing.Tuple[int, int]]:
    count = int(input_file.readline())
    coordinates = [None] * count
    for i, line in enumerate(input_file):
        coordinates[i] = tuple(map(int, line.split()))
    return coordinates
        
def is_alignment(coordinates: typing.List[typing.Tuple[int, int]]) -> bool:
    # y = ax + b
    x1, y1 = coordinates[0]
    x2, y2 = coordinates[1]

    a = (y1 - y2) / (x1 - x2)
    b = y1 - a * x1

    for i in range(2, len(coordinates)):
        x, y = coordinates[i]
        if y != a * x + b:
            return False
    return True

def main() -> None:
    coordinates: typing.List[typing.Tuple[int, int]]
    with open('INPUT.txt', 'r') as input_file:
        coordinates = input_from_file(input_file)
    
    with open('OUTPUT.txt', 'w') as output_file:
        if is_alignment(coordinates)
            output_file.write('Yes')
        else:
            output_file.write('No')

if __name__ == '__main__':
    main()