num1 = 100
num2 = 100
largest  = 0


cont = True

while(cont):
	result = num1 * num2
	result = str(result)
	if(len(result) == 6):
		if(result[0] == result[5] and result[1] == result[4] and result[2] == result[3]):
			if(result > largest):
				largest = result

	num2 += 1
	if(num2 >= 1000):
		num1 += 1
		num2 = 100
	if(num1 >= 1000):
		cont = False


print largest
