{{ self.title() }}

{{ s('description') }}

wm5 给了你 $n$ 个字符串 $s_1, s_2, \cdots, s_n$

你需要求出一个字典序最小的长度为 $k$ 的字符串 $t$，使得存在一个序列 $1\le i_1 < i_2 < \cdots < i_m \le n$ 满足 $t = s_{i_1}+s_{i_2}+\cdots+s_{i_m}$

{{ s('input format') }}

{{ self.input_file() }}

第一行输入两个整数 $n$ 和 $k$

接下来 $n$ 行，第 $i$ 行输入一个字符串 $s_i$，字符串总长度不超过 $10^6$

{{ s('output format') }}

{{ self.output_file() }}

输出一个字符串 $t$ 表示答案

保证有解

{{ s('sample', 'smallrand0') }}

{{ self.sample_text() }}

{{ s('sample', 'smallrand1') }}

{{ self.sample_text() }}

{{ s('sample', 'smallrand2') }}

{{ self.sample_text() }}

{{ s('subtasks') }}

{{ tbl('data') }}

特殊性质 A：所有 $s_i$ 只由一个字符构成

特殊性质 B：每个 $s_i$ 形如若干个 z 加上一个 a ，即 $\overline{zzz\cdots za}$

特殊性质 C：每个串都形如 $\overline{bababa\cdots}$

{{ s('hint') }}

这里是一个非常温馨的提示。