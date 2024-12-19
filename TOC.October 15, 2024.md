> El tercer parcial se evalua con exposiciones.
> La calificación consiste de 2 exposiciones y asistir a las demás exposiciones.

# Autómta de Pila

$M=(Q,\Sigma, \Gamma, \delta, q_0, Z, F)$

$Q=\text{Estados}$

$\Sigma=\text{Alfabeto de entrada}$

$\Gamma=\text{Alfabeto de pila}$

$\delta=\text{Función de trancisión}$

$Q\times(\Sigma\cup\{\epsilon\})\times\Gamma\to Q\times\Gamma*$

$Q\times(\Sigma\cup\{\epsilon\}) \to P(Q)$

$q_0=\text{Estado inicial}$

$Z=\text{Símbolo inicial en la pilla}$

$F=\text{Estados finales}$

---

$\Sigma=\{(, ), a, b\}$

$S \to (S)|(A)$


$L \to a|b$

---

$\Sigma = \{(,),[,],a,b\}$

$\Gamma = \{x,y,z\}$

$S \to (S) | [S] | (A) | [A]$

$A \to LA | L$

$L \to a|b$

