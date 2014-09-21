#include "structdef.h"

extern Stack1 newStack1(); 
/* Creates an empty stack and initialize it. */

extern Boolean push1(Stack1 st, Elem1 data);
/* Pushes data in the stack st and returns TRUE. It returns FALSE if push fails (This case is not handled in the code) . */

extern void pop1(Stack1 st);
/* Pops the topmost element in data. It returns TRUE on sucessful pop and returns FALSE otherwise.*/

extern Elem1 top1(Stack1 st);
/* Returns the topmost element in data. It returns TRUE on sucessful top and returns FALSE otherwise.*/

extern int size1(Stack1 st); 
/* Returns the number of elements in the stack. Returns -1 otherwise.  */

extern void display1(Stack1 st); 
/* Displays the contents of the stack */

extern Boolean isEmpty1(Stack1 st);
/* Returns TRUE if empty else returns FALSE */
