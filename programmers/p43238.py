import numpy as np

def solution(n,times):
    
    times.sort()
    times = np.array(times)
    raw = len(times)
    
    left = 1
    right = n*times[-1]
    
    min_time = right
    
    while 1:
    	
    	mid = int((left + right)/2)
    	temp = times
    	
    	temp = mid/temp
    	temp = [int(x) for x in temp]
    	
    	
    	if sum(temp) < n:
    		left = mid+1
    	else:
    		
    		if  min_time > mid:
    			min_time = mid
    		
    		right = mid-1
    		
    	if left > right :
    		break
    	
    
    return min_time

times = [1,2,3,6]
print(solution(19,times))

