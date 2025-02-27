# FT_Printf
# ft\_printf

## Description

`ft_printf` est une ré-implémentation de la fonction standard `printf` en C. Cette version personnalisée permet d'afficher du texte formaté en gérant plusieurs types de conversions et de modificateurs.

## Fonctionnalités

- Gère les conversions suivantes :
  - `%c` : Caractère
  - `%s` : Chaîne de caractères
  - `%d` / `%i` : Entiers signés (base 10)
  - `%u` : Entiers non signés (base 10)
  - `%p` : Pointeur (affichage en héxadécimal avec `0x`)
  - `%x` : Entiers non signés en héxadécimal (minuscules)
  - `%X` : Entiers non signés en héxadécimal (majuscules)

## Compilation

Pour compiler la librairie `libftprintf.a`, utilise la commande suivante :

```sh
make
```

## Utilisation

Inclure `ft_printf.h` et compiler avec `libftprintf.a` :

```c
#include "ft_printf.h"

int main() {
    ft_printf("Hello %s!\n", "world");
    return 0;
}
```

Puis compiler avec :

```sh
cc -Wall -Wextra -Werror main.c libftprintf.a -o test
./test
```

## Commandes Makefile

- `make` : Compile la librairie
- `make clean` : Supprime les fichiers objets
- `make fclean` : Supprime les fichiers objets et la librairie
- `make re` : Recompile entièrement le projet

Projet réalisé dans le cadre de l'école 42.

