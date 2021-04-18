依托NumPy的datetime64、timedelta64等数据类型,pandas可以处理各种时间序列数据，还能调用scikits.timeseries等Python支持库的时间序列功能。

日期时间（Datetime）：带时区的日期时间，类似于标准库datetime.datetime 。

时间差（Timedelta）：绝对时间周期，类似于标准库的 datetime.timedelta。

时间段（Timespan）：在某一时点以指定频率定义的时间跨度。

日期偏移（Dateoffset）：与日历运算对应的时间段，类似于 dateutil 的 dateutil.relativedelta.relativedelta。

```
import numpy as npimport pandas as pdimport osimport datetimeos.chdir(r'F:\Python\Pandas\documentation')data = pd.read_excel("./Excel文件.xlsx",0)
```

【通过pd.to_datetime创建时间序列】

```
dti = pd.to_datetime(['2020/3/19', np.datetime64('2020-03-20'),                      datetime.datetime(2020, 3, 21)])
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yTJANJwPcV0vukGG95B39b8bk1Cs5AibIdsFibIe6ibS1H3RgjU5hadicwTm1LvDKH1j9z494p3s4ianw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

要实现精准转换，除了传递datetime字符串，还要指定format参数，指定此参数还可以加速转换速度。

```
pd.to_datetime('2020/11/12', format='%Y/%m/%d')
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yTJANJwPcV0vukGG95B39bgeyTJDkB9APKyUekles534YyYKTMk93PsibRtia5GUOjAnazPLVGRnAw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

```
pd.to_datetime('12-11-2020 19:19', format='%d-%m-%Y %H:%M')
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yTJANJwPcV0vukGG95B39bEd6t5TePibH4ln81uPeRBHibXicaLMTHSYIyezqIgtaH8SFmm5rIWjMMw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

pandas还可以把DataFrame里的整数或字符串列组合成Timestamp Series

```
df = pd.DataFrame({'year': [2020, 2021],                   'month': [2, 3],                   'day': [4, 5],                   'hour': [2, 3]})df['date_time'] = pd.to_datetime(df)
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yTJANJwPcV0vukGG95B39b3to1wn9siblbHQX8SFTBfhnhBFFjgPvegHdyOoQnkUvodqmptSpdriaA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

只传递组合所需的列也可以

```
df['date'] = pd.to_datetime(df[['year','month','day']])
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yTJANJwPcV0vukGG95B39byG4kov3icQVoUyxnNG4RuPwWiaVkkkK5iacmUjYnS3TzkotVkNy3u55jA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

**【无效时间日期数据处理】**

不可解析时，默认值errors='raise'会触发错误

```
pd.to_datetime(['2020/03/31', 'yyyy'], errors='raise')
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yTJANJwPcV0vukGG95B39b2WOSXibTWePNCzyDepaGF1Xlemb5EncaYd4kzwtxyLd67XSyGOvTwsA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

errors='ignore'返回原始输入

```
pd.to_datetime(['2020/03/31', 'yyyy'], errors='ignore')
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yTJANJwPcV0vukGG95B39bCrN4rrltgbFiattusiavppJhPtxFrQdx70ic7VXwwYaN5fQ3YDBEtrrFQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

errors='coerce'把无法解析的数据转换为NaT

```
pd.to_datetime(['2020/03/31', 'yyyy'], errors='coerce')
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yTJANJwPcV0vukGG95B39buZPz8Z0d52kjoFeoHrN1T1Vl5knMib9rX2AoR66lXqTXAnTVvNFyDqQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

**【生成时间戳范围】**

生成DatetimeIndex、TimedeltaIndex、PeriodIndex等定频日期与时间段序列

按小时递增H

```
pd.date_range('2020-03-20', periods=5, freq='H')
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yTJANJwPcV0vukGG95B39bhBqQkyYMxwnc5uRuYXbaLhx7QhgLBBc3BiabmKcicM30ibpfQiaquHImjA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

按天数递增D

```
pd.date_range('2020-03-20', periods=5, freq='D')
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yTJANJwPcV0vukGG95B39bT8JiaJEKy1jPJbHNPvJbRiajN9BWUJEPYeFAHPcPk0u1knsMy29kj90g/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

按月份递增M，取每月月末

