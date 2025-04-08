def main() -> None:
    binary = input()
    decimal = int(binary, 2)
    octal = f'{decimal:o}'
    print(octal)

if __name__ == '__main__':
    main()