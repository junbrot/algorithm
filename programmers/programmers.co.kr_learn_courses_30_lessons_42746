def check(n1: str, n2: str):
	return n1+n2 < n2+n1

def solution(numbers):
	
	arr = [str(x) for x in numbers]
	arr.sort(reverse = True)
	
	for i in range(1,len(arr)):
		idx = i
		while(idx > 0 and check(arr[idx-1],arr[idx])):
			arr[idx-1],arr[idx] = arr[idx],arr[idx-1]
			idx-=1
				
	return str(int(''.join(arr)))
	
print(solution([3,30,34,5,9]))
