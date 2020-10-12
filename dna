from csv import reader

from sys import argv

def main():
    if len(argv) != 3:
        print("Use the format: dna.py (database).csv (sequence).txt")
        return 1
    
    dna = loadSeq(argv[2])
    
    strs, table = loadDatabase(argv[1])
    
    found = [0] * len(strs)
    
    check = [False] * len(strs)
    
    for i in range(len(strs)):
        
        found[i] = 0
        
        pos = 0
        
        while pos < len(dna):
            pos = dna.find(strs[i], pos +1, len(dna))
            
            if pos != -1:
                found[i] += 1
                
            else:
                break
    

    i = 0
    j = 0
    
    while i < len(table):
        while j < len(strs):
            
            carry1 = table[i][j +1]
            carry2 = found[j]
            
            print(carry1, end="_")
            print(carry2)
            
            if carry2 == carry1:
                print("ye")
            #print()
            
            j += 1
        
        j = 0
        
        i += 1


def loadSeq(name):
    with open(name, "r") as seq:
        sequence = reader(seq)
        for row in sequence:
            dnaRow = row
            
    return dnaRow[0]


def loadDatabase(nam2):
    with open(nam2, "r") as database:
        table = list(reader(database))
        table[0].remove("name")
        strs = table[0]
        table.pop(0)

    return strs, table
    


main()
