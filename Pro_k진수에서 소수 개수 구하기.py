import math

def trans(n, q):
  rev_base = ''
  while n > 0:
    n, mod = divmod(n, q)
    rev_base += str(mod)

  return rev_base[::-1] 

def isprime(n):
  if n == 1:
    return False;

  for i in range(2, int(math.sqrt(n)) + 1):
    if n % i == 0:
      return False
  return True

def solution(n, k):
  answer = 0
  transnum = trans(n,k).split('0')

  for ele in transnum:
    if ele and isprime(int(ele)) == True:
      answer += 1

  return answer
