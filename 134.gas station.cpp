/******************************************
problem:
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
Note:
The solution is guaranteed to be unique.

author: guohongzhi

language: C

结论：对于一个循环数组，如果这个数组整体和 SUM >= 0，那么必然可以在数组中找到这么一个元素：从这个数组元素出发，
绕数组一圈，能保证累加和一直是出于非负状态。

分析：

a. 最开始，站点0是始发站，假设车开出站点p后，油箱空了，假设sum1 = diff[0] +diff[1] + ... + diff[p]，可知sum1 < 0；
b. 根据上面的论述，我们将p+1作为始发站，开出q站后，油箱又空了，设sum2 = diff[p+1] +diff[p+2] + ... + diff[q]，
可知sum2 < 0。
c. 将q+1作为始发站，假设一直开到了未循环的最末站，油箱没见底儿，设sum3 = diff[q+1] +diff[q+2] + ... + diff[size-1]，
可知sum3 >= 0。

要想知道车能否开回 q 站，其实就是在sum3 的基础上，依次加上 diff[0] 到 diff[q]，看看sum3在这个过程中是否会小于0。
但是我们之前已经知道 diff[0] 到 diff[p-1] 这段路，油箱能一直保持非负，因此我们只要算算sum3 + sum1是否 <0，
就知道能不能开到 p+1站了。如果能从p+1站开出，只要算算sum3 + sum1 + sum2 是否 < 0，就知都能不能开回q站了。

因为 sum1, sum2 都 < 0，因此如果 sum3 + sum1 + sum2 >=0 那么 sum3 + sum1 必然 >= 0，也就是说，只要sum3 + sum1 + sum2 >=0，
车必然能开回q站。而sum3 + sum1 + sum2 其实就是 diff数组的总和 Total，遍历完所有元素已经算出来了。
因此 Total 能否 >= 0，就是是否存在这样的站点的 充分必要条件。

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
