# Python3 program to implement 
# the above approach 
  
# Function to find the substring with K 
# pairwise distinct characters and 
# with same frequency 
def no_of_substring(s, N): 
  
    # Length of the string 
    str_len = len(s) 
  
    count = 0
  
    # Iterate over the string 
    for i in range(str_len): 
  
        # Stores the occurrence of each 
        # character in the substring 
        # Set all values at each index to zero 
        fre = [0] * 26
  
        max_index = 0
  
        # Stores the count of 
        # unique characters 
        dist = 0
  
        # Moving the substring ending at j 
        for j in range(i, str_len): 
  
            # Calculate the index of 
            # character in frequency array 
            x = ord(s[j]) - ord('a') 
  
            if (fre[x] == 0): 
                dist += 1
  
            # Increment the frequency 
            fre[x] += 1
  
            # Update the maximum index 
            max_index = max(max_index, fre[x]) 
  
            # Check for both the conditions 
            if(dist >= N and 
             ((max_index * dist) == (j - i + 1))): 
                count += 1
  
    # Return the answer 
    return count 
  
# Driver Code 
s = "abcdaaae"
N = 3
  
# Function call 
print(no_of_substring(s, N)) 
  
# This code is contributed by Shivam Singh 