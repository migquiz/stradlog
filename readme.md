## Stradlog  
  
A collection of programs about data structures and algorithm, this    
contains the author's own interpretation of what about to be discussed  
in here. 
  
This may contain funny and unrelated codes so look at your own discretion.  
  
Arrays are good for random access which all can say it's a fast data structure,  
but the lack of restriction in duplicated values and sorted arrangement like  
sets or ordered array make itself slow when in terms of searching.  
  
So far, I have learned elementary sort algorithms including bubble sort,  
insertion sort, selection sort. I have worked my skills too in Big O Notation  
which is used to analyze your algorithms in a worst-case situation. Well,  
there might be sometimes when you need to ignore the constants and focus on  
just the average case.  
  
Another data structure I have dwelved into is Hash Tables or maps,hash,  
dictionaries or associative arrays in other language. It allows one to  
have blazing fast lookup for a data. The basic structure is a key-value  
pair which for every use of a key, a consistent value is produced everytime  
through the gate or the hash function. If value lies on the same cell called  
collision, a linear search will be made.

Stacks , not the snacks. You can only read, write and remove at the front,it's  
actually the last. I have translated the program that parses an expression then  
lint it from Ruby to C++. Linting involves many process but the functionality  
it has is the braces parsing and matching. Then, there's this Queue, not the  
barbequeue. There's a bit difference of it from the stack , you can only insert  
at the end and read and remove at the front. More like a movie goer who wants  
to buy a ticket for a movie obviously, then waiting the data to be inquested  
and remove , go see your much awaited movie.  
  
Another topic on recursion for I have reviewed it again. But the example that  
was used is the Quicksort Algorithm. A SortableArray class which involves  
the use of partitioning, from the keyword "part" and a picked pivot, pointer's  
move left and right then swapping values based on the pivot number. The left  
moves to right while it's less than or equal the pivot, while the right pointer  
moves exactly opposite the left pointer do. It would only stop if the pointers  
point to the same value or the left pointer past the right , then we return  
the left pointer for the quicksort. It keeps breaking down the array into halves  
though the worst case would be a full ascending or descending array where the  
pivot ends ups in the not-middle.  
  
In the earlier reviews or codes I have made, linked list always come into the  
field , but here in this book , it introduces the "level-up" version of linked  
list and that is doubly linked list. In this data structure , you don't have a  
single pointer to the next node but also a pointer to previous node.  
  
Binary Trees, in this book, it talks about speeding up all things with it. One  
important rule I have found is a parent node must have two child which one is  
lesser and the other one is greater. In order to understand recursion , one  
must think about the stack, so I tried traversing the tree with the use of stack.  
The tip is , in traversing a binary tree comparison operation namely the greatless  
and recursion were the most important things to remember. As you go deeper in the  
tree, the top most most node in the stack (recursion) will be the deepest node  
in the tree. One more thing in recursion , you focus on what you want to happen  
then considering other things, everything will be fine , hopefully.

Graphs here we go. To be an element of container in C++, the class/type should be  
moveable or copy-able or swappable (lol) , this is the so called element requirements  
if you want to know more then research it.That's why the rule of three, should be mastered.  
In the analysis of an algorithm using the space complexity, one must determine if the  
analysis used is including the input or not because sometimes the additional input  
was only considered.  

