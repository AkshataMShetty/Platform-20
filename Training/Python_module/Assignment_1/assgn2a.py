#script to generate prime numbers

def prime (num) :
	ret = []
	
	for n in range(2, num + 1) :
		for i in range(2, n) :
			if(n % i) == 0 :
				break;
		else :
			ret.append(n)
	
	return ret

print " Prime Numbers "
x = input ("Enter the range for prime number ")
print prime(x)

