class Tree:
    def __init__(self, start, end):
        self.right = None
        self.left = None
        self.start = start
        self.end = end
        
    def insert(self, start, end):
        cur = self
        while True:
            if start >= cur.end:
                if not cur.right:
                    cur.right = Tree(start, end)
                    return True
                cur = cur.right
            elif end <= cur.start:
                if not cur.left:
                    cur.left = Tree(start, end)
                    return True
                cur = cur.left
            else:
                return False
        
class MyCalendar:
    def __init__(self):
        self.root = None
        
    def book(self, start: int, end: int) -> bool:
        if not self.root:
            self.root = Tree(start, end)
            return True
        return self.root.insert(start, end)


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)