CommandParser
=============

Custom network protocol command parser

### Requirements
- Ragel
- Graphviz (if you want to plot the generated diagram).
- C Compiler
- GNU Make

You probably want linux or OSX for this, good luck on windows.

### Testing

#### Build the project
```
$ make all
```
This will also generate a diagram of the assignment parsing FSM as parse_assignment.png

#### Test the assignment parser
```
$ ./text_parse_assignment
fish = "haddock"
Name: fish
Value = (str): haddock


crabs = 12
Name: crabs
Value = (int): 12


```
#### Test the command parser
```
$ ./test_netprot_process_command
SET CHANNEL NAME='CHN 1'
+OK

GET CHANNEL NAME
+CHN 1
```





