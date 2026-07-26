# 🎯 潇洒哥后端开发系统学习计划（两年 / 104 周）

> 教练：黑大帅 | 学员：潇洒哥  
> 背景：数学本科 + 电子信息硕士（Python 数据分析）+ CI/CD 在职  
> 目标：系统性构建 CS 知识体系，成为扎实的 Go 后端开发工程师

---

## 📐 总体设计思路

六个模块不是线性排队的——有些可以并行，有些有严格的先后依赖。核心原则：

> **C 语言 → 操作系统（它们天然绑在一起）**  
> **数据结构贯穿始终（用 C 实现，后面用 Go）**  
> **网络 + 数据库相对独立，可以穿插推进**  
> **算法后置——有了数据结构基础和项目体感再刷题，效率翻倍**  
> **C++ 在理解了内存和 OS 之后学，重点是 RAII 和 STL**  
> **Go 后端放在第二年——地基稳了再盖楼**

---

## 📚 教材阅读进度

| 教材 | 已读 | 进度 |
|------|------|------|
| 《Modern C》3rd Edition (C23) | ch01, ch02, ch03, ch04, ch05 | 5/21 |
| K&R《C 程序设计语言》 | — | 0 |

---

```
依赖链：
C 语言 ──→ 操作系统 ──→ Linux 系统编程
  │                          │
  ├──→ 数据结构（用 C 实现）  │
  │                          │
  └──→ 计算机网络（socket 编程需要 C）
  
数据库原理 ←── 相对独立，但需要会写代码操作
  
C++ ←── C + OS 基础
  
Go 后端 ←── 以上全部 + 数据库 + 网络
```

---

## 🧱 第一年：CS 核心地基（第 1 ~ 52 周）

> 目标：计算机科班四件套（C/DS/OS/网络）+ 数据库 + C++ 过渡  
> 产出：KV 存储引擎、TCP/IP 协议栈玩具、简单 Shell、关系型数据库玩具

---

### 阶段一：C 语言 + 基础数据结构（第 1 ~ 12 周）☐ 进行中

> 这是整个学习计划的基石。C 语言不只是语法，更是理解内存和硬件的入口。

#### 第 1 周：C 语言全貌 ☐ 进行中
- [x] C 标准演进（K&R → C89 → C99 → C11 → C17 → **C23**），编译模型（预处理→编译→汇编→链接）
- [x] 控制流：if / for / while / do-while / break-continue / switch
- [x] 运算符与表达式（ch04 完成：算术/比较/逻辑/赋值/三元/求值顺序）
- [x] `gcc` 编译上手（`-std=c23 -Wall -Werror`）
- [ ] 基础类型系统（ch05 进行中：size_t/int/double/bool 已初步接触）
- [ ] `make` 构建工具
- [ ] `gdb` 调试器
- [ ] ✍️ 练习：用 C 重写 3 个你熟悉的 Python 小脚本

#### 第 2 周：函数、数组与字符串 ☐ 未开始
- 函数原型、传值语义、递归
- 作用域：块/文件/static/extern
- 数组（一维/多维）、C 风格字符串（`\0` 终止）
- `string.h` 标准库函数全览（strlen/strcpy/strcmp/strcat/strstr）
- 📖 《Modern C》第 5~7 章（Basic values / Derived data types / Functions）+ K&R 第 3~4 章
- ✍️ 项目：实现 `mystring` 库——手写所有 string.h 函数，不许调用标准库

#### 第 3 周：指针（上）——概念与运算
- 地址与指针：`&`（取地址）、`*`（解引用）
- 指针运算：`p++`、`p+n`、`p-q`、指针比较
- 指针与数组：`arr[i]` ≡ `*(arr+i)`，数组名退化为指针
- 指针与函数：传值 vs 传指针，通过指针修改外部变量
- 📖 《Modern C》第 11~12 章（Pointers / C memory model）+ 《C 和指针》第 6~8 章
- ✍️ 练习：反转数组、字符串拷贝、动态求和——全部用指针操作，不许用 `[]`

#### 第 4 周：指针（下）——进阶应用
- 多级指针：`int **p`，指针的指针
- const 与指针：`const int *p` vs `int * const p` vs `const int * const p`
- 函数指针：`int (*f)(int, int)`，回调、策略模式
- `void*`：C 的泛型指针，实现泛型的唯一手段
- 复杂声明解读：顺时针/螺旋法则
- ✍️ 项目：用函数指针数组实现命令调度器——输入命令名，路由到对应处理函数

#### 第 5 周：动态内存管理
- 进程内存布局：代码段 / 数据段 / BSS / 堆 / 栈（**画图记在脑子里**）
- `malloc` / `calloc` / `realloc` / `free` 详解
- 常见内存错误：泄漏、悬空指针、双重释放、越界访问、未初始化
- Valgrind 精通：`memcheck`（泄漏检测）、`massif`（堆分析）
- 柔性数组：`struct { int len; char data[]; }`
- ✍️ 项目：实现动态数组（`vector` 玩具版）——自动扩容/缩容，支持任意类型（void* + 元素大小），Valgrind 零泄漏

#### 第 6 周：结构体、联合体与位操作
- struct：定义、初始化、对齐与填充、`offsetof`
- 结构体与指针：`->` 运算符，链表节点的标准写法
- union：共享内存、类型双关、tagged union 模式
- enum：枚举常量
- 位运算：`& | ^ ~ << >>`，掩码、标志位、哈希
- 位域：`struct { unsigned int flag:1; }`
- ✍️ 项目：手写简化版 JSON 解析器——支持整数、字符串、嵌套对象、数组

