# monty
this repo is for the monty project about stacks and queues

## Description
This project is about stacks and queues, we have to create a monty interpreter, monty is a scripting language that is first compiled into monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## basic commands
- `push`: pushes an element to the stack.
- `pall`: prints all the values on the stack, starting from the top of the stack.
- `pint`: prints the value at the top of the stack, followed by a new line.
- `pop`: removes the top element of the stack.
- `swap`: swaps the top two elements of the stack.
- `add`: adds the top two elements of the stack.
- `nop`: doesn’t do anything.

## extra commands
- `sub`: subtracts the top element of the stack from the second top element of the stack.
- `div`: divides the second top element of the stack by the top element of the stack.
- `mul`: multiplies the second top element of the stack with the top element of the stack.
- `mod`: computes the rest of the division of the second top element of the stack by the top element of the stack.
- `pchar`: prints the char at the top of the stack, followed by a new line.
- `pstr`: prints the string starting at the top of the stack, followed by a new line.
- `rotl`: rotates the stack to the top.
- `rotr`: rotates the stack to the bottom.
- `stack`: sets the format of the data to a stack (LIFO). This is the default behavior of the program.
- `queue`: sets the format of the data to a queue (FIFO).

---
our flow of the code is :
read file -> get line -> get opcode -> get value -> execute opcode -> get next line -> repeat until end of file
-> close file -> free memory -> exit

---

## Authors
- [Abdullah Faik](https://github.com/Abdullah-Faik)
- [Mohamed ezzat](https://github.com/mohvmedezzvt)

