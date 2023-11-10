#include "binary_conversion.h"
#include "sum_of_largest_subsequences.h"

int main() {

	// 1. 进制转化
	
	int n;
	std::string num;
	int m;
	std::cin >> n >> num >> m;
	double decimal = toDecimal(num, n);  // 先将 n 进制数转换为十进制数
	std::string res = toBase(decimal, m);  // 再将十进制数转换为 m 进制数
	std::cout << decimal << std::endl;
	

	// 2. 最大子序列的和
	/*
	int A[6] = { 1,-2,-9,3,2,10 };
	const int MaxSum = sum_of_largest_subsequences(A, 6);
	std::cout << "最大子序列的和为:" << MaxSum << std::endl;
	return 0;
	*/


}
