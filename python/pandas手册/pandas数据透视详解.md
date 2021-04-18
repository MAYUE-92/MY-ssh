数据透视表是Excel中最常用的数据汇总工具，它可以根据一个或多个制定的维度对数据进行聚合。在python中同样可以通过pandas.pivot_table函数来实现这些功能。本篇文章将介绍 pandas.pivot_table函数与Excel数据透视表之间的联系，以及具体的使用方法。

数据还是上次那个模拟的数据。
![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2wyx6ibkkZCv5I2mYVUywA0rzhND71eMRMfC565WgINQmBgt9EWMx5ZjKK0VVJaToibxjm1OgDvunDw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

【语法参数】

<pre class=""><ol class="list-paddingleft-2"><li><p><code class=""><span><span class="">pivot_table(data, </span><span class="">#数据</span></span></code></p></li><li data-node-id="20210225163430-nzw85nv"><p><code class=""><span><span class="">           values=</span><span class="">None</span><span class="">,  </span><span class="">#透视聚合的值 </span></span></code></p></li><li><p><code class=""><span><span class="">           index=</span><span class="">None</span><span class="">,   </span><span class="">#行</span></span></code></p></li><li data-node-id="20210225163430-eudce87"><p><code class=""><span><span class="">           columns=</span><span class="">None</span><span class="">,  </span><span class="">#列</span></span></code></p></li><li><p><code class=""><span><span class="">           aggfunc=</span><span class="">'mean'</span><span class="">,  </span><span class="">#聚合方式</span></span></code></p></li><li data-node-id="20210225163430-y6wqesk"><p><code class=""><span><span class="">           fill_value=</span><span class="">None</span><span class="">, </span><span class="">#缺失值填充方式</span></span></code></p></li><li><p><code class=""><span><span class="">           margins=</span><span class="">False</span><span class="">, </span><span class="">#添加行列汇总</span></span></code></p></li><li data-node-id="20210225163430-iawajdd"><p><code class=""><span><span class="">           dropna=</span><span class="">True</span><span class="">,  </span><span class="">#去掉NA值的计算</span></span></code></p></li><li><p><code class=""><span><span class="">           margins_name=</span><span class="">'All'</span><span class="">)</span></span></code></p></li></ol></pre>

【数据准备】

<pre class=""><ol class="list-paddingleft-2"><li><p><code class=""><span><span class="">import</span><span class=""> os</span></span></code></p></li><li data-node-id="20210225163430-6szmzqy"><p><code class=""><span><span class="">os.chdir(r</span><span class="">"F:\Python\Pandas"</span><span class="">)</span></span></code></p></li><li><p><code class=""><span><span class="">import</span><span class=""> pandas </span><span class="">as</span><span class=""> pd</span></span></code></p></li><li data-node-id="20210225163430-aalqnfe"><p><code class=""><span><span class="">import</span><span class=""> numpy </span><span class="">as</span><span class=""> np</span></span></code></p></li><li><p><code class=""><span><span class="">order = pd.read_excel(</span><span class="">'Pivot.xlsx'</span><span class="">)</span></span></code></p></li></ol></pre>

#简单的透视:每人平均销售金额

<pre class=""><ol class="list-paddingleft-2"><li><p><code class=""><span><span class="">order1 = pd.pivot_table(order,values=</span><span class="">"金额"</span><span class="">,index=</span><span class="">"姓名"</span><span class="">)</span></span></code></p></li><li data-node-id="20210225163430-vfnan5g"><p><code class=""><span><span class="">order1.sort_values(</span><span class="">by</span><span class="">=[</span><span class="">'金额'</span><span class="">],inplace=</span><span class="">True</span><span class="">,ascending=</span><span class="">False</span><span class="">)</span></span></code></p></li><li><p><code class=""><span><span class="">order1[</span><span class="">'金额'</span><span class="">] = round(order1[</span><span class="">'金额'</span><span class="">])</span></span></code></p></li><li data-node-id="20210225163430-ixft3h8"><p><code class=""><span><span class="">order1.rename(columns={</span><span class="">'金额'</span><span class="">:</span><span class="">'平均销售金额'</span><span class="">},inplace=</span><span class="">True</span><span class="">)</span></span></code></p></li><li><p><code class=""><span><span class="">order1.to_excel(</span><span class="">'order1.xlsx'</span><span class="">)</span></span></code></p></li></ol></pre>

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2wyx6ibkkZCv5I2mYVUywA0rP0QjBpHXXuSnPnaHMt4WjPGU48sUOIiaDsm98icOICbNgY4QwRcjL8WA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

#每人各区域平均销售金额

<pre class=""><ol class="list-paddingleft-2"><li><p><code class=""><span><span class="">order2 = pd.pivot_table(order,values=[</span><span class="">'金额'</span><span class="">],index=[</span><span class="">'姓名'</span><span class="">,</span><span class="">'区域'</span><span class="">])</span></span></code></p></li><li data-node-id="20210225163430-apfqhwb"><p><code class=""><span><span class="">order2.rename(columns={</span><span class="">'金额'</span><span class="">:</span><span class="">'平均销售金额'</span><span class="">},inplace=</span><span class="">True</span><span class="">)</span></span></code></p></li><li><p><code class=""><span><span class="">order2.to_excel(</span><span class="">'order2.xlsx'</span><span class="">)</span></span></code></p></li></ol></pre>

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2wyx6ibkkZCv5I2mYVUywA0rXVIIriacZl58uoMHXlXRY85hkI8RDpDQbhzVkvoHeWyshA6XrSIFNew/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

#每人各区域销售平均金额和平均数量

<pre class=""><ol class="list-paddingleft-2"><li><p><code class=""><span><span class="">order3 = pd.pivot_table(order,values=[</span><span class="">'金额'</span><span class="">,</span><span class="">'数量'</span><span class="">],index=[</span><span class="">'姓名'</span><span class="">,</span><span class="">'区域'</span><span class="">])</span></span></code></p></li><li data-node-id="20210225163430-9lzss3e"><p><code class=""><span><span class="">order3.rename(columns={</span><span class="">'金额'</span><span class="">:</span><span class="">'平均销售金额'</span><span class="">,</span><span class="">'数量'</span><span class="">:</span><span class="">'平均销售数量'</span><span class="">},inplace=</span><span class="">True</span><span class="">)</span></span></code></p></li><li><p><code class=""><span><span class="">order3.to_excel(</span><span class="">'order3.xlsx'</span><span class="">)</span></span></code></p></li></ol></pre>

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2wyx6ibkkZCv5I2mYVUywA0rZJcKU0T3soiat8xbN70bibaO0UqHoE8r78lRUoib0kR2Z8MP1V5qDsfjA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

#每人各区域销售总金额和总数量

<pre class=""><ol class="list-paddingleft-2"><li><p><code class=""><span>order4 = pd.pivot_table(order,</span></code></p></li><li data-node-id="20210225163430-v4haq1a"><p><code class=""><span><span class="">                        values=[</span><span class="">'金额'</span><span class="">,</span><span class="">'数量'</span><span class="">],</span></span></code></p></li><li><p><code class=""><span><span class="">                        index=[</span><span class="">'姓名'</span><span class="">,</span><span class="">'区域'</span><span class="">],</span></span></code></p></li><li data-node-id="20210225163430-70me1kx"><p><code class=""><span><span class="">                        aggfunc={</span><span class="">'金额'</span><span class="">:np.sum,</span></span></code></p></li><li><p><code class=""><span><span class="">                                 </span><span class="">'数量'</span><span class="">:np.sum})</span></span></code></p></li><li data-node-id="20210225163430-vgr6gfn"><p><code class=""><span><span class="">order4.rename(columns={</span><span class="">'金额'</span><span class="">:</span><span class="">'总销售金额'</span><span class="">,</span><span class="">'数量'</span><span class="">:</span><span class="">'总销售数量'</span><span class="">},inplace=</span><span class="">True</span><span class="">)</span></span></code></p></li><li><p><code class=""><span><span class="">order4.to_excel(</span><span class="">'order4.xlsx'</span><span class="">)</span></span></code></p></li></ol></pre>

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2wyx6ibkkZCv5I2mYVUywA0rCM295SRKfThYIpdZ4NLwWRPKbQN7SmSTSa7kj28O4aBeZjjmu9wnfA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

#汇总每人总销售金额数量、平均销售金额数量、订单数量

<pre class=""><ol class="list-paddingleft-2"><li><p><code class=""><span>order5 = pd.pivot_table(order,</span></code></p></li><li data-node-id="20210225163430-f1hl14g"><p><code class=""><span><span class="">                        values=[</span><span class="">'金额'</span><span class="">,</span><span class="">'数量'</span><span class="">],</span></span></code></p></li><li><p><code class=""><span><span class="">                        index=</span><span class="">'姓名'</span><span class="">,</span></span></code></p></li><li data-node-id="20210225163430-7hl0yzw"><p><code class=""><span>                        aggfunc=[np.sum,np.mean,len])</span></code></p></li><li><p><code class=""><span><span class="">order5.to_excel(</span><span class="">'order5.xlsx'</span><span class="">)</span></span></code></p></li></ol></pre>

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2wyx6ibkkZCv5I2mYVUywA0rXQ2AeOicXILuQWOibUSt1Ciafx4vKsgVV6I4Khnr6KYT0Uzfs9YiaX876w/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

#增加一个列的维度，区域

<pre class=""><ol class="list-paddingleft-2"><li><p><code class=""><span>order6 = pd.pivot_table(order,</span></code></p></li><li data-node-id="20210225163430-ait9l4q"><p><code class=""><span><span class="">                        values=[</span><span class="">'金额'</span><span class="">],</span></span></code></p></li><li><p><code class=""><span><span class="">                        index=</span><span class="">'姓名'</span><span class="">,</span></span></code></p></li><li data-node-id="20210225163430-8i6fb7k"><p><code class=""><span><span class="">                        columns=</span><span class="">'区域'</span><span class="">,</span></span></code></p></li><li><p><code class=""><span>                        aggfunc=[np.sum,len])</span></code></p></li><li data-node-id="20210225163430-79sux2h"><p><code class=""><span><span class="">order6.to_excel(</span><span class="">'order6.xlsx'</span><span class="">)</span></span></code></p></li></ol></pre>

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2wyx6ibkkZCv5I2mYVUywA0riavRZibcuQmAaALKKeCUVOT9rHewGcagLqdeibWJQMEQtfiafu1w0c2VtA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

#增加多列维度,区域、产品

<pre class=""><ol class="list-paddingleft-2"><li><p><code class=""><span>order7 = pd.pivot_table(order,</span></code></p></li><li data-node-id="20210225163430-eq0674c"><p><code class=""><span><span class="">                        values=[</span><span class="">'金额'</span><span class="">],</span></span></code></p></li><li><p><code class=""><span><span class="">                        index=</span><span class="">'姓名'</span><span class="">,</span></span></code></p></li><li data-node-id="20210225163430-bow8fo8"><p><code class=""><span><span class="">                        columns=[</span><span class="">'区域'</span><span class="">,</span><span class="">'产品'</span><span class="">],</span></span></code></p></li><li><p><code class=""><span>                        aggfunc=[np.sum,len])</span></code></p></li><li data-node-id="20210225163430-x088i7l"><p><code class=""><span><span class="">order7.to_excel(</span><span class="">'order7.xlsx'</span><span class="">)</span></span></code></p></li></ol></pre>

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2wyx6ibkkZCv5I2mYVUywA0ru5XnJKoCvP9UkibqBEriaqtGKQQ1lzxaYznpBdc86PyDVK7U2BWGWx8Q/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

#增加汇总：margins=True

<pre class=""><ol class="list-paddingleft-2"><li><p><code class=""><span>order8 = pd.pivot_table(order,</span></code></p></li><li data-node-id="20210225163430-n7dzs07"><p><code class=""><span><span class="">                        values=[</span><span class="">'金额'</span><span class="">,</span><span class="">'数量'</span><span class="">],</span></span></code></p></li><li><p><code class=""><span><span class="">                        index=</span><span class="">'姓名'</span><span class="">,</span></span></code></p></li><li data-node-id="20210225163430-902lpxx"><p><code class=""><span>                        aggfunc=[np.sum,np.mean,len],</span></code></p></li><li><p><code class=""><span><span class="">                        margins=</span><span class="">True</span><span class="">)</span></span></code></p></li><li data-node-id="20210225163430-v1zgij0"><p><code class=""><span><span class="">order8.to_excel(</span><span class="">'order8.xlsx'</span><span class="">)</span></span></code></p></li></ol></pre>

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2wyx6ibkkZCv5I2mYVUywA0rjS3C74FKWhOIKouZ1JlNibJxIgBrg5mcRZNjTDcXHG64tTsXLCfxHzg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

#透视结果筛选

<pre class=""><ol class="list-paddingleft-2"><li><p><code class=""><span><span class="">order8.query(</span><span class="">'姓名 == ["殷瑞瑞","殷影影"]'</span><span class="">)</span></span></code></p></li></ol></pre>

![图片](https://mmbiz.qpic.cn/mmbiz_png/1AQokuKOz2wyx6ibkkZCv5I2mYVUywA0rLvzcGVWP3OQwbicNYlstfQbpqCAuia29kmQX6JmDIVczribu9YzvubiaVw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)
