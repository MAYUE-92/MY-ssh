import datadell


def registed():
    func = datadell.DataDell()
    func.read_func()
    name = input('请输入注册名：')
    username = func.name_get(name)
    if name == username:
        print("注册名已存在，请换一个")
        return registed()
    else:
        pwd = input('请输入密码：')

    func.registed(name, pwd)
    print("注册成功，请登陆")
    return login()


def lock(name):
    func = datadell.DataDell()
    func.read_func()
    func.lock_func(name)
    print("账户已锁定")


def login():
    n = 0
    func = datadell.DataDell()
    func.read_func()
    login_name = input("请输入用户名：")
    try:
        username = func.name_get(login_name)
        lock_key = func.get_lock(login_name)
        pwd = func.pw_get(login_name)
    except AssertionError:
        print("你尚未注册") #也可写pass

    if lock_key == "T":
        print('您的账户被锁定了，请改库')
    else:
        if login_name == username:
            while n < 3:
                password = input("登录密码：")
                if (login_name == username) and (password == pwd):
                    print("登陆成功，欢迎{}".format(login_name))
                    break
                else:
                    n += 1
                    print("账号密码不匹配，您还剩余{}次机会".format(3 - n))
            else:
                return lock(login_name)
        else:
            print("找不到您的用户名，请注册")
            return registed()



if __name__ == "__main__":
    a = login()