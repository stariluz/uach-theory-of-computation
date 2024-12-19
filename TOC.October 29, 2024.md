# Gramáticas sensibles al contexto

$G=(N,T,P,S)$

$N=\text{ Conjunto de no terminales}$

$T=\text{ Conjunto de terminales}$

$S \in N=\text{ Símbolo/Producción inicial}$

$P=\text{ Conjunto de producciones}$

$\alpha \to beta$

$\alpha y \beta \in (N \cup \Sigma)^+$

$|\alpha|\leq|\Beta$

| Tipo                          | Ejemplo                                 |
| ----------------------------- | --------------------------------------- |
| Tipo 3. Regulares             | $a^mb^nc^o \| m\ge 0, n\geq 0, o \ge 0$ |
| Tipo 2. Libres de contexto    | $a^mb^nc^o \| m\ge 0, n\geq 0, o = 2m$  |
| Tipo 1. Sensibles al contexto | $a^mb^nc^o \| m\ge 0, n = 2m, o = m$    |
| Tipo 0. Sensibles al contexto | $a^mb^nc^o \| m\ge 0, n = 2m, o = m$    |

Ejercicio 1
---

$A=\{w: a^nb^nc^n, n>=0 \}$

$S\to abc | aSBc

$cB \to Bc$

$bB\to bb$


# Maquina de turing

$MT=(Q,\Sigma, \Gamma, q_0, \delta, b, F)$

$Q=\text{Conjunto de estados}$

$\Sigma=\text{Alfabeto de entrada}$

$\Gamma=\text{Alfabeto de símbolos de la cinta}, \Sigma \subseteq \Gamma$

$q_0=\text{Estado inicial}$

$F \subseteq Q \text{Estados finales}$

$\delta=\text{Función de trancisión}$

$\delta:Q\times\Gamma\to Q\times\Gamma\times\{L,R\}$

$Q\times(\Sigma\cup\{\epsilon\}) \to P(Q)$

$b=\text{Caractér en blanco}$

