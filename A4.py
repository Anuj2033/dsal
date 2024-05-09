class set:
    
    def __init__(self):
        self.data = []

    
    # Add New Element
    def add(self, elmt):
        if(elmt not in self.data):
            self.data.append(elmt)
    
    
    # Remove element
    def remove(self, elmt):
        if(elmt in self.data):
            self.data.remove(elmt)
            return True
        else:
            return False
    
    
    # Contains
    def contain(self, elmt):
        if(elmt in self.data):
            return True
        else:
            return False


    # Size
    def size(self):
        count = 0
        for elmt in self.data:
            count += 1
        return count


    # Instersection of set
    def intersection(self, first_set):
        ans = []
        for elmt in first_set:
            if(elmt in self.data):
                ans.append(elmt)
        return ans
    
    # Union
    def union(self, first_set):
        ans = self.data.copy()
        for elmt in first_set:
            if(elmt not in self.data):
                ans.append(elmt)
        return ans
    
    
    # Difference
    def difference(self, first_set):
        ans = self.data.copy()
        for elmt in first_set:
            if elmt in ans:
                ans.remove(elmt)
        return ans

    # Subset
    def subset(self, first_set):
        for e in first_set:
            if e not in first_set:
                return False
        return True


    # Display 
    def display(self):
        print(self.data)
    
    
# Input
def input_set():
    ans = []
    n = int(input("Enter no of elements in set:"))
    for i in range(n):
        ans.append(int(input(f"Enter element {i+1}:")))
    return ans



def menu():
    print("MENU")
    print("1.Add new element")
    print("2.Remove element")
    print("3.Search element")
    print("4.Display Size of Set")
    print("5.Intersection of Sets")
    print("6.Union of Sets")
    print("7.Difference of Sets")
    print("8.Check if subset of Set")
    print("9.Display Set")
    print("10. exit")
    print("0.Display Menu")



def main():
    s1 = set()
    choice = 1

    menu()

    while(choice != 10):
        choice = int(input("Enter a choice:"))

        match(choice):
            case (1):
                n = int(input("Enter a number to add:"))
                s1.add(n)

            case (2):
                n = int(input("Enter a number to remove:"))
                if(s1.remove(n)):
                    print("Element removed successfully")
                else:
                    print("Element no in the set")
            

            case (3):
                n = int(input("Enter number to find:"))
                if(s1.contain(n)):
                    print("Element present in the set")
                else:
                    print("Element not present in set")
            
            case (4):
                print("Size of the set is ", s1.size())
            
            case(5):
                s = input_set()
                print("Intersection of set is ", end="")
                print(s1.intersection(s))
            

            case(6):
                s = input_set()
                print("Union of set is ", end="")
                print(s1.union(s))
            

            case(7):
                s = input_set()
                print("Difference of set is ", end="")
                print(s1.difference(s))
            
            case(8):
                s = input_set()
                if(s1.subset(s)):
                    print("Set is Subset")
                else:
                    print("Set is not subset")
            
            case (9):
                s1.display()
            
            case (0):
                menu()
            
            case default:
                print("Invalid Choice")
            
if __name__ == "__main__":
    main()
            
                