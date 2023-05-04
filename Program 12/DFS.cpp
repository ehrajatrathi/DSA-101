#include<stdio.h>


int a[5][5] = {
		{0,1,1,0,1},
		{1,0,0,0,0},
		{1,0,0,1,0},
		{0,0,1,0,1},
		{1,0,0,0,0}
	};
int visited[5] = {0,0,0,0,0};

void DFS(int i){
	visited[i] = 1;
	printf("%d ", i);
	for(int j = 0; j < 5 ; j++){
		if(a[i][j] == 1 && !visited[j])
			DFS(j);
	}
}


int main(){
	DFS(2);
}
