Using loops and branches, I would like you to program a calculator simulator. 

The program should loop until a specific input is provided, that indicates the user wants to quit.  Valid input should be a single digit, one of the mathematical operators: +, -, /, *, a clear command, an equal sign (=), and whatever your quit command is.

Each iteration of the loop the program should handle the input correctly. 

    If the input is a digit, it should multiply whatever value it is holding for the current value by 10 and add the value of the new digit.
    If the input is a mathematical operator, it should move the current value to a separate variable, store what symbol was entered to be the next operator, and clear the current variable to receive the next number.
    If the clear command is entered, it should clear all fields and revert back to a zero state.
    If the equal sign is entered, it should process whatever operator is being stored and display the current value.
    If the quite command is entered it should terminate the program.

For example:

Program starts from a zero state; the current value is zero and no operator is in queue.

User enters a '1'.

Program multiplies current value 0 by 10 resulting in 0, and adds 1, making current value 1.

User enters a '2'.

Program multiplies 1 by 10 resulting in 10, and adds 2, making current value 12.

User enters a '+'.

Program moves 12 to a separate variable, and clears current value to 0, and stores the + as the next operator.

User enters a '3'.

Program multiplies 0 by 10 resulting in 0 and adds 3 making current value 3.

User enters a '/'.

At this point the program will perform the operator in queue and add the 12 with the 3 making the running total 15, queue the '/' as the next operator and clear the current value to 0.

User enters a '5'.

Program multiplies 0 by 10 resulting in 0 and adds 5 making current value 5.

User enters '='.

Program performs the queued operator and divides 15 by 5 and displays the resulting value of 3.
