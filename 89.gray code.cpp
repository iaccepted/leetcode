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
��Ȼ��������ת��Ϊ�����룺g 0 = b 0 ,g i = b i �� b i-1
������Ȼ������������λ��Ϊ����������λ��������θ�λΪ��������ĸ�λ��θ�λ��
�������λ��θ�λ�������ơ����磬����Ȼ�������� 1001��ת��Ϊ������Ĺ����ǣ�������
��λ��Ȼ�󽫵� 1 λ�� 1 �͵� 2 λ�� 0 ��򣬵õ� 1����Ϊ������ĵ� 2 λ������ 2 λ�� 0 �͵� 3 λ
�� 0 ��򣬵õ� 0����Ϊ������ĵ� 3 λ������ 3 λ�� 0 �͵� 4 λ�� 1 ��򣬵õ� 1����Ϊ�������
�� 4 λ�����գ�������Ϊ 1101��
������ת��Ϊ��Ȼ�������룺b 0 = g 0 ,b i = g i-1 �� b i-1
��������������λ��Ϊ��Ȼ������������λ���θ�λΪ��Ȼ�����Ƹ�λ�������θ�λ��
�������λ��θ�λ�������ơ����磬�������� 1000 ת��Ϊ��Ȼ��������Ĺ����ǣ��������
λ 1����Ϊ��Ȼ������������λ��Ȼ����Ȼ��������ĵ� 1 λ 1 �͸�����ĵ� 2 λ 0 ��򣬵�
�� 1����Ϊ��Ȼ��������ĵ� 2 λ������Ȼ��������ĵ� 2 λ 1 �͸�����ĵ� 3 λ 0 ��򣬵õ� 1��
��Ϊ��Ȼ��������ĵ� 3 λ������Ȼ��������ĵ� 3 λ 1 �͸�����ĵ� 4 λ 0 ��򣬵õ� 1����Ϊ
��Ȼ��������ĵ� 4 λ�����գ���Ȼ��������Ϊ 1111��

�ݹ��������

���ַ������ڸ������Ƿ��������ʵ�����õݹ�����¹��������죺
1λ����������������0, 1
(n+1)λ�������е�ǰn�����ֵ���nλ����������֣���˳����д����ǰ׺0
(n+1)λ�������еĺ�n�����ֵ���nλ����������֣���������д����ǰ׺1

for example��
0   00   000
1   01	 001
    
    11   011
    10   010
    
    		 110
    		 111
    		 101
    		 100
    		 

������
0�ĸ�����Ϊ0��n(n > 0)�ĸ�����Ϊn^(n/2)�������Ӧ�Ķ�����
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
