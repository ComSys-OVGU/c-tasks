# Working with structs
## Motivation
As your programs become more complex you may need structures that hold more than one variable. So let us introduce structs.

## Task
Before you can use a struct you need to define it. Now what does that mean? Let's look at an example:
<br>

```c
struct food {
    char name[10];
    int calories;
    int price;
};
```

We now defined a struct type `food` that we can use similarly to a variable. It can save three values: An array of characters and two integers. We can manipulate it pretty much the same way as any other variable but have a handy container for values that belong together. <br>
To access values inside a struct you need the name of the struct followed by a `.` followed by the name of that variable.

```c
struct food cherry; //defining a struct of the type food named cherry
strcpy(cherry.name, "Cherry"); //accessing the variable name inside the struct using .
cherry.calories = 50;
cherry.price = 69;
};
```

<br>


Look at the example in structs.c.
<br> <br>
Define two more food instances of your choice and fill them with values.
Define a new type of struct `meal` that contains three `food` structs and and an array of characters to give a name to the meal. Create an instance of that struct and fill it with your food instances and look at the values using printf. Try accessing everything from your `meal` struct.
