{{ self.title() }}

{{ s('background') }}

这是一道 cdx 当年场切的题

{{ s('description') }}

wm4 拿到了 $n$ 个正整数 $a_1,a_2, \cdots ,a_n$ 和一个正整数 $c$

他想知道最大的 $t$ ($t \le c$) 使得存在从 $a$ 中选出若干个数的方案满足和为 $t$

{{ s('input format') }}

{{ self.input_file() }}

第一行输入一个整数 $T$ 表示数据组数

对于每组数据：

第一行输入两个整数 $n$，$c$

接下来一行 $n$ 个数表示 $a_1$ 到 $a_n$

{{ s('output format') }}

{{ self.output_file() }}

每组数据输出一个数 $t$ 表示最大的小于等于 $c$ 的子集和

{{ s('sample', 'ex1') }}

{{ self.sample_text() }}

{{ s('subtasks') }}

{{ tbl('data') }}

{{ s('hint') }}

这里是一个非常温馨的提示。