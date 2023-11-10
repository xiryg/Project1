#pragma once
#include <string>
#include <iostream>


// 将 str 表示的 n 进制数转换为十进制数
double toDecimal(std::string str, int n);

// 将十进制数 x 转换为 m 进制数
std::string toBase(double x, int m);