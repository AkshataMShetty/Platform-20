#to check the string is palindrome or not

def palindrome(string) :
	r_string = string[::-1]

	if string == r_string :
		return True
	else :
		return False

x = raw_input("enter a string :")

if True == palindrome(x) :
	print "string is palindrome"
else :
	print "string is not palindrome"
		
