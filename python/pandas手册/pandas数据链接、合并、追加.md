这是第三篇。数据的合并、追加和连接，涉及concat、append和merge。没有join，因为merge基本上包含了join所有功能，没必要多来一个。

```
with pd.ExcelFile("./Excel文件.xlsx") as xlsx:
    M1 = pd.read_excel(xlsx, 2) #M1是3.12日销售数据
    M2 = pd.read_excel(xlsx, 3) #M2是3.14日销售数据，格式和M1一样
    M3 = pd.read_excel(xlsx, 4) #M3是M1的订单状态
    M4 = pd.read_excel(xlsx, 5) #M4是省份的大区和负责人表
```

数据是四个表格，M1是3.12日销售数据；M2是3.14日销售数据，格式和M1一样；M3是M1的订单状态；M4是省份的大区和负责人表。

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xBytwl3MAria2U2SQ5J0z3ia4K1xlLZYGO96p7GDPkavWORHj8q26YZniaI9rdUKG3bdYCoqJGgvMYA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xBytwl3MAria2U2SQ5J0z3iaqJ0ZicHIm89YYyIHTloK0fEuE7mbXmf0Wma6KuE72UxbfBm6ibZ859Pw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xBytwl3MAria2U2SQ5J0z3iaFmYcRvXhdias3cbKMRwiaLueOq8pSlLpgB55UUSFr1M7QgVyXYPOs4Wg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xBytwl3MAria2U2SQ5J0z3iaJKxtcicxzMKibNkDajGDp6spvoN5TMhibjvAdMq8iawEZYMKjuuvkfUauw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

**【concat】**

concat方法是拼接函数，有行拼接和列拼接，默认是行拼接，拼接方法默认是外拼接（并集），拼接的对象是pandas数据类型。 语法如下↓

```
pd.concat(objs,  series，dataframe或者是panel对象构成的序列lsit
          axis=0, 指明连接的轴向，0行, 1列，默认为0
          join='outer', 指明连接方式,inner交集,outer并集，默认为outer
          ignore_index=False, 重建索引
          keys=None,
          levels=None,
          names=None,
          verify_integrity=False,
          copy=True)
```

1.concat把两个表进行连接,默认axis=0，竖向连接

```
df01 = pd.concat([M1,M2])
df01 = df01.reset_index(drop=True) #重新设置索引
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xBytwl3MAria2U2SQ5J0z3iaBpVibOMWk10bTeN7fZEsNLTtyDxjQ8iad8HxgPCHiaO89Rv5vrHMqSEIQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

2.增加keys，新增一列索引

```
df02 = pd.concat([M1,M2], keys=['12日','14日'])
df02.loc['14日'] #选择14日的数据
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xBytwl3MAria2U2SQ5J0z3iauAk4tGVibgSDLqCvFFib8A7lt03pNQokzWBMfOfhOO3EPubxFStUImYA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

3.设置axis=1，横向连接

```
df03 = pd.concat([M1,M3],axis=1,ignore_index=True)
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xBytwl3MAria2U2SQ5J0z3iaMicfEdQM0f9MSeNnRpnKQgEKq9phnp01YI5gTLhvanhdKXS8CWeVaibQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

4.join连接方式为inner,按索引列，两边同时有的索引进行连接

```
df04 = pd.concat([M1,M3],axis=1,join='inner')
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xBytwl3MAria2U2SQ5J0z3iaQ2vVMKZfFCScM8WibTcd8JrKFcA3khzzQUqYovMv6z3mtxZSj2yXsjA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

5.使用append追加

```
df05 = M1.append(M2)
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xBytwl3MAria2U2SQ5J0z3ianicqYYnAoWmLOb9R7XhLvoLX8DRNQ0hUHIicx6B4p5WhArfyl9urH5iag/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

6.Series连接

```
s1 = pd.Series([0, 1, 2, 3], name='ID')
s2 = pd.Series(['四川', '江西', '云娜', '河北'], name='省份')
s3 = pd.Series([10, 14, 44, 65], name='金额')
df06 = pd.concat([s1,s2,s3],axis=1)
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xBytwl3MAria2U2SQ5J0z3iaSaDYPOl9j7sic01nCkdQ1FZoz9j7JRYKsqYh8waGZicMDtgEPHibv5ctQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

