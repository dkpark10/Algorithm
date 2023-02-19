weight = [
  [ 1, 7, 6, 7, 5, 4, 5, 3, 2, 3 ],
  [ 7, 1, 2, 4, 2, 3, 5, 4, 5, 6 ],
  [ 6, 2, 1, 2, 3, 2, 3, 5, 4, 5 ],
  [ 7, 4, 2, 1, 5, 3, 2, 6, 5, 4 ],
  [ 5, 2, 3, 5, 1, 2, 4, 2, 3, 5 ],
  [ 4, 3, 2, 3, 2, 1, 2, 3, 2, 3 ],
  [ 5, 5, 3, 2, 4, 2, 1, 5, 3, 2 ],
  [ 3, 4, 5, 6, 2, 3, 5, 1, 2, 4 ],
  [ 2, 5, 4, 5, 3, 2, 3, 2, 1, 2 ],
  [ 3, 6, 5, 4, 5, 3, 2, 4, 2, 1 ]
]

pad = [
  [3,1],
  [0,0],
  [0,1],
  [0,2],
  [1,0],
  [1,1],
  [1,2],
  [2,0],
  [2,1],
  [2,2],
]

dp = [[[-1 for _ in range(10)] for _ in range(10)] for _ in range(12)]

def touch(current:int, left:int, right:int, numbers):
  if current >= len(numbers):
    return 0

  ref = dp[current][left][right]
  if ref != -1:
    return ref;

  number = int(numbers[current])

  def calcost(hand: str):
    if hand == 'l':
      return weight[left][number]
    return weight[right][number]

  if left == number or right == number:
    dp[current][left][right] = 1 + touch(current + 1, left, right, numbers)
    return dp[current][left][right]

  lcost = touch(current + 1, number, right, numbers) + calcost('l')
  rcost = touch(current + 1, left, number, numbers) + calcost('r')

  dp[current][left][right] = min(lcost, rcost)
  return dp[current][left][right]

def solution(numbers):
  return touch(0,4,6, numbers)

res1 = solution("1756")
print(res1)
res2 = solution("5123")
print(res2)

# 오른손 엄지로 5, 왼손 엄지로 123을 누르거나 오른손 엄지로 5, 왼손 엄지로 1, 오른손 엄지로 23을 누르면 가중치 8로 최소입니다.