// 크루스칼 알고리즘 사용
// 가중치가 낮은 간선 순으로 sorting
// 사이클이 없게 하기 위해 union-find 알고리즘 사용

// 서로 부모가 다른 정점을 연결할 때 -> 한 노드의 부모의 부모값을 다른 노드의
// 부모값으로 바꿔주면 빠름

// 부모를 찾는 과정에서, 그 부모와 연결되어 있는 노드들의 부모값을 업데이트

// kruskal 알고리즘은 greedy method.
// 시간 복잡도 : O(Elog2^E)
// 적은 숫자의 간선을 가지는 그래프에 

int V,E;
vector<vector<int>> v;
vector<int> parent;

bool compare(vector<int> a, vector<int> b )
{ 
	return a[2] < b[2]; 
}

int endCheck()
{
	int parent_check = parent[1];
	for(int i=2; i<=V; i++)
	{
		if(parent_check != parent[i])
			return 0;
	}
	return 1;
}

int findParent(int i)
{
	if(parent[i] == i)
		return i;
	else
		return parent[i] = findParent(parent[i]);
}

void kr()
{
	long int final_length = 0;
	for(int i=0; i<v.size(); i++)
	{
		if(endCheck())
			break;
	
		int now_node = v[i][0];
		int next_node = v[i][1];
		int length = v[i][2];
		
		int nowParent = findParent(now_node);
		int nextParent = findParent(next_node);
		
		if(nowParent == nextParent)
			continue;
		else
		{
			parent[nextParent] = nowParent;
			final_length += length;
		}
	}
	printf("%d\n",final_length);
}

int main() {
	
	scanf("%d %d",&V,&E);
	v.resize(E);
	parent.resize(V+1);
	
	for(int i=1; i<=V; i++)
		parent[i] = i;
	
	for(int i=0; i<E; i++)
	{
		int f,s,t;
		scanf(" %d %d %d",&f,&s,&t);
		
		vector<int> temp_v;
		temp_v.push_back(f);
		temp_v.push_back(s);
		temp_v.push_back(t);
		
		v[i] = temp_v;
	}
	
	sort(v.begin(),v.end(),compare);
	kr();
	
	return 0;
}
