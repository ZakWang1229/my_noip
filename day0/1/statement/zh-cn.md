{{ self.title() }}

{{ s('background') }}

这是一道 cdx 当年场切的题

{{ s('description') }}

wm1 和 wm2 在玩一个游戏：有两堆石子，每次操作可以选择一个有偶数个石子的石子堆，将其中一半石子移到另一堆

wm1 先手，不能操作者输

给定 $n, m$, 问有多少数对 $(a,b)$ ($1\le a\le n,1\le b\le m$) 满足如果初始两堆分别有a和b个石子的条件下 wm1 赢/平/输的方案数

{{ s('input format') }}

{{ self.input_file() }}

第一行输入 $T$ 表示数据组数

对于每组数据：

第 1 行以二进制形式输入正整数 $n$

第 2 行以二进制形式输入正整数 $m$

{{ s('output format') }}

{{ self.output_file() }}

对于每组数据，输出一行三个数表示 wm1 赢/平/输的方案数

{{ s('sample', 'ex1') }}

{{ self.sample_text() }}

{{ s('subtasks') }}

{{ tbl('data') }}

{{ s('hint') }}

这里是一个非常温馨的提示。