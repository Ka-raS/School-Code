from datetime import (
    datetime,
    timedelta
)

class Customer:
    def __init__(self: 'Customer', id: str, name: str, duration: timedelta) -> None:
        self.id = id
        self.name = name
        self.duration = duration
    
    def __str__(self: 'Customer') -> str:
        hour = self.duration.seconds // 3600
        minute = self.duration.seconds // 60 % 60
        return f'{self.id} {self.name} {hour} gio {minute} phut'

def main() -> None:
    customers: list[Customer] = []
    customer_count = int(input())

    for _ in range(customer_count):
        id = input()
        name = input()

        begin = datetime.strptime(input(), '%H:%M')
        end = datetime.strptime(input(), '%H:%M')
        duration = end - begin

        customer = Customer(id, name, duration)
        customers.append(customer)

    customers.sort(key=lambda customer: -customer.duration)
    for customer in customers:
        print(customer)

if __name__ == '__main__':
    main()