数据还是之前的数据

```
import numpy as np
import pandas as pd
import os
os.chdir(r'F:\Python\Pandas\documentation')
df = pd.read_excel('./Excel文件.xlsx')
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xfqsC66Rj2A9VJXllTWfibckONS5Obl2azAfrezM1RUAdCz2w0l5tRB7RzJic6Ax58ns0mCia4iaL4jg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

1.选取特定列，可以改变顺序

```
df01 = df[["省份","ID"]]
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xfqsC66Rj2A9VJXllTWfibcr0s5TcsrvvUM1VBF5mibCTpFeJTTDcDfdicicqh6lOeibwUa7cIAUhLbqg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

2.选取特定行

```
df02 = df[2:6] #选择3-6行
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xfqsC66Rj2A9VJXllTWfibc3epjicSabUoQYSVGayG91LAnDtQWD8QWwdhf1MiaIVk7ODaRK5WE6IYw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

```
df03 = df[::2] #间隔一行筛选
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xfqsC66Rj2A9VJXllTWfibcHiaibPaaH6kLo1NLTlWGAHD0zQY4iaL1saW3YbIZ1XjI8AUaxibd7bMWqQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

```
df04 = df[::-1] #倒序排列
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xfqsC66Rj2A9VJXllTWfibcoGHuEgAPuuDI526WWwe0GEXvytwd0ZVg5z7qcJQiclsoic2ENajEUROg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

3.选择赋值操作

```
df1 = df.copy()df1[2:5] = 'aaa'
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xfqsC66Rj2A9VJXllTWfibcibSbhibnYpdqfmM3eAaPdpXjPAyhMpapeticZFJgnyFicWPy603pHlNibkg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

4.loc选择

loc主要是基于标签(label)的，包括行标签(index)和列标签(columns)，即行名称和列名称，可以使用df.loc[index_name,col_name]选择指定位置的数据。

```
df.loc[1:5,] #2-6行
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xfqsC66Rj2A9VJXllTWfibcY0ZHic9fudOFqFwpyXRY4Fyh3hDNZZPaMDaJ4fWYjMvk9N7AFELBuDg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

```
df.loc[1:5,['ID','省份']] #2-6行，ID、省份两列
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xfqsC66Rj2A9VJXllTWfibcKicibo5icDBz9PSekp2aH7F6h65kA4dMqcYsoWF22HsC1jAZFeKOcMXEw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

```
df.loc[1:5,'ID':'金额'] #2-6行，ID到金额四列
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xfqsC66Rj2A9VJXllTWfibcIaYvWNSEjypHvbhYhYWFzzic5WFmv95EpQwxGmoibB2Ht9pA6DMlIIWw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

5.iloc选择

iloc，通过行号索引行数据是基于位置的索引，如果column name太长，输入不方便，或者index是一列时间序列，更不好输入，那就可以选择 .iloc了，该方法接受列名的index,iloc 使得我们可以对column使用slice（切片）的方法对数据进行选取。

```
df.iloc[1:3,] #2-3行
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xfqsC66Rj2A9VJXllTWfibcfJfSCD2dcPzrjG3MYnMcOOsIib5rGicmY4Hu8tuCvk4Csk1vOcP2orVA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

```
df.iloc[1:5, 0:3] #2-5行，1-3列
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xfqsC66Rj2A9VJXllTWfibcmEPnPGftiaAxCS9swzqVUpDvhOBCQ03sXhAT3sGpAWdUF1WpxqMhxJA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

```
df.iloc[[1,3,4,5], [0,2,4]] #1/3/4/5行，1/2/4列
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xfqsC66Rj2A9VJXllTWfibcr5wCZ5tZPfKpfr2DQtibibXfic72QejxLPDfgNzbzBkEJsfhlqXagjSug/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

```
df.iloc[:,1:4] #所有行，2-4列
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xfqsC66Rj2A9VJXllTWfibcEfbteh9ac1GhcP5JwibwpKFZnDMDf4DYTUw7AiaicN1iaCmHfzRibx2zoqQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

```
df.iloc[1,2] #第二行，第三列
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xfqsC66Rj2A9VJXllTWfibczKA3T2Qicko3d0WVYArthFLRIMcx9wB4HHmGBTnIWMLuTRRpviaxU4UA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

