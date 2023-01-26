#include<iostream>
using namespace std;
    void sort012(int a[], int *n)
    {
        int n1=0,n2=0,n3=0;
        for(int i=0;i<*n;i++){
            if(a[i]==1){
                n1++;
            }
             if(a[i]==0){
                n2++;
            }
             if(a[i]==2){
                n3++;
            }
        }int i=0;
        while(n2!=0){
            a[i]=0;
            i++;
            n2--;
        } i=n2-1;
        while(n1!=0){
            a[i]=1;
            i++;
            n1--;
        }
         i=n2+n1-1;
        while(n3!=0){
            a[i]=2;
            i++;
            n3--;
        }
    }
int  main(){
    int n;
    int a[n];
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort012( a,  &n);
    for(int i=0;i<n;i++){
        cout<<a[i];
    }

    return 0;
}