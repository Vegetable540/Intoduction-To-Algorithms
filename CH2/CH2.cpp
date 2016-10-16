// CH2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <cassert>

#include <algorithm>

using namespace std;

void merge(vector<int> &numbs, int l, int m, int r)
{
	vector<int> left;
	for (int i = l; i <= m; ++i) {
		left.push_back(numbs[i]);
	}

	vector<int> right;
	for (int i = m + 1; i <= r; ++i) {
		right.push_back(numbs[i]);
	}

	int i = 0;
	int j = 0;
	int k;

	for (k = l; k <= r; ++k) {
		if (i >= left.size() || j >= right.size())
			break;

		if (left[i] <= right[j]) {
			numbs[k] = left[i];
			i++;
		}
		else {
			numbs[k] = right[j];
			j++;
		}
	}

	vector<int> *pRemain;
	int nRemainStartP;
	if (i >= left.size())
	{
		pRemain = &right;
		nRemainStartP = j;
	}
	else
	{
		pRemain = &left;
		nRemainStartP = i;
	}

	for (; k <= r; ++k) {
		numbs[k] = pRemain->at(nRemainStartP++);
	}
}

void mergeSort(vector<int> &numbs, int start, int end)
{
	if (start < end)
	{
		int m = (start + end) / 2;

		mergeSort(numbs, start, m);
		mergeSort(numbs, m + 1, end);

		merge(numbs, start, m, end);
	}
}

int main()
{
	vector<int> oTest{10, 9, 8, 7, 6, 5, 4, 1};
	mergeSort(oTest, 0, oTest.size() - 1);

	vector<int> oCorrect = oTest;
	sort(oCorrect.begin(), oCorrect.end());

	assert(oTest == oCorrect);

    return 0;
}

