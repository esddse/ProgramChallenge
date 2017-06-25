# STL

***

## 容器

#### 分类

* 顺序容器： vector， deque， list
* 关联容器： set， multiset， map， multimap
* 容器适配器： stack， queue， priority_queue

顺序容器和关联容器合称**第一类容器

#### 容器迭代器类别

|容器|迭代器类别|
|:--:|:--------:|
|vector|随机|
|dequeue|随机|
|list|双向|
|set/multiset|双向|
|map/multimap|双向|
|stack|不支持迭代器|
|queue|不支持迭代器|
|priority_queue|不支持迭代器|

#### 所有标准容器共有的成员函数

* 按词典序比较容器的运算符: =, <, <=, >, >=, ==, !=
* empty: 判断容器空
* max_size: 容器中最多能装多少元素
* size: 容器中元素数
* swap: 交换两个相同类型元素的内容

#### 仅第一类容器有的成员函数

* begin: 返回指向容器第一个元素的迭代器
* end: 返回指向同期最后一个元素后面位置的迭代器
* rbegin: 返回指向容器中最后一个元素的迭代器
* rend: 返回指向容器中第一个元素前面位置的迭代器
* erase: 从容器中删除一个或几个元素
	* a.erase(it_first, it_end): 删除[it_first, it_end)中的元素
	* a.erase(it): 删除it所在位置的元素
	* vec.erase(pos): vector可以删除特定位置
	* set.erase(val): set可删除特定值
	* map.erase(key): map可删除特定键
* clear: 删除元素中所有元素

#### 顺序容器共有操作

* front：返回容器第一个元素的引用
* back：返回容器最后一个元素的引用
* push_back：在容器末尾增加新元素
* pop_back: 删除容器末尾元素

#### vector

见上

#### dequeue

比vector多出下面成员函数：
* push_front
* pop_front

#### list

除了上面提到的成员函数外，还支持下面的函数:
* push_front：在前面插入
* pop_front：删除前面的元素 
* sort： 排序（list不支持stl的sort算法）
* remove： 删除和指定值相等的所有元素
* unique： 删除所有和前一个元素相同的元素
* merge： 合并两个链表，并清空被合并的那个
* reverse： 颠倒链表
* splice：在指定位置前面插入另一链表中一个或多个元素，并在另一链表中删除被插入元素
	* lst1.splice(iter1, lst2, iter2, iter3); // 将[iter2, iter3)插入iter1之前 

#### 关联容器共有操作

关联容器内部元素有序排列，新元素插入的位置取决于它的值

* find: 查找
* lower_bound: 查找[begin, end)中的最小的位置pos,使得[begin, pos)中所有的元素都比val小
* upper_bound: 查找[begin, end)中的最小的位置pos,使得[pos， end)中所有的元素都比val大
* equal_range: 返回一个pair，其中pair.first就是lower_bound,pair.second就是upper_bound
* count: 计算等于某个值的元素个数
* insert: 插入元素

#### multiset

#### multimap

multimap中的元素由<Key, Value>组成，每个元素是一个pair对象

默认情况安装Key关键字升序排列

```
mp.insert(make_pair(key, value));
```

## 算法

#### 统计类算法

用于依次处理容器中的每个元素，处理的结果一般是某个标量

```
size_t count(InIt first, InIt last, const T& val);  //统计[first, last)中等于val的元素个数
size_t count_if(InIt first, InIt last, Pred pr); // 计算[first, last)中符合pr(e)==true的元素e的个数
FwdIt min_element(FwdIt first, FwdIt last); //返回[first,last)中最小元素的迭代器，以小于号作为比较器
FwdIt max_element(FwdIt first, FwdIt last); //返回[first,last)中最大元素的迭代器,以小于号作比较器 
T accumulate(InIt first, InIt last, T val); //对[first,last)区间元素执行val = val + *I,返回val
T accumulate(InIt first, InIt last, T val, Pred pr); //对[first, last)区间内元素执行 val = pr(val, *I)，返回val
```

#### 查找类算法

查找容器中是否存在符合条件的元素，返回这些元素在容器中的存储位置（迭代器表示）

```
iter find(iter first, iter end, const T& val); // 查找[first,end)之间值为val的元素，找到返回该迭代器，找不到返回end
bool binary_search(FwdIt first, FwdIt last, const T& val); 
bool binary_search(FwdIt first, FwdIt last, const T& val, Pred pr); 

```