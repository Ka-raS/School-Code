def main() -> None:
    binary = input()
    decimal = int(binary, 2)
    octal = oct(decimal)[2:]
    print(octal)

if __name__ == '__main__':
    main()