6.at函数

at函数，根据指定行index及列label，快速定位DataFrame的元素，选择列时仅支持列名:data.at[row_index,'column_names']

```
df.at[0,"省份"]
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xfqsC66Rj2A9VJXllTWfibczQn4tNib4lRnBKicWGibT1ywDpTgUOpLBViaT82y4yibVzFt6UNQdJnLshQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

7.iat函数

iat函数，与at的功能相同，只使用索引参数:data.iat[row_index,column_index]

```
df.iat[0,2]
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xfqsC66Rj2A9VJXllTWfibc5uic0m6JwzwrNuFJCMpm4TrhMRYP60VKgicZh3MvNAeic7ncIywXnGwww/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

8.随机选择sample

默认情况下，每行具有相同的选择概率，但如果希望行具有不同的概率，则可以将sample函数采样权重作为weights。这些权重可以是列表。

```
df.sample(n=5, weights="数量")
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xfqsC66Rj2A9VJXllTWfibcU2ia8vLjldqz4L9sqAhOqTbPibwzibBwDRyyPoic6qM6icIWicBlotbwUOmw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

9.布尔索引筛选

```
#金额大于500的行
df[df["金额"]>550]
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xfqsC66Rj2A9VJXllTWfibcvCibQaHsVRgOEQL3T4eSXfz84geg7hLy1KJgIlCHwNuTTfwpMkRZD5Q/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

10.列表推导和map系列方法也可用于产生更复杂的标准

```
#ID以8结尾的行
con = df['ID'].map(lambda x: x.endswith("8"))
df[con]
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xfqsC66Rj2A9VJXllTWfibciaVHsl0cEFAQwW9s6SmfjTibX4icrRgrKhohwWI2deFoM17H6k6G6MiarQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

11.模糊筛选

```
#省份包含西（江西、西藏）或者南（湖南）
con = df['省份'].str.contains("西|南")
df[con]
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xfqsC66Rj2A9VJXllTWfibcykFFqrIPTNv0xTYhbURrsiayiaicwQILwbjGHVNQHAwnicmdXlcVIianQSw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

```
#省份不包含西（江西、西藏）或者南（湖南）,在条件前面加上~
con = df['省份'].str.contains("西|南")
df[~con]
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xfqsC66Rj2A9VJXllTWfibcZDNkQ7fnLEdJbqbtibG40Ya0mgkrzJPQBfL98ibRTT6UJ72Eue3TAicicA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

12.行列筛选

```
con = df['金额'].map(lambda x: x>500) #金额大于500

#金额大于500，省份不=四川和湖南，制定4列数据
df.loc[con & (df['省份']!="四川") & (df['省份']!="湖南"),['ID','日期','金额','省份']]
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xfqsC66Rj2A9VJXllTWfibcvK6QP5nV3SGzvia2rFc58jB6EIchf8GnEciad93afbgS7yicg1OtFKnvA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

13.使用isin进行索引

```
con = df['省份'].isin(['四川','江西'])
df[con]
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xfqsC66Rj2A9VJXllTWfibcHJqK1niaZESmvvTN4l0pRW5nYfEQCOW8X7VQluj0ZsuziaDyTaraaLVQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

14.重复数据

duplicated 返回一个布尔向量，其长度为行数，表示行是否重复

```
df['省份'].duplicated(keep='last')
```

```
df.duplicated('省份', keep='last')
```

drop_duplicates删除重复的行

```
df.drop_duplicates("省份", keep='last')
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xfqsC66Rj2A9VJXllTWfibcDjHGUfwx4yDHt5FpOoxG1ia3PZ5iaJ5q0Xwu8O1qj2X07BAxfNDtQWAA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

*

```
df.drop_duplicates(['省份','数量'], keep='first').sort_values(by='省份').reset_index(drop=True)
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xfqsC66Rj2A9VJXllTWfibcFFLlOlO2DWr9Y5u02dAPbwGIibSOMqBdribsuanp0a7OMYBzfb1c1w4A/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

*
*

```
#keep=False：标记/删除所有重复项df.drop_duplicates("省份", keep=False)
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xfqsC66Rj2A9VJXllTWfibcdQasjFp59XyGmcCUyWHiaCno7oMe6gQI7fFQwy5x8iclib5EoEKgqvtfg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)
