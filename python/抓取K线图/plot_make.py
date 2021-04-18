import cufflinks as cf
import plotly.offline as plyo


class PlotMake():
    '''
    参数说明：df是一个dataframe类型
    '''
    def __init__(self, df):
        self.df = df
    '''通过cufflinks和plotly制作K线图'''
    def make(self):
        qf = cf.QuantFig(self.df,
                         legend='top',
                         )
        qf.add_bollinger_bands(periods=15, boll_std=2)
        # 设置RSI指标线
        qf.add_rsi(periods=14, showbands=False)
        plyo.plot(qf.iplot(asFigure=True), filename='qf_01.html')
