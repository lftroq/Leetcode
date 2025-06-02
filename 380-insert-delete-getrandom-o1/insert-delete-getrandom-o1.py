class RandomizedSet:

    def __init__(self):
        self.list = []
        self.dict = {}

    def insert(self, val: int) -> bool:
        if val in self.dict:
            return False
        self.dict[val] = len(self.list)
        self.list.append(val)
        return True

    def remove(self, val: int) -> bool:
        if val not in self.dict:
            return False
        x = self.list[-1]
        idx = self.dict[val]
        self.list[idx] = x
        self.dict[x] = idx
        self.list.pop()
        del self.dict[val]
        return True

    def getRandom(self) -> int:
        return random.choice(self.list)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
