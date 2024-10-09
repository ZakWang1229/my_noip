### 样例输入

```
4 5 7 5
```
 
### 样例输出
```
34
```

## 先从正面思考

**朴素算法**：预处理出l长的字符总和为s的方案数（例如，2的长度下组合成5，有05、14、23、32、41、50,6种方案），考虑枚举x、y、z、w的值进行dp转移。但是在枚举过程中会出现许多次重复计算（例如 4 5 5 5的输入，在枚举中5 5 5  5的字串被计算了2次）。

为什么会产生重复计算呢？因为在枚举中，会有一个字串**有多个子串满足俳句**的要求。

## 从反面进行考虑

既然一个字串有多个字串满足俳句的话会被重复计算，那么我们只需要算出**没有子串满足俳句**的字串数，再用**总的字串数**减去这个值。

那么n位数字，就有10^n种字串数。

### 先划分状态

我们用i来表示状态转移到第i位，用二进制码表示枚举字串的结尾的状态。

我们将十进制数j，转化为第j位为1的二进制码，例如4-&gt;1000。如果4后面加上一个2变成4 2，我们用100010表示，即将4的二进制码向前移动2位，再加上10。同时这个二进制码第6位为1，即代表**末尾两个数**和为6，第2位为1，代表**最末尾的数**为2，用6减去2得4，可以得到**末尾第二个数**为4。

同理举个例子：如果我们枚举到5 3 4 我们得到二进制串 100001001000，这个二进制串可以表示**结尾可表示的数字**有12（12位上为1）、7（7位上为1）、4（4位上为1）、5（12-7=5）、3（7-4=3）、8（12-4=8），这样我们就把5 3 4这三个数字可以组成的情况都包含进去了。

原题中，最大状态为5+7+5=17位所以最多要枚举2^17种状态，在空间范围之内。

### 再来谈转移

我们先枚举i（0&lt;=i&lt;=n）表示当前在第几位，然后我们再枚举2^17的状态。
```
for(int i=1;i&lt;=n;i++)
	{
		for(int j=0;j&lt;=sum;j++)//枚举状态
		{
			if(dp[i-1][j]==0) continue;
			for(int k=1;k&lt;=10;k++)//枚举第i位添加的数字
			{
				int now=(j&lt;&lt;k)|(1&lt;&lt;k-1);//上面提到的二进制码转移
				now&amp;=sum;//防止now溢出
				if((now&amp;end)!=end)//如果状态存在俳句则不进行转移
					dp[i][now]=(dp[i][now]+dp[i-1][j])%mod;
			}
		}
	}
```

注意dp[0][0]=1

### 详细细节请参考代码

```
#include&lt;iostream&gt;
#include&lt;cstdio&gt;
#include&lt;cstring&gt;
using namespace std;

int n,x,y,z;
int end;
int sum;
long long dp[45][1&lt;&lt;18];
long long ans=1,mod=1e9+7;

int main()
{
	freopen(&quot;haiku.txt&quot;,&quot;r&quot;,stdin);
	scanf(&quot;%d%d%d%d&quot;,&amp;n,&amp;x,&amp;y,&amp;z);
	memset(dp,0,sizeof dp);
	end=1&lt;&lt;x+y+z-1;
	end=end|(1&lt;&lt;y+z-1);
	end=end|(1&lt;&lt;z-1);//end记录满足俳句的状态
	sum=(1&lt;&lt;(x+y+z))-1;
	dp[0][0]=1;
	for(int i=1;i&lt;=n;i++)
	{
		ans*=10;
		ans%=mod;
		for(int j=0;j&lt;=sum;j++)
		{
			if(dp[i-1][j]==0) continue;
			for(int k=1;k&lt;=10;k++)
			{
				int now=(j&lt;&lt;k)|(1&lt;&lt;k-1);//上面提到的二进制码转移
				now&amp;=sum;//防止now溢出
				if((now&amp;end)!=end)//如果状态存在俳句则不进行转移
					dp[i][now]=(dp[i][now]+dp[i-1][j])%mod;
			}
		}
	}
	for(int j=0;j&lt;=sum;j++)
		ans=(ans-dp[n][j]+mod)%mod;//用总字串数减去不满足俳句字串数
	printf(&quot;%lld&quot;,ans);
	return 0;
}
```

