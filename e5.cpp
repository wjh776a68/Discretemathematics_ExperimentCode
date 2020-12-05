#include<iostream>
#include<algorithm>

using namespace std;

//int isinclude(int *p,int x)
//{
//	int i;
//	for (i = 0; i < 6; i++) {
//		if (*(p + i) == x) {
//			return 1;
//		}
//		else if (i == 5) {
//			return 0;
//		}
//	}
//	return 0;
//}
//
//void insert(int *p,int x){
//	int i;
//	for (i = 0; i < 6; i++) {
//		if (*(p + i) == 0) {
//			*(p + i) = x;
//			break;
//		}
//	}	
//}
//
//void insertbyarray(int *p,int *lp){
//	int i,li;
//	for(i=0;i<6;i++)
//		if(*(p+i)==0)
//			break;			
//	for(li=0;li<6 && *(lp+li)!=0;li++){
//		*(p+i)=*(lp+li);
//		i++;
//	}				
//}
//
//int arrange(int *lp){
//	int already[6]={0};
//	int *p=already;
//	int i;
//	insertbyarray(p,lp);	
//	for(i=1;i<=6;i++){
//		if(isinclude(p,i)==1)
//			continue;
//		else{		
//			insert(p,i);
//			if(already[5]!=0){
//				printf("%d %d %d %d %d %d\n",*p,*(p+1),*(p+2),*(p+3),*(p+4),*(p+5));				
//				break;	
//			}			
//			arrange(p);			
//		}
//	}
//}

int main(){
	int already[6]={1,2,3,4,5,6};
	int sum = 0;
	//int *p=already;
	//arrange(p);
	while (next_permutation(already, already + 6)) {
		for (int i = 0; i < 6; i++) {
			cout << already[i];
		}
		cout << '\n';
		sum++;
	}
	cout << "全排列共计" << sum << "个\n";
	return 0;
}
