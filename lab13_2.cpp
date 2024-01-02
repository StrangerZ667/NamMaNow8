#include <iostream>
#include <cmath>
using namespace std;

const int N = 30;
const int M = 70;

void updateImage(bool [][M],int,int,int);

void showImage(const bool [][M]);

int main()
{
    bool image[N][M] = {};
    int s,x,y;
    do{
        showImage(image);
        cout << "Input your brush size and location: ";
        cin >> s >> x >> y;
        updateImage(image,s,x,y);
    }while(s != 0 || x != 0 || y != 0);
    return 0;
}


void updateImage(bool image[][M],int s,int x,int y){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if (sqrt(pow(i-x,2)+pow(j-y,2))<= s-1) image[i][j]=1;
        }
    }
}

void showImage(const bool image[][M]){
 for(int i=0;i<N+2;i++){
    for(int j=0;j<M+2;j++){
        if(i==0 or i==31) cout << '-';
        else if(j==0 or j==71) cout << '|';
        else if(image[i-1][j-1] == 0) cout << ' ';
        else if(image[i-1][j-1] == 1) cout << '*';
        }
        cout << endl;
    }
}
