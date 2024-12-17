class Tokens:
    def __init__(self, filePath,StoreFilePath):
        with open(filePath, 'r') as file:
            self.data = file.read()
        self.file = StoreFilePath
        self.tokens = {
            "keywords" : [],
            "identifier" : [],
            "intergerConstant" : [],
            "floatingPointConstant" : [],
            "stringConstant" : [],
            "labels" : [],
            "operators" : [],
            "octals" : [],
            "backslach" : []
        }
        
        self.operator = ['+', '-', '*', '/', '%', '==', '!=', '<', '>', '<=', '>=', '&&', '||', '!', '&', '|', '^', '~']


    def removeMacros(self):
        lines = self.data.splitlines()
        macros = {}

        for line in lines:
            if '#define' in line:
                words = line.split(' ')
                if len(words) > 2:
                    macroName = words[1]
                    macroSub = words[2]
                    macros[macroName] = macroSub

        newLines = []

        for line in lines:
            if '#define' in line:
                continue
            for macroName, macroSub in macros.items():
                line = line.replace(macroName, macroSub)
            newLines.append(line)

        self.data = '\n'.join(newLines)
        with open(self.file, 'w') as filePath:
            filePath.write(self.data)

    def addLineNumber(self):
        lines = self.data.splitlines()
        k = 1
        newLines = []

        for line in lines:
            line = f"{k} {line}"
            newLines.append(line)
            k += 1

        self.data = '\n'.join(newLines)
        with open(self.file, 'w') as file:
            file.write(self.data)
            
    def removeComments(self):
        lines = self.data.splitlines()
        flag = True
        newLines = []
        for i in lines:
            if '//' in i :
                continue
            if '/*' in i:
                flag = False
            
            if '*/' in i:
                flag = True
                continue
            if flag == True:
                newLines.append(i)
        self.data = '\n'.join(newLines)
        with open(self.file,'w') as file:
            file.write(self.data)

    def identifyTokens(self,filePath):
        with open(self.file,'r') as file:
            token = file.read()
        with open(filePath,'r') as file:
            keyword = file.read()
        keyword = keyword.splitlines()
            
        words = token.replace(';', ' ; ').replace(',', ' , ').split()  
        
        for i in words:
            if i in keyword:
                self.tokens["keywords"].append(i)
                
            elif i.isdigit():
                self.tokens["intergerConstant"].append(i)
                
            elif i.startswith('"') and i.endswith('"'):
                self.tokens["stringConstant"].append(i)
            
            elif i.endswith(':') and i[:-1].isidentifier():
                self.tokens["labels"].append(i[:-1])
            
            elif i in self.operator:
                self.tokens["operators"].append(i)
            
            elif i.startswith('0') and all(c in '01234567' for c in i[1:]):
                self.tokens["octals"].append(i)
        
            elif i.startswith('\\') and len(i) == 2:
                self.tokens["backslash"].append(i)
                
            elif i.replace('.', '', 1).isdigit() and '.' in i:
                ["floatingPointConstant"].append(i)
            
            elif i.isidentifier():
                self.tokens["identifier"].append(i)
                
    def display(self):
        print(self.tokens)

        

c = Tokens('main.c','tokens.txt')
c.removeMacros()
c.addLineNumber()
c.removeComments()
c.identifyTokens('CKeyword.txt')
c.display()
