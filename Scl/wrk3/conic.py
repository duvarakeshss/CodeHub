import sympy as sp

x , y = sp.symbols('x y')
u = sp.Function('u')(x,y)

def find(eq):
    
    A = eq.lhs.coeff(sp.diff(sp.diff(u,x),x))   
    B = eq.lhs.coeff(sp.diff(sp.diff(u,x),y)) + eq.lhs.coeff(sp.diff(sp.diff(u,y),x))
    C = eq.lhs.coeff(sp.diff(sp.diff(u,y),y))
    
    D = B**2 - 4 * A * C
    
    if D == 0:
        print("parabola")
    elif D < 0:
        print("Elliptical")
    else:
        print("Hyberbolic")
    
    print("Determinant : ",D)

Eq1 = sp.Eq(
    sp.diff(sp.diff(u, x), x) +
    sp.diff(sp.diff(u, y), y),
        0
)
   
find(Eq1) 

eq1 = sp.Eq(
        sp.diff(sp.diff(u, x), x) -
        12 ** 2 * sp.diff(sp.diff(u, y), y),
        0
    )
find(eq1)

eq2 = sp.Eq(
        sp.diff(u, x) -
        12 * sp.diff(sp.diff(u, y), y),
        0
    )
find(eq2)