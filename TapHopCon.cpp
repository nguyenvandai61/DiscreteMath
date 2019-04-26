#include <stdio.h>

int n;
bool a[100];

void show(){
    for (int i=1; i<=n; i++)
    if (a[i]) 
    	printf("%d ", i);
    printf("\n");
}

void Try(int u){
    if (u==n+1) {
        show();
        return ;
    }
    a[u]=0;
    Try(u+1);
    a[u]=1;
    Try(u+1);
}

main(){
    scanf("%d", &n);
    Try(1);
}
