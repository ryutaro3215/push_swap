import random

# 0から499までの数字のリストを生成
numbers = list(range(100))

# リストをランダムに並び替えて順列を生成
random.shuffle(numbers)

# 生成された順列をスペースで区切って出力
print(' '.join(map(str, numbers)))
