# maximal_rectangle

给定一个二维矩阵，其中字符为0/1，计算最大矩形面积，其中字符全为1.

思路：动态规划。三个vector，分别表示矩形的宽（height），即行，矩形的左边（left）和右边（right），即列号。面积为（height*（right-left））。
     进行每一行的循环。遇到1，则高度++，遇到零则高度置零。表示，当一个列中遇到连续的1高度才会一直++，只要有一个零便回归为0.
     同时，遇到1，则left为max（cur_left，left[j]），遇到零，则cur_left为列号+1，left[j]为0.
     则right为min（cur_right，right[j]），遇到零，则cur_right为列号，left[j]为n.
     
     表示
     1.遇到零，重新计算左边和右边.遇1不需要改变左右边界。
     2.遇到1，不改变cur_left和cur_right，此时left和right遇到同一个1，cur之差为2，所以使得cur_left的值为列号+1.
     3.遇到1，max（上一个左边，与当前列号）是为了取最右的左边；同样min（上一个右边，与当前的列号），是为了取最左的右边。
     
