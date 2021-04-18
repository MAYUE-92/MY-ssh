import pdfplumber
import os

#os.chdir(r"D:\\code\\python_project\\python_code\\get_pdf\\")


with pdfplumber.open(r"get_pdf\\延安高铁站.pdf") as pdf:
    pages = pdf.pages   # 第一页的信息
    for i in pages:
        text = i.extract_text()
        print(text)
    

