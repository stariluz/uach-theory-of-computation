Una producción es una regla de la gramática.

$S \to aAB$

#### Producciones

$A \to a|b$

$B \to AAB| \epsilon$

$B \to AAB$

##### Terminales

$A \to a$

$A \to b$

$B \to \epsilon$

Una gramática es una tuplla compuesta de

$G=(N,T,P,S)$

$N=\textrm{Conjunto de no terminales }$

$T=\textrm{Conjunto de terminles } \Sigma \subseteq T$

$P=\textrm{Conjunto de producciones }$

$S=\textrm{Producción inicial } S \in N$


$A=\{aa,ab,aaaa,aaab,aaba,abaa,aabb,abab,abba,abbbb,...\}$

$T=aAB$

<!-- IMAGEN 1 -->
---

$\Sigma=\{a,b\}$

$A=\{w: \textrm{tiene subcadena bb}\}$

$S \to ABA$

$B\to bb$

$A \to aA|bA|\epsilon$ (Es igual a $(a|b)*=\Sigma*$)

<!-- IMAGEN 2 -->

---

$\Sigma=\{a,b\}$

$B=\{w: \textrm{inicia o termina con a}\}$

$S \to A|B$

$A\to aC$

$B\to Ca$

$C \to aC|bC|\epsilon$
