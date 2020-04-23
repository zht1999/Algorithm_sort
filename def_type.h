#pragma once

#include<stdio.h>
#include<cstdlib>
#include<iostream>
#include<ctime>
using namespace std;

typedef int ElemType;  //数组元素类型

typedef  long int LenType; //数组长度类型

class Array_sort
{
public:
	LenType len;
	ElemType *r;

	void InitList(LenType length)
	{
		if(len!=length)
			delete[] r;
		// 0号单元不用，方便对下标操作
		r = (ElemType*)malloc((length + 1) * sizeof(ElemType));
		len = length;
	}

	void CreateRand(ElemType bound) //随机产生序列
	{
		srand((int)time(0));  // 产生随机种子  把0换成NULL也行
		for (LenType i = 1; i <= len; i++)
		{
			r[i] = rand() % bound;
		}

	}


	void PrintTypeSortedList() //输出有序序列
	{
		for (LenType i = 1; i <= len; i++)
		{
			cout << r_copy[i] << endl;
		}
	}

	double InsertSort() //插入排序
	{
		double start, end;
		CopyList();
		start = clock();
		InsertSortSub(1, rc_len);
		end = clock();
		return (double)(end - start) / CLOCKS_PER_SEC;
	}

	//堆排序
	double HeapSort() 
	{
		CopyList();
		double start, end;
		start = clock();
		LenType i; 
		ElemType tmp;
		for (i = rc_len / 2; i > 0; --i)
			HeapAdjust(i, rc_len); // 构造初始大顶堆
		for (i = rc_len; i > 1; --i) {
			tmp = r_copy[i];
			r_copy[i] = r_copy[1];
			r_copy[1] = tmp; // 将最大的关键字放到r[i]
			HeapAdjust(1, i - 1); // 对r[1..i-1]调用筛选法重新调整为堆
		}
		end = clock();
		return (double)(end - start) / CLOCKS_PER_SEC;
	}

	//快速排序
	double QuickSort() 
	{
		CopyList();
		double start, end;
		start = clock();
		QSort(1,rc_len);
		end = clock();
		return (double)(end - start) / CLOCKS_PER_SEC;
	}

	//归并排序
	double MergeSort()
	{
		CopyList();
		double start, end;
		start = clock();
		ElemType* tmp = new ElemType[rc_len + 1]; //额外存储空间
		MSort(r_copy,tmp, 1, rc_len);
		delete[] tmp; //释放
		end = clock();
		return (double)(end - start) / CLOCKS_PER_SEC;
	}




private:
	ElemType* r_copy;
	LenType rc_len=0;

	void CopyList() //复制序列
	{
		if (rc_len!=len)//重载
		{
			delete[] r_copy;
			rc_len = len;
			r_copy = (ElemType*)malloc((len + 1) * sizeof(ElemType)); //分配空间
		}
		memcpy(r_copy, r, (len + 1) * sizeof(ElemType)); //内存拷贝
	}

	//插入排序子程序
	void InsertSortSub(LenType low, LenType high) {
		// 这个子函数对r[low..high]做简单插入排序
		for (LenType i = low + 1; i <= high; ++i)
			if (r_copy[i] < r_copy[i - 1]) //当前元素小于前面有序数组的最末元素 
			{ 
				ElemType tmp = r_copy[i];
				LenType j = i - 1;
				for (; tmp < r_copy[j] && j >= low; --j)
					r_copy[j + 1] = r_copy[j]; // 元素后移
				r_copy[j + 1] = tmp;      // 插入到合适位置
			}
	}

	//堆排序子程序
	void HeapAdjust(LenType s, LenType m)
	{
		// 已知r[s..m]中除了r[s]以外，都满足大顶堆的定义
		// 本函数通过调整，使得r[s..m]成为一个大顶堆
		ElemType tmp = r_copy[s];
		for (LenType i = 2 * s; i <= m; i *= 2) { // 每次向下一层
			if (i < m && r_copy[i] < r_copy[i + 1]) ++i;
			if (tmp >= r_copy[i]) break; // 已经找到合适的位置
			r_copy[s] = r_copy[i]; s = i; // 与孩子换位
		}
		r_copy[s] = tmp;
	}

	//快速排序子程序
	LenType Partition(LenType low, LenType high) {
		// 选择一个枢轴，将r[low..high]分为两部分
		// 返回枢轴最后所在的位置，以便进一步划分
		// 划分以后，在枢轴之前（之后）的元素都小于（大于）或等于枢轴
		LenType pivotloc = low; // 枢轴可以任意选取，例如取第一个位置
		ElemType tmp = r_copy[pivotloc];
		ElemType pivotkey = tmp;
		while (low < high) {
			while (low < high && r_copy[high] >= pivotkey) --high; //先从后往前找到第一个不符号大小规则的数，调整
			r_copy[low] = r_copy[high];
			while (low < high && r_copy[low] <= pivotkey) ++low; //从前向后找到第一个不符合大小规则的数，调整
			r_copy[high] = r_copy[low];
		}
		r_copy[low] = tmp;
		return low;
	}
	void QSort(LenType low, LenType high) {
		// 对L[low..high]进行快速排序
		if (low < high) {
			LenType pivotloc = Partition(low, high);
			QSort(low, pivotloc - 1);
			QSort(pivotloc + 1, high);
		}
	}

	//归并排序子程序
	void Merge(ElemType* Rs, ElemType* Rt, LenType s, LenType m, LenType t) {
		// 已知Rs[s..m]和Rs[m+1..t]都是有序表，将它们归并存储到Rt[s..t]
		LenType i, j, k;
		for (i = s, j = m + 1, k = s; i <= m && j <= t; ++k) //将两个数组按序复制到Rt，直到一个数组全部插完 
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
			for (LenType i = low; i <= high; ++i) Rs[i] = Rt[i]; //将结果复制到Rs，返回上一级
		}
	}

	//是否更新
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