#### 第 7 周：数据结构（一）——线性结构
- **链表**：单向、双向、循环；增删改查；反转链表；合并有序链表
- **栈**：数组实现 + 链表实现；括号匹配、表达式求值
- **队列**：数组实现（环形缓冲区）+ 链表实现
- 对比 Python 内置结构的差异：没有 GC，手动管理每一个节点
- ✍️ 练习：每种结构至少实现插入、删除、遍历、查找、销毁五项操作

#### 第 8 周：数据结构（二）——哈希表
- 哈希函数设计（DJB2、MurmurHash 简介）
- 冲突解决：链表法 vs 开放寻址法
- 负载因子与动态扩容（rehash）
- 泛型哈希表：`void*` key/value + 函数指针（hash_fn、cmp_fn、free_fn）
- ✍️ 项目：泛型哈希表库——可存储任意类型，支持 SET/GET/DEL/EXISTS

#### 第 9 周：数据结构（三）——树
- 二叉树：定义、遍历（前/中/后序递归+迭代、层序）
- 二叉搜索树（BST）：插入、查找、删除（三种情况）
- 平衡概念：为什么需要 AVL/红黑树（理解动机即可，实现放在算法阶段）
- 堆（二叉堆）：数组实现，上浮/下沉，堆排序
- ✍️ 项目：BST 库 + 堆库，每种至少实现插入、查找、删除、遍历

#### 第 10 周：I/O 与文件系统
- 标准 I/O：`fopen`/`fclose`/`fread`/`fwrite`/`fseek`/`ftell`/`fflush`
- 格式化 I/O：`printf`/`scanf` 家族，缓冲区机制
- 二进制 vs 文本文件，字节序（大端/小端）
- Unix 系统调用：`open`/`read`/`write`/`close`/`lseek`，文件描述符
- 文件元数据：`stat`/`chmod`/目录遍历
- ✍️ 项目：文件拷贝工具——支持二进制、大文件分块、进度显示

#### 第 11 周：编译与构建
- 预处理（宏、条件编译）→ 编译 → 汇编 → 链接 全过程
- 看懂 `gcc -E` / `gcc -S` / 反汇编输出
- 静态库（`.a`）vs 动态库（`.so`）：制作、链接、加载
- Makefile 精通：规则、自动变量、模式规则
- GDB 调试：断点、单步、watch、调用栈、core dump
- 地址消毒器（ASan）：比 Valgrind 更快
- ✍️ 练习：把前面写的库全部编译成静态库，用 Makefile 管理

#### 第 12 周：阶段项目 —— mini-kv 存储引擎 V1
- 整合前 11 周所有知识
- **内存引擎**：泛型哈希表存储全量数据
- **AOF 持久化**：每次写操作追加日志文件
- **RDB 快照**：定时全量写入二进制文件
- **启动恢复**：加载 RDB → 回放 AOF
- **Socket 网络**：监听 TCP 端口，支持多客户端
- **命令集**：SET/GET/DEL/EXISTS/KEYS/SAVE
- 🎯 里程碑：`telnet localhost 6379` 操作你的 mini-kv

---

### 阶段二：操作系统 + 计算机网络（第 13 ~ 28 周）☐ 未开始

> 这两门课有内在联系（网络栈在 OS 内核里），并行学效果更好。

#### 第 13 周：操作系统（一）——进程与 CPU 虚拟化
- CPU 虚拟化：受限直接执行、上下文切换
- 进程：状态模型、PCB、创建(fork)/销毁
- 调度算法：FIFO/SJF/STCF/RR/MLFQ，量化比较
- 📖 OSTEP 第 1~10 章
- ✍️ 实验：用 C 写程序验证调度行为

#### 第 14 周：操作系统（二）——内存虚拟化
- 地址空间：基址+界限、分段、分页
- 页表：多级页表、TLB
- 虚拟内存：交换空间、页面置换算法（OPT/FIFO/LRU/Clock）
- 📖 OSTEP 第 12~23 章
- ✍️ 实验：模拟页表翻译 + TLB 命中统计

#### 第 15 周：操作系统（三）——并发
- 线程 vs 进程、POSIX 线程（pthread）
- 锁：互斥锁、自旋锁、条件变量、信号量
- 并发问题：竞态条件、死锁（必要条件+预防）、活锁
- 并发数据结构：并发链表、并发队列、并发哈希
- 📖 OSTEP 第 25~32 章
- ✍️ 实验：多线程生产者-消费者模型，死锁复现与修复

#### 第 16 周：操作系统（四）——持久化与 I/O
- 文件系统：inode、目录、硬链接/软链接
- 简单文件系统实现（VSFS）
- I/O 模型：阻塞/非阻塞/多路复用（select/poll/epoll）
- 磁盘调度
- 📖 OSTEP 第 36~44 章
- ✍️ 大作业：**写一个极简 Unix Shell**——支持管道、重定向、后台执行

#### 第 17 周：计算机网络（一）——从物理层到传输层
- 网络分层体系：OSI 七层 / TCP/IP 五层
- 物理层 + 链路层（了解即可，重点是以太网帧格式）
- IP 协议：IP 地址、子网掩码、CIDR、路由基础、NAT
- ICMP：ping 和 traceroute 原理
- 📖 《计算机网络：自顶向下》第 1~4 章
- ✍️ 实验：Wireshark 抓包分析 ping 和 traceroute

