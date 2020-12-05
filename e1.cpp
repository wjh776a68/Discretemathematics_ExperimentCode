#include<iostream>

using namespace std;

int isinclude(int *p,int x){
	int i;

	for (i = 0; i < 9; i++) {
		if (*(p + i) == x) {
			return 1;
		}		
		else if (i == 8) {
			return 0;
		}
	}
	return 0;
}

int insert(int *p,int x){
	int i;

	for (i = 0; i < 9; i++) {
		if (*(p + i) == 0) {
			*(p + i) = x;
			break;
		}
	}

	return 0;
}

int nofull(int *p){
	int i;
	for (i = 0; i < 9; i++) {
		if (*(p + i) == 0) {
			return 1;
		}
		else if (i == 8) {
			return 0;
		}
	}		
}

int main(void){
	float a[9][9]={ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
				    0 , 0 ,1.3,2.1,0.9,0.7,1.8,2.0,1.8,
				    0 , 0 , 0 ,0.9,1.8,1.2,2.8,2.3,1.1,
				    0 , 0 , 0 , 0 ,2.6,1.7,2.5,1.9,1.0,
				    0 , 0 , 0 , 0 , 0 ,0.7,1.6,1.5,0.9,
			        0 , 0 , 0 , 0 , 0 , 0 ,0.9,1.1,0.8,
				    0 , 0 , 0 , 0 , 0 , 0 , 0 ,0.6,1.0,
				    0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,0.5};
				    
	int tmp1,tmp2,i=0,point1,point2;
	float sum=5.0f,tmp2sum;
	int already[8]={1},*p=already;

	for (tmp2 = 1; tmp2 < 9; tmp2++) {
		for (tmp1 = tmp2 + 1; tmp1 < 9; tmp1++) {
			a[tmp1][tmp2] = a[tmp2][tmp1];
		}		
	}
		
	//printf("海边->1 ");	
	cout << "Sea->1 ";
	while(nofull(p)==1){
		tmp2sum=10;									// bigger all elements in a[][]

		for (tmp1 = 1; tmp1 < 9; tmp1++) {
			if (isinclude(p, tmp1) == 1) {

				for (i = 1; i < 9; i++)
					if (isinclude(p, i) == 0)
						point1 = i;

				for (i = 1; i < 9; i++) {
					if (isinclude(p, i) == 0) {
						if (a[tmp1][i] < a[tmp1][point1])
							point1 = i;
					}
				}

				if (a[tmp1][point1] < tmp2sum)
					tmp2sum = a[tmp2 = tmp1][point2 = point1];
			}
		}
								
		//printf("%d->%d ",tmp2,point2);
		cout << tmp2 <<"->"<< point2 << " ";
		sum+=tmp2sum;
		insert(p,point2);		
	}
	//printf("\n最短距离: %f\n",sum);
	cout << "\nThe Shortest Distance is: " << sum << "\n";
	return 0;			
}