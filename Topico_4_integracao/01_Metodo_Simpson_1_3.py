import math
def f(x):
  return math.sqrt(6*x -3)

def simpson38(f,a,b,c,d,e, dis):
  h = (1)/3
  x0 = a
  x1 = b
  x2 = c
  x3 = d
  x4 = e
  #print(f"{x0} {x1} {x2}")
  return (3*h/8)*(f(x0)+3*f(x1)+3*f(x2)+f(x3)+f(x4))

print(simpson38(f, 1, 2, 1, 2, 3, 1))