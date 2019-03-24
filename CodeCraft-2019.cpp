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
//	string line;// read the line by line
	int carId;// car id
	int carFrom;//car from
	int carTo;//car to
	int carHighspeed;//car high speed
	int carPlantime;//car plan time
};

int main(int argc,char *argv[])
{
	std::cout << "Begin" << std::endl;

        if(argc < 5){
                std::cout << "please input args: carPath, roadPath, crossPath, answerPath" << std::endl;
                exit(1);
        }

        std::string carPath(argv[1]);
        std::string roadPath(argv[2]);
        std::string crossPath(argv[3]);
        std::string answerPath(argv[4]);

        std::cout << "carPath is " << carPath << std::endl;
        std::cout << "roadPath is " << roadPath << std::endl;
        std::cout << "crossPath is " << crossPath << std::endl;
        std::cout << "answerPath is " << answerPath << std::endl;
        // TODO:read input filebuf

    int i,j,k=5;
    int n=0;//car total number,from 0 to n 
    int a[10];
    ifstream carDatain("../config/car.txt",ios::in);// car data in
    ofstream answerOut("answerPath");//answer out
    if(!carDatain)
    {
        cout<<"car.txt can not open"<<endl;//panduan wenjian shifou dakai
    }
    int cardata[100];//che 5ge shuju
    string stem;//not read the first line data
    string s;//duru shuju字符串
    getline(carDatain,stem);//hulue di yi hang #
    vector<carInfo>car;//car de dong tai jie gou ti shuzui
    while(getline(carDatain,s))//zhuhang durushuju
    {
	    
	    carInfo info;//lin shi liang
//	    info.line="sd";//the line first
//	    info.line=s;//read the string by line to line
	    //字符串中取出数字
	    char * z=(char*)s.data();
	    const char *d= " ,()";//fen ge fu
	    char *p;
	    p=strtok(z,d);
	    i=1;
	    while(p){
                    //transance string to number
                    stringstream ss;
		    ss<<p;
		    ss>>a[i];
		    i++;
		    p=strtok(NULL,d);
	    }
	    //字符串中取出数字
	    info.carId=a[1];//carId
	    info.carFrom=a[2];//carFrom
	    info.carTo=a[3];//carTo
	    info.carHighspeed=a[4];//carHighspeed
	    info.carPlantime=a[5];//carPlantime
	    car.push_back(info);// push_back to car
	    // cout<<s<<endl;//know if the s line has in the info,line
	    n++;//car number + 1, total n;
    }
//ceshi jiegouti fangwen 
    for(i=0;i<n;i++){
	    cout<<car[i].carId<<' '<<car[i].carFrom<<' '<<car[i].carTo<<' ';
            cout<< car[i].carHighspeed<<' '<<car[i].carPlantime<<endl;
//	    cout<<car[i].line<<endl;
    }
    //duru shuju 
    //for(i=1;i<=k;i++)
    //      fin>>cardata[i];



    //lujing shuchu
    answerOut<<"#(carId,StartTime,RoadId...)"<<endl;
    for(int i=1;i<=k;i++)
    {
	   
          answerOut<<'('<<cardata[i]<<','<<')'<<endl;
	    
    }
    answerOut<<endl;

    //guanbi wenjian
    answerOut.close();
    carDatain.close();
    return 0;
}