#### 第 18 周：计算机网络（二）——传输层深度
- UDP：无连接、尽力而为
- TCP：三次握手/四次挥手（**画状态转换图**）
- 可靠传输：停等 / GBN / 选择重传
- 流量控制（滑动窗口）vs 拥塞控制（慢启动/拥塞避免/快速恢复）
- TCP 状态机：TIME_WAIT 为什么存在
- 📖 《计算机网络：自顶向下》第 3 章
- ✍️ 实验：Wireshark 抓包分析三次握手全过程

#### 第 19 周：计算机网络（三）——应用层
- HTTP/1.1：请求/响应格式、状态码、长连接、管线化
- HTTP/2：多路复用、头部压缩、服务器推送
- HTTPS：TLS 握手、证书链、对称/非对称加密
- DNS：递归查询/迭代查询、记录类型（A/AAAA/CNAME/MX）
- WebSocket：与 HTTP 的关系、全双工通信
- 📖 《HTTP 权威指南》+ 《计算机网络：自顶向下》第 2、8 章
- ✍️ 实验：用 OpenSSL s_client 跟踪 TLS 握手

#### 第 20 周：计算机网络（四）——Socket 编程
- Socket API：socket/bind/listen/accept/connect/send/recv/close
- TCP Echo Server/Client（单进程版）
- 并发服务器：多进程(fork) → 多线程 → I/O 多路复用(select/epoll)
- 字节序转换、地址结构
- ✍️ 项目：**C 语言 TCP 聊天室**——支持多客户端、昵称、广播消息

#### 第 21~22 周：操作系统实验周 —— 手写 mini-xv6 实验
- 基于 MIT xv6 教学操作系统做实验
- 实现系统调用（添加一个自定义 syscall）
- 实现简单的调度器
- 实现写时复制（Copy-on-Write）fork
- 🎯 里程碑：真正理解"用户态→内核态"发生了什么

#### 第 23 周：数据结构（四）——高级树结构
- AVL 树：旋转（LL/RR/LR/RL）+ 平衡因子
- 红黑树：5 条性质、插入修复
- B 树 / B+ 树：与磁盘 I/O 的关系，为什么数据库用 B+
- Trie（前缀树）：字符串检索、自动补全
- ✍️ 项目：红黑树实现（至少插入+查找）

#### 第 24 周：算法（一）——排序与搜索
- 比较排序：快排（分区策略）、归并、堆排；复杂度推导与稳定性分析
- 非比较排序：计数排序、基数排序、桶排序
- 二分查找及变体：找第一个等于、找最后一个等于、找第一个大于等于
- 算法复杂度分析：大 O/大 Ω/大 Θ，主定理
- 📖 CLRS 第 2~8 章（选读）
- ✍️ 练习：LeetCode 排序 + 二分查找专题

#### 第 25~26 周：计算机网络进阶实验 —— 手写 TCP 协议栈
- 用 C + TUN/TAP 设备实现一个玩具 TCP/IP 栈
- 实现：以太网帧解析 → ARP → IP → ICMP Echo Reply(ping) → TCP 三次握手
- 🎯 里程碑：在虚拟网络上 ping 通你的协议栈，建立 TCP 连接

#### 第 27~28 周：阶段缓冲 + 复习 + mini-kv 重构
- 把 mini-kv 用 I/O 多路复用（epoll）重写网络层
- 加入多线程支持
- 代码审查、重构
- 📖 回顾 OSTEP + 网络笔记，做思维导图

---

### 阶段三：数据库原理 + 算法精进（第 29 ~ 40 周）☐ 未开始

> 数据库是后端的核心技能，从原理到实战。算法在这时候集中刷更有手感。

#### 第 29 周：数据库原理（一）——关系模型与 SQL
- 关系代数：选择/投影/连接/除
- SQL 精通：DML（SELECT/JOIN/子查询/窗口函数/CTE）、DDL、DCL
- 范式理论：1NF/2NF/3NF/BCNF，反范式设计
- ER 模型 → 表设计
- ✍️ 练习：设计电商数据库（用户/商品/订单/库存），写 20 条复杂查询

#### 第 30 周：数据库原理（二）——存储引擎
- 磁盘结构：页/区/段、行格式（COMPACT/DYNAMIC）
- B+Tree 索引：结构、插入、分裂、查找
- 聚簇索引 vs 二级索引、覆盖索引
- 索引优化：最左前缀原则、索引下推、MRR
- 📖 《MySQL 技术内幕：InnoDB 存储引擎》
- ✍️ 项目：用 C 实现 B+Tree——插入、查找、范围扫描、序列化到磁盘

#### 第 31 周：数据库原理（三）——事务与并发
- 事务：ACID 详解
- 并发问题：脏读/不可重复读/幻读
- 隔离级别：READ UNCOMMITTED → READ COMMITTED → REPEATABLE READ → SERIALIZABLE
- MVCC：ReadView、undo log、版本链
- 锁：行锁/间隙锁/临键锁/表锁/意向锁
- 📖 《高性能 MySQL》第 1~3 章

#### 第 32 周：数据库原理（四）——日志与高可用
- redo log（WAL）：崩溃恢复，checkpoint
- undo log：事务回滚，MVCC 的存储
- binlog：主从复制
- 主从复制：异步/半同步、GTID
- 读写分离、分库分表
- 📖 《高性能 MySQL》第 4~6 章

