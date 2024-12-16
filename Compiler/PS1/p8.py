    

class Node:
    def __init__(self,data):
        self.data = data
        self.next = None
        

class Linkedlist:
    def __init__(self):
        self.head = None
    
    def append(self,data):
        newNode = Node(data)
        if self.head == None:
            self.head = newNode
            return
        current = self.head
        while current.next:
            current = current.next
        current.next = newNode
        
    def display(self):
        current = self.head
        if not current:
            print("List Empty")
            return
        while current.next:
            print(current.data)
            current = current.next

    def search(self,target):
        current = self.head
        if not current:
            return False
        while current.next:
            if current.data == target:
                return True
            current = current.next

class BNode:
    def __init__(self,data):
        self.data = data
        self.right = None
        self.left = None

class BST:
    def __init__(self):
        self.root = None
        self.traversal = []
    
    def append(self,data):
        newNode = BNode(data)
        if not self.root:
            self.root = newNode
            return
        else:
            self.insert(self.root,newNode)
        
    def insert(self,current,newNode):
        
        if newNode.data < current.data:
            if current.left is None:
                current.left = newNode
            else:
                self.insert(current.left,newNode) 

        elif newNode.data > current.data:
            if current.right is None:
                current.right = newNode
            else:
                self.insert(current.right,newNode)
    
    def inoderTraversal(self,current):
        if current is not None:
            self.inoderTraversal(current.left)
            self.traversal.append(current.data)
            self.inoderTraversal(current.right)
    
class HashTable:
    def __init__(self, size=10):
        self.size = size
        self.table = [[] for _ in range(self.size)]

    def hashFunction(self, key):
        return sum(ord(char) for char in key) % self.size

    def insert(self, key):
        index = self.hashFunction(key)
        if key not in self.table[index]:
            self.table[index].append(key)

    def search(self, key):
        index = self.hashFunction(key)
        return key in self.table[index]

    def display(self):
        print("Hash Table:")
        for i, bucket in enumerate(self.table):
            print(f"Index {i}: {bucket}")

      
class CreateKeyword:
    def __init__(self,filePath):
        with open(filePath,'r') as file:
            self.data = file.read()
        
    def createArray(self):
        self.keyword = self.data.splitlines()
        print(self.keyword)

    def createList(self):
        lines = self.data.splitlines()
        self.list = Linkedlist()
        for i in lines:
            self.list.append(i)
    
    def createBst(self):
        bst = BST()
        lines = self.data.splitlines()
        for i in lines:
            bst.append(i)
        bst.inoderTraversal(bst.root)
        print(bst.traversal)

    def createHashTable(self):
        self.hashTable = HashTable()
        for keyword in self.data.splitlines():
            self.hashTable.insert(keyword)
        self.hashTable.display()
        

filePath = 'CKeyword.txt'
keyword = CreateKeyword(filePath)
keyword.createArray()
keyword.createList()
keyword.createBst()
keyword.createHashTable()