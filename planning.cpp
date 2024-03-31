#include<bits/stdc++.h>
using namespace std;

#define inf 0x7fffffff
#define M 201
int Dist[M],visit[M],n,path[M];

// def route_sgl(cur_map: Map, start: int, end: int, mode=0|1) -> list:
int* route_sgl(int m[][15],int start,int end,bool mode){
    // start 处理输入，根据mode转换为所需邻接表
    // 还没写
    // end
    int Min,Next;
    Dist[start]=0;
    visit[start]=0;
    while(start!=end){
        Min=inf;
        for(int i=0;i<n;i++){
            if(visit[i]&&m[start][i]!=inf){
                if(Dist[i]>m[start][i]+Dist[start]){
                    Dist[i]=m[start][i]+Dist[start];
                    path[i]=start;
                }
            }
            if(visit[i]&&Dist[i]<Min){
                Next=i;
                Min=Dist[i];
            }
        }
        if(Min==inf) break;
        start=Next;
        visit[start]=0;
    }
    //list.append+list.reverse然后返回列表
}

int main(){
    int n,m,i,j,a,b,dis,start,Min,next,targe;
    int Map[M][M];
    while(scanf("%d%d",&n,&m)==2){
        for(i=0;i<n;i++){
            visit[i]=1;
            Dist[i]=inf;
            for(j=0;j<n;j++)
                Map[i][j]=inf;
        }
        while(m--){
            scanf("%d%d%d",&a,&b,&dis);
            Map[a][b]=min(Map[a][b],dis);
            Map[b][a]=Map[a][b];
        }
        scanf("%d%d",&start,&targe);
        Dist[start]=0;
        visit[start]=0;
        while(start!=targe){
            Min=inf;
            for(i=0;i<n;i++){
                if(Map[start][i]!=inf)
                    Dist[i]=min(Dist[i],Map[start][i]+Dist[start]);
                if(visit[i]&&Dist[i]<Min){
                    next=i;
                    Min=Dist[i];
                }
            }
            if(Min==inf) break;
            start=next;
            visit[start]=0;
        }
        if(Dist[targe]==inf) puts("-1");
        else  printf("%d\n",Dist[targe]);
    }
    return 0;
}