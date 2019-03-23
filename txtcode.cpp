#include<iostream>
#include<fstream>
using namespace std;
 
int main()
{
    ifstream fin("inputcar.txt",ios::in);
    ofstream fout("answer.txt");
    if(!fin)
    {
        cout<<"inputcar can not open"<<endl;
    }
    int a[100];  //距离
    int n,k;
    fin>>n>>k;
    for(int i=0;i<k+1;i++)
        fin>>a[i];
    int sum=0;   //加油次数
    int k1=0;      //加油后的里程数
    for(int i=0;i<k+1;i++)
        if(a[i]>n)
        {
            fout<<"No Solution";
            return -1;
        }
    for(int i=0;i<k+1;i++)
    {
        k1+=a[i];
        if(k1>n)
        {
            sum++;
            k1=a[i];
        }
    }
    fout<<"#停靠的加油站(carId,StartTime,RoadId...)"<<endl;
    k1=0;
    for(int i=0;i<k+1;i++)
    {
        k1+=a[i];
        if(k1>n)
        {
            k1=a[i];
            fout<<'('<<i<<','<<')'<<endl;
        }
    }
    fout<<endl;
    fout.close();
    fin.close();
    return 0;
}
