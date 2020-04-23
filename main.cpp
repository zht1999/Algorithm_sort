#include<stdio.h>
#include<cstdlib>
#include<iostream>
#include<ctime>
#include<fstream>
#include"def_type.h"
using namespace std;

int main()
{
	Array_sort a;
	double time = 0;
	ofstream outfile;
	outfile.open("time.txt");
	for (int i = 1; i <=10; i++) 
	{
		a.InitList(i * 50000);
		cout << i << endl;
		outfile << i << endl;
		for (int j = 1; j <= 5; j++) {
			a.CreateRand(10000);
			time = a.InsertSort();
			outfile << time << ' ';
			time = a.HeapSort();
			outfile << time << ' ';
			time = a.QuickSort();
			outfile << time << ' ';
			time = a.MergeSort();
			outfile << time << ' ';
			outfile << endl;
		}
	}
	outfile.close();
	system("pause");
}



