import stock_get
import data_dell
import plot_make
'''调用stock_get.py文件中的StockGet模块'''


def stock(code, start_data, end_data):
    a = stock_get.StockGet(code, start_data, end_data)
    a.get_data()
    a.data_save()
    a.csv_save()


'''调用data_dell.py文件中的DataDell模块'''


def data_read(f_name):
    a = data_dell.DataDell(f_name)
    data = a.rd_csv()
    return data


'''调用plot_make.py文件中的PlotMake模块'''


def plt_mk(df):
    a = plot_make.PlotMake(df)
    a.make()


# ? 参数设定并调用函数
code = 'sh.600519'
start_data = '2020-01-01'
end_data = '2021-02-25'
name = code + '.csv'
print(name)

stock(code, start_data, end_data)
data = data_read(name)
plt_mk(data)