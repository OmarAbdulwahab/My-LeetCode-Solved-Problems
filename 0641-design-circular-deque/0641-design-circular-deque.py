class MyCircularDeque:

    def __init__(self, k: int):
        # left is inclusive, right is exclusive
        self.left = 0
        self.right = 0
        self.arr = [None] * (k+2)
        self.k = k

    def insertFront(self, value: int) -> bool:
        if self.isFull():
            return False
        
        self.left -= 1
        self.arr[self.left % len(self.arr)] = value
        return True

    def insertLast(self, value: int) -> bool:
        if self.isFull():
            return False
        
        self.arr[self.right % len(self.arr)] = value
        self.right += 1
        return True

    def deleteFront(self) -> bool:
        if self.isEmpty():
            return False
        
        self.arr[self.left % len(self.arr)] = None
        self.left += 1
        return True

    def deleteLast(self) -> bool:
        if self.isEmpty():
            return False
        
        self.right -= 1
        self.arr[self.right % len(self.arr)] = None
        return True

    def getFront(self) -> int:
        if self.isEmpty():
            return -1
        return self.arr[self.left % len(self.arr)]

    def getRear(self) -> int:
        if self.isEmpty():
            return -1
        return self.arr[(self.right - 1) % len(self.arr)]

    def isEmpty(self) -> bool:
        return (self.right - self.left) == 0

    def isFull(self) -> bool:
        return (self.right - self.left) == self.k


# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()