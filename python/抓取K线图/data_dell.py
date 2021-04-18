import pandas as pd

class DataDell():
    '''
    参数说明：
    f_name：是csv文件名
    '''
    def __init__(self, f_name):
        self.f_name = f_name
    '''通过pandas读取csv文件，并返回想要的数据类型（DataFrame）'''
    def rd_csv(self): 
        df = pd.read_csv(self.f_name, parse_dates=True)
        self.nw_df = df[['date', 'open', 'high', 'low', 'close']]
        return self.nw_df
    
if __name__ == "__main__":
    name = "sz.000001.csv"
    a = DataDell(name)
    print(a.read_csv())