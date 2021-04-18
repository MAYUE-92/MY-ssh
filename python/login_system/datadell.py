import pandas as pd


class DataDell():
    def __init__(self):
        pass

    '''读取储存用户信息的csv文件，将所有信息保存为DataFrame对象'''
    def read_func(self, filename=r'D:\code\python_project\python_code\login_system\user.csv'):
        #? 必须设置id列为index索引，否则，pandas会自动添加一个索引，后期会造成索引错误
        self.data = pd.read_csv(filename, encoding='utf-8')
        return self.data
    
    '''提取用户名的相关信息，并保存为列表，以便后续模块进行判断'''
    #? username是用户信息存储文件的用户名列的列名，可以设为默认值，直接调用即可，无需传参
    def name_get(self, u_name, username='username'):
        index = self.data[(self.data['username'] == u_name)].index.tolist() 
        for i in index:
            #? 获取对应id的密码
            self.name = self.data.loc[i, username]
            return self.name
    
    '''根据用户名，提取对应的登陆密码，以便登陆功能检测密码是否匹配，返回值为tex'''
    def pw_get(self, u_name, pwd='password'):
        #? 获取用户的id
        index = self.data[(self.data['username'] == u_name)].index.tolist() 
        for i in index:
            #? 获取对应id的密码
            self.pw = self.data.loc[i, pwd]
            return self.pw
    

    def get_lock(self, u_name, lock='lock'):
        index = self.data[(self.data['username'] == u_name)].index.tolist() 
        for i in index:
            #? 获取对应id的密码
            self.lock = self.data.loc[i, lock]
            return self.lock

    '''该功能模块用于新用户注册，将新用户信息保存到用户信息储存文档的csv文件中'''
    #? 新用户注册，id为系统自增长，所以不用设定，需要传入用户的用户名和密码，其中lock和times值设为默认参
    def registed(self, u_name, pwd, lock="F"):
        #? 够键一个新的DataFrame对象，整体添加进data对象中，从而保存到csv文件。
        num = pd.DataFrame({
            "username": u_name,
            "password": pwd,
            "lock": lock
            }, index=[1])
        nums = self.data.append(num, ignore_index=True)
        nums.to_csv(r"D:\code\python_project\python_code\login_system\user.csv", index=None)

    #? 作用就是只要用户登陆错误3次，就将lock设为T
    def lock_func(self, u_name):
        index = self.data[(self.data['username']==u_name)].index.tolist()
        for i in index:
            self.data.loc[i, 'lock'] = "T"
            self.data.to_csv(r'D:\code\python_project\python_code\login_system\user.csv', index=None)
    

'''模块测试'''
if __name__ =="__main__":
    #! 读取功能测试
    filename = r'D:\code\python_project\python_code\login_system\user.csv'
    a = DataDell()
    data = a.read_func() #? 参数已设为默认参，若储存文件地址变更，从新传参即可。
    print("用户信息表：")
    print(data)
    print('=='*50)

    #! 测试用户名拉取
    print("系统中的用户：")
    b = a.name_get('mayue')
    print(b)
    print('=='*50)

    #! 测试密码拉去
    username = 'mayue'
    print('用户{}密码为'.format(username))
    c = a.pw_get(u_name=username)
    print(c)
    print('=='*50)

    # #! 测试注册模块
    # new_user = 'zhangsan'
    # password = 'mmmmmm'
    # d = a.registed(u_name=new_user, pwd=password)
    # new_data = a.read_func(filename)
    # print(new_data)
    # print('=='*50)

    # #! 测试锁定功能
    # f = a.lock_func('zhangsan')
    # s = a.read_func(filename)
    # print(s)