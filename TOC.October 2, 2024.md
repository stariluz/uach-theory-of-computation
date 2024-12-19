$\Sigma = \{[,=,>\}$

$A=\{ w | [^m=^n>^m \textrm{donde } m>0, n>1\}$

$S \to [S> | [A>$

$A \to ==A_1$

$A_1 \to =A_1 | \epsilon$

---

$\Sigma = \{],-,>\}$

$B=\{ w | ]^m-^n>^{2m} \textrm{donde } m \gt 0, n\geq3\}$

$S \to ]S>> | ]B>>$

$B \to ---B_1$

$B_1 \to -B_1 | \epsilon$

---

$\Sigma = \{(,),[,],\{,\},a,b\}$

$C=\{ w | \textrm{ usa parentesis, corchetes y/o llaves bien balanceados. }\}$

$S \to (S) | [S] | \{S\} | A$

$C \to LC | \epsilon$

$L \to a|b$

> Una gramática ambigua es una que puede generar la misma cadena de 2 maneras diferentes.