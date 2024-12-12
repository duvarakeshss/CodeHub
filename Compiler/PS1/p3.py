import os
class count:
    def __init__(self,file):
        self.filepath = file
        with open(self.filepath,'r',encoding='utf-8') as file:
            self.content = file.read()
            file.close()
        
    def count(self):
        self.lineCount = len(self.content.splitlines())
        self.spaceCount = 0 
        self.digitCount = 0
        self.alphabetCount = 0
        self.specialCharCount = 0
        for char in self.content:
            i = ord(char)
            
            if char == " ":
                self.spaceCount += 1
            
            elif i >= 48 and i <= 57:
                self.digitCount += 1
        
            elif (i >= 65 and i <= 90) or (i >= 97 and i <= 122):
                self.alphabetCount += 1
            
            else:
                if char !='\n':
                    self.specialCharCount += 1

                
    def display(self):
        print("Lines Count : ",self.lineCount)
        print("Space Count : ",self.spaceCount)
        print("Digit Count : ",self.digitCount)
        print("Alphabet Count : ",self.alphabetCount)
        print("Special Character Count : ",self.specialCharCount)
        print(f"File Size : {os.path.getsize(self.filepath)} bytes")
    
countData = count('p2.txt')
countData.count()
countData.display()
