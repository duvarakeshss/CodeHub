class Parse:
   def __init__(self,filePath):
       with open(filePath,'r') as file:
           self.data = file.read()
  
   def removeMacros(self):
       lines = self.data.splitlines()
       macros = {}
       for line in lines:
           if '#define' in line:
               word = line.split(' ')
               if len(word) > 2:
                   macroName = word[1]
                   macrosub = word[2]
                   macros[macroName] = macrosub
       newLines = []
       print(macros)
       for line in lines:
           if '#define' in line:
               continue
           for macroName , macrosub in macros.items():
               line = line.replace(macroName,macrosub)
           newLines.append(line)
       self.data = '\n'.join(newLines)
       with open(file,'w') as filePath:
           filePath.write(self.data)
       filePath.close()
file = 'main.c'
c = Parse(file)
c.removeMacros(file)
