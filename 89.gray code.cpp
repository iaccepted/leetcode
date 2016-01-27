/******************************************
problem:
The gray code is a binary numeral system where two successive values differ in only one bit.
Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.
For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.

author: guohongzhi

language: C

ps:
自然二进制码转换为格雷码：g 0 = b 0 ,g i = b i ⊕ b i-1
保留自然二进制码的最高位作为格雷码的最高位，格雷码次高位为二进制码的高位与次高位异
或，其余各位与次高位的求法类似。例如，将自然二进制码 1001，转换为格雷码的过程是：保留最
高位；然后将第 1 位的 1 和第 2 位的 0 异或，得到 1，作为格雷码的第 2 位；将第 2 位的 0 和第 3 位
的 0 异或，得到 0，作为格雷码的第 3 位；将第 3 位的 0 和第 4 位的 1 异或，得到 1，作为格雷码的
第 4 位，最终，格雷码为 1101。
格雷码转换为自然二进制码：b 0 = g 0 ,b i = g i-1 ⊕ b i-1
保留格雷码的最高位作为自然二进制码的最高位，次高位为自然二进制高位与格雷码次高位异
或，其余各位与次高位的求法类似。例如，将格雷码 1000 转换为自然二进制码的过程是：保留最高
位 1，作为自然二进制码的最高位；然后将自然二进制码的第 1 位 1 和格雷码的第 2 位 0 异或，得
到 1，作为自然二进制码的第 2 位；将自然二进制码的第 2 位 1 和格雷码的第 3 位 0 异或，得到 1，
作为自然二进制码的第 3 位；将自然二进制码的第 3 位 1 和格雷码的第 4 位 0 异或，得到 1，作为
自然二进制码的第 4 位，最终，自然二进制码为 1111。

递归生成码表

这种方法基于格雷码是反射码的事实，利用递归的如下规则来构造：
1位格雷码有两个码字0, 1
(n+1)位格雷码中的前n个码字等于n位格雷码的码字，按顺序书写，加前缀0
(n+1)位格雷码中的后n个码字等于n位格雷码的码字，按逆序书写，加前缀1

for example：
0   00   000
1   01	 001
    
    11   011
    10   010
    
    		 110
    		 111
    		 101
    		 100
    		 

方法二
0的格雷码为0，n(n > 0)的格雷码为n^(n/2)这个数对应的二进制
******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* grayCode(int n, int* returnSize) 
{ 
	int size = (1 << n);
	int *res = (int *)calloc(size, sizeof(int));
	res[0] = 0;
	res[1] = 1;
	
	int index = 2;
	for (int i = 2; i <= n; ++i)
	{
		int base = (1 << i);
		for (int j = index - 1; j >= 0; --j)
		{
			res[index++] = (base | res[j]);
		}
	}
	*returnSize = size;
	return res;
}

int *grayCode2(int n, int *returnSize)
{
	int size = (1 << n);
	int *res = (int *)calloc(size, sizeof(int));
	res[0] = 0;
	
	for (int i = 1; i < size; ++i)
	{
		res[i] = (i ^ (i >> 1));
	}
	*returnSize = size;
	return res;
}

int main()
{
	int n;
	int *res = grayCode(5, &n);
	
	for (int i = 0; i < n; ++i)
	{
		printf("%d  ", res[i]);
	}
	printf("\n");
	return 0;
}
