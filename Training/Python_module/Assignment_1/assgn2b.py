#script to print armstrong number between 1 to 500

def armstrong(num):
	
	i = 1
	ret = []

	while i <= num :
		temp = i
		s = 0

		while temp != 0 :
			res = temp % 10
			temp = temp / 10
			s = s + (res ** 3)

		if s == i :
			ret.append(i)

		i += 1
	return ret

print " armstrong number "
print armstrong(500)
