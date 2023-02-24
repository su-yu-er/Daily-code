id：fc5c46085eafa85b93bb7278b81ad63fe0aa9a80
		894612

# 一、冒泡排序函数

## A - 进阶模拟qsort

```c
#include<stdio.h>
#include<stdlib.h>

//交换函数
void swap(char* x, char* y, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char c = *x;
		*x = *y;
		*y = c;
		x++;
		y++;
	}
}

//实现bobble排序程序员不一定知道未来排序的数据类型
void bobble_sort(void* base, int sz, int width, int(*cmp)(void* a, void* b))
{
	int i = 0, j = 0;
	//趟数
	for (i = 0; i < sz - 1; i++)
	{
		//每趟比较的对数
		for (j = 0; j < sz - 1 - i; j++)
		{
			//两个元素比较
			if (cmp((char*)base + j * width, (char*)base + (j+1) * width) > 0)
			{
				//交换
				swap((char*)base + j * width, (char*)base + (j+1) * width, width);
			}
		}		
	}
}

int cmp(const void* x, const void* y)
{
	int* a = (int*)x;
	int* b = (int*)y;
	return *a - *b;
}

int main()
{
	int i = 0;
	int arr[5] = { 2,5,1,6,8 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	//qsort(arr,5, sizeof(arr[0]), cmp);

	bobble_sort(arr, sz, sizeof(arr[0]),cmp);

	for (i = 0; i < 5;i++)
	{
		printf("%d ", arr[i]);
	}
	
	return 0;
}
```





# 二、dfs与bfs

#### 1、什么是搜索

**dfs(暴力搜索)**  

**bfs-?（搜索最小，最少**）

连通块

常见 染色法

A* 

#### 2、dfs和bfs模板

dfs一定需要传入参数，来转移状态，

```c
void dfs(参数)//一般都是层数
{
    if (不合法状态)
        return;
    if (当前为终点/边界)
    {
        进行或计数统计答案等操作
        return;//终止当前函数}
    }//终止条件的
    for (枚举当前的所有方案)
    {
        if(当前方案合法/当前方案没有被标记过)
        {
            记录当前方案
            标记当前方案
            dfs（下一位置)
            还原标记
        }
    }
}
```

bfs看心情

