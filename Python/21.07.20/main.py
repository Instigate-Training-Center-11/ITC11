import magic_sort

array1 = [['aaa1', "zah", 'bdd'],
          ['a1', 'zah', 'add'],
          ['z9', 'z', 'bdd'],
          ['xh1', 'abc', 'bdd'],
          ['xh1', 'abc', 'bdd'],
          ['r1', 'aa', 'bb'],
          ['a0', '00', '77'],
          ['ww1', '08', '00']]

array2 = [['k1', '54', '78'],
          ['k2', 'kaa', 'bdd'],
          ['ka2', 'abc', 'bdd'],
          ['k2', 'abc', 'dbe']]

print("First example:", end = "\n\n")
magic_sort.my_sort(array1)

print("Second example:", end = "\n\n")
magic_sort.my_sort(array2)