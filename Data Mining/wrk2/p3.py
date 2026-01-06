import pandas as pd

class Analysis:
    def __init__(self,file_path):
        self.data = pd.read_csv(file_path)
        
    def missingValues(self):
        missing = self.data.isnull().sum()
        print("Missing Values in each column:")
        print(missing)
        print(f"\nTotal columns with missing values: {(missing > 0).sum()}")
    
    def statesCount(self):
        if 'statname' in self.data.columns:
            states = self.data['statname'].nunique()
            print(f"\nNumber of unique states: {states}")
        else:
            print("\nStates count: Column 'statname' not found in dataset")
    
    def schoolCategories(self):
        """
        School categories in the dataset based on the columns:
        1-7 represent different school types
        """
        categories = [
            "Primary with upper primary and secondary and higher secondary",
            "Upper Primary with secondary and higher secondary", 
            "Primary with upper primary and secondary",
            "Upper Primary with secondary",
            "Secondary only",
            "Secondary with Hr. Secondary",
            "Hr. Secondary only"
        ]
        print(f"\nNumber of school categories: {len(categories)}")
        print("\nSchool Categories:")
        for i, cat in enumerate(categories, 1):
            print(f"{i}. {cat}")
    
    def singleTeacherPercentage(self):
        """
        Calculate percentage of schools with single teacher in secondary level
        Uses sing_tch_sch_all (Schools with Single Teacher: All Schools)
        and schools (total schools)
        """
        if 'sing_tch_sch_all' in self.data.columns and 'schools' in self.data.columns:
            total_schools = self.data['schools'].sum()
            single_teacher_schools = self.data['sing_tch_sch_all'].sum()
            percentage = (single_teacher_schools / total_schools) * 100
            print(f"\nTotal Schools: {total_schools}")
            print(f"Schools with Single Teacher: {single_teacher_schools}")
            print(f"Percentage of schools with single teacher: {percentage:.2f}%")
        else:
            print("\nSingle teacher percentage: Required columns not found in dataset")
    
    def literacyRateAnalysis(self):
        """
        Find states with highest and lowest literacy rates
        """
        if 'statname' in self.data.columns and 'literacy_rate' in self.data.columns:
            # Remove any null values
            data_clean = self.data[['statname', 'literacy_rate']].dropna()
            
            # Get unique states with their literacy rates
            state_literacy = data_clean.groupby('statname')['literacy_rate'].mean().sort_values()
            
            print("\n=== Literacy Rate Analysis ===")
            print(f"\nLowest Literacy Rate:")
            lowest = state_literacy.head(1)
            print(f"{lowest.index[0]}: {lowest.values[0]:.2f}%")
            
            print(f"\nHighest Literacy Rate:")
            highest = state_literacy.tail(1)
            print(f"{highest.index[0]}: {highest.values[0]:.2f}%")
            
            print(f"\nAll States (sorted by literacy rate):")
            for state, rate in state_literacy.items():
                print(f"{state}: {rate:.2f}%")
        else:
            print("\nLiteracy rate analysis: Required columns not found in dataset")

# NOTE: Replace with actual data file path when available
# Current file is metadata only
object = Analysis("2015_16_Statewise_Secondary_Metadata.csv")



# 1. Check for missing values
object.missingValues()

# 2. Count states
object.statesCount()

# 3. School categories
object.schoolCategories()

# 4. Single teacher percentage
object.singleTeacherPercentage()

# 5. Literacy rate analysis
object.literacyRateAnalysis()