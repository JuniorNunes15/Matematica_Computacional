import math
import sys

def f(c,m, v):
    g = 9.8
    return ((g*m)/c)*(1-math.e**(-(c/m)*t))-v



def bissecao(c, v, t):
    m_ini = 50
    m_fim = 100
    m_meio = (m_ini+m_fim)/2

    while((f(c, m_meio, v) < -0.001) or (f(c,m_meio, v) > 0.001)):
        print(f(c, m_ini, v)*f(c, m_meio, v))
        if(f(c, m_ini, v)*f(c, m_meio, v)<0):
            m_fim = m_meio
        else:
            m_ini = m_meio
        m_meio = (m_ini+m_fim)/2
        
    return m_meio


if __name__ == "__main__":

    c, v, t = map(float, sys.stdin.readline().split())
    
    print('%.2f' % bissecao(c,v,t))


