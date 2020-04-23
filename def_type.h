#pragma once

#include<stdio.h>
#include<cstdlib>
#include<iostream>
#include<ctime>
using namespace std;

typedef int ElemType;  //����Ԫ������

typedef  long int LenType; //���鳤������

class Array_sort
{
public:
	LenType len;
	ElemType *r;

	void InitList(LenType length)
	{
		if(len!=length)
			delete[] r;
		// 0�ŵ�Ԫ���ã�������±����
		r = (ElemType*)malloc((length + 1) * sizeof(ElemType));
		len = length;
	}

	void CreateRand(ElemType bound) //�����������
	{
		srand((int)time(0));  // �����������  ��0����NULLҲ��
		for (LenType i = 1; i <= len; i++)
		{
			r[i] = rand() % bound;
		}

	}


	void PrintTypeSortedList() //�����������
	{
		for (LenType i = 1; i <= len; i++)
		{
			cout << r_copy[i] << endl;
		}
	}

	double InsertSort() //��������
	{
		double start, end;
		CopyList();
		start = clock();
		InsertSortSub(1, rc_len);
		end = clock();
		return (double)(end - start) / CLOCKS_PER_SEC;
	}

	//������
	double HeapSort() 
	{
		CopyList();
		double start, end;
		start = clock();
		LenType i; 
		ElemType tmp;
		for (i = rc_len / 2; i > 0; --i)
			HeapAdjust(i, rc_len); // �����ʼ�󶥶�
		for (i = rc_len; i > 1; --i) {
			tmp = r_copy[i];
			r_copy[i] = r_copy[1];
			r_copy[1] = tmp; // �����Ĺؼ��ַŵ�r[i]
			HeapAdjust(1, i - 1); // ��r[1..i-1]����ɸѡ�����µ���Ϊ��
		}
		end = clock();
		return (double)(end - start) / CLOCKS_PER_SEC;
	}

	//��������
	double QuickSort() 
	{
		CopyList();
		double start, end;
		start = clock();
		QSort(1,rc_len);
		end = clock();
		return (double)(end - start) / CLOCKS_PER_SEC;
	}

	//�鲢����
	double MergeSort()
	{
		CopyList();
		double start, end;
		start = clock();
		ElemType* tmp = new ElemType[rc_len + 1]; //����洢�ռ�
		MSort(r_copy,tmp, 1, rc_len);
		delete[] tmp; //�ͷ�
		end = clock();
		return (double)(end - start) / CLOCKS_PER_SEC;
	}




private:
	ElemType* r_copy;
	LenType rc_len=0;

	void CopyList() //��������
	{
		if (rc_len!=len)//����
		{
			delete[] r_copy;
			rc_len = len;
			r_copy = (ElemType*)malloc((len + 1) * sizeof(ElemType)); //����ռ�
		}
		memcpy(r_copy, r, (len + 1) * sizeof(ElemType)); //�ڴ濽��
	}

	//���������ӳ���
	void InsertSortSub(LenType low, LenType high) {
		// ����Ӻ�����r[low..high]���򵥲�������
		for (LenType i = low + 1; i <= high; ++i)
			if (r_copy[i] < r_copy[i - 1]) //��ǰԪ��С��ǰ�������������ĩԪ�� 
			{ 
				ElemType tmp = r_copy[i];
				LenType j = i - 1;
				for (; tmp < r_copy[j] && j >= low; --j)
					r_copy[j + 1] = r_copy[j]; // Ԫ�غ���
				r_copy[j + 1] = tmp;      // ���뵽����λ��
			}
	}

	//�������ӳ���
	void HeapAdjust(LenType s, LenType m)
	{
		// ��֪r[s..m]�г���r[s]���⣬������󶥶ѵĶ���
		// ������ͨ��������ʹ��r[s..m]��Ϊһ���󶥶�
		ElemType tmp = r_copy[s];
		for (LenType i = 2 * s; i <= m; i *= 2) { // ÿ������һ��
			if (i < m && r_copy[i] < r_copy[i + 1]) ++i;
			if (tmp >= r_copy[i]) break; // �Ѿ��ҵ����ʵ�λ��
			r_copy[s] = r_copy[i]; s = i; // �뺢�ӻ�λ
		}
		r_copy[s] = tmp;
	}

	//���������ӳ���
	LenType Partition(LenType low, LenType high) {
		// ѡ��һ�����ᣬ��r[low..high]��Ϊ������
		// ��������������ڵ�λ�ã��Ա��һ������
		// �����Ժ�������֮ǰ��֮�󣩵�Ԫ�ض�С�ڣ����ڣ����������
		LenType pivotloc = low; // �����������ѡȡ������ȡ��һ��λ��
		ElemType tmp = r_copy[pivotloc];
		ElemType pivotkey = tmp;
		while (low < high) {
			while (low < high && r_copy[high] >= pivotkey) --high; //�ȴӺ���ǰ�ҵ���һ�������Ŵ�С�������������
			r_copy[low] = r_copy[high];
			while (low < high && r_copy[low] <= pivotkey) ++low; //��ǰ����ҵ���һ�������ϴ�С�������������
			r_copy[high] = r_copy[low];
		}
		r_copy[low] = tmp;
		return low;
	}
	void QSort(LenType low, LenType high) {
		// ��L[low..high]���п�������
		if (low < high) {
			LenType pivotloc = Partition(low, high);
			QSort(low, pivotloc - 1);
			QSort(pivotloc + 1, high);
		}
	}

	//�鲢�����ӳ���
	void Merge(ElemType* Rs, ElemType* Rt, LenType s, LenType m, LenType t) {
		// ��֪Rs[s..m]��Rs[m+1..t]��������������ǹ鲢�洢��Rt[s..t]
		LenType i, j, k;
		for (i = s, j = m + 1, k = s; i <= m && j <= t; ++k) //���������鰴���Ƶ�Rt��ֱ��һ������ȫ������ 
		{
			if (Rs[i] <= Rs[j]) Rt[k] = Rs[i++];
			else Rt[k] = Rs[j++];
		}
		for (; i <= m; ++i, ++k) Rt[k] = Rs[i];
		for (; j <= t; ++j, ++k) Rt[k] = Rs[j];
	}
	void MSort(ElemType* Rs, ElemType* Rt, LenType low, LenType high) {
		if (low < high) {
			LenType mid = (low + high) / 2;
			MSort(Rs, Rt, low, mid); MSort(Rs, Rt, mid + 1, high);
			Merge(Rs, Rt, low, mid, high);
			for (LenType i = low; i <= high; ++i) Rs[i] = Rt[i]; //��������Ƶ�Rs��������һ��
		}
	}

	//�Ƿ����
	bool IsEqual()
	{
		if (rc_len != len)
			return false;
		else {
			for (LenType i = 1; i <= len; i++) {
				if (r_copy[i] != r[i])
					return false;
			}
		}
		return true;
	}
};