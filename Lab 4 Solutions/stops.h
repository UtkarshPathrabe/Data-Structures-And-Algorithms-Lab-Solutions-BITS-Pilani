#include "sttypes.h"

extern Stack newStack(); 
/* Creates an empty stack and initialize it. */

extern Boolean push(Stack st, Elem data);
/* Pushes data in the stack st and returns TRUE. It returns FALSE if push fails (This case is not handled in the code) . */

extern void pop(Stack st);
/* Pops the topmost element in data. It returns TRUE on sucessful pop and returns FALSE otherwise.*/

extern Elem top(Stack st);
/* Returns the topmost element in data. It returns TRUE on sucessful top and returns FALSE otherwise.*/

extern int size(Stack st); 
/* Returns the number of elements in the stack. Returns -1 otherwise.  */

extern void display(Stack st);
/* Displays the contents of the stack */

extern Boolean isEmpty(Stack st);
/* Returns TRUE if empty else returns FALSE */
