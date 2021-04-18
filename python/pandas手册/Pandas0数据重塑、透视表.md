**【stack和unstack】**

```
"""
1.stack：将数据的列“旋转”为行
2.unstack：将数据的行“旋转”为列
3.stack和unstack默认操作为最内层
4.stack和unstack默认旋转轴的级别将会成果结果中的最低级别（最内层）
5.stack和unstack为一组逆运算操作
"""
```

```
data = pd.read_excel("Excel文件.xlsx",sheet_name='stack',index_col='月份')
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yY2N4UMVbICV44IGge5Fudhsgo3sfKAhby9RzVYUaNvwdAT3P0ucnBu1vFaKGicYU8nicsTrY6mia6w/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

数据长上面这样，需求是把四川和海南两列转换到一列进行显示。

```
d1 = data.stack()
d1.index.names=['月份', '省份']
d1.rename('金额',inplace=True)
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yY2N4UMVbICV44IGge5Fudq62NgGdxmKsr8lu6aXV5ts6EqVDic7GUuaiaytBOkcJfoficXUMUXTyiag/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

```
d2 = d1.unstack(level=0)
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yY2N4UMVbICV44IGge5Fudmr1QM0EjHF1qXLibRmDJbjylXU5fvYgK6a7wVOELj6mFTuK5l4iafLrw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

```
d3 = d1.unstack(level=1)
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yY2N4UMVbICV44IGge5FudLaus1kK4DzGicndU2lsuc6EoavNYyBibfSxUnaT69vlO8Oupojk1ibf9Q/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

**【melt】**

stack有个使用前提，需要对普通列设置为索引，在stack之后又要将这些索引转换为普通列，未免过于麻烦。其实还有一种melt方法，要简单得多

```
m1 = pd.read_excel("Excel文件.xlsx",sheet_name='melt')
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yY2N4UMVbICV44IGge5FudnBorCfH9HoL76nicTQJz70T0sRylTPFyLmAKlPmW1FLWgxT03BSOeoQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

```
m2 = m1.melt(id_vars = ['月份','品类'],
             value_vars = ['四川','海南'],
             var_name = '省份',
             value_name = '金额')
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yY2N4UMVbICV44IGge5Fud4MIfu9sk1iax5qcA3k2CRVk2xnAY8ZOO98RHZWuwicibQfxcicJn0Nek5g/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

**【GroupBy】**

```
lakers = pd.read_excel('湖人比赛数据.xlsx')
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yY2N4UMVbICV44IGge5FudNIp4jwhCsGAWzSKRyicLgibYRjZgKDdaK98uNLhcwK7RB7KMwst8ZSKQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

数据是湖人这个赛季每场比赛的数据，截止到3.10号。

```
lal01 = lakers.groupby(['对手','结果']).size()
lal01 = lal01.unstack(1).fillna(0)
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yY2N4UMVbICV44IGge5FuduW1Yt3voKKSdrIv0cEOqf8WzKNgzamprReBoTWp53fqGIGkUlJ5DrA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

**【pivot_table】**

数据透视表才是主角，下面再说一下使用方法。数据还是湖人的比赛数据。

1.对所有数据透视，默认是平均值

```
lal02 = pd.pivot_table(lakers,index = '对手')
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yY2N4UMVbICV44IGge5Fud17XXFOQ1TeYPgGC6E0L1tqZu1vKsCjp2LN7TzVlRcXCpudYFC5GShQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

2.加上主客场字段

```
lal03 = pd.pivot_table(lakers,index = ['对手','主客场'])
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yY2N4UMVbICV44IGge5Fud7G6sOmjibz9KWoEV91YibOJ53nFibE5XyWWSYgickhQHGfxOeWTpr9vXKQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

3.可以交换顺序

```
lal04 = pd.pivot_table(lakers,index = ['主客场','对手'])
```

4.通过value字段透视指定字段数据

```
lal05 = pd.pivot_table(lakers,
                       index=['主客场','结果'],
                       values=['得分','篮板','助攻'])
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yY2N4UMVbICV44IGge5FudgakGEHZX8hedx6mm9zI8Uh9x3ll9FCictbEF2onGUqdfhzG31Iia0nFA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

5.aggfunc参数可以设置我们对数据聚合时进行的函数操作。默认aggfunc='mean'计算均值。

```
lal06 = pd.pivot_table(lakers,
                       index=['主客场','结果'],
                       values=['得分','篮板','助攻'],
                       aggfunc=[len, np.mean])
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yY2N4UMVbICV44IGge5FudK8q2e7ucHFwA28tvyYosoJIyL6DkQjY1cwz94wVLcpcBibNgXz4YqMg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

6.通过字典可以制定每个数据的聚合方式

```
lal07 = pd.pivot_table(lakers,
                       index=['主客场','结果'],
                       values=['得分','篮板','助攻'],
                       aggfunc={'得分':[np.mean,len], '篮板':np.mean, '助攻':np.mean})
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yY2N4UMVbICV44IGge5FudtBfozm5OoNt0VNbOW9hjbex5Pb5IicicGh2ja5gI6pRFpDbSFr23TBxg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

7.columns列透视

```
lal08 = pd.pivot_table(lakers,
                       index=['对手','主客场'],
                       columns=['结果'],
                       values=['得分','篮板','助攻'],
                       aggfunc={'得分':[np.mean,len],'篮板':np.mean, '助攻':np.mean})
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yY2N4UMVbICV44IGge5FudsnOAbC4CRPg1Br02mqXK6wxy3kyA5dYIMqUDRJlhs8q4VqQ0TqoQ4w/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

8.fill_value填充空值

```
lal09 = pd.pivot_table(lakers,
                       index=['对手','主客场'],
                       columns=['结果'],
                       values=['得分','篮板','助攻'],
                       aggfunc={'得分':[np.mean,len], '篮板':np.mean, '助攻':np.mean},
                       fill_value=0)
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yY2N4UMVbICV44IGge5FudAMVcyHta16UibnXl8ibQ5j3gzwYUAMtYkruSlaVIXqVAL1CHn3loIQ9g/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

9.对透视结果的高级透视表过滤

```
lal10 = lal09.query('对手==["独行侠"]')
lal11 = lal09.query('对手==["独行侠","快船"]')
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yY2N4UMVbICV44IGge5FudXichalJj00Wcmqe6PCUGhJIRaEVmj8HDLn7InUcadKR0oS0uFiccuQPA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yY2N4UMVbICV44IGge5FudIkQlKOibahsicorK8qoxNDxhZAWMBK16l9bIh0IJRENU8N0GLAbeAjMw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)
