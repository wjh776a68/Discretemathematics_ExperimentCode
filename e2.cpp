/***************************************************
*
*		��ɢ��ѧ ʵ��� ���·���� ʵ�����
*
*		ѧ�ţ�		2018218794
*		����:		�¼�� 
*		�༶��		�����18-3��
*		������ڣ�	2020/12/04
*
***************************************************/


#include<iostream>
#include<algorithm>
#include<Windows.h>

using namespace std;

//relationship:  agr1 ��Ҫ arg2 ���Ϊǰ�ᣬ����1��ʾ��Ҫֱ��������0��ʾ��ֱ������ 			
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

char costtime[13]={0,4,1,3,2,2,1,7,15,5,10,11,5};												//��ĳ�ڵ���Ҫ���ѵ�ʱ��
char passtime[13]={0};																			//��ĳ�ڵ��Ѿ�������ʱ�� 
bool isfinished[13]={0};																		//ĳ�ڵ��Ƿ���� 


int main(){
																								//���ó�ʼ�ڵ㣨��ʼ�ɽ��У� 
//	isfinished[1]=1;
//	isfinished[3]=1;
//	isfinished[4]=1;
//	isfinished[5]=1;
//	isfinished[6]=1;
	system("mode con cols=120 lines=30");

	cout << "��ɢ��ѧ ʵ��� ���·����\n\n";

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
			if(check==13){																		//�ýڵ�ɽ��б��� 
				passtime[i] = max(costtime[i], passtime[i]);
				for(int anothercheck=1;anothercheck<13;anothercheck++){
					if(relationship[i][anothercheck]==1){
						passtime[i]=max((int)passtime[i],passtime[anothercheck]+costtime[i]);	//��ȡ����ýڵ��������ʱ�䣨���������̵�ʱ�䣩
					}
				}
				
			}
			
			//for(int del=1;del<13;del++){														//ɾ���������������裨���������) 
			isfinished[i] = true;
				//if(relationship[del][i]!=0){
				//	relationship[del][i]=0;
				//}
			//}
		}
	}
	
	cout << "������ţ�" << "\t";
	for (int i = 1; i < 13; i++) {
		cout << i << "\t"<<"";									
		
	}
	cout << endl;


	cout << "���ֿ�ʼ�ܣ�" << "\t";
	int maxcost=0;
	for(int i=1;i<13;i++){
		cout << passtime[i] - costtime[i]<<"\t";												//passtime�����Ϊ��ɸýڵ���ʱ�䣬��ת���ɿ�ʼʱ������
		maxcost=max(maxcost, (int)passtime[i]);
	}
	cout << endl;


	cout << "���ֽ����ܣ�" << "\t";
	//int maxcost = 0;
	for (int i = 1; i < 13; i++) {
		cout << (int)passtime[i] << "\t";												//passtime�����Ϊ��ɸýڵ���ʱ�䣬��ת���ɿ�ʼʱ������
		//maxcost = max(maxcost, (int)passtime[i]);
	}
	cout << endl;

	cout << endl;

	cout << "����ͺ�ʱʱ��(��)��";
	cout << maxcost << endl;
	
	return 0;
}
