def is_prime(n):
	if(n % 2 == 0):
		return False
	p = 3
	while(p < n**0.5+1):
		if(n % p == 0):
			return False
		p += 2
	return True





count = 6
num = 13
sum = 2 + 3 + 5 + 7 + 11 + 13

while(num < 2000000):
	num += 2

	if(is_prime(num)):
		sum += num

print sum
