import pandas as pd
from bs4 import BeautifulSoup
import requests


class Html:
    def __init__(self,filepath):
        self.file = filepath

    def scrapeHtml(self,url):
        response = requests.get(url)
        response.raise_for_status()
        soup = BeautifulSoup(response.text, 'html.parser')
        with open(self.file, 'w', encoding='utf-8') as file_pointer:
            file_pointer.write(str(soup))       

    def readHtml(self):
        with open(self.file,'r',encoding='utf-8') as f:
            self.data = f.read()
        f.close()

    def removeTags(self):
        flag = True
        self.notag = ""
        for i in range(len(self.data)):
            if self.data[i] == '<':
                flag = False

            if self.data[i] == '>':
                flag = True
                continue

            if flag == False:
                continue
            if flag == True:
                self.notag+=(self.data[i])
        lines = self.notag.splitlines()
        self.notag = [line.strip() for line in lines if line.strip() != '']
        c = 0
        with open('p2.txt','w',encoding='utf-8') as file:
            for i in self.notag:
                if c < len(self.notag)-1:
                    file.write(i + '\n')
                else:
                    file.write(i)
                c += 1

filepath = 'index.html'
url = "https://www.geeksforgeeks.org/how-to-automate-an-excel-sheet-in-python/?ref=feed"

data = Html(filepath)
data.scrapeHtml(url)
data.readHtml()
data.removeTags()