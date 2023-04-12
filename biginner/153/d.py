n = int(input())
ans = 2
while n > 1 :
	n//=2
	ans*=2
ans-=1
print(ans)