7.使用keys重命名

```
df07 = pd.concat(([s1,s2,s3]),axis=1,keys=['AAA','BBB','CCC'])
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xBytwl3MAria2U2SQ5J0z3iaQnXGJJC4rXmRpaqdUPwcxJpB1XVcf5uq5JaeaeMvN8ENO2Y4jnFMgw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

**【merge方法】**

merge和SQL的连接、R的merge使用很相似、可以实现Excel中vlookup的功能，但更强大。语法如下↓

```
pd.merge(left, #参与合并的左侧DataFrame
         right, #参与合并的右侧DataFrame
         how='inner', #inner、outer、left、right其中之一
         on=None, 用于连接的列索引名称，必须同时存在于左、右两个DataFrame中，默认是以两个DataFrame列名的交集作为连接键，若要实现多键连接
         left_on=None, 左侧DataFrame中用于连接键的列名，这个参数在左右列名不同但代表的含义相同时非常有用
         right_on=None, 右侧DataFrame中用于连接键的列名
         left_index=False, 使用左侧DataFrame中的行索引作为连接键
         right_index=False, 使用右侧DataFrame中的行索引作为连接键
         sort=True, 将合并的数据进行排序，设置为False可以提高性能
         suffixes=('_x', '_y'), 字符串值组成的元组，用于指定当左右DataFrame存在相同列名时在列名后面附加的后缀名称
         copy=True, 将数据复制到数据结构中，设置为False可以提高性能
         indicator=False, 显示合并数据中数据的来源情况
         validate=None)
```

1.按省份进行匹配

```
df08 = pd.merge(M1, M4, how='inner',on='省份')
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xBytwl3MAria2U2SQ5J0z3iaCe1d0f3gI8JFGM29YYI1jicaDnemtGMbp9iabee7MRcEaOibqJRzKib4TA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

2.多条件匹配。how='inner'，dataframe的链接方式为内连接，我们可以理解基于共同列的交集进行连接，参数on设置连接的共有列名。

```
df09 = pd.merge(M1, M4, how='inner',on=['省份','ID'])
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xBytwl3MAria2U2SQ5J0z3iajFv61ok8TTazzEdrD98npI1o3E56r9ibZeB9NAmlo1qfmrv361p6xtg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

3.left左连接。dataframe的链接方式为左连接，我们可以理解基于左边位置dataframe的列进行连接，参数on设置连接的共有列名。

```
df10 = pd.merge(M1, M4, how='left',on=['省份','ID'])
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xBytwl3MAria2U2SQ5J0z3iaJEaRsAQz29XR2via4yOXQpQVKZ8cxVPECj9QaU2jq9OzUHqtwmye2kg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

4.right右连接。dataframe的链接方式为左连接，我们可以理解基于右边位置dataframe的列进行连接，参数on设置连接的共有列名

```
df11 = pd.merge(M1, M4, how='right',on=['省份','ID'])
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xBytwl3MAria2U2SQ5J0z3iaLASnNP4aqyc5hvYUW3FsgWbnwn1B9IjxhxgRR5mrIKBl7NRYnHqztg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

5.outer外连接。dataframe的链接方式为外连接，我们可以理解基于共同列的并集进行连接，参数on设置连接的共有列名。

```
df12 = pd.merge(M1, M4, how='outer',on=['省份','ID'])
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xBytwl3MAria2U2SQ5J0z3ia3ibzBE1zhRGJOHiaILCDib4Ao9MeARm3mLng3Osg305ZDiasD6zhDDVp5w/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

6.生成全数据

```
left = pd.DataFrame({'A': [1, 1], 'B': [1, 2]})
right = pd.DataFrame({'A': [1, 1, 1], 'B': ['AA', 'BB', 'CC']})
df13 = pd.merge(left, right, on='A', how='outer')
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2xBytwl3MAria2U2SQ5J0z3iaw52MjOwH4hQRrYlYj1icCkFtaDFph0wibrNzsRILr7etQJLkAcauZxMg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

join和merge的连接方法类似，这里就不展开join方法了，建议用merge方法。下一篇是数据表格重塑和数据透视表。
