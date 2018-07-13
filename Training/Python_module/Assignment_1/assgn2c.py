#script to generate fibonacci series

def fibonacci(num) :
	ret = []
	first = 0
	second = 1
	next_num = 0

	ret.append(first)
	ret.append(second)

	for n in range(1 , num + 1) :
		next_num = first + second
		first = second
		second = next_num

		if next_num > num :
			break
		else :
			ret.append(next_num)

	return ret



x = input("print the range of fibonacci series")

print fibonacci(x)
