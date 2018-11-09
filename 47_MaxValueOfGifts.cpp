#if 0
#include<iostream>
#include<cstring>
using namespace std;

int getMaxValue_solution3(const int* values, int rows, int cols)
{
	if(values == nullptr || rows <= 0 || cols <= 0)
        return 0;
    
    int dp[rows][cols];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = *values;
    for(int i = 1; i < rows; i++)
        dp[i][0] += dp[i - 1][0] + values[i * cols];
    for(int j = 1; j < cols; j++)
        dp[0][j] += dp[0][j - 1] + values[j];
    for(int i = 1; i < rows; i++)
    {
    	for(int j = 1; j < cols; j++)
    	{
    		dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + values[i * cols + j];
		}
	}
	return dp[rows - 1][cols - 1];
}
#endif
/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

// ������47�����������ֵ
// ��Ŀ����һ��m��n�����̵�ÿһ�񶼷���һ�����ÿ�����ﶼ��һ���ļ�ֵ
// ����ֵ����0��������Դ����̵����Ͻǿ�ʼ�ø�����������ÿ�������
// �������ƶ�һ��ֱ���������̵����½ǡ�����һ�����̼��������������
// ����������õ����ټ�ֵ�����

#include <algorithm>
#include <iostream>

int getMaxValue_solution1(const int* values, int rows, int cols)
{
    if(values == nullptr || rows <= 0 || cols <= 0)
        return 0;

    int** maxValues = new int*[rows];
    for(int i = 0; i < rows; ++i)
        maxValues[i] = new int[cols];

    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            int left = 0;
            int up = 0;

            if(i > 0)
                up = maxValues[i - 1][j];

            if(j > 0)
                left = maxValues[i][j - 1];

            maxValues[i][j] = std::max(left, up) + values[i * cols + j];
        }
    }

    int maxValue = maxValues[rows - 1][cols - 1];

    for(int i = 0; i < rows; ++i)
        delete[] maxValues[i];
    delete[] maxValues;

    return maxValue;
}

int getMaxValue_solution2(const int* values, int rows, int cols)
{
    if(values == nullptr || rows <= 0 || cols <= 0)
        return 0;

    int* maxValues = new int[cols];
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            int left = 0;
            int up = 0;

            if(i > 0)
                up = maxValues[j];

            if(j > 0)
                left = maxValues[j - 1];

            maxValues[j] = std::max(left, up) + values[i * cols + j];
        }
    }

    int maxValue = maxValues[cols - 1];

    delete[] maxValues;

    return maxValue;
}

// ====================���Դ���====================
void test(const char* testName, const int* values, int rows, int cols, int expected)
{
	#if 1
    if(getMaxValue_solution1(values, rows, cols) == expected)
        std::cout << testName << ": solution1 passed." << std::endl;
    else
        std::cout << testName << ": solution1 FAILED." << std::endl;

    if(getMaxValue_solution2(values, rows, cols) == expected)
        std::cout << testName << ": solution2 passed." << std::endl;
    else
        std::cout << testName << ": solution2 FAILED." << std::endl;
    #endif
    
	#if 0  
    if(getMaxValue_solution3(values, rows, cols) == expected)
        std::cout << testName << ": solution3 passed." << std::endl;
    else
        std::cout << testName << ": solution3 FAILED." << std::endl;
    #endif
}

void test1()
{
    // ��������
    int values[][3] = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };
    int expected = 29;
    test("test1", (const int*) values, 3, 3, expected);
}

void test2()
{
    //��������
    int values[][4] = {
        { 1, 10, 3, 8 },
        { 12, 2, 9, 6 },
        { 5, 7, 4, 11 },
        { 3, 7, 16, 5 }
    };
    int expected = 53;
    test("test2", (const int*) values, 4, 4, expected);
}

void test3()
{
    // һ������
    int values[][4] = {
        { 1, 10, 3, 8 }
    };
    int expected = 22;
    test("test3", (const int*) values, 1, 4, expected);
}

void test4()
{
    int values[4][1] = {
        { 1 },
        { 12 },
        { 5 },
        { 3 }
    };
    int expected = 21;
    test("test4", (const int*) values, 4, 1, expected);
}

void test5()
{
    // һ��һ��
    int values[][1] = {
        { 3 }
    };
    int expected = 3;
    test("test5", (const int*) values, 1, 1, expected);
}

void test6()
{
    // ��ָ��
    int expected = 0;
    test("test6", nullptr, 0, 0, expected);
}

void test7()
{
    //��������
    int values[][6] = {
        { 1, 10, 3, 8, 7, 4 },
        { 12, 2, 9, 6, 5, 8 },
        { 5, 7, 4, 11, 5, 9 },
        { 3, 7, 16, 5, 9, 8 }
    };
    int expected = 70;
    test("test7", (const int*) values, 4, 6, expected);
}

int main(int argc, char* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();

    return 0;
}
