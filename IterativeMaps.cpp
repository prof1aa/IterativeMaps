// IterativeMaps.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "stdio.h"
#include <iostream>
#include "stdlib.h"

using namespace std;

#define DEBUG true
#define MAXI 4096 //1048576

class IMNode{
public:
	char data;
	unsigned short int count;
	IMNode(){ 
		data = '*';
		count = 0;
	}
	IMNode(char x, unsigned short int y){
		data = x;
		if (DEBUG) cout << "unsigned short int =" << sizeof(unsigned short int)<<endl;

		if (y > sizeOf(unsigned short int)){
			cerr << "Invalid Count; Resetting to unsigned short int";
			y = sizeof(unsigned short int);
		}
		count = y;
	}
};//end class IMNode

class IterativeMaps{
protected:
	unsigned long numberOfMaps;
public:
	IMNode IMArray[MAXI];
	//int gg[99];
	
	IterativeMaps(){
		numberOfMaps = 0;
	}

	IterativeMaps(char x, unsigned short int cnt){
		if (DEBUG) cout << "unsigned short int =" << sizeof(unsigned short int) << endl;

		numberOfMaps = 1;
		IMArray[0].data = x;

		if (cnt > sizeOf(unsigned short int)){
			cerr << "Invalid Count; Resetting to unsigned short int";
			cnt = sizeof(unsigned short int);
		}
		IMArray[0].count = cnt;

		if (DEBUG) cout << "numberOfMaps = " << numberOfMaps << endl;
	}


	bool IM_Insert(char x, unsigned short int cnt){
		if (DEBUG) cout << "numberOfMaps = " << numberOfMaps << endl;
		int L = 0, T;
		int R = numberOfMaps - 1;
	
		while (L <= R){
			T = (L + R) / 2; //when both ZERO becomes ERR
			
			if (x == (IMArray[T]).data){
				IMArray[T].count += cnt;
				return true;  // Found then EXIT ftr updating count
			}
			else
				if (x < IMArray[T].data)
					R = T - 1; // 0 & 0 gives -1 here whihc becomes maxInt for unsigned
				else
					L = T + 1;
			if (DEBUG) cout << "L = " << L << " & R = " << R << endl;
		} //end while

		if (++numberOfMaps <= MAXI){
			unsigned long shft = numberOfMaps - 1;
			while (shft > L){
				IMArray[shft] = IMArray[shft - 1]; //pull them RIGHT
				shft--;
			}
			//Now insert @ L
			IMArray[L].data = x;
			IMArray[L].count = cnt;
			return true;
		}// end if
		else return false;
	} //end IM_Insert

	void IM_Print(){
		for (unsigned int i = 0; i < numberOfMaps; i++){
			cout << i + 1 << ":";
			for (int j = 0; j < IMArray[i].count; j++)
				cout << IMArray[i].data;
			cout << endl;
		}// end for
		cout << "___________________________________"<<endl;
	}// end IM_Print

};//end class IM

int _tmain(int argc, _TCHAR* argv[])
{
	//int xx;
	//cin >> xx;

	if (DEBUG) cout << "unsigned short int =" << sizeof(unsigned short int) << endl;

	IterativeMaps MP('t', 5);
	MP.IM_Print();
	MP.IM_Insert('a', 7);
	MP.IM_Print();
	MP.IM_Insert('z', 9);
	MP.IM_Print();
	MP.IM_Insert('g', 6);
	MP.IM_Print();
	MP.IM_Insert('c', 4);
	MP.IM_Print();
	MP.IM_Insert('b', 2);
	MP.IM_Print();
	MP.IM_Insert('v', 20);
	MP.IM_Print();
	MP.IM_Insert('h', 30);
	MP.IM_Print();

//-- add chars to existing
	MP.IM_Insert('b', 1);
	MP.IM_Print();
	MP.IM_Insert('b', 2);
	MP.IM_Print();
	MP.IM_Insert('c', 19);
	MP.IM_Print();

//______________________
	return 0;
}

