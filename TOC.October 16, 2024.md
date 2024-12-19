$\Sigma = \{a,b,c\}$

$A =\{w: b^n a* c^n a*, n \geq 0 \}$

$S \to A$

$A \to A_1A_2$

$A_2 \to bA_2c|A_3$

$A_3 \to aA_3|\epsilon$


$B=\begin{Bmatrix}
w: \begin{matrix}
\text{si inicia en a es par} \\
\text{si inicia en b es impar} \\
\text{si inicia en c es palindrome par} \\
\end{matrix}
\end{Bmatrix}$

$C=\{w: \text{si inicia en c es palindrome par}\}$