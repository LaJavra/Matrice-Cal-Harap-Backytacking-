#include <iostream>
#include <fstream>
#include <limits.h>
#define NMAX INT_MAX/200
using namespace std;

int alex[NMAX];
int dl[]={1,0,0,-1};
int dc[]={0,-1,1,0};
int m,n,a[10000][10000];
static int z=0;
void citire() {
    ifstream fin("cal.txt");
    fin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            fin>>a[i][j];}}
        fin.close();
    }

void afisare(){
    ofstream out("scoate_cal.txt");
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            out<<a[i][j]<<" ";}
            out<<endl;}
    }

void umple(int linie, int coloana){
a[linie][coloana]=2;
    if(a[m][z]==2){
            alex[z]=z;
            return;}
    for(int directie=0;directie<4;directie++)
        {
        int i=linie+dl[directie];
        int j=coloana+dc[directie];
    if(i>=1 && i<=m && j>=1 && j<=n && !a[i][j])
        umple(i,j);
}
}
void curata_cacatul(){
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]==2)
                a[i][j]=0;}}

}
int main()
{   int i,j;
citire();
for(i=1,j=1;j<=n;j++)
{   z++;
    curata_cacatul();
    if(a[i][j]!=1)
    umple(i,j);
}
curata_cacatul();
afisare();
int k;
    for(k=0;k<NMAX;k++)
            if(alex[k]!=0)
                cout<<alex[k]<<" ";
return 0;}
