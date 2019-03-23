#include<stdio.h>
#include<cstring>
#include<string.h>
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
struct carInfo{
	string line;
	int carId;
	int carFrom;
	int carTo;
	int carHighspeed;
	int carPlantime;
};

int main()
{

    int i,j,k=5;
    int a[10];
    ifstream fin("inputcar.txt",ios::in);
    ofstream fout("answer.txt");
    if(!fin)
    {
        cout<<"inputcar can not open"<<endl;//panduan wenjian shifou dakai
    }
    int cardata[100];//che 5ge shuju
    string stem;//yueguo di yi hang
    string s;//duru shuju字符串
    getline(fin,stem);//hulue di yi hang #

    vector<carInfo>car;//car de dong tai jie gou ti shuzui
    

    while(getline(fin,s))//zhuhang durushuju
    {
	    
	    carInfo info;//lin shi liang
	    info.line="sd";
	    info.line=s;//
	    char * z=(char*)s.data();
	    const char *d= " ,()";
	    char *p;
	    p=strtok(z,d);
	    i=1;
	    while(p){
//字符串中取出数字
                    stringstream ss;
		    ss<<p;
		    ss>>a[i];
		    i++;
		    p=strtok(NULL,d);
	    }
	    //字符串中取出数字
	    info.carId=a[1];
	    info.carFrom=a[2];
	    info.carTo=a[3];
	    info.carHighspeed=a[4];
	    info.carPlantime=a[5];

	    cout<<info.line<<endl;
	    car.push_back(info);
	   // cout<<s<<endl;
    }

//ceshi jiegouti fangwen 
    for(i=0;i<=15;i++){
	    cout<<car[i].carId<<' '<<car[i].carFrom<<' '<<car[i].carTo<<' '<<car[i].carHighspeed<<' '<<car[i].carPlantime<<endl;
//	   cout<<car[i].line<<endl;

    }

    cout<<endl;
cout<<car[10].line<<endl;	    

    //duru shuju 
    //for(i=1;i<=k;i++)
    //      fin>>cardata[i];



    //lujing shuchu
    fout<<"#(carId,StartTime,RoadId...)"<<endl;
    for(int i=1;i<=k;i++)
    {
	   
          fout<<'('<<cardata[i]<<','<<')'<<endl;
	    
    }
    fout<<endl;

    //guanbi wenjian
    fout.close();
    fin.close();
    return 0;
}
