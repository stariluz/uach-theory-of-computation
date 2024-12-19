```sh
# ^ inicia con
# $ termina con
# () agrupación
# | alternación +o
```
```sh
grep -E "^a" # Inicia en a
grep -E "^ab$" # Inicia en a y termina con b
grep -E "^a(a|b)b$" # Inicia en a, contiene a o b y termina en b
grep -E "^a(a|b)*b$" # Inicia en a, contiene cerradura de kleene y termina en b
grep -E "^a(a|b)+b$" # Inicia en a, contiene cerradura positiva y termina en b
grep -E "^ac?(a|b)+b$" # Contiene puede o no contener una letra c
grep -E "^a((a|b)(a|b))*b$" # Es par, inicia en Inicia en a y termina en b

./kleene 5 ab | grep -E "^a((a|b)(a|b))*b$"
```