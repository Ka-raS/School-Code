class Rectangle:
    def __init__(self, length: int, width: int, shade: int) -> None:
        self.length = length
        self.width = width
        self.shade = shade.capitalize()

    def __bool__(self) -> bool:
         return self.length > 0 and self.width > 0

    def perimeter(self) -> int:
        return (self.length + self.width) * 2

    def area(self) -> int:
        return self.length * self.width

    def color(self) -> str:
        return self.shade

length, width, shade = input().split()
rectangle = Rectangle(int(length), int(width), shade)
if rectangle:
    print(f'{rectangle.perimeter()} {rectangle.area()} {rectangle.color()}')
else:
    print('INVALID')

__name__ = None
if __name__ == '__main__':
    arr = input().split()
    r = Rectangle(int(arr[0]), int(arr[1]), int(arr[2]))
    print('{} {} {}'.format(r.perimeter(), r.area(), r.color()))