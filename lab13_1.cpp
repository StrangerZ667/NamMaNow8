#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]){
    B[4]=0,B[1]=0;
    double sum=0,tick=1,har=0;
    for(int i=0;i<=N-1;i++){
        tick*=A[i];
        sum+=A[i];
        har+=(1/A[i]);
        if(A[i] > B[4]) B[4] = A[i];
    }
    B[3] = N/har;
    B[0] = sum/N;
    B[5] = B[4];
    for(int i=0;i<=N-1;i++){
        if(A[i] < B[5]) B[5] = A[i];
        B[1]+=pow((A[i]-B[0]),2);
    }
    B[1] = sqrt(B[1]/N);
    B[2] = pow(tick,(1.0/N));
}