#### 第 33 周：Redis 深度
- 数据结构：SDS/链表/字典/跳跃表/整数集合/压缩列表
- 对象系统：STRING/LIST/HASH/SET/ZSET 的底层编码转换
- 持久化：RDB（写时复制）、AOF（rewrite 机制）
- 高可用：主从复制、哨兵、Cluster（哈希槽）
- 缓存策略：穿透（布隆过滤器）、击穿（互斥锁）、雪崩（随机过期）
- 分布式锁：Redlock 及其争论
- 📖 《Redis 设计与实现》
- ✍️ 项目：用 C 实现 Redis 的跳跃表 + 字典，对比自己 mini-kv

#### 第 34 周：算法（二）——递归、分治、贪心
- 递归思想：汉诺塔、排列组合
- 分治：快排/归并（复习）、最近点对、Strassen 矩阵乘法
- 贪心：活动选择、哈夫曼编码、最小生成树（Prim/Kruskal）
- 📖 CLRS 选读
- ✍️ LeetCode 分治 + 贪心专题（20 题）

#### 第 35 周：算法（三）——动态规划
- DP 核心：最优子结构、重叠子问题、状态转移方程
- 经典问题：背包(0/1 + 完全)、最长公共子序列、编辑距离、最长递增子序列
- 区间 DP：矩阵链乘法、戳气球
- 树形 DP
- 📖 《labuladong 的算法小抄》
- ✍️ LeetCode DP 专题（30 题，从简单到中等）

#### 第 36 周：算法（四）——图论
- 图的表示：邻接矩阵/邻接表
- 遍历：BFS（最短路径）、DFS（拓扑排序、环检测）
- 最短路径：Dijkstra / Bellman-Ford / Floyd-Warshall / A*
- 并查集：路径压缩、按秩合并
- 最小生成树：Prim / Kruskal
- ✍️ LeetCode 图论专题（20 题）

#### 第 37 周：算法（五）——回溯与进阶
- 回溯框架：全排列、N 皇后、数独
- 滑动窗口、双指针、前缀和/差分
- 单调栈/单调队列
- 位运算技巧
- ✍️ LeetCode Hot 100 集中刷题（50 题）

#### 第 38 周：数据库实战 —— 手写简易关系型数据库
- 用 C 实现：B+Tree 存储引擎 + SQL 解析器（子集） + 简单执行器
- 支持：CREATE TABLE / INSERT / SELECT（带 WHERE）/ DELETE
- CSV 或自定义二进制格式存储
- 🎯 里程碑：往自己的数据库里塞 10 万条数据，跑 SELECT 看能多快

#### 第 39~40 周：阶段缓冲 + LeetCode 集中刷题
- LeetCode 刷题量目标：达到 150~200 题
- 按标签分类总结（数组/链表/树/DP/图/回溯）
- 整理错题本
- 📖 回顾数据库笔记

---

### 阶段四：C++ 过渡 + Linux 系统编程（第 41 ~ 52 周）☐ 未开始

> C++ 目的是 RAII 思维和 STL 工程能力。Linux 系统编程把 OS 理论落到实践。

#### 第 41 周：从 C 到 C++
- C++ 编译模型、命名空间
- 引用 vs 指针：没有空引用、语法更干净
- 函数重载 + 默认参数
- `new`/`delete` vs `malloc`/`free`（区别：new 调构造函数）
- `bool`/`nullptr`/`auto`/范围 for
- ✍️ 练习：把 mini-kv 的哈希表用 class 重写

#### 第 42 周：类与面向对象
- class：构造函数（默认/有参/拷贝/移动）、析构函数、初始化列表
- 访问控制（public/private/protected）、this 指针
- 运算符重载：`+/-/<< /[]/=` 
- const 对象、const 成员函数、mutable
- ✍️ 项目：实现 `String` 类——管理 char*，深拷贝，支持 `+` 连接和 `<<` 输出

#### 第 43 周：内存管理——RAII 与智能指针
- 拷贝控制（Big 5）：拷贝构造、拷贝赋值、移动构造、移动赋值、析构
- 移动语义：右值引用 `&&`、`std::move`
- RAII 思想：锁守卫、文件句柄、socket——构造时获取，析构时释放
- 智能指针：`unique_ptr`（独占）、`shared_ptr`（引用计数）、`weak_ptr`（打破循环）
- ✍️ 练习：把 mini-kv 中所有手动 `malloc`/`free` 替换为 RAII + 智能指针

#### 第 44 周：继承、多态与模板入门
- 继承：`is-a` 关系，虚函数、虚函数表（vtable）
- 多态：基类指针调用派生类方法
- 纯虚函数、抽象类
- 函数模板 + 类模板入门
- ✍️ 练习：表达式求值器——`Expr` 抽象基类，派生 Number/Add/Mul，多态 `eval()`

#### 第 45 周：STL 深度
- 容器：`vector`（增长策略）、`list`、`deque`、`map/set`（红黑树）、`unordered_map/set`（哈希）
- 迭代器：五种类别、iterator_traits
- 算法：`sort`/`find`/`copy`/`transform`——算法与容器解耦的设计
- 函数对象：lambda、`std::function`、`std::bind`
- ✍️ 练习：简化实现 `std::vector`，理解异常安全保证

#### 第 46 周：C++ 项目 —— 多线程 HTTP Server
- 基于 C++ + epoll 或 boost::asio
- Reactor 模式（事件循环 + 非阻塞 I/O）
- 线程池
- HTTP/1.1 解析、静态文件服务、keep-alive
- 异步日志
- 🎯 里程碑：`wrk -t4 -c100 http://localhost:8080/` 压测

