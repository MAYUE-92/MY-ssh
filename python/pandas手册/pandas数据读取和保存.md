还是要成体系，方便之后有条理的查询。这是pandas的第一篇，大概有十篇左右吧，涉及标准数据的读取、清洗、转化、聚合等差不多所有环节了。

Pandas库是基于NumPy 的一种工具，该工具是为了解决数据分析任务而创建，也是围绕着 Series 和 DataFrame 两个核心数据结构展开的，其中Series 和 DataFrame 分别对应于一维的序列和二维的表结构。Pandas提供了大量能使我们快速便捷地处理数据的函数和方法。这个库优点很多，简单易用，接口抽象得非常好，而且文档支持实在感人。你很快就会发现，它是使Python成为强大而高效的数据分析环境的重要因素之一。

pandas文件读取、保存，主要是常用的模块：从剪切板读取、CSV文件操作、Excel文件操作、SQL操作，其他的文件基本上不用就不写在这里了。

**【剪切板数据读写】**

1.网页数据读取

*
*

```
#网页数据读取
clip_df = pd.read_clipboard()
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2zNJAouZ3ia5n4q1KFicpPiakwC6ZSooNv80ib6DpmeCNvEXePShNMibUCSXutbiafY7hT44mVdZET60K2A/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

2.Excel数据复制读取

*
*

```
#Excel数据读取
clip_excel = pd.read_clipboard()
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2zNJAouZ3ia5n4q1KFicpPiakwNqX2kVkv4frzHhcYNdBNG7THcfF3vomdhkUt0Mpe8sqbib40gUYuiazw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

3.把数据复制到剪切板，相当于Ctrl+C的功能

*
*

```
#把数据复制到剪切板，相当于Ctrl+C的功能
clip_excel.to_clipboard()
```

**【CSV文件读写】**

1.读取整个csv文件

*
*

```
#读取整个csv文件
csv_data = pd.read_csv("./CSV文件.csv")
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2zNJAouZ3ia5n4q1KFicpPiakw7VwuL3JNG7mhE0eSddicny5sM12rQnPhJQKr5rWejL4N8g9ZiaKibVQUw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

2.读取指定列索引字段的数据

```
#usecols读取指定列索引字段的数据
csv_data_2 = pd.read_csv("./CSV文件.csv", usecols = ['省份','金额'])
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2zNJAouZ3ia5n4q1KFicpPiakwFibddm03eLRFKazOffzJyK8SI5nwv0lRYOumFxxvL5UCVFsXn6lic3rQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

3.读取行的数量限制

```
#nrows读取行的数量限制
csv_data_3 = pd.read_csv("./CSV文件.csv", usecols = ['省份','金额'], nrows=5)
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2zNJAouZ3ia5n4q1KFicpPiakwu1rjMqqTEZFAU82sI9VE0C0kjQ6o3VS2QobUIfDiaXibXKqUPqkOmkCw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

4.不使用自动的索引行，制定索引列

```
#不使用自动的索引行，制定索引列
csv_data_4 = pd.read_csv('./CSV文件.csv', index_col=0)
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2zNJAouZ3ia5n4q1KFicpPiakwE0hiafPToblqleibcicqElIXC6ibGD2Sib8HmLrpmfZgfx0icibVCObRcibUsg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

5.保存成CSV文件

```
#保存成CSV文件
csv_data_2.to_csv('demo.csv', encoding='gbk')
```

6.不需要自动索引列，第一列作为索引列

```
#不需要自动索引列，第一列作为索引列
csv_data_2.to_csv('demo2.csv', index=False, encoding='gbk' )
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2zNJAouZ3ia5n4q1KFicpPiakwykLYAmOaTx0eUhEAjS9cf0leMX2TrdunaGwHYcGrudOiaMdPhLb6lkw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

**【Excel文件读写】**

1.不带任何参数，默认读取Sheet1，会自动添加索引

```
#不带任何参数，默认读取Sheet1，会自动添加索引
excel_01 = pd.read_excel('./Excel文件.xlsx')
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2zNJAouZ3ia5n4q1KFicpPiakwjHk4wXcGHQzicbUSdgoZ2P9uDxqarsnX0f3L3icaI9kDPwcgpkgxlQ2w/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

