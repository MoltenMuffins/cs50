
[Source](https://cs50.harvard.edu/x/2020/psets/1/mario/more/ "Permalink to Mario - CS50x")

# Mario - CS50x

> If you already started to work on Problem Set 1 in CS50 Lab, you may [continue working on it][1] there. If you're just now starting to work in this problem, be sure to use CS50 IDE instead by following the instructions below!

## World 1-1

Toward the beginning of World 1-1 in Nintendo's Super Mario Brothers, Mario must hop over adjacent pyramids of blocks, per the below.

![screenshot of Mario jumping over adjacent pyramids](https://cs50.harvard.edu/x/2020/psets/1/mario/more/pyramids.png)

Let's recreate those pyramids in C, albeit in text, using hashes (`#`) for bricks, a la the below. Each hash is a bit taller than it is wide, so the pyramids themselves are also be taller than they are wide.
    
    
       #  #
      ##  ##
     ###  ###
    ####  ####
    

The program we'll write will be called `mario`. And let's allow the user to decide just how tall the pyramids should be by first prompting them for a positive integer between, say, 1 and 8, inclusive.

Here's how the program might work if the user inputs `8` when prompted:
    
    
    $ ./mario
    Height: 8
           #  #
          ##  ##
         ###  ###
        ####  ####
       #####  #####
      ######  ######
     #######  #######
    ########  ########
    
    

Here's how the program might work if the user inputs `4` when prompted:
    
    
    $ ./mario
    Height: 4
       #  #
      ##  ##
     ###  ###
    ####  ####
    

Here's how the program might work if the user inputs `2` when prompted:
    
    
    $ ./mario
    Height: 2
     #  #
    ##  ##
    

And here's how the program might work if the user inputs `1` when prompted:

If the user doesn't, in fact, input a positive integer between 1 and 8, inclusive, when prompted, the program should re-prompt the user until they cooperate:
    
    
    $ ./mario
    Height: -1
    Height: 0
    Height: 42
    Height: 50
    Height: 4
       #  #
      ##  ##
     ###  ###
    ####  ####
    

Notice that width of the "gap" between adjacent pyramids is equal to the width of two hashes, irrespective of the pyramids' heights.

Create a new directory called `mario` inside of your `pset1` directory by executing

Create a new file called `mario.c` inside your `mario` directory. Modify `mario.c` in such a way that it implements this program as described!

### Walkthrough
[![Link to walkthrough video](https://img.youtube.com/vi/FzN9RAjYG_Q/0.jpg)](https://youtu.be/FzN9RAjYG_Q)

### How to Test Your Code

Does your code work as prescribed when you input

* `-1` (or other negative numbers)?
* `0`?
* `1` through `8`?
* `9` or other positive numbers?
* letters or words?
* no input at all, when you only hit Enter?

You can also execute the below to evaluate the correctness of your code using `check50`. But be sure to compile and test it yourself as well!
    
    
    check50 cs50/problems/2020/x/mario/more
    

Execute the below to evaluate the style of your code using `style50`.

## How to Submit

Execute the below, logging in with your GitHub username and password when prompted. For security, you'll see asterisks (`*`) instead of the actual characters in your password.
    
    
    submit50 cs50/problems/2020/x/mario/more
    

[1]: https://lab.cs50.io/cs50/labs/2020/x/mario/more/
