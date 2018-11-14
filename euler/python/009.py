a = 1
b = 2
c = 3

cont = True

while(cont):
	if((a + b + c) == 1000):
		if((a**2 + b**2) == c**2):
			print a * b * c
			cont = False
		else:
			c += 1
	else:
		if(b < 997):
			if(c < 997):
				c += 1
			else:
				b += 1
				c = b + 1
		else:
			a += 1
			b = a + 1
			c = b + 1