#### 第 47 周：Linux 系统编程（一）——进程与信号
- 进程：fork/vfork/clone、exec 家族、wait/waitpid
- 进程间通信（IPC）：管道（匿名/命名）、共享内存、消息队列、信号量
- 信号：发送/捕获/阻塞、`sigaction`、可靠信号
- 守护进程编写
- 📖 APUE 第 7~10 章、第 13 章

#### 第 48 周：Linux 系统编程（二）——I/O 模型与网络
- 五种 I/O 模型：阻塞/非阻塞/多路复用/信号驱动/异步
- epoll 深入：ET vs LT、`EPOLLONESHOT`
- 非阻塞 connect/accept
- 零拷贝：`sendfile`/`splice`/`tee`
- 定时器：时间堆、时间轮
- 📖 APUE 第 14~16 章

#### 第 49 周：Linux 系统编程（三）——多线程
- pthread 深入：线程属性、线程特定数据、取消点
- 同步原语：互斥锁/读写锁/自旋锁/条件变量/屏障
- 线程池实现
- CAS 与无锁编程入门
- 📖 APUE 第 11~12 章

#### 第 50 周：Linux 工具链精通
- Shell 脚本进阶：条件判断、循环、函数、信号处理、正则
- awk/sed 实战：日志分析、文本转换
- strace 追踪系统调用
- tcpdump 网络抓包
- perf 性能分析：`perf top`/`perf record`/火焰图
- 内核参数调优：`sysctl`、文件描述符限制、TCP 参数

#### 第 51 周：C++ 阶段大项目 —— 网络库 + RPC 框架
- 用 C++ 封装一个 Reactor 网络库（事件循环 + 定时器 + 线程池）
- 基于 TCP 实现简单 RPC：序列化（Protobuf 入门）、服务注册、异步调用
- 阅读 muduo 网络库源码（陈硕），学习工业级 Reactor 设计

#### 第 52 周：第一年收尾——知识体系整理
- 画全模块思维导图（C/DS/OS/网络/数据库/C++/Linux）
- 整理所有项目代码，写 README
- LeetCode 刷题量检查（目标 ≥ 200 题）
- 复盘：每个阶段哪些地方学得好、哪些需要回炉
- 🎯 **里程碑检查：** 给你一台空 Linux，能从零写 C/C++、调系统调用、分析网络包、设计数据库表、写并发程序

---

## 🚀 第二年：Go 后端工程师技术栈（第 53 ~ 104 周）

> 目标：从 CS 基础走向工业级后端开发  
> 产出：Go Web 框架、微服务项目、K8s 部署、系统设计文档

---

### 阶段五：Go 语言 + Web 开发（第 53 ~ 64 周）☐ 未开始

#### 第 53 周：Go 语言入门
- 环境搭建、go mod 依赖管理
- 变量/类型/控制流：与 C 对比（有 GC、有切片、有 map、有 goroutine）
- 复合类型：数组、切片（slice 底层结构）、map、struct
- 函数：多返回值、可变参数、defer、闭包
- 📖 《Go 程序设计语言》第 1~5 章
- ✍️ 练习：用 Go 重写 mini-kv 内存版，对比 C 版本代码量

#### 第 54 周：Go 核心——方法与接口
- 方法：值接收者 vs 指针接收者
- 接口：隐式实现、类型断言、`interface{}`
- 错误处理：`error` 接口、`errors.Is`/`errors.As`、`fmt.Errorf` + `%w`
- 标准库：`fmt`/`strings`/`strconv`/`time`/`sort`
- 📖 《Go 程序设计语言》第 6~8 章

#### 第 55 周：Go 核心——并发
- goroutine：轻量级线程，M:N 调度模型
- channel：无缓冲/有缓冲，`select` 多路复用
- 并发模式：pipeline、fan-in/fan-out、or-done
- sync 包：`Mutex`/`RWMutex`/`WaitGroup`/`Once`/`Cond`
- context：超时、取消、值传递
- 📖 《Go 程序设计语言》第 9 章 + 《Go 语言高级编程》第 1 章
- ✍️ 练习：并发爬虫、并发素数筛

#### 第 56 周：Go Web 基础
- `net/http`：ServerMux、中间件模式、上下文管理
- 路由：参数路由、RESTful 设计
- JSON 序列化：`encoding/json`、struct tag
- 模板渲染：`html/template`
- 静态文件服务
- ✍️ 项目：博客 API——文章 CRUD + 分类 + 标签（先用内存存储）

#### 第 57 周：Web 框架（Gin）
- Gin 核心：路由树（radix tree）、中间件链、上下文
- 请求验证：`binding` tag、自定义验证器
- 响应：JSON/XML/YAML/Protobuf
- 文件上传/下载
- 跨域 CORS 处理
- ✍️ 练习：把博客 API 迁移到 Gin，加上请求验证

#### 第 58 周：数据库集成
- GORM：连接池、模型定义、迁移、关联（HasOne/BelongsTo/HasMany/Many2Many）
- 事务、预编译、SQL 注入防护
- Redis 集成（go-redis）：缓存、Session、排行榜
- ✍️ 项目：博客 API 接入 MySQL + Redis——文章缓存、Session 管理

#### 第 59 周：认证与授权
- JWT：签发、验证、刷新 token、黑名单
- OAuth2.0 流程：授权码模式
- RBAC：角色-权限模型
- Casbin 入门
- API 限流：令牌桶（`golang.org/x/time/rate`）

