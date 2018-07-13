lst = range(0,11)
print lst

for ele in lst :
	print ele

value = input("enter the value to be inserted at beginning:")
lst.insert(0,value)
print lst
	
pos = input("enter the position:")
value = input("enter the value:")
lst.insert(pos,value)
print lst

value = input("enter the value to be inserted at the end:")
lst.append(value)
print lst

pos = input("enter the pos to delete:")
del(lst[pos])
print lst


lst.remove(10)
print lst

print "length of list : ",len(lst)

