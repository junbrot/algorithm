# dp N을 사용해서 number 만들기

def solution(N, number):
    
	all_list = [[]]
	answer = 0
	for i in range(1,9):
	
		temp_list = []
		
		for j in range(1,i):
			bef_list = all_list[j]
			aft_list = all_list[i-j]
			
			for bef in bef_list:
				for aft in aft_list:
					temp_list.append(bef+aft)
					temp_list.append(bef-aft)
					temp_list.append(bef*aft)
					if bef!=0 and aft != 0:
						temp_list.append(bef//aft)
					
		
		temp_list.append(int(str(N)*i))
		temp_list = list(set(temp_list))
		all_list.append(temp_list)
		if number in temp_list :
			answer = i
			break
		
	if answer == 0:
		answer = -1
	    
	return answer
