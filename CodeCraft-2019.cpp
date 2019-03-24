// run code ./CodeCraft-2019 ../config/car.txt ../config/road.txt ../config/cross.txt  ../config/answer.txt
#include<stdio.h>
#include<cstring>
#include<string.h>
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
//car data
struct carInfo{
//	string line;// read the line by line
	int carId;// car id
	int carFrom;//car from
	int carTo;//car to
	int carHighspeed;//car high speed
	int carPlantime;//car plan time
};

//road data
struct roadInfo{
	int roadId;//road id
	int roadLength;//length
	int roadHighspeed;//speed
	int roadChannel;//channel
	int roadFrom;//from
	int roadTo;//to
	int roadIsduplex;//isduplex
};

//cross data
struct crossInfo{
	int crossId;//cross id
	int crossRoadid_1;//roadId
	int crossRoadid_2;//roadId
	int crossRoadid_3;//roadId
	int crossRoadid_4;//roadId
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

    int i,j,m,n;
    int mapToroad[101][101];//map to roadid
    int mapToroadspeed[10001];//map to roadid xuyao zhuyi road de id fanwei
    int k=5;//export data in answer
    int carNum=0;//car total number,from 1 to carNum
    int roadNum=0;//road total number,from 1 to roadNum
    int crossNum=0;//cross total number ,from 1 to crossNum
    int a[10];//transform string to number
    ifstream carDatain(carPath,ios::in);// car data in
    ifstream roadDatain(roadPath,ios::in);// road data in
    ifstream crossDatain(crossPath,ios::in);//cross data in
    ofstream answerOut(answerPath);//answer out
    if(!carDatain)//is car data open success?
    {
        cout<<"car.txt can not open"<<endl;//panduan wenjian shifou dakai
    }
    if(!roadDatain)//is road data open success?
    {
        cout<<"road.txt can not open"<<endl;//panduan wenjian shifou dakai
    }
    if(!crossDatain)//is cross data open success?
    {
        cout<<"cross.txt can not open"<<endl;//panduan wenjian shifou dakai
    }
    

// read car data
//  int cardata[100];//che 5ge shuju
    string stem;//not read the first line data
    string s;//duru shuju字符串
    getline(carDatain,stem);//hulue di yi hang #
    vector<carInfo>car;//car de dong tai jie gou ti shuzui
    while(getline(carDatain,s))// read the data line by line
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
                    //transform string to number
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
	    carNum++;//car number + 1, total carNum;
    }

//read road data
    getline(roadDatain,stem);//hulue di yi hang #
    vector<roadInfo>road;//car de dong tai jie gou ti shuzui
    while(getline(roadDatain,s))// read the data line by line
    {

            roadInfo info;//lin shi liang
//          info.line="sd";//the line first
//          info.line=s;//read the string by line to line
            //字符串中取出数字
            char * z=(char*)s.data();
            const char *d= " ,()";//fen ge fu
            char *p;
            p=strtok(z,d);
            i=1;
            while(p){
                    //transform string to number
                    stringstream ss;
                    ss<<p;
                    ss>>a[i];
                    i++;
                    p=strtok(NULL,d);
            }
            //字符串中取出数字
            info.roadId=a[1];//road id
            info.roadLength=a[2];//road length
            info.roadHighspeed=a[3];//road high speed
            info.roadChannel=a[4];//road channel
            info.roadFrom=a[5];//road from crossid
	    info.roadTo=a[6];//road to crossid
	    info.roadIsduplex=a[7];//road isduplex?
            road.push_back(info);// push_back to car
            // cout<<s<<endl;//know if the s line has in the info,line
            roadNum++;//road number + 1, total carNum;
    }

