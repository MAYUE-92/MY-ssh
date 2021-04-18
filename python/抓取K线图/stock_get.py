import baostock as bs
import pandas as pd


class StockGet():
    '''定义一个空列表，用于遍历get_data()返回的数据包，获取数据'''
    data = []

    '''
    参数说明：
    code：股票代码
    start_date：开始日期
    end_data：结束日期
    '''
    def __init__(self, code, start_date, end_date):
        self.code = code
        self.start_date = start_date
        self.end_data = end_date

    '''此方法用于登陆baostock，获取服务器响应，并拉取数据包到内存，其中frequency是指的获取数据日期单位为天，dajustflag为偏差'''
    def get_data(self):
        bs.login()
        self.re = bs.query_history_k_data_plus(self.code,
                                               "date,code,open,high,low,close",
                                               start_date=self.start_date,
                                               end_date=self.end_data,
                                               frequency="d",
                                               adjustflag='3')
        bs.logout()
        return self.re
    '''此方法是将get_data()获取到的数据包遍历并存入列表data中'''
    def data_save(self):
        while (self.re.error_code == '0') & self.re.next():
            self.data.append(self.re.get_row_data())
    '''使用pandas库，将data中的数据写入csv'''
    def csv_save(self):
        csv = pd.DataFrame(self.data, columns=self.re.fields)
        csv.to_csv('{}.csv'.format(self.code), index=False)


if __name__ == "__main__":
    pass