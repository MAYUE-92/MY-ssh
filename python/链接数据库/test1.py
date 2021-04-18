import pandas as pd
import re


class DataDell():
    def __init__(self):
        pass

    '''使用pandas读取文件，并生成DataFarme对象，仅写了读取csv和excel的.xlsx文件两种类型,异常值和空白值填充为0'''
    def data_read(self, filename, index_col=None, sheet=0, skiprows=None):
        name = re.search('(\.)\w+', filename)
        if name.group() == '.csv':
            self.data = pd.read_csv(filename, index_col=index_col, skiprows=skiprows).fillna('0')
            return self.data
        elif name.group() == '.xlsx':
            self.data = pd.read_excel(filename, sheet_name=sheet, skiprows=skiprows, index_col=index_col).fillna('0')
            return self.data
        else:
            return print('仅限定microsoftoffice—excle文件和csv文件')

    '''数据切片功能，从dataframe对像中截取需要的片段，截取方式按列切片。'''
    def data_chioce(self, choice):
        if type(choice) == list:
            self.num = self.data[choice]
            return self.num
        else:
            print("参数必须以列表的形式传入，例如['业务员','总收益']")
        
    '''数据透视功能'''
    def data_pivot(self):
        frame = self.data[[]]

a = DataDell()
data = a.data_read('D:\code\python_project\python_code\日报可视化\data.xlsx')
print(data.head(5))