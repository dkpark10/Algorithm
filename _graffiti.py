from itertools import product

def discount(x):
  [percentage, price] = x
  return price * (100 - percentage) / 100

def solution(users, emoticons):
  answer = [0 ,0]
  temp = [0,0]
  discout = list(product([40, 30, 20, 10], repeat = len(emoticons)))

  for percentage in discout:
    discounted_price = list(map(discount, zip(percentage, emoticons)))
    temp = [0, 0]

    for user in users:
      pluscnt = 0
      price = 0

      for (idx, dp) in enumerate(discounted_price):
        if percentage[idx] >= user[0]:
          price += dp
      
      if price >= user[1]:
        pluscnt += 1
        price = 0

      temp[0] += pluscnt;
      temp[1] += price

    if temp[0] > answer[0]:
      answer = temp
    elif temp[1] > answer[1] and temp[0] == answer[0]:
      answer[1] = temp[1]

  return answer

# users = [[40, 2900], [23, 10000], [11, 5200], [5, 5900], [40, 3100], [27, 9200], [32, 6900]]
# emoticons = [1300, 1500, 1600, 4900]

# res1 = solution(users, emoticons)
# print(res1)

users = [[40, 10000], [25, 10000]]	
emoticons = [7000, 9000]	

res2 = solution(users, emoticons)
print(res2)