#include<iostream>

using namespace std;


int main(){

    int S[4] = { 0 };                                                           //已访问过的城市
    int D[4][4] = { //0     1   2   3                                           //邻接矩阵，用于存储两个城市之间的距离
            /*0*/   0,    2,  6,  5,
            /*1*/   2,    0,  4,  4,
            /*2*/   6,    4,  0,  2,
            /*3*/   5,    4,  2,  0 };

    int sum = 0;                                                                //已访问过的城市的最短路径长度之和
    int CurrentMinDistance;                                                     //当前最短路径值 
    int CurrentBestMove;                                                        //临时城市储存变量

    std::cout << "离散数学 实验四 旅行商问题\n\n";

    std::cout << "旅行商途径顺序: "<<0<<'\t';

    for (int i = 1; i < 4; i++) {
        CurrentMinDistance = 0x7FFFFFFF;
        for (int  ii = 1; ii < 4; ii++) {
            int iii = 0;
            for (; iii < i; iii++) {                                            //是否访问过
                if (S[iii] == ii) {                                     
                    break;                                                      
                }
            } 

            if (iii == i) {
                if (D[ii][S[i - 1]] < CurrentMinDistance) {                      //D[k][S[i - 1]]表示当前未被访问的城市k与上一个已访问过的城市i-1之间的距离
                    CurrentBestMove = ii;                                        //j用于存储已访问过的城市，临时变量，如有更短距离则被覆盖
                    CurrentMinDistance = D[ii][S[i - 1]];
                }
                                
            }
           
        } 
        S[i] = CurrentBestMove;                                                 //确定下一城市                                   
        sum += CurrentMinDistance;
        std::cout << CurrentBestMove << "\t";
    }                                                      

    std::cout << 0 << "\t";
    sum += D[0][CurrentBestMove];

    std::cout << endl;

    std::cout << "最短距离为：\t" << sum << endl;                //D[0][j]为旅行商所在的最后一个城市与原出发的城市之间的距离

    return 0;
}