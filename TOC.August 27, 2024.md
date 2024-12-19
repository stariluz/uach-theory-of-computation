
$\Sigma^*$

$S \to K$

$K \to LK | \epsilon$

$L \to a | b$


> Tarea: Imagen de la cerradura de Kleene

$\Sigma=\{a,b\}$

$A=\{w: w \textrm{ tiene subcadena bb}\}$

$S \to A$

$A \to KA_1K$

$A_1 \to bb$

$K \to LK | \epsilon$

$L \to a | b$


> Tarea: Imagen del autómata

---

$\Sigma=\{a,b\}$

$B=\{w: w \textrm{ inicia o termina en b}\}$

$S \to B$

$B \to B_1 | B_2$

$B_1 \to bK$

$B_2 \to Kb$

$K \to LK | \epsilon$

$L \to a | b$


> Tarea: Imagen del autómata

$Q = \{q_0, q_1, q_2, q_3, q_4\}$


$\Sigma = \{a,b\}$


$F = {q_2, q_4}$


$\delta: \begin{matrix}
(q_0, \epsilon) \to \{q_1, q_2\}\\
(q_1, b) \to \{q_2\}\\
(q_2, a) \to \{q_2\}\\
(q_2, b) \to \{q_2\}\\
(q_3, a) \to \{q_3\}\\
(q_3, b) \to \{q_3, q_4\}\\
\end{matrix}$


---

$\Sigma = \{a,b\}$

$D = \{w: w \textrm{ inicia o termina en b y tiene la subcadena bb}\}$

$S \to D$

$D \to KA_1 | bKA_1K | KA_1Kb | A_1K$

$B \to bb$

> Tarea: Imagen del autómata
a la
> Examen. Podemos irnos directos Al AFD. Es recomendable hacer el AFN
> para no equivocarse si el AFD es muy tardado.