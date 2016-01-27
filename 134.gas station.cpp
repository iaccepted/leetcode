/******************************************
problem:
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
Note:
The solution is guaranteed to be unique.

author: guohongzhi

language: C

���ۣ�����һ��ѭ�����飬��������������� SUM >= 0����ô��Ȼ�������������ҵ���ôһ��Ԫ�أ����������Ԫ�س�����
������һȦ���ܱ�֤�ۼӺ�һֱ�ǳ��ڷǸ�״̬��

������

a. �ʼ��վ��0��ʼ��վ�����賵����վ��p��������ˣ�����sum1 = diff[0] +diff[1] + ... + diff[p]����֪sum1 < 0��
b. ������������������ǽ�p+1��Ϊʼ��վ������qվ�������ֿ��ˣ���sum2 = diff[p+1] +diff[p+2] + ... + diff[q]��
��֪sum2 < 0��
c. ��q+1��Ϊʼ��վ������һֱ������δѭ������ĩվ������û���׶�����sum3 = diff[q+1] +diff[q+2] + ... + diff[size-1]��
��֪sum3 >= 0��

Ҫ��֪�����ܷ񿪻� q վ����ʵ������sum3 �Ļ����ϣ����μ��� diff[0] �� diff[q]������sum3������������Ƿ��С��0��
��������֮ǰ�Ѿ�֪�� diff[0] �� diff[p-1] ���·��������һֱ���ַǸ����������ֻҪ����sum3 + sum1�Ƿ� <0��
��֪���ܲ��ܿ��� p+1վ�ˡ�����ܴ�p+1վ������ֻҪ����sum3 + sum1 + sum2 �Ƿ� < 0����֪���ܲ��ܿ���qվ�ˡ�

��Ϊ sum1, sum2 �� < 0�������� sum3 + sum1 + sum2 >=0 ��ô sum3 + sum1 ��Ȼ >= 0��Ҳ����˵��ֻҪsum3 + sum1 + sum2 >=0��
����Ȼ�ܿ���qվ����sum3 + sum1 + sum2 ��ʵ���� diff������ܺ� Total������������Ԫ���Ѿ�������ˡ�
��� Total �ܷ� >= 0�������Ƿ����������վ��� ��ֱ�Ҫ������

******************************************/

#include <stdio.h>
#include <stdlib.h>

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize)
{
	int total = 0, leftGas = 0, start = -1;
	for (int i = 0; i < gasSize; ++i)
	{
		total += gas[i] - cost[i];
		leftGas += gas[i] - cost[i];

		if (leftGas < 0)
		{
			start = i;
			leftGas = 0;
		}
	}
	return total >= 0 ? start + 1 : -1;
}

int main()
{
	int gas[4] = {3, 5, 2};
	int cost[4] = {4, 6 , 1};
	int index = canCompleteCircuit(gas, 4, cost, 4);
	
	printf("%d\n", index);
	return 0;
}
