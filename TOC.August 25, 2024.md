$\Sigma = \{ [a-z], [a-z] \text{, '|', '-', '>', }\epsilon\}$
A) Escribir la gramática para generar una producción de una gramática libre de contexto $N\to aBcD... | ... | \epsilon$ o $A \to \epsilon \text{, por ejemplo.}$

$P \to NFD$

$N \to [A-Z]$

$F \to \textrm{'-' '>'}$

$D \to OD_1$

$D_1 \to \textrm{'|'} D | \epsilon$

$O \to TO_1 | NO_1 | \textrm{'}\epsilon\textrm{'}$

$O \to O | \epsilon$

$T \to [a-z]$

B) Escribir la gramática para generar gramáticas libres de contexto

$G \to PG_1|S$

$G_1 \to \textrm{'\n'}G | \epsilon$

c) Por cada a tiene que haber una b.