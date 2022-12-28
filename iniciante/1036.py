from math import sqrt
a, b, c = input().split()
a = float(a)
b = float(b)
c = float(c)

if a == 0:
  print("Impossivel calcular")
else:
  R = ((b**2)-(4*a*c))
  if R <= 0:
    print("Impossivel calcular")
  else:
    R = sqrt(R)
    R1 = (-1*b+R)/(2*a)
    R2 = (-1*b-R)/(2*a)
    print("R1 = %.5f"%(R1)) 
    print("R2 = %.5f"%(R2))