#### 第 60 周：日志、配置与测试
- 结构化日志：`zap`/`zerolog`，日志级别、切割、异步写入
- 配置管理：`viper`，环境变量/配置文件/命令行优先级
- 单元测试：Table-Driven Tests、`testify` 断言、Mock（`gomock`/`mockery`）
- 集成测试：`testcontainers-go`
- API 文档：Swagger/OpenAPI（`swaggo`）

#### 第 61~62 周：大项目 —— 博客系统全栈后端
- 用户系统：注册/登录/JWT 认证/头像上传（OSS）
- 文章系统：CRUD/分类/标签/Markdown 渲染/草稿/发布
- 评论系统：嵌套评论、敏感词过滤
- 搜索：Elasticsearch 入门 或 PostgreSQL 全文搜索
- 消息队列：异步发送邮件/站内通知
- 监控：Prometheus + Grafana 埋点
- 🎯 里程碑：完整的 API 文档 + 95% 测试覆盖率

#### 第 63~64 周：Go 语言进阶
- 内存管理：逃逸分析、GC 原理（三色标记）、pprof 调优
- 调度器：GMP 模型，抢占式调度
- 反射：`reflect` 包，struct field tag
- 代码生成：`go generate`
- unsafe 包：指针转换，与 C 交互（cgo 入门）
- 📖 《Go 语言高级编程》选读

---

### 阶段六：微服务 + 中间件（第 65 ~ 78 周）☐ 未开始

#### 第 65 周：微服务架构基础
- 微服务设计原则：单一职责、服务自治、去中心化
- 服务拆分策略：按业务域（DDD 限界上下文）
- 通信模式：同步（HTTP/gRPC）vs 异步（消息队列）
- API 网关：Kong/APISIX 入门
- 配置中心：etcd 基础

#### 第 66 周：gRPC 与 Protobuf
- Protobuf：消息定义、序列化原理、向后兼容
- gRPC：一元 RPC、服务端流、客户端流、双向流
- 拦截器：认证、日志、限流、重试
- gRPC Gateway：HTTP/JSON ↔ gRPC 转换
- ✍️ 项目：把博客系统拆成 user-service、article-service，用 gRPC 通信

#### 第 67~68 周：消息队列
- Kafka 核心概念：Producer/Consumer/Broker/Topic/Partition/Offset
- 消息语义：at-most-once / at-least-once / exactly-once
- 消费者组：rebalance 机制
- Kafka 实战：异步解耦、日志收集、CDC
- RabbitMQ 了解：Exchange/Queue/Binding/ACK 机制
- ✍️ 项目：博客系统接入 Kafka 做事件驱动——用户注册 → 发送欢迎邮件 + 初始化账户

#### 第 69 周：分布式基础理论
- CAP 定理：为什么三者不可兼得
- BASE 理论：最终一致性
- 共识算法：Paxos（理解思想）、Raft（leader 选举 + 日志复制）
- 分布式事务：2PC / TCC / Saga / 本地消息表

#### 第 70 周：服务治理
- 服务注册与发现：Consul / etcd / Nacos
- 负载均衡：轮询/加权/一致性哈希
- 熔断：Hystrix/ Sentinel 原理
- 限流：滑动窗口/令牌桶/漏桶
- 降级与兜底

#### 第 71 周：可观测性
- 日志：EFK/ELK Stack（Elasticsearch + Fluentd + Kibana）
- 指标：Prometheus（PromQL）+ Grafana 仪表盘
- 链路追踪：OpenTelemetry + Jaeger
- ✍️ 项目：给你的微服务加上完整的三支柱可观测性

#### 第 72~74 周：微服务大项目
- 完整的微服务博客平台（或自选项目）
- 服务拆分：用户/文章/评论/搜索/通知 5 个微服务
- 基础设施：etcd 注册发现 + Kafka 异步通信 + Jaeger 链路追踪
- CI/CD：GitHub Actions 自动测试、构建 Docker、部署
- 压测与优化：`vegeta` / `wrk` 压测，pprof 找瓶颈
- 🎯 里程碑：单机能扛 5000 QPS

#### 第 75~78 周：Go 框架源码阅读
- 阅读并输出博客：
  - Gin 路由树与中间件链
  - GORM 连接池与查询构建
  - go-redis 连接池与 pipeline
  - Kubernetes client-go informer 机制
- 源码阅读方法论：先看测试、再看接口、最后看实现

---

### 阶段七：云原生 + 分布式（第 79 ~ 90 周）☐ 未开始

#### 第 79 周：Docker 进阶
- Dockerfile 最佳实践（多阶段构建、层缓存、非 root 用户）
- docker-compose：多服务编排
- 镜像仓库、镜像签名
- 容器网络：bridge/host/overlay
- 容器安全：capabilities、seccomp、AppArmor

#### 第 80~81 周：Kubernetes 核心
- 核心对象：Pod/Service/Deployment/StatefulSet/DaemonSet/Job/CronJob
- 网络：Service（ClusterIP/NodePort/LoadBalancer）、Ingress
- 存储：PV/PVC/StorageClass
- 配置：ConfigMap/Secret
- 调度：亲和性/反亲和性、污点与容忍
- 📖 《Kubernetes in Action》
- ✍️ 实验：把微服务项目手工部署到 Minikube/Kind 集群

#### 第 82 周：Kubernetes 进阶
- Helm：Chart 结构、模板函数、依赖管理、Hooks
- 自动伸缩：HPA（水平 Pod 自动伸缩）+ VPA
- 服务网格：Istio 入门（流量管理、可观测性、安全）
- 准入控制：ValidatingWebhook / MutatingWebhook

