# 学习情况
1、本周我学习了关于迭代器的概念，迭代器是一种模式，它可以使得对于序列类型的数据结构的遍历行为与被遍历的对象分离，即我们无需关心该序列的底层结
构是什么样子的。只要拿到这个对象,使用迭代器就可以遍历这个对象的内部.
2、还学习了Collection集合，集合类是用来存放某类对象的。集合类有一个共同特点，就是它们只容纳对象（实际上是对象名，即指向地址的指针）。这一点和数组不同，数组可以容纳对象和简单数据。如果在集合类中既想使用简单数据类型，又想利用集合类的灵活性，就可以把简单数据类型数据变成该数据类型类的对象，然后放入集合中处理，但这样执行效率会降低。
集合类容纳的对象都是Object类的实例，一旦把一个对象置入集合类中，它的类信息将丢失，也就是说，集合类中容纳的都是指向Object类对象的指针。这样的设计是为了使集合类具有通用性，因为Object类是所有类的祖先，所以可以在这些集合中存放任何类而不受限制。当然这也带来了不便，这令使用集合成员之前必须对它重新造型。Java中的集合类可以分为两大类：一类是实现Collection接口；另一类是实现Map接口。
3、(1)学会了String和int的相互转换
int num=100;
String s=String.valueOf(num);

String s="100";
int x=Integer.parseInt(s);

(2)学会了String和StringBulider的相互转换

StringBulider sb = new StringBulider(str);
String str = sb.toString();
