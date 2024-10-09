{{ self.title() }}

{{ s('description') }}

若 $h=\{h_1,h_2,\cdots h_n\}$ 存在 $1\le x<y<z<w\le n+1$ 满足 $\sum\limits_{i=x}^{y-1}h_i=X,\sum\limits_{i=y}^{z-1}h_i=Y,\sum\limits_{i=z}^{w-1}h_i=Z$ 时，则称数列 $h$ 是**好的**

wm3 想知道在所有长度为 $n$ 且 $h_i\in\mathbb{N}^{+}\cap[1,10]$ 的 $10^n$ 个序列 $h$ 中，有多少个序列是**好的**，答案对 $10^9+7$ 取模。

{{ s('input format') }}

{{ self.input_file() }}

第一行4个数 $n$， $X$， $Y$， $Z$

{{ s('output format') }}

{{ self.output_file() }}

一行一个整数表示合法序列的数量对 $10^9+7$ 取模的结果

{{ s('sample', 'ex1') }}

{{ self.sample_text() }}

{{ s('sample', 'ex2') }}

{{ self.sample_text() }}

{{ s('sample', 'ex3') }}

{{ self.sample_text() }}

{{ s('subtasks') }}

{{ tbl('data') }}

{{ s('hint') }}

这里是一个非常温馨的提示。