class Parse:
    def __init__(self,filePath):
        with open(filePath,'r') as file:
            self.data = file.read()
        file.close
    
    def addLineNumber(self):
        lines = self.data.splitlines()
        k = 1
        newLines = []
        for i in lines:
            i = str(k)+' '+i
            newLines.append(i)
            k += 1
        self.data = '\n'.join(newLines)
        with open('Addline.txt','w') as file:
            file.write(self.data)
        file.close()

filePath = "main.c"
lineNum = Parse(filePath)
lineNum.addLineNumber()
        