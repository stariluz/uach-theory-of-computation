# Expresiones regulares

$A= \{ w: |w| \textrm{ es par y } w \textrm{ termina en b}\}$

```sh
grep -E "^(a|b)((a|b)(a|b))*b$"
```

$A'= \{ w: |w| \textrm{ es impar y } w \textrm{ termina en b}\}$

```sh
grep -E "^((a|b)(a|b))*b$"
```

$B= \{ w: |w| \textrm{ es impar y } w \textrm{ termina en b}\}$

```sh
grep -E "(^a(a|b)((a|b)(a|b))*$)|(^b(a|b)*$)|(^$)"
```

## Ejercicios de tarea
$A= \{ w: |w| \textrm{ es multiplo de 3 }\}$

$S \to A$

$A \to LLLA | \epsilon$

$L \to a | b$

```sh
grep -E "^((a|b)(a|b)(a|b))*$"
```

$B = \{ w: w \textrm{ inicia y termina en diferente símbolo }\}$

$S \to B$

$B \to aKb | bKa$

$K \to LK | \epsilon$

$L \to a | b$

```sh
grep -E "(^a(a|b)*b$)|(^b(a|b)*a$)"
```

$C = \{ w: w \textrm{ inicia y termina en diferente símbolo y } |w| \textrm{ es multiplo de 3 }\}$

$S \to C$

$C \to aLAb | bLAa$

$A \to LLLA | \epsilon$

$L \to a | b$

```sh
grep -E "(^a(a|b)((a|b)(a|b)(a|b))*b$)|(^b(a|b)((a|b)(a|b)(a|b))*a$)"
```