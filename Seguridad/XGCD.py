def egcd(a, b):   
    if a == 0 :   
        return b, 0, 1
             
    gcd, x1, y1 = egcd(b%a, a)  
    x = y1 - (b//a) * x1  
    y = x1  
     
    return gcd, x, y 
      

print("Ingrese el primer numero") 
a = int(input())

print("Ingrese el segundo numero") 
b = int(input())

g, x, y = egcd(a, b)  
print("gcd(", a , "," , b, ") = ", g)  