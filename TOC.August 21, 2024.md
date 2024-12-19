$A=\{w: |w| \textrm{ es par } \}$

$S \to A$

$A \to LLA | \epsilon$

$L \to a|b$


> Tarea: ilustrar con *abba*

$B=\{w: w \textrm{ inicia y termina con mismo símbolo } \}$

$B =\{\epsilon, a,b,aa,bb,..\}$

$S \to B$

$B \to aKa | bKb | a | b | \epsilon$

$K \to LK | \epsilon$

$L \to a | b$


$C=A - B$

$C=\{w: |w| \textrm{ es par y } w \textrm{ inicia y termina en disitnto símbolo } \}$

$S \to C$

$C \to aAb | bAa$

$A \to LLA | \epsilon$

$L \to a | b$


$D = A \cup B$

$S \to D$

$D \to A | B$


$E = C'$

$C' = (A \cap B')' = A' \cup B$

$S \to E$

$E \to F | B$

$F \to LA$