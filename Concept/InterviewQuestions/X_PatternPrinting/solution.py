str1 = "hello world"

for i in range(0, len(str1)):
    for j in range(0, len(str1)):
        if (i == j) or (len(str1)-1-j == i):
            print(str1[j], end="")
        else:
            print(" ", end="")
    print()

# Output:
# h         d
#  e       l 
#   l     r  
#   l   o   
#     o w    
           
#     o w    
#   l   o   
#   l     r  
#  e       l 
# h         d
