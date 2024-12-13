class Solution:
    def kthCharacter(self, k: int, operations: List[int]) -> str:
        ## so how many operations aplied to a?
        k = k-1 # first position is 0
        a = bin(k)[2:] # turn into binary, remove bx header
        a = a[::-1] # reverse 
        a = a + "0"*(len(operations)-len(a)) #add zeros
        
        counter= 0 # merge both lists
        for a,b in zip(a,operations):
            if a=="1" and b==1:
                counter+=1
        return chr(ord('a')+counter%26) #26 is the size of the alphabet
       
                