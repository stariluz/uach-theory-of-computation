$\Sigma = \{a,b,(,)\}$

$A = \{ w: (^n(a,b)*)^n, n>0\}$

$S \to (S) | (A)$

$A \to LA | \epsilon$

$L \to a|b$

> Siempre que se deba asegurar que hay la misma cantidad de un lado que de otro, la gramática será libre de contexto

---

$\Sigma = \{a,b,c\}$

$A = \{ w: a \textrm{ y } b \textrm{ balanceads con }c^+ \textrm{ a la mitad}\}$

$S \to aSa | bSb | c$

---

$\Sigma = \{a,b\}$

$A = \{ w: \textrm{es palíndrome par}\}$

$S \to aSa | bSb | \epsilon$

---

$\Sigma = \{a,b\}$

$A = \{ w: \textrm{es palíndrome}\}$

$S \to aSa | bSb | a | b | \epsilon$
