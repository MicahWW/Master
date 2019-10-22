sum_of_squares = 0
square_of_sum = 0
sum_temp = 0

for i in range(1, 101):
	sum_of_squares += i * i

for i in range(1, 101):
	sum_temp += i

square_of_sum = sum_temp * sum_temp

print (square_of_sum - sum_of_squares)
