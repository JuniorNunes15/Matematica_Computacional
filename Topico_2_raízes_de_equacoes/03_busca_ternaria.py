import math


def f(a, x):
    """
    Função que calcula o valor do polinômio para um dado x e coeficientes.
    """
    ret = 0
    for i in range(len(a)):
        ret = ret * x + a[i]
    return ret


def ternary_search(a, l, h, tol):
    """
    Função que realiza a busca ternária para encontrar uma raiz do polinômio.
    """

    iteracoes = 1
    while abs(h - l) > tol:
        #print(f"Iteracao {iteracoes} l = {l} h = {h} f(l) = {f(a, l)} f(h) = {f(a, h)}")

        m1 = l + (h - l) / 3
        m2 = l + 2 * (h - l) / 3

        f_m1 = f(a, m1)
        f_m2 = f(a, m2)

        if f_m1 * f_m2 < 0:
            h = m2
        else:
            l = m1

        iteracoes += 1

    a = round(l, 10)
    b = round(h, 10)

    return iteracoes, a, b


if __name__ == "__main__":
    n = int(input())
    a = [float(x) for x in input().split()]
    l, h = [float(x) for x in input().split()]
    tol = float(input())

    iteracoes, a, b = ternary_search(a, l, h, tol)

    print("busca ternaria realizou {} iteracoes".format(iteracoes))
    print("a solucao está no intervalo [{:.10f},{:.10f}]".format(a, b))
