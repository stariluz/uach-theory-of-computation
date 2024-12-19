```sh
#D
grep -E "(^bb(a|b)*$)|(^(a|b)*bb$)|(^b(a|b)*bb(a|b)*$)|(^(a|b)*bb(a|b)*b$)"
```

```sh
#E
grep -E "(^a*(b(a)+)*b?$)|((^$)|(^a$)|(^a(a|b)*a$))"
```