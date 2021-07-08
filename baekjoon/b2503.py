# brute Force 숫자야구

num = int(input())

number = []
strike = []
ball = []
for i in range(num):
	temp = input()
	number.append([int(temp[0]),int(temp[1]),int(temp[2])])
	strike.append(int(temp[4]))
	ball.append(int(temp[6]))

available = []
for i in range(1,10):
	
	for j in range(1,10):
	
		if i == j :
			continue
		
		for k in range(1,10):
			if i == k or j == k:
				continue
			available.append([i,j,k])

for i in range(num):
	
	st = strike[i]
	b = ball[i]
	
	pop_element = []
	
	for element in available:
		
		ele_st = 0
		ele_b = 0
		
		for k in range(3):
			
			if element[k] == number[i][k]:
				ele_st += 1
			
			elif element[k] in number[i]:
				ele_b += 1
			
		if ele_st != st or ele_b != b:
			pop_element.append(element)
			continue

	available = [x for x in available if x not in pop_element]
	
print(len(available))