![img](https://img-blog.csdnimg.cn/20210217121643395.gif)

```c
void bfs(起始点) {
    将起始点放入队列中;
    标记起始点访问;
	while (如果队列不为空){
		访问队列首元素;
		删除队列首元素;
		for (x 所有相邻的点){
			if (该点未访问且合法){
				将该点加入队列末尾; 
			}
		} 
	} 
	队列为空，BFS结束; 
}
```

## 案列

## dfs（深度搜索）

### [A - 全排列问题](https://vjudge.csgrandeur.cn/contest/541415#problem/A)

```C++
#include<iostream>
#include<iomanip>

using namespace std;
const int N=100;
int n,ans[N];
bool vis[N];

void pr()
{
	for(int i=1;i<=n;i++) cout<<setw(5)<<ans[i];
	cout<<endl;
}

bool rule(int x)
{
	return !vis[x];
}

void dfs(int cnt)
{//cnt是层数
	if(cnt==n+1)
    {
		pr();//打印ans数组
		return ;
	}
	for(int i=1;i<=n;i++)
    {
		if(rule(i))
        {
			ans[cnt]=i;
			vis[i]=1;
			dfs(cnt+1);
			vis[i]=0;
		}
	}
}

int main()
{
	cin>>n;
	dfs(1);
	return 0;
}
```



### [B - Lake Counting S](https://vjudge.csgrandeur.cn/contest/541415#problem/B)

```C++
#include<iostream>
#include<iomanip>

using namespace std;
const int N=105;
int n,ans[N],m;
bool vis[N][N];
char s[N][N];
int dis[8][2]={{1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};



bool rule(int x,int y){//是否走过，是否越界，是否能够走
	return !vis[x][y]&&x>=1&&x<=n&&y>=1&&y<=m&&s[x][y]=='W';
}

void dfs(int x,int y){//x,y下标
	for(int i=0;i<8;i++){
		int dx=x+dis[i][0];
		int dy=y+dis[i][1];
		if(rule(dx,dy)){
			vis[dx][dy]=1;
			s[dx][dy]='.';
			dfs(dx,dy);
		}
	}
}

int main(){
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s[i][j]=='W')
				dfs(i,j),s[i][j]='.',ans++;
	cout<<ans<<endl;
	return 0;
}
```

### C - 全组合

题目：

实质上就是N个数字遍历 例如N = 3 分别遍历出：
1
2
3
1 2
1 3
2 3
1 2 3
遍历以上的饲料是否符合条件
核心程序就是

```c++
#include <iostream>
#include <cstdio>
#define MAX 22
using namespace std;
int n,r,x; 
int a[MAX] = {1};
bool visited[MAX];
void Dfs(int k)
{
	int i;
	if(k == x + 1)
	{
		for(i = 1;i <= x;i++)
		{
			printf("%3d",a[i]);
		}
		return 0;
	}
	for(i = a[k - 1];i <= n;i++)
	{
		if(visited[i] == 0)
		{
			visited[i] = 1;
			a[k] = i;
			Dfs(k + 1);
			visited[i] = 0;
		}
	}
}
int main()
{
    //n为排列组合的最大范围数。
    //r为排列组合的长度。
    //x为当前dfs的层数。
	cin >> n >> r;
	for(x = 1;x <= r;x++)
	{
		Dfs(1);
	}
	
	return 0;
}

```



## bfs（广度搜索）

### A - 抓住那头牛

题目：农夫约翰被告知一头逃跑的奶牛的位置，想立即抓住她。他从数字线上的*点 N*（0 ≤ *N* ≤ 100，000）开始，母牛在同一数字线上的点 K （0 ≤ *K* ≤ 100，000）。 农夫约翰有两种交通工具：步行和传送。

*步行：FJ可以在一分钟内
从任何点X移动到*点X-1*或X + 1*传送：FJ可以在一分钟内从任何点X移动到2× *X*点。

如果这头牛不知道它的追逐，根本不动，农夫约翰需要多长时间才能取回它？

输入

第 1 行：两个空格分隔的整数：*N* 和 *K*

输出

第 1 行：农夫约翰抓住逃跑的牛所需的时间最短，以分钟为单位。

样本

| 输入复制 | 输出复制 |
| -------- | -------- |
| `5 17`   | `4`      |

提示

农夫约翰到达逃逸牛的最快方法是沿着以下路径移动：5-10-9-18-17，需要 4 分钟。

```c
#include<iostream>
#include<queue>
using namespace std;
const int N = 1e5 + 10;
int n, m;
bool vis[N];

//判断函数，检查数据是否合理、位置是否被标记
bool rule(int x) {
    return x >= 0 && x <= 100000 && !vis[x];
}

//结构体node创建
struct node {	//step为步数
    int x, step;//x为数字线上的位置		
};

//bfs函数
void bfs() {
    
    queue<node>st;//建立一个node类型的对列
    node cur, temp;//定义两个node变量
    temp.x = n, temp.step = 0;
    st.push(temp);//入队
    vis[n] = 1;//标记搜索过的位置
    
    while (!st.empty()) 
    {
        cur = st.front();//获得st队列的首元素
        st.pop();//出队
        if (cur.x == m) //判断是否到达目标位置
        {
            cout << cur.step << endl;
            return;
        }
        temp.step = cur.step + 1;//步数加一
        
        //每一次搜索的三种分支
        if (rule(cur.x + 1))
            temp.x = cur.x + 1, st.push(temp), vis[temp.x] = 1;
        if (rule(cur.x - 1))
            temp.x = cur.x - 1, st.push(temp), vis[temp.x] = 1;
        if (rule(cur.x * 2))
            temp.x = cur.x * 2, st.push(temp), vis[temp.x] = 1;
    }
}

int main() {
    cin >> n >> m;
    bfs();
    return 0;
}
```





# 三、博弈

## 1、理论铺垫

1、定义P-position和N-position：其中P代表Previous，N代表Next。直观的说，上一次move的人有必胜策略的局面是P-position，也就是“先手必败”，现在轮到move的人有必胜策略的局面是N-position，也就是“先手可保证必胜”。

（1）.无法进行任何移动的局面（也就是terminal position）是P-position；

（2）.可以移动到P-position的局面是N-position；

（3）.所有移动都导致N-position的局面是P-position。

2、P/N状态有如下性质：

（1）、若面临末状态者为获胜则末状态为胜态否则末状态为必败态。
（2）、一个局面是胜态的充要条件是该局面进行某种决策后会成为必败态。
（3）、一个局面是必败态的充要条件是该局面无论进行何种决策均会成为胜态
3、P点： 即必败点，某玩家位于此点，只要对方无失误，则必败；

   N点： 即必胜点，某玩家位于此点，只要自己无失误，则必胜。

4、取石子游戏算法实现

步骤1:将所有终结位置标记为必败点（P点）；

步骤2: 将所有一步操作能进入必败点（P点）的位置标记为必胜点（N点）

步骤3:如果从某个点开始的所有一步操作都只能进入必胜点（N点） ，则将该点标记为必败点（P点） ；

步骤4: 如果在步骤3未能找到新的必败（P点），则算法终止；否则，返回到步骤2

/*

a.如果当前是P点，那么一步（向前）可以走到的都是N点

b.如果当前点未标明P/N属性，那么看看该点向后走是不是都只能到达N点，如果是，那么该点是P点。

c.如果该点是N点，倒无法确定什么。

如果没办法标一个点，那么异常结束。

*/

## 2、常见的博弈类别

### A、威佐夫博弈

### 博弈条件：

威佐夫博弈（Wythoff's game）：有两堆各若干个物品，两个人轮流从任一堆取至少一个或同时从两堆中取同样多的物品，规定每次至少取一个，多者不限，最后取光者得胜。



#### 结论：

两个人如果都采用正确操作，那么面对非奇异局势，先拿者必胜；反之，则后拿者取胜。那么任给一个局势（a，b），怎样判断它是不是奇异局势呢？我们有如下公式：

ak =[k（1+√5）/2]，bk= ak + k （k=0，1，2，...n 方括号表示取整函数)



