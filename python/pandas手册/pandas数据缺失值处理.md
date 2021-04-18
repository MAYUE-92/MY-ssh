数据丢失(缺失)在现实生活中总是一个问题。机器学习和数据挖掘等领域由于数据缺失导致的数据质量差，在模型预测的准确性上面临着严重的问题。在这些领域，缺失值处理是使模型更加准确和有效的重点。

数据导入

```
import numpy as np
import pandas as pd
import os
os.chdir(r'F:\Python\Pandas\documentation')
data = pd.read_excel('./Excel文件.xlsx',sheet_name='缺失值')
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2w3kYAD4xqjSlxGlgia636P600E07HbZAOIJUNXYK9eRmH61mMPV4Jec5Djuy1PByTJkr7ahqfs0Ow/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

**【检查缺失值】**

查找省份列是空值的数据

```
con = data['省份'].isnull()
miss1 = data[con]
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2w3kYAD4xqjSlxGlgia636P6cBG2dM8tcpEkx8AnONOZGnXHFiaQbnTaEqIa1uB4qRCujuy9INELKIw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

查找省份列不是空值的数据

```
con2 = data['省份'].notnull()
miss2 = data[con2]
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2w3kYAD4xqjSlxGlgia636P6N6kPo1o5ZoWyv4Bicia5ib1NEKA8mzQZcKqpzvjJYpqOXuJeEYyicLllIg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

**【缺少数据的计算】**

在求和数据时，NA将被视为0；如果数据全部是NA，那么结果将是NA

```
data['金额'].sum()
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2w3kYAD4xqjSlxGlgia636P6JUpSwNFbxd4HJUCic8p7fc2WUdS9ZKJCDSRUTNhbDIPJcFchcT8zNzQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

**【填充缺少数据】**

Pandas提供了各种方法来清除缺失的值。fillna()函数可以通过几种方法用非空数据填充NA值。

整个表格有缺失的值统一填充为"-"

```
miss3 = data.fillna("-")
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2w3kYAD4xqjSlxGlgia636P6NYjhMULq9u3xnJmSVpNAGibXlKMR2yLpqbP3HGEEpRkEfEboBKE8PTA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

对金额列填充为平均值

```
miss4 = data.copy()
miss4['金额'] = miss4['金额'].fillna(np.mean(miss4['金额']))
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2w3kYAD4xqjSlxGlgia636P6MKMeB2QprXdibtm9ib8prEvxdVfjmHGHrwweWVsxWzkymK0Lun3JCMCQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

取最近上面的一个数据进行填充

```
miss5 = data.fillna(method='pad')
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2w3kYAD4xqjSlxGlgia636P68zNZaqeWdo5IezThl2JIRRNZ7BbPvKZibyVoOOr0Z0NPasEKibLfda8w/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

取最近后面的一个数据进行填充

```
miss6 = data.fillna(method='bfill')
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2w3kYAD4xqjSlxGlgia636P68icEE3AERajibcbgvOgeb3vzIOiaFEWp7aWvickBtIib5QKMsicYkAvI9cSg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

**【删除缺失值】**

```
'''DataFrame.dropna(axis=0, how='any', thresh=None, subset=None, inplace=False)

函数作用：删除含有空值的行或列

axis:维度，axis=0表示index行,axis=1表示columns列，默认为0

how:"all"表示这一行或列中的元素全部缺失（为nan）才删除这一行或列，"any"表示这一行或列中只要有元素缺失，就删除这一行或列

thresh:一行或一列中至少出现了N个缺失值才删除。

subset：在某些列的子集中选择出现了缺失值的列删除，不在子集中的含有缺失值得列或行不会删除（有axis决定是行还是列）

inplace：刷选过缺失值得新数据是存为副本还是直接在原数据上进行修改。'''
```

```
miss7 = data.dropna()
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2w3kYAD4xqjSlxGlgia636P6s5FcnCadSrOzD13j6N2ictnpCWxvayUHaxNpfIXfUCQfkDSwvRTAlYw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

通过subset，设置指定列都是空值的行才删除

```
miss71 = data.dropna(subset=['日期','省份'])
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2w3kYAD4xqjSlxGlgia636P6HoKMqJ0DKicvJpicRM8QAO8icn73SRia9BV8Clblcic0BPRAIhOmexwBjWQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

通过thresh，删除每行至少出现了3个缺失值的行

```
miss72 = data.dropna(thresh=3)
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2w3kYAD4xqjSlxGlgia636P6pVOeFjcc3V48PaRYHZF3D4HPmDlia3IpXsd96INNRU8Zkhy3k9LW2dA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

删除有缺失值的列

```
miss8 = data.dropna(axis=1)
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2w3kYAD4xqjSlxGlgia636P6X46QeGLYQetehAqpIkHr0mxkQ0jzUhd5SdSgUtNA1H7evSPRGbxRRA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)
