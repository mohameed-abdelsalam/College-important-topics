#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int iSpartition(int size,int arr[size][size],int n,int identical[],int visited[]){

    for(int i=0 ; i<size ; i++)
        {
        for (int j=0; j<size; j++)
          {
            if(arr[i][j])
             {
              if (visited[j] == 0)
                 {
                visited[j] = 1;
                identical[j] = ! identical[i];
                 if (!iSpartition(size,arr,j,identical,visited))
                   return (0);
                 }
        else if (identical[j] == identical[i])
            return (0);
            }
         }
      }
    return 1;
}

int main()
{
    int x=0,y=0,z=0,m=0;
    scanf("%d",&x);
    scanf("%d",&y);
    int adj[x][x];
     for (int i = 0; i < x; i++){
            for (int j = 0; j < x; j++){
               adj[i][j]=0;
        }
    }

    for (int i=0 ; i<y;i++){
    scanf ("%d",&z);
    scanf ("%d",&m);
    z--;
    m--;
    adj[z][m]=1;
    adj[m][z]=1;
           }
    int visited[x];
    int identical[x];
memset(identical,-1,sizeof(identical));
memset(visited,0,sizeof(visited));


    visited[0]=1;
    identical[0]=1;

    if(iSpartition(x,adj,0,identical,visited)){
        printf("Yes");
    }else{
        printf("No");
    }
    return 0;
}
