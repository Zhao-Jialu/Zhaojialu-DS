# 第十章学习内容
这周我学习了贪心算法、分治算法、动态规划、随机化算法和回溯算法。
## 贪心算法
贪婪算法分阶段的工作，可以认为所作决定是好的，而不考虑将来的后果。一般来说，这意味着选择的是局部最优。如果是这样的话，南无算法就是正确的；否则，算法得到的是一个次最优解。如果不要求最佳答案，那么有时用简单的贪婪算法省城金丝答案，而不是使用一般来说产生准确答案所需要的算法。
## 分治算法
分治算法由两部分组成：分：递归解决较小的问题（当然，基本情况除外）治：然后，从子问题的解构建原问题的解。传统上，在正文中至少有两个递归调用的例程叫做分治算法，而正文中只含一个递归调用的例程不是分治算法。我们一般坚持子问题是不相交的。
## 动态规划
任何数学递归公式都可以直接翻译成递归算法，但是基本现实是编译器常常不能正确对待递归算法，结果导致低效的算法。当我们怀疑很可能是这种情况时，我们必须再给编译器提供一些帮助，将递归算法重新写成非递归算法，让后者把哪些子问题的答案系统的记录在一个表内。利用这种方法的一种技巧叫做动态规划。
## 随机化算法
在算法期间，随机数至少有一次用于决策。该算法的运行时间不只依赖于特定的输入，而且依赖于所发生的随机数。一个随机算法的最坏情形运行时间几乎总是和非随机算法的最坏情形运行时间相同。重要的区别在于，好的随机化算法没有不好的输入，而只有坏的随机数（相对于特定的输入）。
## 回溯算法
回溯算法也叫试探法，它是一种系统地搜索问题的解的方法。回溯算法的基本思想是：从一条路往前走，能进则进，不能进则退回来，换一条路再试。用回溯算法解决问题的一般步骤为： 1、定义一个解空间，它包含问题的解。 2、利用适于搜索的方法组织解空间。 3、利用深度优先法搜索解空间。 4、利用限界函数避免移动到不可能产生解的子空间。 问题的解空间通常是在搜索问题的解的过程中动态产生的，这是回溯算法的一个重要特性。
## 下周计划
学习第十一和第十二章并对前面的知识进行复习。
