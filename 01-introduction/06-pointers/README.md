# Working with pointers
## Motivation
Gain basic understanding of and some practice with pointers.

## Tasks
What are pointers? <br>
Pointers, as the name suggests, point to a certain memory address. Let's start with an example. First we create a variable.
```c
int age = 21;
```
The value of this variable is currently 21. This value is stored at a memory address that you usually don't get to see. Now let's create a pointer compatible to this variable. Use the same data type with an added `*`.
```c
int * p;
```
Currently this pointer does not have a meaningful value as it is not connected to our variable. It is like an arrow pointing somewhere into the blue. Luckily we can now tie the tip of our arrow to the variable we are interested in using `&`.
```c
p = &age;
```
Now, if you print `p` to the terminal you will get the memory adress where the `21` held in `age` is stored. If you want to access the value stored at the memory adress your pointer leads to you again use `*`. As an example let's change the value of `age` using the pointer.
```c
*p = 30;
```
Take a look at `point.c` to see all this in action.
<br>
<br>

Now take a look at pointers.c and make some changes to it. Use only the pointer to the outside struct to make the changes.
<br>
- Change `dwarf_ptr` by giving it the value of `dwarf[]`. Note that when referencing pointers in structs instead of the usual `.` you will use `->` as shown on line 33 and 34. Also note that when pointing to an array you only need to point at the element `[0]`.
<br>
- Change the value of `best_Character` to what is stored in `favorite[]`.
<br>
- The struct `inside` is part of the struct `outside`. Change the value of the array in the inside struct. Again use the pointer to the outside struct to access it. Try changing the value via:
  - struct inside -> array
  - struct inside -> pointer to array
  - pointer to struct inside -> array
  - pointer to struct inside -> pointer to array
<br>
- Print the changed vallue accessing it via:
  - struct outside -> struct inside -> location
  - struct outside -> struct inside -> pointer to location_
  - pointer to struct outside -> struct inside -> location
  - pointer to struct outside -> struct inside -> pointer to location
  - pointer to struct outside -> pointer to struct inside -> location
  - pointer to struct outside -> pointer to struct inside -> pointer to location.