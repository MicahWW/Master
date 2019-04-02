first = 1
second = 2

#start with 2 because of the second number starting out as 2
sum = 2

current = 0

while(current < 4000000):
	current = first + second

	if(current % 2 == 0):
		sum += current

	first = second
	second = current

print sum
