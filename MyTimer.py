import time as t

class MyTimer():
    def __init__(self):
        #增加一个列表，用来存放对应的年月日
        self.unit = ['年','月','日','小时','分钟','秒']
        
        self.prompt = "未计时开始"
        self.lasted = []
        
        #属性名begin,end和方法名start,调用时属性不会覆盖方法
        self.begin = 0      
        self.end = 0
        
    def __str__(self):
        return self.prompt

    __repr__ = __str__

    def __add__(self,other):
        prompt = "总共运行了"
        result = []
        for index in range(6):
            result.append(self.lasted[index] + other.lasted[index])
            if result[index]:
                prompt += (str(result[index]) + self.unit[index])
            return prompt
    
    #开始计时
    def start(self):
        self.begin = t.localtime()
        self.prompt = "请先调用stop()停止计时"
        print("计时开始。。。")

    #停止计时
    def stop(self):
        if not self.begin:
            print("请先调用start()开始计时")
        else:
            self.end = t.localtime()
            self._calc()
            print("计时结束。。。")

    #内部方法，计算运行时间
    def _calc(self):
        self.lasted = []
        self.prompt = "总共运行了多长时间"
        for index in range(6):
            self.lasted.append(self.end[index] - self.begin[index])
            #如果为0，则不显示，追加一个if的判断
            if self.lasted[index]:
                self.prompt += str(self.lasted[index]) + self.unit[index]
        #为下一轮计时初始化变量
        self.begin = 0
        self.end = 0

        print(self.prompt)
