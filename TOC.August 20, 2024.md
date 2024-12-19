
### Ejercicio 1

$A=\{w \textrm{  con subcadena bb}\}$

$S \to ABA$

$A \to CA\epsilon$

$B \to bb$

$C \to a|b$

$B=\{w \textrm{ que inician o terminan en b}\}$

$B_1=\{w \textrm{ que inician en b}\}$

$B_2=\{w \textrm{ que terminan en b}\}$

$S_1 \to bB$

$B \to CB|\epsilon$

$C \to a|b$

$S_2 \to Bb$

$S \to bB|Bb$

$C=A \cup B$

$C=\{w \textrm{ tiene subcadena bb o inician en b o termina en b}\}$

$S \to ABA | bA | Ab$

$A \to CA|\epsilon$

$B \to bb$

$C \to a|b$

> Tarea ilustrar con *abbb*

$D=A \cap B$

$D=\{w \textrm{ tiene la subcadena bb y inicia en b o termina en b}\}$

$(A \cap B_1) \cup (A \cap B_2)$

$S_1 \to bABA | BA$

$A \to CA | \epsilon$

$B \to bb$

$C \to a | b$

> Tarea ilustrar con *bababb*

$S_2 \to ABAb | AB$

$S \to bABA | BA | ABAb | AB$

$A \to CA | \epsilon$

$B \to bb$

$C \to a | b$


El parser es el analizdor sintáctico, el lexer es el analizador léxico.


---
### Ejercicio Correo Electrónico

$\Sigma = \{  a, ..., z, \_, @, .\}$

$\textrm{ Dominio} D \to NC$

$\textrm{ Nombre} N \to LN'$

$N' \to LN' | \_N' | \epsilon$

$\textrm{ Extensión} C \to .LLL$

> Tarea: Ilustrar con a_.net

$S \to NAD$

$A \to @$

$N \to LN'$

$N' \to LN' | \_N' | \epsilon$

$C \to .LLL$

$L \to a |\ ...\ | z$

$D \to NC$

> Tarea: ilustrar con a@b.com