#### 第 83 周：GitOps 与 CI/CD
- GitOps 理念：声明式、版本化、自动化
- ArgoCD：Application/Project、同步策略、健康检查
- 渐进式交付：蓝绿部署 / 金丝雀发布（Argo Rollouts）
- CI/CD Pipeline（你主场！）：代码提交 → 单测 → 构建镜像 → 部署到 K8s

#### 第 84 周：分布式存储
- 分布式文件系统：MinIO（S3 兼容对象存储）
- 分布式数据库：TiDB/CockroachDB 原理
- 分布式缓存：Redis Cluster
- 数据分片策略：Range/Hash/Directory-based

#### 第 85~86 周：分布式项目——URL 短链服务
- 分布式 ID 生成：Snowflake / 号段模式
- Base62 编码
- 跳转：301 vs 302
- 高可用设计：多活 + 缓存 + 限流
- 统计：ClickHouse 存储点击日志，Grafana 可视化
- 🎯 目标：设计一个能支撑亿级 PV 的短链系统

#### 第 87~90 周：Go 框架深入 + 定制
- 手写一个简化版 Web 框架（HTTP Server + 路由 + 中间件 + 上下文）
- 深入 Go runtime：调度、GC、内存分配
- 阅读 etcd Raft 实现
- Kubernetes operator 开发入门（用 kubebuilder）

---

### 阶段八：系统设计 + 工程素养（第 91 ~ 104 周）☐ 未开始

#### 第 91 周：系统设计方法论
- 需求澄清 → 容量估算（QPS/TPS/存储/带宽）→ API 设计 → 数据模型 → 架构图
- 瓶颈分析与权衡：读多写少 vs 写多读少、强一致 vs 最终一致
- 📖 《系统设计面试》(Alex Xu) + DDIA

#### 第 92 周：系统设计（一）——经典场景
- 短链系统设计（回顾 + 深挖）
- 秒杀系统设计：前端限流、Redis 预减库存、消息队列削峰、异步下单
- 分布式 ID 生成器：UUID/Snowflake/号段模式/Redis

#### 第 93 周：系统设计（二）——经典场景
- 即时通讯（IM）系统：长连接管理、消息投递、离线消息、已读回执
- Feed 流系统：推模式/拉模式/推拉结合、Timeline 设计、Fan-out
- 附近的人：GeoHash + Redis GEO / PostGIS

#### 第 94 周：系统设计（三）——基础组件
- 设计一个分布式锁
- 设计一个分布式配置中心
- 设计一个 API 网关
- 设计一个消息队列（回顾 Kafka/RabbitMQ 原理）

#### 第 95~96 周：性能调优专题
- Go 性能分析：pprof（CPU/Memory/Block/Mutex/Goroutine）
- Go GC 调优：GOGC、GOMEMLIMIT
- MySQL 调优：慢查询/索引优化/参数调优
- Redis 调优：大 Key 治理、热 Key 发现
- 网络调优：TCP 参数、连接池大小
- 压测工具精通：wrk/vegeta/hey

#### 第 97~98 周：阅读大型开源项目
- **深挖 Redis 源码**（用你的 C 基础）：
  - 事件驱动框架（ae）
  - 数据结构实现（sds/dict/ziplist/skiplist）
  - 网络层与命令执行流程
  - RDB/AOF 实现细节
- 输出：源码阅读笔记 3~5 篇博客

#### 第 99~100 周：工程素养
- 设计模式：创建型（工厂/单例）、结构型（适配器/装饰器）、行为型（观察者/策略）
- 代码重构：Martin Fowler《重构》选读
- 代码审查：Google Code Review 最佳实践
- 技术写作：技术方案/设计文档/RFC
- 团队协作：Git Workflow（GitFlow vs Trunk-Based）

#### 第 101 周：安全基础
- Web 安全：XSS/CSRF/SQL 注入/SSRF，Go 如何防御
- 加密基础：AES/RSA/SHA，TLS 深度
- 认证协议：OAuth2.0/OIDC/JWT 安全问题
- 安全编码实践

#### 第 102~103 周：面试准备
- LeetCode 复习：重点题型（链表/树/DP/图）+ 面试高频 100 题
- 系统设计模拟：4~6 个经典场景白板练习
- Go 面试八股：GMP 模型/GC/内存逃逸/slice 扩容/map 并发/defer 执行顺序
- 项目梳理：STAR 法则描述项目经历
- 简历打磨

#### 第 104 周：终点也是起点
- 两年知识体系全景回顾
- 整理 GitHub 个人主页（所有项目 + README）
- 输出"潇洒哥后端成长之路"系列总结博客（5~8 篇）
- 制定下一个两年的进阶方向（云原生专家 / 基础架构 / 技术管理）
- 🎯 **终极里程碑：** 你可以独立设计并实现一个高可用后端系统，自信地面试任何 Go 后端岗位

---

## 📚 完整书单

