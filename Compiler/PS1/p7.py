class Parse:
    def __init__(self,filePath):
        with open(filePath,'r') as file:
            self.data = file.read()
    
    def removeMultilinesSpaces(self):
        lines = self.data.splitlines()
        newLines = []

        for i in lines:    
            if i.strip():
                line = i.split()
                newLine = ' '.join(line)
                newLines.append(newLine)
        
        self.data = '\n'.join(newLines)
        
        with open('remlineSpace.c','w') as file:
            file.write(self.data)

    
filePath = "main.c"
lex = Parse(filePath)
lex.removeMultilinesSpaces()


