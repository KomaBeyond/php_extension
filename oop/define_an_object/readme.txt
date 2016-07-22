1，zend_class_entry 是内核中定义的一个结构体，是内核实现PHP语言中类与对象的一个非常基础、关键的结构类型。他就相当于我们定义的类的原型。
2，INIT_CLASS_ENTRY 宏用来分配一个类空间以及进行初始化操作。
3，zend_register_internal_class 函数用来PHP内核空间注册一个类对象。
4，可以如代码一样使用 ZEND_ME 宏和 ZEND_METHOD 宏来进行累方法的声明定义。
同样可以使用 PHP_ME 和 PHP_METHOD，这两者之间的区别是，前者要传递类名称，而后者要传递类引用指针（使用zend_class_entry声明的）
推荐使用后者，而在代码中我使用了前者
5，最后注意不论使用 PHP_METHOD 还是使用 ZEND_METHOD 都需要在头文件中进行声明，类似于MINIT这类的方法一样，都需要先在头文件中声明

6，php调用实例
```php
$fanta = new Fanta();
$fanta->run();
```
