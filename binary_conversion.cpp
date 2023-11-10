#include "binary_conversion.h"
#include <cmath>


// 将 str 表示的 n 进制数转换为十进制数
double toDecimal(std::string str, int n) {
	double res = 0;
	bool isFractional = false; // 是否为小数部分
	int fractionalDigits = 0; // 小数部分的位数

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '.') {
			isFractional = true;
			continue;
		}

		int digit;
		if (str[i] >= '0' && str[i] <= '9') {
			digit = str[i] - '0';
		}
		else if (str[i] >= 'A' && str[i] <= 'F') {
			digit = str[i] - 'A' + 10;
		}
		else {
			continue; // 非法字符，忽略
		}

		if (isFractional) {
			res += digit * pow(n, -fractionalDigits - 1);
			fractionalDigits++;
		}
		else {
			res = res * n + digit;
		}
	}

	return res;
}

// 将十进制数 x 转换为 m 进制数
std::string toBase(double x, int m) {
	std::string res = "";
	int integerPart = static_cast<int>(x); // 整数部分

	while (integerPart) {
		int r = integerPart % m;
		char c = r < 10 ? r + '0' : r - 10 + 'A';
		res = c + res;
		integerPart /= m;
	}

	double fractionalPart = x - floor(x); // 小数部分
	if (fractionalPart > 0) {
		res += '.';
		int fractionalDigits = 0;

		while (fractionalPart > 0 && fractionalDigits < 6) {
			fractionalPart *= m;
			int digit = static_cast<int>(floor(fractionalPart + 1e-10));
			char c = digit < 10 ? digit + '0' : digit - 10 + 'A';
			res += c;
			fractionalPart -= digit;
			fractionalDigits++;
		}
	}

	if (res == "") res = "0";  // 特判 x = 0 的情况
	return res;
}

