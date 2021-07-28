import numpy as np

def dfs(tickets,stack):
	
	if len(tickets) == 0:
		return 1
	
	else:
		
		last = stack[-1]
		for i in range(len(tickets)):
			
			if tickets[i][0] == last:

				next = tickets[i][1]
				stack.append(next)
				temp_tickets = tickets.copy()
				del(temp_tickets[i])

				if dfs(temp_tickets,stack) == 1:
					return 1
				stack.pop()
			
	return 0
	
def solution(tickets):
	
	tickets.sort()
	stack = []
	stack.append('ICN')
	
	dfs(tickets,stack)
	
	answer = stack
	return answer


a = [["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], ["ATL", "ICN"], ["ATL","SFO"]];
solution(a);
