# Half-SimpleCompiler

## 1. Introduction

This is a homework project for a course named *Compilers: Principles, Techniques, and Tools*. In this project, my classmate([@caopeixinnku](https://github.com/caopeixinnku)) and I implemented a simple c compiler, which can construct an **Abstract Syntax Tree(AST)** and output this tree structure. However, due to time limit, we did not implement the left part to generate an excutable file(That's why we add the "Half-" prefix). This is left as a future work.

(Note: This compiler **only** supports simple syntax and *Integer* variable type.)



## 2. Structure

We design some classes to help us construct the AST:

- **ASTNode:** The base class of all AST node. Define many general interfaces we can use.
  - **CompoundNode:** Node that represents compound structure(contents inside *{}*). This class can help to deal with the problem of *scope*.
  - **ConstNode:** Node that represents const values.
  - **IdDeclarationNode:** Node that represents a declaration statement.
  - **OperatorNode:** Node that represents operators(e.g. '+', '-', '*', '/', '=' etc.). This kind of node can be used to represent expression of calculation or assignment.
  - **RepeatNode: **Node that represents *while* or *for* loop.
  - **TypeSpcfNode: **Node that represents a type specification.
- **Symbol: **A class to represent identifiers used in the source code. The *name* and *type* attributes stand for the name and type of an identifier respectively, and the *offset* and *index* attributes represent the offset and index in the symbol table.
- **SymbolTable: **A class that stores all the **Symbol** objects. This data structure is used to solve the problem of *redefinition*.

The pipeline of this work will be like this:

1. *lex* is used to parse the source code and get the tokens.
2. *yacc* is used to do shift/reduce actions according to Production defined in `grammar.y`
3. During the grammar analysis, we construct the AST and print it out.

(Note: The construction of an AST is in a **bottom-up** way, not in a recursive way.)



## 3. Run

1. Download the sorce code:

   ```bash
   git clone https://github.com/BHbean/Half-SimpleCompiler.git
   ```

2. Assign *excute* permission to `run.sh`:

   ```bash
   cd Half-SimpleComiler
   chmod 777 run.sh
   ```

3. run with your source code(text file):

   ```bash
   ./run.sh yourcode.c [yourcode2.txt ...]
   ```

   
