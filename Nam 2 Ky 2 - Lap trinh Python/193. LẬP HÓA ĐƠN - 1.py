from typing import List

def water_price(number: int) -> int:
    if number <= 50:
        return number * 102
    if number <= 100:
        return round(number * 150 * 1.03 - 2575)
    return number * 210 - 7875

class Receipt:
    def __init__(self, id: str, name: str, begin: int, end: int) -> None:
        self.id = id
        self.name = name
        self.price = water_price(end - begin)

    def __str__(self) -> str:
        return f'{self.id} {self.name} {self.price}'

def main() -> None:
    receipts: list[Receipt] = []
    receipt_count = int(input())

    for index in range(1, receipt_count + 1):
        id = f'KH{index:02}'
        name = input()
        begin = int(input())
        end = int(input())
        receipts.append(Receipt(id, name, begin, end))

    receipts.sort(key=lambda receipt: -receipt.price)
    for receipt in receipts:
        print(receipt)

if __name__ == '__main__':
    main()