奇妙的是其中出现了[黄金分割数](https://baike.baidu.com/item/黄金分割数/10996195?fromModule=lemma_inlink)（1+√5）/2 = 1.618...因此，由ak，bk组成的矩形近似为黄金矩形，由于2/（1+√5）=（√5-1）/2，可以先求出j=[a（√5-1）/2]，若a=[j（1+√5）/2]，那么a = aj，bj = aj + j，若不等于，那么a = aj+1，b = aj + j + 1，若都不是，那么就不是奇异局势。然后再按照上述法则进行，一定会遇到奇异局势。



#### 证明

**定理 0**：一个状态是必败态，当且仅当它的所有后继状态都是必胜态；而一个状态是必胜态，只要它的后继状态有一个以上的必败态即可。

证明略去。

容易发现下面的定理：

**定理 1**：(a，b) 和 (b, a) 的胜负性是相同的（a <> b）。

证明：如果 (a, b) 是必胜态，那么将必胜策略中所有的操作，对第一堆的变为第二堆，对第二堆的变为第一堆，就构成 (b, a) 的必胜策略

**定理 2**：若 (a, b) 是必败态，则对于所有的 x <> a 和 y <> b，(x, b) 和 (a, y) 是必胜态。

证明：

对于 x > a 和 y > b，不管是哪一种情况，总可以从 x 堆或 y 堆中取出一定量的石子使当前状态变为必败态 (a, b)，由定理 1，(x, b) 和 (a, y) 为必胜态。

对于 x < a 和 y < b，不管是哪一种情况，如果 (x, b) 或 (a, y) 是必败态的话，由上述可得 (a, b) 是必胜态，矛盾。故 (x, b) 和 (a, y) 均为为必胜态。

**定理 3**: 若 (a, b) 是必败态，则对于所有的 d > 0，(a + d, b + d) 是必胜态。

证明：

与定理 2 类似。

**定理 4**：在所有的必败态中，每个数字恰巧出现一次。

证明：

有了定理 1，对于对称的状态我们只需要处理其中一个，而两个数不会相同（相同的状态必然是必胜态），于是我们把每个状态中较小的数字放在前面，每行写一个状态，去掉括号并按照升序排列每行的第一个数，就构成了如下的矩阵：

1 2

3 5

4 7

6 10

……

假设数字k在矩阵中出现两次或两次以上，则有(k,a)，(k,b)都为必败态，与定理2矛盾。

假设数字k为序列中没有出现且值最小的数字，则有 (k,k+i)为必胜态(i>0)，则对任意i，必然存在j(0<j<k)使得(k-j,k+i-j)或(k,k+i-j)或(k-j,k+i)为必败态 (若不如此，则无论如何取石子，对方必胜)，根据假设，显然(k,k+i-j)必胜，因此，对任意i，必有(k-j,k+i-j)或(k-j,k+i)=0, (0<j<k) 必败

根据[鸽巢原理](https://baike.baidu.com/item/鸽巢原理/731656?fromModule=lemma_inlink)，必然存在3个i的取值(其实是无穷多个，j只有k-1种取值，而i有无数种)记为i1, i2, i3使得j1=j2=j3=m。对这3个i，同样必然存在一对i，不妨为(i1,i2)，使(k-m,k+i1-m)且(k-m,k+i2-m)必败或f(k-m,k+i1)且f(k-m,k+i2)必败。显然与定理2矛盾，因此不存在这样的数k。

观察这个矩阵，我们又可以得到新的定理：

**定理 5**：矩阵中每行第一个数恰巧是前面每一行中没有出现过的最小正整数。

证明：

由定理 4，矩阵中每个数字恰巧出现一次，而按照这个矩阵的定义，第二列的数总比同行第一列大，第一列又按照升序排列，所以每一行的第一个数正好为前面每一行中没有出现过的最小正整数。

**定理 6**：矩阵第 i 行的第二个数正好为第一个数加上 i

证明：

用[数学归纳法](https://baike.baidu.com/item/数学归纳法/5155524?fromModule=lemma_inlink)。

\1) 对于第一行显然成立

\2) 若对于前 i - 1 行均成立，则所有的 (a[p], a[p] + p) (a[p] 为第 p 行第一个数，p < i) 均为必败态，那么考察第 i 行的状态 (a[i], a[i] + delta)。容易看出 delta >= i，因为如果 delta < i，一定可以通过一次操作变为前面出现过的必败态，那么这个状态就是必胜态。下面由 delta >= i，我们来说明 delta = i。

首先，我们考虑从第一堆中取出 p 个石子，得到状态 (a[i] - p, a[i] - p + delta)，由定理 5，比 a[i] 小的数都在之前出现过，若 a[i] - p 出现在某一行的第一列，由于存在必败态 (a[i] - p, a[i] - p + d) (d < delta)，故 (a[i] - p, a[i] - p + delta) 一定为必胜态（定理 2）；若 a[i] - p 出现

![img](https://bkimg.cdn.bcebos.com/formula/f30b7a1b850897cc537ad0496a0fe0d2.svg)

在某一行的第二列，由于第一列是单增的，因而其对应的第一列数必小于 a[i] + delta，故而也可推出其状态为必胜态。

对于从两堆石子中取出相同数目的情况与之类似，容易看出一定为必胜态。

于是，(a[i], a[i] + delta) 状态的胜负性只与状态 (a[i], a[i] + d) (d < delta) 有关。不难看出，delta = i 时恰为必败态，因为不论从第二堆中取出多少个石子，作为另一堆的第一堆石子并没有在之前出现过，所以得到的一定是一个必胜态，因而 (a[i], a[i] + delta) 为必败态，由定理 2 及定理 4 可得，原命题成立。即矩阵中第 i 行第二列的数等于同行第一列的数加上 i。

这时，我们所有的问题都转化到了矩阵上，只要能通过合适的方法表示出这个矩阵，我们就可以很好地解决原问题。

下面的过程可能需要比较高的数学技巧，首先给出我们需要的一个重要定理（[x] 表示 x 的整数部分，{x} 表示 x 的小数部分，即 {x} = x - [x]）：

**定理 7**（Beatty 定理）：如果存在正无理数 A, B 满足 1/A + 1/B = 1，那么集合 P = { [At], t

证明：详见Beatty定理。

考虑到 Beatty 定理中“恰为 Z

于是我们得到每一行第二列的数为 [

我们的目的是要让 Z

于是应用 Beatty 定理，我们得到最终我们需要的定理：

**定理 8**：上述矩阵中每一行第一列的数为 [

证明：由 Beatty 定理显然得证。

设a、b是正[无理数](https://baike.baidu.com/item/无理数?fromModule=lemma_inlink)且 1/a +1/b =1。记P={ 【na】 | n为任意的[正整数](https://baike.baidu.com/item/正整数?fromModule=lemma_inlink)}，Q={ 【nb】 | n 为任意的正整数}，则P与Q是Z+的一个划分，即P∩Q为空集且P∪Q为正整数集合Z+。

证明：因为a、b为正且1/a +1/b=1，则a、b>1，所以对于不同的整数n，【na】各不相同，类似对b有相同的结果。因此任一个整数至多在集合P或Q中出现一次。

\* 现证明P∩Q为空集；([反证法](https://baike.baidu.com/item/反证法?fromModule=lemma_inlink))假设k为P∩Q的一个整数，则存在正整数m、n使得【ma】=【nb】=k。即k < ma、nb<k+1，等价地改写不等式为

\* m/(k+1)< 1/a < m/k及n/(k+1)< 1/b < n/k。相加起来得 (m+n)/(k+1) < 1 < (m+n)/k，即 k < m+n < k+1。这与m、n为整数有[矛盾](https://baike.baidu.com/item/矛盾?fromModule=lemma_inlink)，所以P∩Q为空集。现证明Z+=P∪Q；已知P∪Q是Z+的[子集](https://baike.baidu.com/item/子集?fromModule=lemma_inlink)，剩下来只要证明Z+是P∪Q的子集。(反证法)假设Z+\(P∪Q)有一个元素k，则存在正整数m、n使得【ma】< k <【(m+1)a】、【nb】< k <【(n+1)b】。 由此得ma < k ≦【 (m+1)a】-1<(m+1)a -1，类似地有nb < k ≦【 (n+1)b】-1<(n+1)b -1。等价地改写为 m/k < 1/a < (m+1)/(k+1)及n/k < 1/b < (n+1)/(k+1)。两式加起来，得

(m+n)/k < 1 < (m+n+2)/(k+1)，即m+n < k < k+1 < m+n+2。这与m, n, k皆为正整数矛盾。所以Z+=P∪Q。

![img](https://bkimg.cdn.bcebos.com/pic/0b46f21fbe096b635593ca130e338744eaf8acef?x-bce-process=image/watermark,image_d2F0ZXIvYmFpa2UxMTY=,g_7,xp_5,yp_5)

### B、巴什博弈

#### 问题模型：

只有一堆n个物品，两个人轮流从这堆物品中取物，规定每次至少取一个，最多取m个，最后取光者得胜。

#### 解决思路：

当n=m+1时，由于一次最多只能取m个，所以无论先取者拿走多少个，后取者都能够一次拿走剩余的物品，后者取胜，所以当一方面对的局势是n%(m+1)=0时，其面临的是必败的局势。所以当n=（m+1)*r+s，（r为任意自然数，s≤m)时,如果先取者要拿走s个物品，如果后取者拿走x（≤m)个，那么先取者再拿走m+1-k个，结果剩下（m+1）（r-1）个，以后保持这样的取法，那么先取者肯定获胜。总之，要保持给对手留下（m+1）的倍数，就能最后获胜。

3、变形：条件不变，改为最后取光的人输。

结论：当（n-1）%（m+1）==0时后手胜利。

### C、Fibonacci博弈

#### 1、问题模型：

 有一堆个数为n的石子，游戏双方轮流取石子，满足： 

（1）先手不能在第一次把所有的石子取完； 

（2）之后每次可以取的石子数介于1到对手刚取的石子数的2倍之间（包含1和对手刚取的石子数的2倍）。 约定取走最后一个石子的人为赢家。

#### 2、解决思路：

  当n为Fibonacci数时，先手必败。即存在先手的必败态当且仅当石头个数为Fibonacci数。 

##### 证明：

根据“Zeckendorf定理”（齐肯多夫定理）：任何正整数可以表示为若干个不连续的Fibonacci数之和。如n=83 = 55+21+5+2，我们看看这个分解有什么指导意义：假如先手取2颗，那么后手无法取5颗或更多，而5是一个Fibonacci数，那么一定是先手取走这5颗石子中的最后一颗，同理，接下去先手取走接下来的后21颗中的最后一颗，再取走后55颗中的最后一颗，那么先手赢。

反证：如果n是Fibonacci数，如n=89：记先手一开始所取的石子数为y

（1）若y>=34颗（也就是89的向前两项），那么一定后手赢，因为89-34=55=34+21<2*34。

（2）y<34时剩下的石子数x介于55到89之间，它一定不是一个Fibonacci数，把x分解成Fibonacci数：x=55+f[i]+…+f[j]，若，如果f[j]<=2y，那么对B就是面临x局面的先手，所以根据之前的分析，后手只要先取f[j]个即可，以后再按之前的分析就可保证必胜。

### D、尼姆博弈

#### 1、问题模型：

有三堆各若干个物品，两个人轮流从某一堆取任意多的物品，规定每次至少取一个，多者不限，最后取光者得胜。

#### 2、解决思路：

用（a，b，c）表示某种局势，显证（0，0，0）是第一种奇异局势，无论谁面对奇异局势，都必然失败。第二种奇异局势是（0，n，n），只要与对手拿走一样多的物品，最后都将导致（0，0，0）。

  搞定这个问题需要把必败态的规律找出：(a,b,c)是必败态等价于a^b^c=0(^表示异或运算）。

  证明:(1)任何p(a,b,c)=0的局面出发的任意局面(a,b,c’);一定有p(a,b,c’)不等于0。否则可以得到c=c’。

（2）任何p(a,b,c)不等于0的局面都可以走向 p(a,b,c)=0的局面

（3）对于 (4,9,13) 这个容易验证是奇异局势           

   其中有两个8，两个4，两个1，非零项成对出现，这就是尼姆和为  零的本质。别人要是拿掉13里的8或者1，那你就拿掉对应的9  中的那个8或者1；别人要是拿        掉13里的4，你就拿掉4里的4；  别人如果拿掉13里的3，就把10作分解，然后想办法满 足非零项成对即可。

3、推广一：如果我们面对的是一个非奇异局势（a，b，c），要如何变为奇异局势呢？假设 a < b< c,我们只要将 c 变为 a^b,即可,因为有如下的运算结果: a^b^(a^b)=(a^a)^(b^b)=0^0=0。要将c 变为a^b，只从 c中减去 c-（a^b）

4、推广二：当石子堆数为n堆时，则推广为当对每堆的数目进行亦或之后值为零是必败态。

 



# 四、快速幂

## 1、什么是快速幂算法

首先，我们先来看一道ACM程序设计题，这道题是杭电OJ中序号为2035的题目，没做过这道题目的同学可以跟着一起做一下，题目如下：

问题描述：

![img](https://img-blog.csdnimg.cn/20190102161125415.png)

这道题目乍一看会觉得并不难啊，题目短短一行而已，而且思路也很容易，求幂这种算法一般在初学程序设计语言的时候应该都有联系过，只要写一个简单的循环就能够搞定。

 * ```c++
 /**
     * 普通的求幂函数
     * @param base 底数
     * @param power  指数
     * @return  求幂结果的最后3位数表示的整数
    **/
    long long normalPower(long long base,long long power)
    {
        long long result=1;
    	for(int i=1;i<=power;i++)
    	{
        	result=result*base;
    	}
    	return result%1000;
    }
 ```c++

这道题不是分分钟解决吗？接下来，让我们来写一个主函数测试一下：

c++
int main()
{
    long long base,power;
    cin>>base>>power;
 
    cout<<"base="<<base<<" power="<<power<<" "<<normalPower(base,power)<<endl;
 
    return 0;
}
 ```

然后，让我们愉快的来求一下2^100的结果的后三位数表示的整数是什么吧！输出结果如下：

![img](https://img-blog.csdnimg.cn/20190102164900548.png)

​		为什么答案会是0呢？明明没有错误的啊！~ 

​		先不急，我们再来考虑一下，这道题其实出的很有意思，题目要求你输出结果的后三位，为什么不让你直接输出结果呢？难道仅仅只是为了增大题目的难度吗？当然不是，我们在初中就学过“指数爆炸”，下面我们在来回顾一下“指数”的概念：

​		**~指数：在乘方a中，其中的a叫做底数，n叫做指数，结果叫幂。**

​		**~f(x)=a^x ， 随着x单位长度的递增，f(x)会呈“爆炸性”增长。**

​        一张纸对折一次，厚度变成原来的2倍。再对折第二次，变为原来的2的2次方倍即4倍。以此类推，假设纸的厚度为0.1mm，则对折24次以后，长度超过1千米；对折39次达55000千米，超过地球赤道长度；对折42次达44万千米，超过地球至月球的距离；对折51次达22亿千米，超过地球至太阳的距离；对折82次为51113光年，超过银河系半径的长度。

​		因此，如果题目让你求2的100次方，貌似我们程序设计语言中最大的long lnog类型也无法承载这么大的数值，所以题目才不会要求你输出结果，因为结果可能会非常的大，大到没有任何类型可以承载。所以我们会发现上面的结果为什么是0，因为已经发生溢出了。

​		那为什么题目要求输出结果的最后三位数表示的整数呢？有的同学可能会问：求一个数的最后三位数表示的整数好办，只要用这个结果进行“取模”运算，让其对1000取模，得到的数就是这个数最后三位数表示的整数。（例如：12345的最后三位数表示的整数是：12345%1000=345）。但是，你这结果都无法求出来，让我怎么进行“取模”运算呢？你这不是瞎闹吗？

​		别急，我们首先来了解一下“取模”运算的运算法则：（具体的证明感兴趣的同学可以问度娘）

```c
 1、(a + b) % p = (a % p + b % p) % p （1） 
 2、(a - b) % p = (a % p - b % p) % p （2） 
 3、(a * b) % p = (a % p * b % p) % p （3）
```

​		其中我们只要关注第“3”条法则即可：(a * b) % p = (a % p * b % p) % p ，我们仔细研究一下这个运算法则，会发现多个因子连续的乘积取模的结果等于每个因子取模后的乘积再取模的结果。也就是说，我们如果要求：

​														**(a*b*c)%d=(a%d*b%d*c%d)%d;**

​		因此，我们可以借助这个法则，只需要在循环乘积的每一步都提前进行“取模”运算，而不是等到最后直接对结果“取模”，也能达到同样的效果。

​		所以，我们的代码可以变成这个样子：

 * ```
 /**
     
     * 普通的求幂函数
     * @param base 底数
     * @param power  指数
     * @return  求幂结果的最后3位数表示的整数
       */
       long long normalPower(long long base,long long power){
    long long result=1;
    for(int i=1;i<=power;i++){
        result=result*base;
        result=result%1000;
    }
    return result%1000;
    }
 ```
 
 我们再来测试一下，这样又能不能输出结果呢？我们仍然来求一下2^100的后三位是什么：

![img](https://img-blog.csdnimg.cn/20190102165515662.png)

​		这一次完美的得到了我们想要的结果。2^100的幂结果的后三位整数位376。

​		为了打消一些同学对这个运算法则的怀疑，我们再用一个结果比较小的式子来验证一下：我们知道2^10为1024,按理来说，最后输出的结果的后三位数表示的整数应该是24，那么是不是这样呢？我们来试一试：

![img](https://img-blog.csdnimg.cn/20190102170143355.png)

最后的结果果然是24，所以这个法则是没有问题的。我们把下面的代码提交给OJ看一下是否能通过：

```c++
#include <iostream>
#include <cmath>

using namespace std;

/**
 * 普通的求幂函数
 * @param base 底数
 * @param power  指数
 * @return  求幂结果的最后3位数表示的整数
   */
   long long normalPower(long long base, long long power) {
   long long result = 1;
   for (int i = 1; i <= power; i++) {
       result = result * base;
       result = result % 1000;
   }
   return result % 1000;
   }

int main() {
    long long base, power;
    while (true) {
        cin >> base >> power;
        if (base == 0 && power == 0) break;
        cout << normalPower(base, power) << endl;
    }
    return 0;

}
 ```

​						最后的结果是成功Accept了。

## 2、再次思考

​		虽然这个求幂的方法很有用，并且提交给OJ也直接Accept了，但是我们来考虑一下这个算法的时间复杂度，假设我们求2的100次方，那么将会执行100次循环。如果我们分析一下这个算法，就会发现这个算法的时间复杂度为O(N),其中N为指数。求一下小的结果还好，那如果我们要求2的1000000000次方呢？这个程序可能会运行很久很久，具体会多久呢，让我们来测试一下，测试代码如下：

```c++
#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

/**

 * 普通的求幂函数
 * @param base 底数
 * @param power  指数
 * @return  求幂结果的最后3位数表示的整数
   */
   long long normalPower(long long base, long long power) {
   long long result = 1;
   for (int i = 1; i <= power; i++) {
       result = result * base;
       result = result % 1000;
   }
   return result % 1000;
   }

int main() {
    clock_t start, finish;
    //clock_t为CPU时钟计时单元数
    long long base, power;
    cin >> base >> power;
    start = clock();
    //clock()函数返回此时CPU时钟计时单元数
    cout << normalPower(base, power) << endl;
    finish = clock();
    //clock()函数返回此时CPU时钟计时单元数
    cout << "the time cost is" << double(finish - start) / CLOCKS_PER_SEC;
    //finish与start的差值即为程序运行花费的CPU时钟单元数量，再除每秒CPU有多少个时钟单元，即为程序耗时
    return 0;

}
```

​		结果如图所示：

![img](https://img-blog.csdnimg.cn/20190102173019265.png)

​		我们发现，虽然结果是成功求出来了，但是用了将近18秒的时间才求出最后的答案。这效率当然是非常的低下的，更谈不上实际的生产应用了。那么有没有什么好的办法能够对其进行优化呢？接下来就是我们本次的主题了：快速幂算法。

## 3、快速幂算法初步入门

​		快速幂算法能帮我们算出指数非常大的幂，传统的求幂算法之所以时间复杂度非常高（为O(指数n)），就是因为当指数n非常大的时候，需要执行的循环操作次数也非常大。所以我们快速幂算法的核心思想就是每一步都把指数分成两半，而相应的底数做平方运算。这样不仅能把非常大的指数给不断变小，所需要执行的循环次数也变小，而最后表示的结果却一直不会变。让我们先来看一个简单的例子：

```c
3^10=3*3*3*3*3*3*3*3*3*3

//尽量想办法把指数变小来，这里的指数为10

3^10=(3*3)*(3*3)*(3*3)*(3*3)*(3*3)

3^10=(3*3)^5

3^10=9^5

//此时指数由10缩减一半变成了5，而底数变成了原来的平方，求3^10原本需要执行10次循环操作，求9^5却只需要执行5次循环操作，但是3^10却等于9^5,我们用一次（底数做平方操作）的操作减少了原本一半的循环量，特别是在幂特别大的时候效果非常好，例如2^10000=4^5000,底数只是做了一个小小的平方操作，而指数就从10000变成了5000，减少了5000次的循环操作。

//现在我们的问题是如何把指数5变成原来的一半，5是一个奇数，5的一半是2.5，但是我们知道，指数不能为小数，因此我们不能这么简单粗暴的直接执行5/2，然而，这里还有另一种方法能表示9^5

9^5=（9^4）*（9^1）

//此时我们抽出了一个底数的一次方，这里即为9^1，这个9^1我们先单独移出来,剩下的9^4又能够在执行“缩指数”操作了，把指数缩小一半，底数执行平方操作

9^5=（81^2）*(9^1)

//把指数缩小一半，底数执行平方操作

9^5=（6561^1）*(9^1)

//此时，我们发现指数又变成了一个奇数1，按照上面对指数为奇数的操作方法，应该抽出了一个底数的一次方，这里即为6561^1，这个6561^1我们先单独移出来，但是此时指数却变成了0，也就意味着我们无法再进行“缩指数”操作了。

9^5=（6561^0）*(9^1)*(6561^1)=1*(9^1)*(6561^1)=(9^1)*(6561^1)=9*6561=59049

我们能够发现，最后的结果是9*6561，而9是怎么产生的？是不是当指数为奇数5时，此时底数为9。那6561又是怎么产生的呢？是不是当指数为奇数1时，此时的底数为6561。所以我们能发现一个规律：最后求出的幂结果实际上就是在变化过程中所有当指数为奇数时底数的乘积。
```

​		让我们来看一段简单的动画演示（点击放大）：

![img](https://img-blog.csdnimg.cn/20190103145233776.gif)

​		接下来，再让我们用代码来演示一下上面的算法：

```c++
long long fastPower(long long base, long long power) {
    long long result = 1;
    while (power > 0) {
        if (power % 2 == 0) {
            //如果指数为偶数
            power = power / 2;//把指数缩小为一半
            base = base * base % 1000;//底数变大成原来的平方
        } else {
            //如果指数为奇数
            power = power - 1;//把指数减去1，使其变成一个偶数
            result = result * base % 1000;//此时记得要把指数为奇数时分离出来的底数的一次方收集好
            power = power / 2;//此时指数为偶数，可以继续执行操作
            base = base * base % 1000;
        }
    }
    return result;
}
```

​		我们再来测试一下此时的快速幂算法和普通的求幂算法的效率，我们仍然来求2的1000000000次方，看一看用时又会是多少：

![img](https://img-blog.csdnimg.cn/20190103140313548.png)

​		真让人简直不可思议，竟然只花了0.002秒就求出了结果，而且结果也是376，然而普通的算法却用了将近18秒的时间才求出最后的结果。

## 4、压榨性能再优化

虽然上面的快速幂算法效率已经很高了，但是我们仍然能够再一次的对其进行“压榨级别”的优化。我们上面的代码看起来仍然有些地方可以再进一步地进行简化，例如在if和else代码块中仍然有重复性的代码：

```c
        power = power / 2;
        base = base * base % 1000;
```
​												**而**

```c
        power = power - 1;//把指数减去1，使其变成一个偶数
        power = power / 2;
```
```
可以压缩成一句：
            power = power / 2;
```

因为power是一个整数，例如当power是奇数5时,power-1=4,power/2=2；而如果我们直接用power/2=5/2=2。在整型运算中得到的结果是一样的，因此，我们的代码可以压缩成下面这样：

```c++
long long fastPower(long long base, long long power) {
    long long result = 1;
    while (power > 0) {
        if (power % 2 == 1) {
            result = result * base % 1000;
        }
        power = power / 2;
        base = (base * base) % 1000;
    }
    return result;
}
```

接下来，我们来测试一下优化后的性能如何，仍然是求2的1000000000次方：

![img](https://img-blog.csdnimg.cn/20190103142357532.png)

结果仍然是正确的376，但时间上的花费从0.002减少成了0.001。

 

## 5、终极优化

​		在C语言中，power%2==1可以用更快的“位运算”来代替，例如：power&1。因为如果power为偶数，则其二进制表示的最后一位一定是0；如果power是奇数，则其二进制表示的最后一位一定是1。将他们分别与1的二进制做“与”运算，得到的就是power二进制最后一位的数字了，是0则为偶数，是1则为奇数。例如5是奇数，则5&1=1；而6是偶数，则6&1=0；因此奇偶数的判断就可以用“位运算”来替换了。

![img](https://img-blog.csdnimg.cn/20190103143841293.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzE5NzgyMDE5,size_16,color_FFFFFF,t_70)

​		同样，对于power=power/2来说，也可以用更快的“位运算”进行替代，我们只要把power的二进制表示向右移动1位就能变成原来的一半了。

![img](https://img-blog.csdnimg.cn/20190103144259337.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzE5NzgyMDE5,size_16,color_FFFFFF,t_70)

​		最后，我们的代码就能优化成下面这样：

```c++
long long fastPower(long long base, long long power) {
    long long result = 1;
    while (power > 0) {
        if (power & 1) {//此处等价于if(power%2==1)
            result = result * base % 1000;
        }
        power >>= 1;//此处等价于power=power/2
        base = (base * base) % 1000;
    }
    return result;
}
```

我们仍然测试一下求2的1000000000次方，看看终极优化后的代码的性能是怎样的：

![img](https://img-blog.csdnimg.cn/20190103144956564.png)

简直可怕，时间花费竟然接近于0秒，我们从最开始的18秒最后压缩到接近0秒，真的是感慨算法的威力！如果同样两家公司，采用不同的算法，给用户带来的体验区别是非常大的，这无不让我们感受到算法的威力。



# 五、矩阵快速幂

### 1、矩阵乘法

想要做矩阵快速幂，先要了解矩阵乘法。（考虑到我数学水平有限，这里不展开讲）

先定义矩阵A（n×k）、B（k×m）。

图片来自百度：

![img](https://img-blog.csdnimg.cn/2d39fd62b3f54e7db366507d103cd9a5.png)

#### 矩阵乘法的定义如下：

（1）A（左矩阵）的列数必须与 B（右矩阵）的行数相同，这也是矩阵乘方要求是正方形矩阵的原因，即矩阵自乘要求行和列数相等。

（2） C 的行数与 A（左矩阵）相同，列数与B（右矩阵）相同，即C（n×m）

（3） C 的第 i 行第 j 列的元素 C（ij）由 A 的第 i 行元素与 B的第 j 列元素对应相乘，再取乘积之和。

用一个公式来说就是：

图片来自百度：

![img](https://img-blog.csdnimg.cn/8743932f06574fc7b3e53d62bc73466b.png)

列子：

图片来自百度：

![img](https://img-blog.csdnimg.cn/img_convert/cbfbb81cc866ecf5243051736195b7aa.jpeg)

A出行，B出列，对应相乘再相加。

### 2、关于单位矩阵：

单位矩阵是一个左上到右下对角线的元素都为11，其余元素为00的矩阵，一个矩阵乘以单位矩阵（在行列数允许的情况下），根据矩阵乘法的定义，得到的结果是这个矩阵本身。

OK，了解到这里已经足够我们做矩阵快速幂了。

 矩阵快速幂代码实现
对指数k的操作同上，这里不再复述。

重要的是，重载乘法运算符，使得我们在上面的式子对于矩阵也适用。

代码实现：

```c++
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
 
struct no 
{
	long long a[5][5];
	no() 
    {
		memset(a,0,sizeof(a));
	}
};
 
int p,q,a1,a2;
long long n,Mod;
 
no X(no a,no b) 
{
	no c;
	for(int i=1; i<=2; i++)
		for(int j=1; j<=2; j++)
			for(int k=1; k<=2; k++)
				c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j])%Mod;
	return c;
}
 
no ksm(no a,long long k)
{
	no ans=a;
	for(k--; k; k>>=1,a=X(a,a))
		if(k&1)
			ans=X(ans,a);
	return ans;
}
 
int main() {
	scanf("%d%d%d%d%lld%lld",&p,&q,&a1,&a2,&n,&Mod);
	a1%=Mod;
	a2%=Mod;
	q%=Mod;
	p%=Mod;
	if(n<3) {
		if(n==1)
			printf("%d\n",a1);
		else
			printf("%d\n",a2);
		return 0;
	}
	no a;
	a.a[1][1]=p;
	a.a[1][2]=q;
	a.a[2][1]=1;
	a=ksm(a,n-2);
	printf("%lld\n",(a.a[1][1]*a2+a.a[1][2]*a1)%Mod);
	return 0;
}
```

