from sys import stdin, stdout

# return (g, x, y) a*x + b*y = gcd(x, y)
def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, x, y = egcd(b % a, a)
        return (g, y - (b // a) * x, x)
    
def mulinv(b, n):
    g, x, _ = egcd(b, n)
    if g == 1:
        return x % n

def chineseRemainder(val = [], mod = []):
	bigMod = 1;
	for i in range(len(mod)):
		bigMod *= mod[i]
	
	ans = 0
	for i in range(len(mod)):
		ans += val[i] * bigMod / mod[i] * mulinv(bigMod / mod[i], mod[i])
	ans %= bigMod
	return ans

def solve(cur = 0, lst = [[]], mod = [], val = []):
	res = 0
	
	if cur == len(mod):
		res = chineseRemainder(val, mod)
		if (res <= 1):
			res = 0
	else:
		for x in range(len(lst[cur])):
			val.append(lst[cur][x])
			res += solve(cur+1, lst, mod, val)
			val.pop()
	
	return res
	
mod = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43]
lst = []
n = len(mod)

for x in mod:
	tmp = []
	for i in range(x):
		if i*i*i % x == 1:
			tmp.append(i)
	lst.append(tmp)

result = solve(0, lst,  mod, [])
	
stdout.write(str(result) + "\n")
