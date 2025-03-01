import typing

def main() -> None:
    strings: typing.Set[str] = {}
    count: int = int(input())
    for _ in range(count):
        strings.add(input())
    print(len(strings))

if __name__ == '__main__':
    main()