//read cross data
    getline(crossDatain,stem);//hulue di yi hang #
    vector<crossInfo>cross;//car de dong tai jie gou ti shuzui
    while(getline(crossDatain,s))// read the data line by line
    {

            crossInfo info;//lin shi liang
//          info.line="sd";//the line first
//          info.line=s;//read the string by line to line
            //字符串中取出数字
            char * z=(char*)s.data();
            const char *d= " ,()";//fen ge fu
            char *p;
            p=strtok(z,d);
            i=1;
            while(p){
                    //transform string to number
                    stringstream ss;
                    ss<<p;
                    ss>>a[i];
                    i++;
                    p=strtok(NULL,d);
            }
            //字符串中取出数字
            info.crossId=a[1];//road id
            info.crossRoadid_1=a[2];//cross road 1 -roadId
            info.crossRoadid_2=a[3];//cross road 2 -roadId
            info.crossRoadid_3=a[4];//cross road 3 -roadId
            info.crossRoadid_4=a[5];//cross road 4 -roadId
            
            cross.push_back(info);// push_back to car
            // cout<<s<<endl;//know if the s line has in the info,line
            crossNum++;//cross number + 1, total crossNum;
    }
    int inf=99999999;//can not arrive
    int crossMap[101][101];// biao shi daobuliao
		    
    for(i=1;i<=crossNum;i++)
    {
	    for(j=1;j<=crossNum;j++)
	    {
		    if(i==j)
			    crossMap[i][j]=0;
		    else
			    crossMap[i][j]=inf;
	    }
    }
    for(i=0;i<=10000;i++)
    {
	    mapToroadspeed[i]=0;
    }
/*    
    for(i=1;i<=crossNum;i++)
    {
	    for(j=1;j<=crossNum;j++)
	    {
		 if(i==j)
			 continue;
		 if(cross[i].crossRoadid_1!=-1)
		    {
		       if(cross[i].crossRoadid_1==cross[j].crossRoadid_1)
			       crossMap[i][j]=1;//zhijueding ij
		       if(cross[i].crossRoadid_1==cross[j].crossRoadid_2)
			       crossMap[i][j]=1;
		       if(cross[i].crossRoadid_1==cross[j].crossRoadid_3)
			       crossMap[i][j]=1;
		       if(cross[i].crossRoadid_1==cross[j].crossRoadid_4)
			       crossMap[i][j]=1;
		    }
		 if(cross[i].crossRoadid_2!=-1)
                    {
                       if(cross[i].crossRoadid_1==cross[j].crossRoadid_1)
                               crossMap[i][j]=1;//zhijueding ij
                       if(cross[i].crossRoadid_1==cross[j].crossRoadid_2)
                               crossMap[i][j]=1;
                       if(cross[i].crossRoadid_1==cross[j].crossRoadid_3)
                               crossMap[i][j]=1;
                       if(cross[i].crossRoadid_1==cross[j].crossRoadid_4)
                               crossMap[i][j]=1;
                    }
                 if(cross[i].crossRoadid_3!=-1)
                    {
                       if(cross[i].crossRoadid_1==cross[j].crossRoadid_1)
                               crossMap[i][j]=1;//zhijueding ij
                       if(cross[i].crossRoadid_1==cross[j].crossRoadid_2)
                               crossMap[i][j]=1;
                       if(cross[i].crossRoadid_1==cross[j].crossRoadid_3)
                               crossMap[i][j]=1;
                       if(cross[i].crossRoadid_1==cross[j].crossRoadid_4)
                               crossMap[i][j]=1;
                    }
                 if(cross[i].crossRoadid_4!=-1)
                    {
                       if(cross[i].crossRoadid_1==cross[j].crossRoadid_1)
                               crossMap[i][j]=1;//zhijueding ij
                       if(cross[i].crossRoadid_1==cross[j].crossRoadid_2)
                               crossMap[i][j]=1;
                       if(cross[i].crossRoadid_1==cross[j].crossRoadid_3)
                               crossMap[i][j]=1;
                       if(cross[i].crossRoadid_1==cross[j].crossRoadid_4)
                               crossMap[i][j]=1;
                    }

	    }
    }
*/
    //is duplex? if is then the map will be inf=99999999
    for(i=0;i<roadNum;i++)
    {
	    if(road[i].roadIsduplex==1)
	    {
		    crossMap[road[i].roadFrom][road[i].roadTo]=road[i].roadLength;
		    mapToroad[road[i].roadFrom][road[i].roadTo]=road[i].roadId;//betweentwocrossroaid
		    mapToroadspeed[road[i].roadId]=road[i].roadHighspeed;//the road high speed
		    crossMap[road[i].roadTo][road[i].roadFrom]=road[i].roadLength;
		    mapToroad[road[i].roadFrom][road[i].roadTo]=road[i].roadId;
		    mapToroadspeed[road[i].roadId]=road[i].roadHighspeed;

	    }
	    else
	    {
		    crossMap[road[i].roadFrom][road[i].roadTo]=road[i].roadLength;
		    mapToroad[road[i].roadFrom][road[i].roadTo]=road[i].roadId;
                    mapToroadspeed[road[i].roadId]=road[i].roadHighspeed;
		    crossMap[road[i].roadTo][road[i].roadFrom]=inf;
	    }
    }
    //find the best close road





