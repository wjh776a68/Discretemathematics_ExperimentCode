/***************************************************
*
*		离散数学 实验二 最短路问题 实验代码
*
*		学号：		2018218794
*		姓名:		温嘉昊 
*		班级：		计算机18-3班
*		完成日期：	2020/12/04
*
***************************************************/


#include<iostream>
#include<algorithm>
#include<Windows.h>

using namespace std;

//relationship:  agr1 需要 arg2 完成为前提，其中1表示需要直接依赖，0表示无直接依赖 			
bool relationship[13][13]={//	0  	1 	2 	3 	4 	5	 6	 7 	8	9	10  11	12
					/*0*/		0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,
					/*1*/		1  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,
					/*2*/		1  ,1  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,
					/*3*/		1  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,
					/*4*/		1  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,
					/*5*/		1  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,
					/*6*/		1  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,
					/*7*/		1  ,0  ,1  ,1  ,1  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,
					/*8*/		1  ,0  ,0  ,1  ,0  ,0  ,0  ,1  ,0  ,0  ,0  ,0  ,0  ,
					/*9*/		1  ,0  ,0  ,0  ,0  ,0  ,0  ,1  ,1  ,0  ,0  ,0  ,0  ,
					/*10*/		1  ,0  ,0  ,0  ,0  ,1  ,0  ,1  ,1  ,0  ,0  ,0  ,0  ,
					/*11*/		1  ,0  ,0  ,0  ,0  ,0  ,1  ,0  ,1  ,0  ,1  ,0  ,0  ,
					/*12*/		1  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,1  ,0  ,1  ,1  ,0  
							};

char costtime[13]={0,4,1,3,2,2,1,7,15,5,10,11,5};												//在某节点需要花费的时间
char passtime[13]={0};																			//在某节点已经历过的时间 
bool isfinished[13]={0};																		//某节点是否完成 


int main(){
																								//设置初始节点（开始可进行） 
//	isfinished[1]=1;
//	isfinished[3]=1;
//	isfinished[4]=1;
//	isfinished[5]=1;
//	isfinished[6]=1;
	system("mode con cols=120 lines=30");

	cout << "离散数学 实验二 最短路问题\n\n";

	bool unfinished=true;
	while(unfinished==true){
		unfinished=false;
		
		for(int i=1;i<13;i++){
			int check;
			for(check=1;check<13;check++){
				if(relationship[i][check]!=0 && isfinished[check]==false){
					unfinished=true;
					break;
				}
			}
			if(check==13){																		//该节点可进行遍历 
				passtime[i] = max(costtime[i], passtime[i]);
				for(int anothercheck=1;anothercheck<13;anothercheck++){
					if(relationship[i][anothercheck]==1){
						passtime[i]=max((int)passtime[i],passtime[anothercheck]+costtime[i]);	//求取到达该节点所需最短时间（即完成最长工程的时间）
					}
				}
				
			}
			
			//for(int del=1;del<13;del++){														//删除塔方对自身所需（所需已完成) 
			isfinished[i] = true;
				//if(relationship[del][i]!=0){
				//	relationship[del][i]=0;
				//}
			//}
		}
	}
	
	cout << "工种序号：" << "\t";
	for (int i = 1; i < 13; i++) {
		cout << i << "\t"<<"";									
		
	}
	cout << endl;


	cout << "工种开始周：" << "\t";
	int maxcost=0;
	for(int i=1;i<13;i++){
		cout << passtime[i] - costtime[i]<<"\t";												//passtime储存的为完成该节点后的时间，须转换成开始时间故相减
		maxcost=max(maxcost, (int)passtime[i]);
	}
	cout << endl;


	cout << "工种结束周：" << "\t";
	//int maxcost = 0;
	for (int i = 1; i < 13; i++) {
		cout << (int)passtime[i] << "\t";												//passtime储存的为完成该节点后的时间，须转换成开始时间故相减
		//maxcost = max(maxcost, (int)passtime[i]);
	}
	cout << endl;

	cout << endl;

	cout << "故最低耗时时长(周)：";
	cout << maxcost << endl;
	
	return 0;
}
