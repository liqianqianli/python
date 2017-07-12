class Turtle:
    def __init__(self, x):
        self.num = x

class Fish:
    def __init__(self, y):
        self.num = y

class Pool:
    def __init__(self, x, y):
        self.turtle = Turtle(x)  #直接把需要的类实例化
        self.fish = Fish(y)

    def print_num(self):
        print("水池里总共有乌龟 %d 只，小鱼 %d 条" % (self.turtle.num, self.fish.num))
        
