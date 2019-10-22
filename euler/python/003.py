number = 600851475143
i = 2

while(i < (number+1)):
	if(number % i == 0):
		print i
		number = number / i

	i += 1

