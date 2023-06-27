import sys
import math

def truncate(f, n):
    '''Truncates/pads a float f to n decimal places without rounding'''
    s = '%.12f' % f
    i, p, d = s.partition('.')
    return '.'.join([i, (d+'0'*n)[:n]])

def f(K, Cc, Ca, Cb, x):
    return ((Cc+x)/(((Ca-2*x)**2)*(Cb-x)))-K

def bissection(K, Ca, Cb, Cc, x_i, x_u, qt):
    c = (x_i+x_u)/2.0
    while math.fabs(x_u-x_i) > K:
        if(f(K, Cc, Ca, Cb, x_i)*f(K, Cc, Ca, Cb, c) < 0):
            x_u = c
        else:
            x_i = c
        c = (x_i+x_u)/2.0
        
    return c

if __name__ == "__main__":

    K, Ca, Cb, Cc, x_i, x_u, qt = map(float, sys.stdin.readline().split())
    resultado = bissection(K, Ca, Cb, Cc, x_i, x_u, qt)+0.0001
    
    a = truncate(resultado, int(qt))

    print(a)
    