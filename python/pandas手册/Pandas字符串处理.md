序列和索引包含一些列的字符操作方法，这可以使我们轻易操作数组中的各个元素。最重要的是，这些方法可以自动跳过缺失值。

**数据准备**

```
import numpy as np
import pandas as pd
import os
os.chdir(r'F:\Python\Pandas\documentation')

s = pd.Series(['WangFalin', ' Apple ', ' WaW', np.nan, 'NBA  ', 'python'])
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2wcqGIeA0qNGurVnvBauv8PiaT46s1G4AmxIAJkuL6JKzSHHunBohrOY7RUt9nL1jmFbpWFI5P5V2w/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

字符串转小写

```
s.str.lower() #字符串转小写
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2wcqGIeA0qNGurVnvBauv8PDjPMfawDXUtdUX4UeI3BibnFpCAAiad8QAk8GB22CzTcvaqicxFeU8ltg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

字符串转大写

```
s.str.upper() #字符串转大写
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2wcqGIeA0qNGurVnvBauv8PLm3LvhYrwbL7RUhV4UM5GyeyibHYBysCECGSPpXeiblPJtx1CX4lUUug/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

字符串长度

```
s.str.len() #字符串长度
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2wcqGIeA0qNGurVnvBauv8PZ3BkbhwbFicaYKMY8LNA5DiadkAaOfg1j0WutcYicDtNjic4bHjxog5Nsw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

去除的空格

```
s.str.strip() #去除前后的空格
s.str.lstrip() #去除左侧的空格
s.str.rstrip() #去除右侧的空格
```

字符串替换

```
s.str.replace(" ","空格") #字符串替换
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2wcqGIeA0qNGurVnvBauv8PC9Pp5wm9C4qomkS8zJ70JuoCfry1lOkLJTthh3bODDRTYGhb54IPibA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

**【拆分和替换字符串】**

**读取数据，结果如下**

```
data = pd.read_excel('./Excel文件.xlsx',"字符串")
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2wcqGIeA0qNGurVnvBauv8P5KjeNVU58WzxzF4SibDUJZ5VzHPhUJPibVs3T5mbe8K4E29dcxu0iaa5A/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

把省市区按照“-”进行分列

```
ssq = data['省市区'].str.split('-')
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2wcqGIeA0qNGurVnvBauv8Plkz9bVCVecodYKCrfCgTBEOfoLtXCKXxCIeGpliaZOGCDxbyJVp4SPA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

切分后的列表中的元素可以通过get方法或者[]方法进行读取

获取拆分后的城市列

```
ssq.str.get(1) #获取拆分后的城市列ssq.str[1] #功能和上面一样
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2wcqGIeA0qNGurVnvBauv8PYwPkKqozYqeibMlCtSdhckwJ0BoCerMM6AsmZ9t7pIOicfglBj0DdERg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

使用expand方法可以将这种返回展开为一个数据表

```
ssq2 = data['省市区'].str.split("-",expand=True)
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2wcqGIeA0qNGurVnvBauv8PlP0eYHfrAgOP0xYlB8IEhEhXYnexkFrXefEPw3icwEl5HiambYJBZwMw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

也可以限制切分的次数

```
ssq3 = data['省市区'].str.split("-",expand=True,n=1)
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2wcqGIeA0qNGurVnvBauv8Pa8dLTuWbs9vJy58BUz7goCMbxZTdibibDSicgAVlv5HmsicFXgez8YulNQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

rsplit与split相似，不同的是，这个切分的方向是反的。即从字串的尾端向首段切分

```
ssq4 = data['省市区'].str.rsplit("-",expand=True,n=1)
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2wcqGIeA0qNGurVnvBauv8PaBTjYxf0t9UUwAqhZml5GHV1AibicfqNOTCBfQmMWcj4BxKcibupYBdqA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

**【拼接】**

将单个序列拼接为一个完整字符串

```
s = pd.Series(['A', 'b', 'c', 'd'])
s.str.cat() #如果没有额外声明sep即分隔符默认为空字串
s.str.cat(sep='-')
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2wcqGIeA0qNGurVnvBauv8PjHhiaYiaibH4bCPAktiah335MkuCK9KqvUTJ5T4DAEcS7RY8IwWrDLxcQQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

拼接序列和其他类列表型对象为新的序列

```
s.str.cat(['A', 'B', 'C', 'D'])
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2wcqGIeA0qNGurVnvBauv8PQO1kJaJVYo4nKArvvYhkobAlzFtx6ibs9QzWnVdMRvoET8aOVUaqxsA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

```
data['ID'].str.cat(data['金额'].astype(str))
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2wcqGIeA0qNGurVnvBauv8Ph1wgAAUMnGsicohKq5cczCMq4icMDkp68ohMGbgQLfylul7TVeJYVK9A/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

多列拼接

```
data['ID'].str.cat(data['金额'].astype(str),data['省市区'])
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2wcqGIeA0qNGurVnvBauv8PicSckjxw87dFtlHsM9vX73vI5gibKtvsKGIvsbzWsLu5Dto1R23OzEFQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

【包含某个字符】

```
con = data['省市区'].str.contains('德阳')
data[con]
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2wcqGIeA0qNGurVnvBauv8Psyly1QYwbkrnnxQyHxlH5NWibqvKFDKYdwcOQY9rzIZBYwFPjx16ekg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

```
data['省市区'].str.match('四川-德阳-中江')
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2wcqGIeA0qNGurVnvBauv8Pw11ebV8HWkgQicEKc3YhkZ42NtshEQ5w9qqE8LKIrrkM7tNFlXtVlww/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

startswith以什么开头的字符串

```
con = data['省市区'].str.startswith("四川")
data[con]
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2wcqGIeA0qNGurVnvBauv8P5jYGgGDKT2fmyjfuMxN3YkmfFaVQaz2iccFwf8RAyibDGvTZ3Vj1qUlQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

endswith以什么结束的字符串

```
con = data['省市区'].str.endswith("县")
data[con]
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2wcqGIeA0qNGurVnvBauv8PFUPCcTWFL0MvhrDGVoGjTIMt2RlEoia3Gd4hWXEhibFn2fomFALuOeUw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

是否为数字

```
data['金额'].astype(str).str.isdigit()
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2wcqGIeA0qNGurVnvBauv8PGM0dTDHhOEALhG9f7OExGTE5YVp5tER4saia8ao1DFHuibhOuOibcw1Nw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

截取某个位置字段，和Excel的mid函数差不多

```
data['省市区'].str.slice(0,3)
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2wcqGIeA0qNGurVnvBauv8PtMV5ibyXWj0jSt8JY07I2261wE2IXZTiaJPuFpB41wK5k2O8TG5p77hg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

替换某些字符

```
data['省市区'].str.slice_replace(start=3,stop=7,repl="***")
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2wcqGIeA0qNGurVnvBauv8P9I9hZNiaic9XZjYne6jTSNsMq1purThjZFlZbUmzDWjibLsiarIxh3VSWQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

计算出符合要求字符的个数

```
data['省市区'].str.count("长沙")
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2wcqGIeA0qNGurVnvBauv8PZRwrMwlaJEbo8qbiceY1jiajMZ4OHq7gXFXMSEibC4Gook8xbEbcxmlew/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)
