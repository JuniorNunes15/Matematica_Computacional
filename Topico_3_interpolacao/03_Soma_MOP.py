import sys
import math

def PolinomioLagrange(x, y):
    if len(x) != len(y):
        raise RuntimeError("Tamanhos de listas diferentes")
    else:
        n = len(x)
        return lambda a: sum([y[i] * L(i, x)(a) for i in range(n)])
        
def f(grau,n,lista):
    x = []
    i = 0
    while i < grau+1:
        x = [lista[i]*(n)**i] + x
        i = i+1
    return x

def L(i, x):
    n = len(x)
    num = lambda a: math.prod([(a - x[j]) for j in range(n) if j != i])
    den = math.prod([(x[i] - x[j]) for j in range(n) if j != i])
    return lambda a: num(a) / den

if __name__ == "__main__":
    g = int(input())
    l = input()
    c = [int(numero) for numero in l.split()]
    c.reverse()
    
    y = []
    x = []
    mop = []
    veri = True
    i = 1
    sequencia = []
    while veri:
        sequencia = sequencia + [sum(f(g,i,c))]
        y = y + [sum(f(g,i,c))]
        x = x + [i]
        p = PolinomioLagrange(x,y)
        if int(p(i+1)) == sum(f(g,(i+1),c)):
            veri = False
        else:
            mop = mop + [int(p(i+1))]
        i = i + 1
    print(sum(mop))
    