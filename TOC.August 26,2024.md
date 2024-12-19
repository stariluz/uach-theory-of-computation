### Autómata finito no determinista con transiciones vacías $AFN-\epsilon$

$M = (Q,\Sigma, d, q_0, F)$

$Q = \textrm{ Conjunto finito de estados}$

$\Sigma = \textrm{ Conjunto finito de simbolos de entrada}$

$d = \textrm{ Función de trancisión}$

$q_0 \in Q \textrm{ Estado inicial}$

$F \subseteq Q textrm{ Conjunto de simbolos terminales}$


$\Sigma = \{a,b\}$

$A = \{w: |w| \textrm{ es par e inicia en a}\}$

$S \to aLA$

$L \to a | b$

$A \to LLA | \epsilon$


![Automata 1](./img/TOC.August%2026,%202024.img%201.png)

$Q = \{q_0, q_1, q_2\}$

$F = {q_2}$

$\Sigma = \{a,b\}$

$\delta: \begin{matrix}
(q_0,a) \to \{q_1\}\\
(q_1,a) \to \{q_2\}\\
(q_1,b) \to \{q_2\}\\
(q_2,a) \to \{q_1\}\\
(q_2,b) \to \{q_1\}
\end{matrix}$


$\Sigma=\{a,b\}$

$A = \{w: w \textrm{ inicia en a y termina en B}\}$

$S \to aB$

$B \to Kb$

$K \to LK | \epsilon$

$L \to a | b

![Automata 2](./img/TOC.August%2026,%202024.img%202.png)

$Q = \{q_0, q_1, q_2\}$

$\Sigma = \{a,b\}$

$F = {q_2}$

$\delta: \begin{matrix}
(q_0,a) \to \{q_1\}\\
(q_1,a) \to \{q_1\}\\
(q_1,b) \to \{q_1, q_2\}
\end{matrix}$