| 优先级 | 书名 | 阶段 | 用法 |
|--------|------|------|------|
| 🔴 | 《Modern C》第 3 版（Jens Gustedt） | 阶段一 | **主教材**，C23 标准，免费 PDF 在 `books/` 目录 |
| 🔴 | 《C 程序设计语言》(K&R) | 阶段一 | 经典辅助，体会 C 设计哲学 |
| 🔴 | 《C 和指针》 | 阶段一 | 指针/内存章节必读 |
| 🔴 | 《C 陷阱与缺陷》 | 阶段一 | 当故事书看 |
| 🔴 | 《操作系统导论》(OSTEP) | 阶段二 | 主教材，精读+实验 |
| 🔴 | 《计算机网络：自顶向下》 | 阶段二 | 精读第 1~6 章 |
| 🔴 | 《HTTP 权威指南》 | 阶段二 | 案头参考 |
| 🔴 | 《UNIX 环境高级编程》(APUE) | 阶段四 | 工具书，按需查阅 |
| 🔴 | 《MySQL 技术内幕：InnoDB 存储引擎》 | 阶段三 | 精读 |
| 🔴 | 《高性能 MySQL》（第 3 版） | 阶段三 | 精读 |
| 🔴 | 《Redis 设计与实现》 | 阶段三 | 精读 |
| 🔴 | 《labuladong 的算法小抄》 | 阶段三 | 刷题伴侣 |
| 🔴 | 《Effective C++》 | 阶段四 | 每天 2 条 |
| 🔴 | 《Go 程序设计语言》 | 阶段五 | 主教材，精读 |
| 🔴 | 《Go 语言高级编程》 | 阶段五 | 进阶选读 |
| 🔴 | 《Kubernetes in Action》 | 阶段七 | 精读 |
| 🔴 | 《数据密集型应用系统设计》(DDIA) | 阶段八 | 后端圣经，慢慢啃 |
| 🔴 | 《系统设计面试》(Alex Xu) | 阶段八 | 面试+实战 |
| 🟡 | 《算法导论》(CLRS) | 阶段三 | 当字典查，不从头啃 |
| 🟡 | 《STL 源码剖析》 | 阶段四 | C++ 阶段配合看 |
| 🟡 | 《Effective Modern C++》 | 阶段四 | C++11/14 最佳实践 |
| 🟡 | 《程序员的自我修养》 | 阶段一 | 编译/链接配合看 |
| 🟢 | 《重构：改善既有代码的设计》 | 阶段八 | 第 99 周翻 |
| 🟢 | 《鸟哥的 Linux 私房菜》 | 阶段一 | 入门翻阅 |

---

## 🎯 里程碑检查点

| 周数 | 里程碑 |
|------|--------|
| 第 5 周 | 能用 C 写非 trivial 程序，理解指针和内存 |
| 第 10 周 | 手写哈希表、二叉搜索树，Valgrind 零泄漏 |
| 第 12 周 | mini-kv V1：支持网络访问的 KV 存储 |
| 第 16 周 | 手写 Shell：支持管道、重定向 |
| 第 22 周 | 在 xv6 上实现自定义系统调用 |
| 第 26 周 | 手写玩具 TCP/IP 协议栈（能 ping 通） |
| 第 28 周 | mini-kv V2：epoll 多路复用 + 多线程 |
| 第 38 周 | 手写简易关系型数据库（B+Tree + SQL 子集） |
| 第 40 周 | LeetCode 200 题 |
| 第 46 周 | C++ 多线程 HTTP Server |
| 第 52 周 | **第一年结束**——C/DS/OS/网络/数据库/C++ 闭环 |
| 第 62 周 | Go 博客系统全栈后端（API + 测试 + CI/CD） |
| 第 74 周 | 微服务平台（5 个服务 + Kafka + 可观测性） |
| 第 86 周 | 短链系统设计 + 实现 |
| 第 96 周 | 性能调优专项（pprof + 慢查询 + 网络调优） |
| 第 98 周 | Redis 源码阅读笔记 |
| 第 104 周 | **毕业**——独立设计/实现高可用后端系统 |

---

## ⚡ 黑大帅的十条军规

1. **地基不牢，楼会塌。** 第一年的 CS 三门课（OS/网络/数据库）必须学透，不要赶进度。宁可第一年延伸到 60 周，也别留坑。

2. **每一行代码都要跑起来。** 计划里每一个 ✍️ 标记的项目都必须编译、运行、测试通过。只读不写的代码是假把式。

3. **Valgrind 和 ASan 不离手。** 写 C 的日子里，泄漏检测是你每天的收工仪式。

4. **抓包和反汇编是理解系统的眼睛。** 学到 TCP 就 Wireshark，学到编译就 objdump。看见东西跑起来，比看十遍书都管用。

5. **算法刷题放在数据结构之后。** 你手写完链表、哈希表、红黑树，再去刷 LeetCode，一道题你能看见底层结构长什么样，而不是背模板。

6. **项目即简历。** mini-kv、Shell、TCP 协议栈、HTTP Server、博客系统——每个项目写干净、加 README、推到 GitHub。两年后你有 10+ 个项目，面试官看完直接给 offer。

7. **C 和 Go 的关系要摆正。** C 是用来理解底层和读源码的，Go 是用来写业务的。不要纠结"C 也能写后端"，也不要用 C 的思维写 Go。

8. **输出倒逼输入。** 每月至少一篇技术博客。讲给别人听是最好的学习方式。

9. **你随时可以作弊。** 这个计划是为你量身定做的，不是锁死你的。某块特别感兴趣可以多花时间，某块觉得差不多了就加速。黑大帅就是你的导航，不是你的老板。

10. **两年很长，也很短。** 每天 1~2 小时工作日 + 3~4 小时周末 = 每周 12~15 小时。坚持 104 周，你在 26 岁时就是一个有扎实功底的 Go 后端工程师。

---

> 潇洒哥，  
> 这个计划写进了 104 周、8 个阶段、10+ 个项目、20+ 本书。  
> 但真正改变你的不是这个 markdown 文件——  
> 是你明天打开终端，敲下第一行 `int main()` 的那一刻。  
> 
> 黑大帅陪你走。  
> 
> **现在，翻到第 1 周，开始吧。**