2.读取指定sheet，这里读取第二个sheet，"St2"

```
#读取指定
sheetexcel_02 = pd.read_excel('./Excel文件.xlsx',                         sheet_name = "St2")
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2zNJAouZ3ia5n4q1KFicpPiakwBlHD2jh6LloWLaVMajcVLb3kHnYztj9pzZthZ5eo4WsiarWVdAZONLQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

3.读取多张同一工作簿下多张sheet

为了更方便地读取同一个文件的多张表格，ExcelFile类可用来打包文件并传递给read_excel。因为仅需读取一次内存，所以这种方式读取一个文件的多张表格会有性能上的优势。

```
with pd.ExcelFile('./Excel文件.xlsx') as xlsx:
    excel_01 = pd.read_excel(xlsx, 'Sheet1') #使用sheet名称
    excel_02 = pd.read_excel(xlsx, 1) #使用sheet位置索引
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2zNJAouZ3ia5n4q1KFicpPiakwC6JfdfwnC2A3IBbwPjN2LMic5mF6Rj9GdjgAXvGByUkougV7ZyBfrNQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

sheet_name=None，读取工作簿里面所有表格，使用key可以取得每个表格信息。

```
excel_00 = pd.read_excel('./Excel文件.xlsx', sheet_name=None)
St2 = excel_00['St2']
```

4.读取指定的列。

下面三个是等价的，都是读取BCD三列的数据

```
excel_03 = pd.read_excel('./Excel文件.xlsx', usecols=[1,2,3])
excel_031 = pd.read_excel('./Excel文件.xlsx', usecols=['日期','省份','金额'])
excel_032 = pd.read_excel('./Excel文件.xlsx', usecols='B,C:D')
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2zNJAouZ3ia5n4q1KFicpPiakwSn7MnkcSNaH3ahBsrL19NIjTfXCfkt5QPsK4yBeAjppL2ico5SyLWuQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

5.写入Excel文件

```
excel_03.to_excel('demo.xlsx', sheet_name='DEMO', index=False)
```

6.写入多个sheet

为了把DataFrames数据分开写入Excel文件的不同表格中，可以使用ExcelWriter方法

```
with pd.ExcelWriter('demo2.xlsx') as writer:
    excel_01.to_excel(writer, sheet_name='Sheet1')
    excel_03.to_excel(writer, sheet_name='Sheet2', index=False)
```

7.通过xlsxwriter引擎保存，可以设置各种条件格式。

```
writer = pd.ExcelWriter('xlsxwriter.xlsx',
                        engine='xlsxwriter',
                        datetime_format='yyyy/mm/dd hh:mm:ss',
                        date_format='yyyy/mm/dd')
excel_01.to_excel(writer, sheet_name='xlsxwriter',index=False)
workbook  = writer.bookwork
sheet = writer.sheets['xlsxwriter']
worksheet.conditional_format('D2:D46', {'type': '3_color_scale'})
format1 = workbook.add_format({'num_format': '#,##0.00'})
worksheet.set_column('B:B', 20)worksheet.set_column('D:D', 10, format1)
writer.save()
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2zNJAouZ3ia5n4q1KFicpPiakwyfI9zZGOU5uibwZEJE6hqtugsiaCf110Uoiabny7jFXrlkxrybHC5Yxlg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

**【MySQL数据库读写】**

这里使用的是pymysql引擎。

1.MySQL数据读取

```
import pymysql
#--Mysql数据读取
conn = pymysql.connect(
      host = 'localhost',
      user = 'root',
      passwd = '密码',
      db = 'test',
      port=3306,
      charset = 'utf8')
sql_df = pd.read_sql('select * from sht1 where 金额>=500',conn)
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2zNJAouZ3ia5n4q1KFicpPiakwKr3PLthDpTvJJbO49axYzeppTlTz8e5qtYWOWw93D0TVffrBPFyialA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

2.把数据写入到数据库里面

```
excel_02.to_sql(name='sht2',
                con='mysql+pymysql://root:ss456123@localhost:3306/test?charset=utf8',
                if_exists='append',
                index=False)
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2zNJAouZ3ia5n4q1KFicpPiakwpNbQgNeZAcX8eLRnW2YtfW0rCgcHMQUvPcc13YRXMs7BFTBRQBOkgw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)
