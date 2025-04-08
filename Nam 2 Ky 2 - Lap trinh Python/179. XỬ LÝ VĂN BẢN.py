import re
import sys

def process(document: str) -> str:
    result = ''
    punctuation_marks = '[.?!]'
    sentences = re.split(punctuation_marks, document)
    
    for sentence in sentences:
        if sentence.isspace():
            continue

        sentence = sentence.strip().capitalize()
        sentence = re.sub('\s+', ' ', sentence)
        result += sentence + '\n'

    return result

def main() -> None:
    document = sys.stdin.read()
    document = process(document)
    print(document)

if __name__ == '__main__':
    main()