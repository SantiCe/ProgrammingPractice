#include<stdio.h>
int ar[10005];
int n,m,ma,i,j;
int max(int num1, int num2)
{
   /* local variable declaration */
   int result;

   if (num1 > num2)
      result = num1;
   else
      result = num2;

   return result;
}

int main(){
    scanf("%d",n);
    while(n!= 0){
        ma = -10000005;
        i = 0;
        while(i < n){
            scanf("%d",m);
            ar[i] = m;
            if(i > 0) ar[i]+=ar[i-1];
            //cout << i << " " << ar[i] << endl;
            ma = max(ma,ar[i]);
            j = 0;
            for(j = 0; j < i; j ++){
                ma = max(ma,ar[i]-ar[j]);
            }
            i++;
        }
        if(ma > 0) printf("The maximum winning streak is %d .\n",ma);
        else printf("Losing streak.\n");
        scanf("%d",n);
    }
}
