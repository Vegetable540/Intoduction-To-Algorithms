#include <vector>
#include <cassert>
using namespace std;

namespace FindMaximumSubArray_Violent
{
	void find(const vector<int> &array, int *begin, int *end)
	{
		int maxSum = 0;
		for (int i = 0; i < array.size(); ++i)
		{
			int sum = 0;
			for (int j = i; j < array.size(); ++j)
			{
				sum += array[j];

				if (sum  > maxSum)
				{
					maxSum = sum;
					*begin = i;
					*end = j;
				}
			}
		}
	}
}

namespace FindMaximumSubArray_Recursion
{
	int find_CrossMidSubArray(const vector<int> &array, int left, int mid, int right, int *begin, int *end)
	{
		int lMaxSum = INT_MIN;
		int lTempSum = 0;

		for (int i = mid; i >= left; --i)
		{
			lTempSum += array[i];

			if (lTempSum >= lMaxSum)
			{
				lMaxSum = lTempSum;
				*begin = i;
			}
		}

		int rMaxSum = INT_MIN;
		int rTempSum = 0;

		for (int i = mid + 1; i <= right; ++i)
		{
			rTempSum += array[i];

			if (rTempSum >= rMaxSum)
			{
				rMaxSum = rTempSum;
				*end = i;
			}
		}

		return lMaxSum + rMaxSum;
	}

	int find(const vector<int> &array, int left, int right, int *begin, int *end)
	{
		if (left == right)
		{
			*begin = left;
			*end = right;

			return array[left];
		}
		else
		{
			int mid = (left + right) / 2;

			int lBegin, lEnd = 0;
			int lSum = find(array, left, mid, &lBegin, &lEnd);

			int mBegin, mEnd = 0;
			int mSum = find_CrossMidSubArray(array, left, mid, right, &mBegin, &mEnd);

			int rBegin, rEnd = 0;
			int rSum = find(array, mid + 1, right, &rBegin, &rEnd);

			if (lSum >= mSum && lSum >= rSum)
			{
				*begin = lBegin;
				*end = lEnd;
				return lSum;
			}
			else if (mSum >= lSum && mSum >= rSum)
			{
				*begin = mBegin;
				*end = mEnd;
				return mSum;
			}
			else
			{
				*begin = rBegin;
				*end = rEnd;
				return rSum;
			}
		}
	}

	void find(const vector<int> &array, int *begin, int *end)
	{
		find(array, 0, array.size() - 1, begin, end);
	}
}

class FindMaxiMulSubArray_Test
{
public:
	FindMaxiMulSubArray_Test()
	{
		vector<int> oTest1{ 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
		int begin, end;
		FindMaximumSubArray_Violent::find(oTest1, &begin, &end);
		assert(begin == 7 && end == 10);

		FindMaximumSubArray_Recursion::find(oTest1, &begin, &end);
		assert(begin == 7 && end == 10);
	}
} findMaxiMulSubArrayTest;;