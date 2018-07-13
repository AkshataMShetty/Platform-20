def print_even(num):
	ret = []
	for ele in range(0,num+1) :
		if (ele % 2) == 0 :
			ret.append(ele)
	return ret

x = input("enter the range:")
print print_even(x)

