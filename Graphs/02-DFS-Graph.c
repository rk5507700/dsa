#include<stdio.h>

/*
Graph
0         1
 \       /
  \     /
   \   /
    \ /
     2
    /
   /
   5 ----4
    \    |
     \   |
      \  |
       \ |
        3

*/
int visited[7] = {0, 0, 0, 0, 0, 0, 0};
int a[7][7] = {
        {0, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 1, 0},
        {0, 0, 0, 1, 0, 1, 0},
        {0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0}
};

void DFS(int i){
    printf("%d ", i);
    visited[i] = 1;
    for(int j = 0; j<7; j++){
        if(a[i][j] == 1 && !visited[j]){
            DFS(j);
        }
    }
}

int main(int argc, char const *argv[])
{
    DFS(3);
    return 0;
}
