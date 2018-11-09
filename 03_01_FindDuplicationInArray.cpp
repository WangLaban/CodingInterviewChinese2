#include<iostream>
#include<vector>
using namespace std;

bool duplicationInArray(vector<int> nums, int &duplication)
{
	if(nums.size() == 0)
	    return false;
	for(int i = 0; i < nums.size(); i++)
	{
		if(nums[i] < 0 || nums[i] > nums.size())
		    return false;
		while(nums[i] != i)
		{
			if(nums[i] == nums[nums[i]])
			{
				duplication = nums[i];
				return true;
			}
			swap(nums[i], nums[nums[i]]);
		}
	}
	return false;
}

// ====================���Դ���====================
bool contains(vector<int> array, int number)
{
    for(int i = 0; i < array.size(); ++i)
    {
        if(array[i] == number)
            return true;
    }

    return false;
}

void test(char* testName, vector<int> numbers, vector<int> expected, bool validArgument)
{
    printf("%s begins: ", testName);

    int duplication;
    bool validInput = duplicationInArray(numbers, duplication);

    if(validArgument == validInput)
    {
        if(validArgument)
        {
            if(contains(expected, duplication))
                printf("Passed.\n");
            else
                printf("FAILED.\n");
        }
        else
            printf("Passed.\n");
    }
    else
        printf("FAILED.\n");
}

// �ظ�����������������С������
void test1()
{
    vector<int> numbers = { 2, 1, 3, 1, 4 };
    vector<int> duplications = { 1 };
    test("Test1", numbers, duplications, true);
}

// �ظ�����������������������
void test2()
{
    vector<int> numbers = { 2, 4, 3, 1, 4 };
    vector<int> duplications = { 4 };
    test("Test2", numbers, duplications, true);
}

// �����д��ڶ���ظ�������
void test3()
{
    vector<int> numbers = { 2, 4, 2, 1, 4 };
    vector<int> duplications = { 2, 4 };
    test("Test3", numbers, duplications, true);
}

// û���ظ�������
void test4()
{
    vector<int> numbers = { 2, 1, 3, 0, 4 };
    vector<int> duplications = { -1 }; // not in use in the test function
    test("Test4", numbers, duplications, false);
}

// û���ظ�������
void test5()
{
    vector<int> numbers = { 2, 1, 3, 5, 4 };
    vector<int> duplications = { -1 }; // not in use in the test function
    test("Test5", numbers, duplications, false);
}

// ��Ч������
void test6()
{
    vector<int> numbers;
    vector<int> duplications = { -1 }; // not in use in the test function
    test("Test6", numbers, duplications, false);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    
    return 0;
}
