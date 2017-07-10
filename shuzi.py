import random
secret = random.randint(1,10)
print(",,,,,,,,,,我爱鱼c工作室,,,,,,,,,")
temp = input("猜数字：")
guess = int(temp)
while guess !=secret:
    temp = input("猜错了请重新输入")
    guess = int(temp)
    if guess == secret:
        print("你真是太聪明了")
    else:
        if guess > secret:
            print("嘿嘿，大了")
        else:
            print("哎呦，小了")
print("游戏结束，不玩啦")
