import sys
import math
    
def h(x):
    for elemento in x:
        if elemento != 0:
            return False
    return True        

def f(y):
    nova = []
    j = 0
    tam = len(y)
    while j < tam - 1:
        d = y[j+1] - y[j]
        nova.append(d)
        j = j + 1
    return nova

if __name__ == "__main__":
    tamanho = int(input())
    lista = input()
    x = []
    i = 0
    while i < tamanho:
        x.append(i+1)
        i += 1
    y = [int(numero) for numero in lista.split()]
    l = []
    co = -1
    i = 0
    l = y
    while i < tamanho:
        l = f(l)
        co = co + 1
        if len(l) <2:
            break
        if h(l):
            break
        i = i + 1
        
    print(co)
    
