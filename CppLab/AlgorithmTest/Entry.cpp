#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;
namespace AT1 {
	auto printVecInt = [](vector<int> vec)->void {
		for (int i = 0; i < vec.size(); i++)
			printf("%d\n", vec[i]);
	};

	/*** 整形反序 ***/
	int reverse(int x)
	{
		int result = 0;

		while (x != 0)
		{
			int tail = x % 10;
			int newResult = result * 10 + tail;
			if ((newResult - tail) / 10 != result)
			{
				return 0;
			}
			result = newResult;
			x = x / 10;
		}

		return result;
	}
	//https://leetcode.com/problems/reverse-integer 
	void test1()
	{
		std::cout << reverse(123) << std::endl;
	}

	/* 查找重复元素
	// when find a number i, flip the number at position i-1 to negative.
	// if the number at position i-1 is already negative, i is the number that occurs twice.
	*/
	vector<int> findDuplicates(vector<int> nums)
	{
		vector<int> retVec;
		for (int i = 0; i < nums.size(); i++)
		{
			int index = abs(nums[i]) - 1;
			if (nums[index] < 0)
				retVec.push_back(abs(index + 1));
			nums[index] = -nums[index];
		}
		return retVec;
	}

	/* Firstly, we put each element x in nums[x - 1]. Since x ranges from 1 to N, then x - 1 ranges from 0 to N - 1, it won't exceed the bound of the array.
	Secondly, we check through the array. If a number x doesn't present in nums[x - 1], then x is absent.
	*/
	vector<int> findDuplicates2(vector<int>& nums) {
		vector<int> res;
		int i = 0;
		while (i < nums.size()) {
			if (nums[i] != nums[nums[i] - 1]) swap(nums[i], nums[nums[i] - 1]);
			else i++;
		}
		for (i = 0; i < nums.size(); i++) {
			if (nums[i] != i + 1) res.push_back(nums[i]);
		}
		return res;
	}

	//https://leetcode.com/problems/find-all-duplicates-in-an-array/?tab=Description
	void test2()
	{
		vector<int> srcVec = { 4,3,2,7,8,2,3,1 };
		printVecInt(findDuplicates2(srcVec));
	}

	//------------------------------ 
	string longestPalindrome(string s) {
		if (s.empty()) return "";
		if (s.size() == 1) return s;
		int min_start = 0, max_len = 1;
		for (int i = 0; i < s.size();) {
			if (s.size() - i <= max_len / 2) break;
			int j = i, k = i;
			while (k < s.size() - 1 && s[k + 1] == s[k]) ++k; // Skip duplicate characters.
			i = k + 1;
			while (k < s.size() - 1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; } // Expand.
			int new_len = k - j + 1;
			if (new_len > max_len) { min_start = j; max_len = new_len; }
		}
		return s.substr(min_start, max_len);
	}

	//https://discuss.leetcode.com/topic/12187/simple-c-solution-8ms-13-lines
	//查找最长的回文子字符串 
	void test3()
	{
		string src = "bababd";
		string str = longestPalindrome(src);
		printf("%s\n", str.c_str());
	}


	/*
	 def median(A, B):
	m, n = len(A), len(B)
	if m > n:
		A, B, m, n = B, A, n, m
	if n == 0:
		raise ValueError

	imin, imax, half_len = 0, m, (m + n + 1) / 2
	while imin <= imax:
		i = (imin + imax) / 2
		j = half_len - i
		if i < m and B[j-1] > A[i]:
			# i is too small, must increase it
			imin = i + 1
		elif i > 0 and A[i-1] > B[j]:
			# i is too big, must decrease it
			imax = i - 1
		else:
			# i is perfect

			if i == 0: max_of_left = B[j-1]
			elif j == 0: max_of_left = A[i-1]
			else: max_of_left = max(A[i-1], B[j-1])

			if (m + n) % 2 == 1:
				return max_of_left

			if i == m: min_of_right = B[j]
			elif j == n: min_of_right = A[i]
			else: min_of_right = min(A[i], B[j])

			return (max_of_left + min_of_right) / 2.0
	*/

	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size();
		int n = nums2.size();
	}

	//https://leetcode.com/problems/median-of-two-sorted-arrays/#/solutions
	// 两个已排序的数组的中位数
	void test3() {

	}
};

int main()
{
	//AT1::test1();
	//AT1::test2();
	AT1::test3();

	system("pause");
	return 0;
}