# equalize
Utility to make all lines of a file of equal length. Each line is stripped or expanded with blanks to fit the same length. 

```command
# using wcc: https://github.com/dandyvica/wcc
$ equalize /etc/passwd 100 | wcc
100 100 42 

$ equalize /etc/passwd 100 | wc -L
100
```
