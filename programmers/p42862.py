# 
def solution(n, lost, reserve):
    
	answer = 0
	answer = n - len(lost)
	
	lost = sorted(lost)

	for borrow in lost:
		
		if borrow in reserve:
			answer += 1
			continue
		
		front = borrow-1
		back = borrow+1
		
		front_possible = front in reserve and front not in lost
		back_possible = back in reserve and back not in lost
		
		if front_possible is False and back_possible:
			reserve.remove(back)
			answer += 1
		elif front_possible:
			reserve.remove(front)
			answer += 1
	
	return answer
