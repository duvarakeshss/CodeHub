import pandas as pd

class SparePartsAnalysis:
    
    def __init__(self, filePath):
        # Read CSV without header, assuming sales data is in the first row
        self.data = pd.read_csv(filePath, header=None)
        # Extract the sales row as a list
        self.sales = self.data.iloc[0].tolist()

    def maxSale(self):
        maxSale = max(self.sales)
        
        print(f"1. Maximum sale: {maxSale}")
        
        daysMaxSale = self.sales.count(maxSale)
        print(f"2. No of days Max sale: {daysMaxSale}")

    def isSales(self):
        count = sum(1 for sale in self.sales if sale > 0)
        if count > 0:
            print("3. Sales achieved")
        else:
            print("3. Sales not achieved")

    def noSales(self):
        daysNoSale = self.sales.count(0)
        print(f"4. No of days with no sale: {daysNoSale}")

    def spareDays(self):
        n = len(self.sales) // 2  # Integer division to split evenly
        
        # Correctly slice the list
        self.salesFirstHalf = self.sales[:n]
        self.salesSecondHalf = self.sales[n:]  # Fixed variable name
        
        # Calculate sums correctly
        salesFirstHalfSum = sum(self.salesFirstHalf)
        salesSecondHalfSum = sum(self.salesSecondHalf)
        
        print(f"Sale First Half: {salesFirstHalfSum}")
        print(f"Second Half sum: {salesSecondHalfSum}")
        
        if salesFirstHalfSum > salesSecondHalfSum:
            print("First Half Sale Greater")
        elif salesFirstHalfSum < salesSecondHalfSum:
            print("Second Half is Greater")
        else:
            print("Both halves have equal sales")

    def maxSaleHalf(self):
        # These attributes are created in spareDays(), so call it first or compute here
        if not hasattr(self, 'salesFirstHalf') or not hasattr(self, 'salesSecondHalf'):
            print("Warning: Run spareDays() first to define halves.")
            return
        
        firstHalfMax = max(self.salesFirstHalf)
        secondHalfMax = max(self.salesSecondHalf)
        
        print(f"First half Max sale: {firstHalfMax}")
        print(f"Second half max sale: {secondHalfMax}")


# Usage
filePath = "/home/cslinux/Downloads/Automobile-spare.csv"
analysis = SparePartsAnalysis(filePath)

analysis.maxSale()
analysis.isSales()
analysis.noSales()
analysis.spareDays()
analysis.maxSaleHalf()
