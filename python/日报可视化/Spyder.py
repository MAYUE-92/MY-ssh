from selenium import webdriver
from selenium.webdriver.chrome.options import Options


class Spyder():
    def __init__(self, url, user, password):
        self.url = url
        self.user = user
        self.password = password

    def data_get(self):
        option = Options()
        # option.add_argument('--headless')
        bowser = webdriver.Chrome()
        bowser.get(self.url, option=option)   
        bowser.find_element_by_class_name("ivu-login-username").send_keys(self.user)
        bowser.find_element_by_class_name("ivu-login-password").send_keys(self.password)
        bowser.find_element_by_tag_name('button').click()
