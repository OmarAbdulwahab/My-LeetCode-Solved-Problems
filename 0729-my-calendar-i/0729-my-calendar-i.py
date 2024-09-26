class MyCalendar:

    def __init__(self):
        self.booking = []
        

    def book(self, start: int, end: int) -> bool:
        if len(self.booking) == 0:
            self.booking.append([start, end])
            return True
        for b in self.booking:
            if not (b[1] <= start or end <= b[0]):
                return False
        self.booking.append([start, end])
        return True


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)