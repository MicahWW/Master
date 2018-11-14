count = 6
num = 13

while(count < 10001):
	divide = 2
	num += 2

	# there is no need to check divisbles that are multiples of 2, this checks two the loop then checks the rest
	if(num % divide != 0):
		divide += 1
	else:
		# prevents next loop from even starting
		divide = num + 1000


	while(divide < num):
		if(num % divide != 0):
			divide += 2
		else:
			# exits loop
			divide = num + 1000
	if(divide == num):
		count += 1

print count, num
