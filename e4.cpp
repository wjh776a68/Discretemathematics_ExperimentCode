#include<iostream>

using namespace std;


int main(){

    int S[4] = { 0 };                                                           //�ѷ��ʹ��ĳ���
    int D[4][4] = { //0     1   2   3                                           //�ڽӾ������ڴ洢��������֮��ľ���
            /*0*/   0,    2,  6,  5,
            /*1*/   2,    0,  4,  4,
            /*2*/   6,    4,  0,  2,
            /*3*/   5,    4,  2,  0 };

    int sum = 0;                                                                //�ѷ��ʹ��ĳ��е����·������֮��
    int CurrentMinDistance;                                                     //��ǰ���·��ֵ 
    int CurrentBestMove;                                                        //��ʱ���д������

    std::cout << "��ɢ��ѧ ʵ���� ����������\n\n";

    std::cout << "������;��˳��: "<<0<<'\t';

    for (int i = 1; i < 4; i++) {
        CurrentMinDistance = 0x7FFFFFFF;
        for (int  ii = 1; ii < 4; ii++) {
            int iii = 0;
            for (; iii < i; iii++) {                                            //�Ƿ���ʹ�
                if (S[iii] == ii) {                                     
                    break;                                                      
                }
            } 

            if (iii == i) {
                if (D[ii][S[i - 1]] < CurrentMinDistance) {                      //D[k][S[i - 1]]��ʾ��ǰδ�����ʵĳ���k����һ���ѷ��ʹ��ĳ���i-1֮��ľ���
                    CurrentBestMove = ii;                                        //j���ڴ洢�ѷ��ʹ��ĳ��У���ʱ���������и��̾����򱻸���
                    CurrentMinDistance = D[ii][S[i - 1]];
                }
                                
            }
           
        } 
        S[i] = CurrentBestMove;                                                 //ȷ����һ����                                   
        sum += CurrentMinDistance;
        std::cout << CurrentBestMove << "\t";
    }                                                      

    std::cout << 0 << "\t";
    sum += D[0][CurrentBestMove];

    std::cout << endl;

    std::cout << "��̾���Ϊ��\t" << sum << endl;                //D[0][j]Ϊ���������ڵ����һ��������ԭ�����ĳ���֮��ľ���

    return 0;
}