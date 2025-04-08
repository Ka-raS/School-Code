INTERPRETS = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ_.'

def encode(distance: int, code: str) -> str:
    result = ''
    for letter in code:
        position: int
        if letter == '_':
            position = 26
        elif letter == '.':
            position = 27
        else:
            position = ord(letter) - 65

        position = (position + distance) % 28
        new_letter = INTERPRETS[position]
        result += new_letter
    return result[::-1]

def main() -> None:
    while True:
        inputs = input().split()
        inputs[0] = int(inputs[0])
        if inputs[0] == 0:
            break
        print(encode(*inputs))

if __name__ == '__main__':
    main()