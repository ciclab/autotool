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
* s1: string without quota
* s2: string with quota
* int: positive integer
* ...: zero or multiple replications of previous kind of statement
* switch:

```
   (switch s1
     (s1 s2)
     ...
   )
```

* sequence of statements at same level doesn't matter
* {a/b}: a or b
* []: can be empty
* a full description should be:

```
(
	//type definition  
	(type  
		//type name
		(s1
			//width of this type
			(width int)
			//this type is signed or not
			(flag {signed/unsigned} )
		)  
		...  
	)  
	//stage definition
	(stage  
		//this info not used yet
		(s1 {true/false})  
		...  
	)  
	//enum definition
	(enum  
		//name value value ... (value can be a pair or just a single value)
		(s1 { (s2 s2 s2)/(s2 s2) / s2 } ...)  
		...  
	)  
	//simple variable definition
	//variable name
	(s1  
		(value int)  
	)
	...
	//memory definition
	(memory
		//name
		(s1
			(size {s1/int})
			(type s1)
			(index s1)
			[(read s1 ...)]
			[(write s1 ...)]
    	)
    	...
  	)
	//wire definition
	(wire
		(s1
			(width {s1/int})
		)
		...
	)
	//pipeline definition
	(pipeline
		//pipeline name
		(s1
			(width {s1/int})
		)
		...
	)
	//register definition
	(register
		//register name
		(s1
			(size {s1/int})
			(type s1)
			(index s1)
		)
		...
	)
	//function unit definition
	(function_unit
		//function unit name
		(s1)
		...
	)
	//instruction
	(instruction
		//name of top rule
		(top s1)
		//rule name
		(s1
			//variable definition
			(= s1 s1 ...)//make sure every definition show in code and binary exactly once
			...
			//code definition
			(code [{s1/s2} ...])
			//binary definition
			(binary [{s1/s2/swtich} ...])
			//do definition
			(do )
		)
		...
	)
)
```
