1. each process should send message to i + 1 process first, then receive the 
   message from i - 1 process, otherwise, all the process will block, waiting for 
   the data sent by others, which cause starving
2. if there is only one process in the program, them the process will try to 
   send something to itself, it will cause deadlock. But I don't know why it is 
   called a deadlock
