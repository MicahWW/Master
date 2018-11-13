number = 20
cont = True
i = 0

divisiables = [20, 19, 18, 17, 16, 14, 13, 11]

while(cont):
	while(i<8):
#		print number
		if(number % divisiables[i] != 0):
			number += 2
			i = 0
		else:
			i += 1
#		print "Test {}".format(number)
	cont = False
print number
