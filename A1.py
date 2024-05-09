class HashTable:
    def __init__(self, max_size=123):
        self.max_size = max_size
        self.data_list = [None] * max_size

    # Hash Function
    def get_index(self, key):
        result = 0
        for character in key:
            number = ord(character)
            result += number
        return result % self.max_size

    # Linear probing for collision resolution without replacement
    def get_valid_index(self, key):
        idx = self.get_index(key)
        initial_idx = idx
        while True:
            kv = self.data_list[idx]
            if kv is None:
                return idx
            k, v = kv
            if k == key:
                return idx  # Key already exists
            idx = (idx + 1) % self.max_size  # Linear probing
            if idx == initial_idx:
                raise Exception("HashTable is full")

    # Insert 
    def insert(self, key, value):
        idx = self.get_valid_index(key)
        self.data_list[idx] = (key, value)


    # List all keys and values with index
    def list_all(self):
        for idx, kv in enumerate(self.data_list):
            if kv is not None:
                print(f"{idx} {kv}")



class HashTable1:
    def __init__(self, max_size=123):
        self.max_size = max_size
        self.data_list = [None] * max_size

    # Hash Function
    def get_index(self, key):
        result = 0
        for character in key:
            number = ord(character)
            result += number
        return result % self.max_size

    
    # Linear probing for collision resolution without replacement
    def get_valid_index(self, key):
        idx = self.get_index(key)
        initial_idx = idx

        # Quadratic hashing
        quadratic_counter = 1
        while True:
            kv = self.data_list[idx]
            if kv is None:
                return idx
            k, v = kv
            if k == key:
                return idx  # Key already exists
            idx = (idx + quadratic_counter ** 2) % self.max_size  # Quadratic probing
            quadratic_counter += 1
            if idx == initial_idx:
                raise Exception("HashTable is full")

    # Insert 
    def insert(self, key, value):
        idx = self.get_valid_index(key)
        self.data_list[idx] = (key, value)


    # List all keys and values with index
    def list_all(self):
        for idx, kv in enumerate(self.data_list):
            if kv is not None:
                print(f"{idx} {kv}")



def menu():
    print("MENU")
    print("1.Linear probing")
    print("2.Quadratic Hashing")
    print("3.Exit")


def main():

    choice = 0

    menu()

    while(choice != 3):

        choice = int(input("Enter a choice:"))

        match(choice):

            case (1):

               
                linear = HashTable(max_size=5)
                print("1. add records")
                print("2. display")
                print("3.Previous menu")
                choice1 = 0

                while(choice1 != 3):
                    choice1 = int(input("Enter a choice:"))


                    match(choice1):

                        case (1):
                            key = input("Enter a name:")
                            value = input("Enter a tel number:")
                            linear.insert(key, value)
                        
                        case (2):
                            linear.list_all()
                        
                        case (3):
                            menu()
            

            case (2):

                quadratic = HashTable1(max_size=5)
                print("1.Add records")
                print("2.Display")
                print("3.exit")
                choice2 = 0

                while(choice2 != 3):
                    choice2 = int(input("Enter a choice:"))

                    match(choice2):

                        case (1):
                            key1 = input("Enter a name:")
                            value1 = input("Enter a tel no:")
                            quadratic.insert(key1, value1)
                            

                        case (2):
                            quadratic.list_all()
                            

                        case (3):
                             menu()
                    
                
            case (0):
                menu()
            

if __name__ == "__main__":
    main()

                
                
