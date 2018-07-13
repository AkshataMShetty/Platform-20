#To count vowels and consonants

def count_vowel_consonant(string) :
	index = 0
	vowel = 0
	consonant = 0
	vowels = 'aeiou'
	ret = []
	string = string.lower()

	for data in string :
		
		if data in vowels :
			vowel += 1
		else:
			consonant += 1

	ret.append(vowel)
	ret.append(consonant)

	return ret

x = raw_input("enter a string:")
print "[vowels , consonants]"
print count_vowel_consonant(x)
