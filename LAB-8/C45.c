#include<stdio.h>

void main(){
    int t;
    scanf("%d",&t);

    while(t--){
        int n;
        scanf("%d",&n);

        int a[n],stack[n];
        int top=-1;

        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);

        int need=1;

        for(int i=0;i<n;i++){

            stack[++top]=a[i];

            while(top!=-1 && stack[top]==need){
                top--;
                need++;
            }
        }

        if(need==n+1)
            printf("YES\n");
        else
            printf("NO\n");
    }
}