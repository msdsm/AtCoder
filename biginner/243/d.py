n, x = map(int, input().split())

s = input()

for i in range(n):
	if s[i]=='R':
		x = x*2 + 1
	elif s[i]=='L':
		x = 2*x
	else:
		x = x//2

print(x)