```
pd.date_range('2020-03-20', periods=5, freq='M')
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yTJANJwPcV0vukGG95B39bqMuZuwkc7PNYV1Lhl3UEU1GbCnVaMdFZsn4mPXYB8pVR9D24mANdsw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

按年份递增Y，取每年年末

```
pd.date_range('2020-03-20', periods=5, freq='Y')
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yTJANJwPcV0vukGG95B39bX0cItUnBl7mcXFibPQQB6v1wXibwtVOPWiafYBOp2Fav6TZ8oZDWqSNog/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

**【dt属性】**

Series的值为datetime时，还可以用.dt访问这些属性。

```
s = pd.Series(pd.date_range('20200325 09:10:12', periods=4))
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yTJANJwPcV0vukGG95B39bA6mKx3Lk7mwN9bIFq7LEsVk25bXw8xO2s08uyLogE6e4Cic1z8wTtyA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

```
s.dt.month #取月份值s.dt.weekday #取周号值s.dt.week #取每年第几周s.dt.day  #取日期值s.dt.hour #取小时值s.dt.minute #取分钟值s.dt.second #取秒钟值s.dt.strftime("%Y/%m/%d") #格式化
```

**【DateOffset对象】**

```
ts = pd.Timestamp('2020-10-1 19:19:18')
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yTJANJwPcV0vukGG95B39b5e5PD5dNTPO4wUru1Xj77457R2sAA6Cgmk4vkiaYh5T7EMwuprc1ORQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

向后向前一天

```
ts + pd.Timedelta(days=1)ts + pd.Timedelta(days=-1)
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yTJANJwPcV0vukGG95B39bP45iaaxKgIH8nPaSJzmP1NcpcXyN3qvkkkYyWJOLRuibeqc8Z9uXDH2g/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

向后向前一周

```
ts + pd.Timedelta(weeks=1)ts + pd.Timedelta(weeks=-1)
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yTJANJwPcV0vukGG95B39bKIAzibscNL2WCeibe7GksZiakpxx6wjC9XMPmu6bRtutaGzqTtsricSaGQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

向后向前一小时

```
ts + pd.Timedelta(hours=1)ts + pd.Timedelta(hours=-1)
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yTJANJwPcV0vukGG95B39bDR1GclVCbdBZDeG5RBx58WybciatUYFpIsPePa0QlQXJ36XxdUxjZqQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

向后向前一天

```
ts + pd.DateOffset(days = -1)ts + pd.DateOffset(days = 1, second=5)
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yTJANJwPcV0vukGG95B39ba7EJFfCGyEpurQDwUlQIfywvtc4wS8cczYbY9AokM7SWNBJcwzBEUA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

月末

```
ts + pd.offsets.MonthEnd() #月末
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yTJANJwPcV0vukGG95B39bzUBWjmoFJtTuAfZnN2RFicNdTciaJNEfYHtmjnn9uohJA7oOvJeNPialA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

上月月初

```
ts + pd.offsets.MonthBegin(-1)
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yTJANJwPcV0vukGG95B39bdmFQwibGoUvbKwY9udggiahUticglxBic3tn9hwtW0dIbI6ku3KTk7mpWA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

次月月初

```
ts + pd.offsets.MonthBegin(1)
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yTJANJwPcV0vukGG95B39bHRKJOp703HQghCXVdjtrF2SI0QJshFLia2Rfx5b8zCxyogF5kWvaqsQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

本季度末

```
ts + pd.offsets.QuarterEnd(0)
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yTJANJwPcV0vukGG95B39boxPPYEW6zdYyl7eqoY9UZSZszJ41WY0JHzj09hiaOs39BMibVKicI08KQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

数据处理

```
data['日期+1'] = data['日期'] + pd.Timedelta(days=1)
data['日期+30分钟'] = data['日期'] + pd.Timedelta(minutes=30)

data['月初'] = data['日期'] + pd.offsets.MonthBegin(0)
data['月末'] = data['日期'] + pd.offsets.MonthEnd(0)

data['diff'] = data['月末'] - data['日期+30分钟']
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2yTJANJwPcV0vukGG95B39bzIt0UdLa3KBuic9libTTITugmVkXYhVicCibYUq3DPugsfibVdeglUbLdtw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)
