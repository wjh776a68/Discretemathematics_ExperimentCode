#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

//0�ǶϿ���ֱ������
				//	0	a	b	c	d	e	f	g	h	i	j	k	t
short map[13][13]={			
		/*0*/		0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,
		/*a*/		0,	0,	2,	0,	0,	5,	0,	0,	0,	0,	0,	0,	0,
		/*b*/		0,	2,	0,	4,	0,	0,	3,	0,	0,	0,	0,	0,	0,
		/*c*/		0,	0,	4,	0,	5,	0,	0,	6,	0,	0,	0,	0,	0,
		/*d*/		0,	0,	0,	5,	0,	0,	0,	0,	4,	0,	0,	0,	0,
		/*e*/		0,	5,	0,	0,	0,	0,	6,	0,	0,	5,	0,	0,	0,
		/*f*/		0,	0,	3,	0,	0,	6,	0,	4,	0,	0,	4,	0,	0,
		/*g*/		0,	0,	0,	6,	0,	0,	4,	0,	6,	0,	0,	4,	0,
		/*h*/		0,	0,	0,	0,	4,	0,	0,	6,	0,	0,	0,	0,	7,
		/*i*/		0,	0,	0,	0,	0,	5,	0,	0,	0,	0,	9,	0,	0,
		/*j*/		0,	0,	0,	0,	0,	0,	4,	0,	0,	9,	0,	3,	0,
		/*k*/		0,	0,	0,	0,	0,	0,	0,	4,	0,	0,	3,	0,	8,
		/*t*/		0,	0,	0,	0,	0,	0,	0,	0,	7,	0,	0,	8,	0 };


//��̾��봢��ṹ
struct smalldistance {
	int startpoint;
	int endpoint;
	int mindistance;
};

struct array_struct {
	int startpoint;
	vector<smalldistance> distance;
};



int main() {
	vector<array_struct> oddnode;
	set<short> oddnodename;

	int totalsum = 0;
	for (int x = 1; x < 13; x++) {
		int tmpsum = 0;
		for (int y = 1; y < 13; y++) {
			if (map[x][y] != 0) {
				tmpsum++;
				totalsum += map[x][y];
			}
		}

		if (tmpsum % 2 != 0) {
			array_struct tmp;
			tmp.startpoint = x;
			oddnodename.insert(x);
			for (int i = 1; i < 13; i++) {
				if (map[x][i] != 0) {
					smalldistance tmp_smalldistacne;
					tmp_smalldistacne.startpoint = x;
					tmp_smalldistacne.endpoint = i;
					tmp_smalldistacne.mindistance= map[x][i];
					tmp.distance.push_back(tmp_smalldistacne);
				}

			}

			oddnode.push_back(tmp);
		}
	}

	
	for (auto iter = oddnode.begin(); iter != oddnode.end(); iter++) {//��ʼ�����
		
		bool ischange = true;
		while (ischange == true) {
			ischange = false;
			
			for (auto distence_iter = iter->distance.begin(); distence_iter != iter->distance.end(); distence_iter++) {//���������
				for (int i = 1; i < 13; i++) {//����������
					if (map[distence_iter->endpoint][i] != 0 && i!= iter->startpoint) {
						auto find = iter->distance.begin();
						for (; find != iter->distance.end(); find++) {
							if (find->endpoint == i) {
								break;
							}
						}
						smalldistance tmp_smalldistance;
						tmp_smalldistance.startpoint = distence_iter->startpoint;
						tmp_smalldistance.endpoint = i;
						if (find == iter->distance.end()) {
							tmp_smalldistance.mindistance = distence_iter->mindistance + map[distence_iter->endpoint][i];
							
							//distence_iter++;
							iter->distance.push_back(tmp_smalldistance);
							distence_iter = iter->distance.begin();

							ischange = true;
						}
						else {
							if (find->mindistance > distence_iter->mindistance + map[distence_iter->endpoint][i]) {
								tmp_smalldistance.mindistance = distence_iter->mindistance + map[distence_iter->endpoint][i];
								auto del_item = find;
								iter->distance.erase(del_item);
								//distence_iter++;
								iter->distance.push_back(tmp_smalldistance);
								
								
								
								distence_iter = iter->distance.begin();
								ischange = true;
							}
							
						}
							
					}
					
					
				}
			}
		}

		//auto del = iter;
		//oddnode.erase(del);
		//iter++;


	}

	//for (auto iter = oddnode.begin(); iter != oddnode.end(); iter++) {
	//	auto iter_c = *iter;
	//	for (auto iterinner = iter_c.distance.begin(); iterinner != iter_c.distance.end(); iterinner++) {
	//		if (oddnodename.find(iterinner->endpoint) == oddnodename.end()) {
	//			
	//			iter_c.distance.erase(iterinner);


	//			iterinner = iter_c.distance.begin();

	//			oddnode.erase(iter);
	//			oddnode.push_back(iter_c);
	//			iter = oddnode.begin();

	//		}
	//	}
	//	
	//	
	//}

	vector<short> oddnodename_iter;
	for (auto i = oddnodename.begin(); i != oddnodename.end(); i++) {
		oddnodename_iter.push_back(*i);
	}

	//6������������
	int bestsum = 9999;			//An MAX num
	vector<short> oddnode_bestnum;

	while (next_permutation(oddnodename_iter.begin(),oddnodename_iter.end())) {
		int sum = 0;

		for (auto i = oddnode.begin(); i != oddnode.end(); i++) {
			if (oddnodename_iter[0] == i->startpoint) {

				for (auto ii = i->distance.begin(); ii != i->distance.end(); ii++) {
					if (oddnodename_iter[1] == ii->endpoint) {
						sum += ii->mindistance;
						
					}
				}
			}
		}
		
		for (auto i = oddnode.begin(); i != oddnode.end(); i++) {
			if (oddnodename_iter[2] == i->startpoint) {

				for (auto ii = i->distance.begin(); ii != i->distance.end(); ii++) {
					if (oddnodename_iter[3] == ii->endpoint) {
						sum += ii->mindistance;

					}
				}
			}
		}

		for (auto i = oddnode.begin(); i != oddnode.end(); i++) {
			if (oddnodename_iter[4] == i->startpoint) {

				for (auto ii = i->distance.begin(); ii != i->distance.end(); ii++) {
					if (oddnodename_iter[5] == ii->endpoint) {
						sum += ii->mindistance;

					}
				}
			}
		}


		if (bestsum > sum) {
			bestsum = sum;
			oddnode_bestnum = oddnodename_iter;
		}
	}


	cout << "��ɢ��ѧ ʵ���� �й��ʵ�Ա����\n\n";

	cout << "���·����" << totalsum/2 + bestsum <<endl;
	
	cout << "���� " << oddnode_bestnum[0] << "��" << oddnode_bestnum[1] << ", " << oddnode_bestnum[2] << "��" << oddnode_bestnum[3] << ", " << oddnode_bestnum[4] << "��" << oddnode_bestnum[5] << "��Ҫ��������\n";

	return 0;
}