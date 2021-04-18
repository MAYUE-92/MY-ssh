pandas对象拥有一组常用的数学和统计方法。它们大部分都属于约简和汇总统计，用于从Series中提取的个值（如sum或mean)或从DataFrame的行或列中提取一个Series。

数据读取

```
import numpy as np
import pandas as pd
import os
os.chdir(r'F:\Python\Pandas\documentation')data = pd.read_excel("./Excel文件.xlsx",0)
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2zw0BsqLTscAu9bE63ZgTKo5D5kswibTo1TBfFnGagURERInyJ39a2zia8LbPZZQ95CPZfHxl1FulJw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

**【统计函数】**

1.协方差

```
data['金额'].cov(data['数量'])data.cov()
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2zw0BsqLTscAu9bE63ZgTKoy0JEargXcwmuXtiakfk2AUWv5Oy4eXjiav7rtUF4XmqyU0P117QdLANA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

2.相关系数

默认情况下corr计算相关性时用到的方法是pearson，也可以指定kendall或spearman。

```
data['金额'].corr(data['数量'])
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2zw0BsqLTscAu9bE63ZgTKoabBfg9KdKtnB5HOXavQJUUBfxNnEKUAoTWfA6gGJfYUOyeh3iarwpag/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

```
data.corr(method="kendall")
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2zw0BsqLTscAu9bE63ZgTKoOzH1M6Jyn2Af3Ta7V3yicbjibbekKwkTB5icLgRmCqoC8EUG4DaoEj7JA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

```
data.corr(method="spearman")
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2zw0BsqLTscAu9bE63ZgTKoLLiaZ0TgCPsyC6OP2G3D8AI3opdfJKEDiajvmIXff23Ye5Tuv70T3s0Q/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

3.其他常用函数

```
data['金额'].count() #非空计数
data['金额'].sum() #求和
data['金额'].mean() #平均值
data['金额'].median() #中位数
data['金额'].min() #最小值
data['金额'].max() #最大值
data['金额'].std() #标准差
data['金额'].var() #方差
data['金额'].quantile(0.1) #分位数，取值0-1，表示在不同分位的值
```

**【排名】**

排名，默认相同取均值

```
data['mean'] = data['数量'].rank()
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2zw0BsqLTscAu9bE63ZgTKodujodOxlxd0oeDyJeKNzD5HM77XicHbwibEzesYNWYKdVD4p7RicrhboA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

通过method方法，相同值min取最小值

```
data['min'] = data['数量'].rank(method = 'min')
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2zw0BsqLTscAu9bE63ZgTKoEpbcGp2FExZMlmjm9NEQYFjVj6r1JOgTJYiaib0BqwibwDABkb5EeDLlg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

通过method方法，相同值max取最大值

```
data['max'] = data['数量'].rank(method = 'max')
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2zw0BsqLTscAu9bE63ZgTKoT5zqj4pkfibDLKFZVgBO6txGwVWx7mafgeBrrHlVC8NtibVxbtX3POYw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

按出现的顺序依次排序，不会出现排名重复的情况

```
data['first'] = data['数量'].rank(method = 'first')
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2zw0BsqLTscAu9bE63ZgTKoPq9VA5aDyVMYlJH0qeJ89Q9A1B7LF49yYiaIQOgueKmFyA89xIMpJOw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

ascending=FALSE，倒序

```
data['last'] = data['数量'].rank(method = 'first',ascending=False)
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2zw0BsqLTscAu9bE63ZgTKoapzSxfUHvGA3uGYxUO0QiacgHtKKzicryv1ibeLcXrVL7XazOnYJ4R8QQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

**【窗口函数】**

有的时候，我们需要对不同时间段中的数据进行一个统计，比如3日平均值，3日求和，这样看上去数据更平滑

```
s = data.rolling(window=3,on='日期').sum()data['r3数量'] = s['数量']
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2zw0BsqLTscAu9bE63ZgTKoiazxHl0Bf3nYJu2pjeOFBCOia0FMX3sp1GSxiaKYiaia4lDnmrnlRevwaHA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

上面运行结果有缺失值，导致这个结果的原因是因为在计算时，窗口中默认需要的最小数据个数与窗口长度一致，这里可以设置min_periods=1来修改下

```
s = data.rolling(window=3,on='日期',min_periods=1).sum()data['r3数量'] = s['数量']
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2zw0BsqLTscAu9bE63ZgTKo4ruJBjhbbTbicpDcxvgTPdicMZ5ApPa35IQdzAjyfqlqdQ2hWU1AxVRw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

通过图形展示

```
data['金额'].plot(style='k--')data.rolling(window=5,on='日期').mean()['金额'].plot(style='r')
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2zw0BsqLTscAu9bE63ZgTKo7l0tzn4hkwnjTBBNAtVic1ntice42LdzxoS5nqW7pjbv8RqQgacmxEVg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)
