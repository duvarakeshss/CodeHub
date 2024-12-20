class Parse:
    def __init__(self,filePath):
        with open(filePath,'r') as file:
            self.data = file.read()
        file.close()
        
    def removeComments(self):
        lines = self.data.splitlines()
        flag = True
        newLines = []
        for i in lines:
            if '//' in i:
                flag = False
            if '/*' in i:
                flag = False
            
            if '*/' in i:
                flag = True
                continue
            if flag == True:
                newLines.append(i)
        self.data = '\n'.join(newLines)
        with open('remComfile.c','w') as file:
            file.write(self.data)
        file.close()
filePath = "main.c"
remCom = Parse(filePath)
remCom.removeComments()