//ce si
    for(i=1;i<=crossNum;i++)
    {
	    for(j=1;j<=crossNum;j++)
		    answerOut<<crossMap[i][j]<<' ';
	    answerOut<<endl;
    }
    for(i=1;i<=10000;i++)
    {
	    cout<<mapToroadspeed[i]<<' ';
    }




/* //window cout
//ceshi the car
    for(i=0;i<carNum;i++){
	    cout<<car[i].carId<<' '<<car[i].carFrom<<' '<<car[i].carTo<<' ';
            cout<< car[i].carHighspeed<<' '<<car[i].carPlantime<<endl;
//	    cout<<car[i].line<<endl;
    
    }
//ceshi the road
    for(i=0;i<roadNum;i++){
            cout<<road[i].roadId<<' '<<road[i].roadLength<<' '<<road[i].roadHighspeed<<' ';
            cout<< road[i].roadChannel<<' '<<road[i].roadFrom<<' '<<road[i].roadTo<<' '<<road[i].roadIsduplex<<endl;
//          cout<<car[i].line<<endl;
    }
//ceshi the cross
    for(i=0;i<crossNum;i++){
            cout<<cross[i].crossId<<' '<<cross[i].crossRoadid_1<<' '<<cross[i].crossRoadid_2<<' ';
            cout<<cross[i].crossRoadid_3<<' '<<cross[i].crossRoadid_4<<endl;
//          cout<<car[i].line<<endl;
    }
*/
//duru shuju 
//for(i=1;i<=k;i++)
//      fin>>cardata[i];
//export data out to answer.txt
/*//answerOut
    answerOut<<"#(carId,StartTime,RoadId...)"<<endl;
    for(int i=0;i<carNum;i++)
    {
	   
          answerOut<<'('<<car[i].carId<<','<<')';
	  answerOut<<'('<<car[i].carFrom<<','<<')'<<endl; 
    }
*/
//ceshi the car
    for(i=0;i<carNum;i++){
         answerOut<<car[i].carId<<' '<<car[i].carFrom<<' '<<car[i].carTo<<' ';
         answerOut<< car[i].carHighspeed<<' '<<car[i].carPlantime<<endl;

    }
//ceshi the road
    for(i=0;i<roadNum;i++){
         answerOut<<road[i].roadId<<' '<<road[i].roadLength<<' '<<road[i].roadHighspeed<<' ';
         answerOut<< road[i].roadChannel<<' '<<road[i].roadFrom<<' '<<road[i].roadTo<<' '<<road[i].roadIsduplex<<endl;
    }
//ceshi the cross
    for(i=0;i<crossNum;i++){
         answerOut<<cross[i].crossId<<' '<<cross[i].crossRoadid_1<<' '<<cross[i].crossRoadid_2<<' ';
         answerOut<<cross[i].crossRoadid_3<<' '<<cross[i].crossRoadid_4<<endl;
    }
    answerOut<<endl;
    //close the files
    answerOut.close();//close answer.txt
    carDatain.close();//close car.txt
    roadDatain.close();//close road.txt
    crossDatain.close();//close cross.txt
    return 0;
}
