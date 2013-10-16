AUTOTOOL
===========================

This is autotool to generate Assembler.

--------------------------

## How to use

### build

```
$cd build
$make as
```

### clean

```
$cd build
$make clean
```

## LICENSE

TODO


## des language rule:
1. s1: string without quota
2. s2: string with quota
3. int: positive integer
4. ...: zero or multiple replications of previous kind of statement
5. switch:
   (switch s1
     (s1 s2)
     ...
   )
6. sequence of statements at same level doesn't matter
7. {a/b}: a or b
8. []: can be empty
7. a full description should be:
(
  (type
    (s1
      (width int)
      (flag {signed/unsigned} )
    )
    ...
  )
  (stage
    (s1 {true/false})
    ...
  )
  (enum
    (s1 { (s2 s2) / s2 } ...)
    ...
  )
  (s1
    [(value int)]
    
  )
  ...
  (memory
    (s1
      (size {s1/int})
      (type s1)
      (index s1)
      [(read s1 ...)]
      [(write s1 ...)]
    )
    ...
  )
  (wire
    (s1
      (width {s1/int})
    )
    ...
  )
  (pipeline
    (s1
      (width {s1/int})
    )
  )
  (register
    (s1
      (size {s1/int})
      (type s1)
      (index s1)
    )
  )
  (function_unit
    (s1)
    ...
  )
  (instruction
    (top s1)
    (s1
      (= s1 s1 ...)//make sure every definition show in code and binary exactly once
      ...
      (code [{s1/s2} ...])
      (binary [{s1/s2/swtich} ...])
      (do 先不管)
    )
    ...
  )
)
