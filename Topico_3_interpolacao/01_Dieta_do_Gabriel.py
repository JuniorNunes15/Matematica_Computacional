import sys
import math

def L(i, x):
    n = len(x)
    num = lambda a : math.prod([ (a - x[j]) for j in range(n) if j != i])
    den = math.prod([ (x[i] - x[j]) for j in range(n) if j != i])
    return lambda a : num(a)/den
     
def PolinomioLagrange(x, y):
    if len(x) != len(y):
        raise RuntimeError("tamanho das listas diferentes")
    else:
        n = len(x)
        return lambda a : sum( [ y[i]*L(i,x)(a) for i in range(n)])

if __name__ == "__main__":

    N, M = map(float, sys.stdin.readline().split())

    x = [50, 60, 70]
    x1 = [2500, 2850, 3200]
    x2 = [2350, 2700, 3000]
    x3 = [1900, 2250, 2750]

    p1 = PolinomioLagrange(x, x1)
    p2 = PolinomioLagrange(x, x2)
    p3 = PolinomioLagrange(x, x3)

    val = [25, 45, 65]
    val2 = [p1(M), p2(M), p3(M)]

    result = PolinomioLagrange(val, val2)
    print('%.5f' % result(N))