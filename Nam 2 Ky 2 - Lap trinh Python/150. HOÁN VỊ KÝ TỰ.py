import itertools

def main() -> None:
    keys = input()
    for permutation in itertools.permutations(keys):
        print(*permutation, sep='')

if __name__ == '__main__':
    main()