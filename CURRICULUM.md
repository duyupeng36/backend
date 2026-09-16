# 后端工程师 2.5 年学习路线 — 详细课程大纲

> **导师**: 你在这里遇到的每一个概念，都会在后续项目中被亲手实现。
> **原则**: 不学"知道就好"的东西，只学"能写出来"的东西。

---

## 总览

```shell
Phase 1 ── 计算机基础 (Month 1-12) ──────────────────────────────────
  M1-2   C 语言 + 计算机组成基础          → mini-kv-c
  M3-5   C++ 现代特性 + 数据结构与算法     → mini-kv-cpp + B+Tree
  M6-8   操作系统                         → unix-shell + redis-skiplist
  M9-10  计算机网络                       → 手写 HTTP Server (C)
  M11-12 数据库系统原理                    → blog-system 全栈后端

Phase 2 ── Golang 后端工程师 (Month 13-30) ─────────────────────────
  M13-15 Go 语言精通                      → URL Shortener REST API
  M16-18 Go 后端工程                      → microservice-platform
  M19-21 分布式系统 + 云原生               → 分布式 KV 存储引擎
  M22-24 DevOps + 生产级工程              → 全链路可观测平台
  M25-30 Capstone + 求职冲刺              → 开源项目 + 系统设计
```

---

## Phase 1: 计算机基础（Month 1–12）

### ━━━ Month 1–2: C 语言 + 计算机组成基础 ━━━

**为什么从 C 开始**: C 是所有系统编程语言的母语。理解指针、内存布局和手动内存管理，会让你对后续所有抽象层（OS、数据库引擎、网络协议栈）都有直觉。

**核心知识点**:

| 周 | 主题 | 能力验证 |
| ---- | ------ | ---------- |
| W1-2 | C 语法：控制流、函数、数组、字符串 | 写出计算器、猜数字游戏 |
| W3-4 | 指针与内存：指针运算、多级指针、函数指针、void* | 手写 strlen/strcpy/memcpy，理解栈帧 |
| W5-6 | 结构体、联合体、枚举、位运算 | 实现一个简单的内存分配器 |
| W7 | 动态内存管理：malloc/free/calloc/realloc，内存泄漏检测 | 用 Valgrind 检测并修复泄漏 |
| W8 | 文件 I/O：fopen/fread/fwrite/mmap，二进制 vs 文本 | 实现 CSV 解析器 |
| W9 | 预处理器、编译链接过程（预处理→编译→汇编→链接） | 手动拆解编译过程，理解 .o 文件 |
| W10 | 计算机组成：内存层次结构、缓存、寄存器、字节序 | 解释 sizeof(struct) 的填充规则 |
| W11-12 | 综合实践：构建 mini-kv-c 项目骨架 | hash 表 + 文件持久化基本框架 |

**配套阅读**:

- 📖 *C Primer Plus*（第 6 版）— 配合练习
- 📖 *CS:APP*（深入理解计算机系统）第 1-2 章 — 理解信息表示、程序转换
- 📺 CS50（Harvard）前 5 讲 — 建立编程直觉

**项目: `mini-kv-c`**

在这个项目中你将实现：

- [ ] 基于链式哈希表的 key-value 内存存储
- [ ] 基于追加写（append-only）的文件持久化
- [ ] 简单的 CLI 接口（get/put/delete/dump）
- [ ] 内存池（避免频繁 malloc/free）
- [ ] 基本的并发安全（互斥锁）

**里程碑检查**:

- ✅ 能不查资料写出链表反转、哈希表插入查找
- ✅ 能解释 `int *p = malloc(sizeof(int))` 背后发生了什么（栈、堆、页表）
- ✅ mini-kv-c 能通过所有单元测试，Valgrind 无泄漏

---

### ━━━ Month 3–5: C++ 现代特性 + 数据结构与算法 ━━━

**为什么**: C++17/20 的 RAII、智能指针、模板让你理解"零成本抽象"的设计哲学；同时系统性地实现所有核心数据结构，为算法和后续系统设计打下硬基础。

**核心知识点**:

| 周 | 主题 | 能力验证 |
| ---- | ------ | ---------- |
| W1-2 | C++ 基础：类、构造/析构、运算符重载、引用 vs 指针 | 用 class 重写 mini-kv-c 的接口 |
| W3-4 | RAII、智能指针（unique_ptr/shared_ptr/weak_ptr）、移动语义 | 用 unique_ptr 管理资源，解释所有权转移 |
| W5-6 | 模板：函数模板、类模板、可变参数模板、SFINAE/C++20 Concepts | 写一个类型安全的通用容器 |
| W7-8 | STL 深入：vector/list/deque/map/unordered_map/priority_queue | 手动实现 vector 和 unordered_map |
| W9-10 | 数据结构①：链表、栈、队列、哈希表 | 全部手写实现 + 单元测试 |
| W11-12 | 数据结构②：二叉树、BST、AVL、红黑树、堆、Trie | 全部手写实现 + 复杂度分析 |
| W13-14 | 数据结构③：图（邻接表/矩阵）、并查集、B+树 | 图算法基础设施 |
| W15-16 | 算法①：排序（快排/归并/堆排/计数/基数）、二分查找 | 手写实现 + 复杂度分析 |
| W17-18 | 算法②：BFS/DFS、Dijkstra、拓扑排序 | 图遍历 + 最短路径 |
| W19-20 | 算法③：动态规划（背包、LCS、区间DP）、贪心 | 20+ 经典 DP 题目 |
| W21-24 | 算法④：LeetCode 专项（数组/字符串/树/图/DP 各 15 题） | 共 60+ 题，建立题感 |
| W25-28 | B+Tree 存储引擎设计与实现 | 支持范围查询的磁盘索引 |
| W29-30 | mini-kv-cpp：用 C++ 重写并增强 mini-kv-c | 用 STL + RAII 重构 |
| W31-32 | LeetCode 中等难度专项冲刺 | 每周 10 题，限时训练 |
| W33-36 | 系统级编程实践：内存对齐、虚表、SFINAE 实战 | 能读懂并调试复杂 C++ 代码 |

**配套阅读**:

- 📖 *Effective Modern C++*（Scott Meyers）— C++ 最佳实践
- 📖 *Introduction to Algorithms*（CLRS）— 算法圣经，重点章节反复读
- 📖 *数据结构与算法分析：C++ 描述*（Weiss）— 实现导向
- 🌐 [LeetCode](https://leetcode.cn/) — 刷题平台
- 🌐 [代码随想录](https://programmercarl.com/) — 中文算法学习路径

**项目: `B+Tree 存储引擎`**

- [ ] 实现 B+Tree 的插入、删除、查找、范围扫描
- [ ] 磁盘页管理（页面分配、读写、LRU 缓存）
- [ ] 与 mini-kv-c 的文件持久化对接
- [ ] 并发安全（读写锁）
- [ ] 性能基准测试（对比哈希表 vs B+Tree）

**项目: `mini-kv-cpp`**

- [ ] 用 C++17 重写 mini-kv-c
- [ ] 使用 unique_ptr/shared_ptr 管理内存
- [ ] 用模板实现通用的序列化/反序列化
- [ ] 支持多种后端存储引擎（hash / B+Tree）的可插拔架构
- [ ] 基于 Google Test 的完整测试覆盖

**里程碑检查**:

- ✅ 能手写红黑树的插入和旋转（不需要查资料）
- ✅ 能解释 `std::vector` 的扩容策略和移动语义的性能影响
- ✅ LeetCode 中等题目能在 25 分钟内 AC
- ✅ B+Tree 能正确支持 10 万条记录的插入、查找和范围查询

---

### ━━━ Month 6–8: 操作系统 ━━━

**为什么**: 你写的每一行代码都运行在 OS 之上。理解进程调度、内存管理和文件系统，能让你写出更高效、更健壮的代码，也是理解数据库引擎、网络服务器的必经之路。

**核心知识点**:

| 周 | 主题 | 能力验证 |
| ---- | ------ | ---------- |
| W1-2 | 进程与线程：PCB、上下文切换、fork/exec/waitpid | 用 fork 实现并发服务器 |
| W3-4 | 进程调度：FCFS/SJF/RR/CFS、优先级反转、实时调度 | 能解释 Linux CFS 调度器原理 |
| W5-6 | 内存管理：虚拟地址空间、页表、TLB、页面置换（LRU/FIFO） | 手动模拟页表映射 |
| W7-8 | 内存管理：malloc 实现、内存映射（mmap）、写时复制（COW） | 用 mmap 实现共享内存 IPC |
| W9-10 | 进程间通信：管道、信号、共享内存、消息队列、Socket | 实现简易消息队列 |
| W11-12 | 同步原语：mutex、semaphore、condition variable、barrier | 用信号量实现生产者-消费者 |
| W13-14 | 死锁：条件、检测、避免（银行家算法）、预防 | 编写死锁检测工具 |
| W15-16 | 文件系统：VFS、inode、目录结构、硬链接/软链接 | 实现简单的文件系统 FUSE 挂载 |
| W17-18 | I/O 模型：阻塞/非阻塞、select/poll/epoll、事件驱动 | 实现 epoll-based 事件循环 |
| W19-20 | Unix Shell 实现（核心功能） | 进程管理 + 信号 + 管道 |
| W21-22 | Redis 跳跃表实现 | 并发安全的有序结构 |
| W23-24 | Linux 内核源码阅读（调度器/内存管理选读） | 能读懂并解释关键数据结构 |

**配套阅读**:

- 📖 *Operating Systems: Three Easy Pieces*（OSTEP）— 免费在线，强烈推荐
- 📖 *CS:APP* 第 2、3、6、9 章 — 与 OSTEP 互补
- 📖 *Linux 内核设计与实现*（Robert Love）— Linux 内核入门
- 📺 MIT 6.S081（2020）— 操作系统实验课（xv6）

**项目: `unix-shell`**

- [ ] 命令解析与执行（fork + execvp）
- [ ] 管道（pipe）实现：`ls | grep .c | wc -l`
- [ ] I/O 重定向：`>`, `<`, `>>`
- [ ] 信号处理：Ctrl+C (SIGINT), Ctrl+Z (SIGTSTP)
- [ ] 后台进程管理：jobs, fg, bg
- [ ] 环境变量和 PATH 查找
- [ ] 简单的 shell 脚本支持（变量、条件）

**项目: `redis-skiplist`**

- [ ] 实现跳跃表的插入、删除、查找、范围查询
- [ ] 支持泛型 key-value（模板或 void*）
- [ ] 线程安全（读写锁）
- [ ] 可选：实现简单的 dict（哈希表 + 渐进式 rehash）
- [ ] 与 mini-kv-cpp 对接作为存储后端

**里程碑检查**:

- ✅ 能画出 `fork()` 后父子进程的内存布局（理解 COW）
- ✅ 能解释 epoll 的 ET/LT 模式区别及适用场景
- ✅ unix-shell 能正确处理管道、信号和后台作业
- ✅ 能用 strace 跟踪程序的系统调用并解释每一步

---

### ━━━ Month 9–10: 计算机网络 ━━━

**为什么**: 后端工程师的核心工作就是处理网络请求。从物理层到应用层的每一层理解，都会让你在排查问题、设计协议、优化性能时游刃有余。

**核心知识点**:

| 周 | 主题 | 能力验证 |
| ---- | ------ | ---------- |
| W1-4 | 网络分层模型、IP/ARP/ICMP、子网划分、DNS | 画出 HTTP 请求经过的每一层；手算子网 |
| W5 | TCP ①：三次握手、四次挥手、状态机（TIME_WAIT 等） | 画出完整 TCP 状态转换图 |
| W6 | TCP ②：滑动窗口、流量控制、拥塞控制（慢启动/拥塞避免/快重传/快恢复） | 用 Wireshark 观察窗口变化 |
| W7 | TCP ③：Nagle 算法、延迟 ACK、keepalive、粘包问题 | 编程解决粘包 |
| W8 | UDP：特点、适用场景、UDP 上的可靠传输设计 | 对比 TCP/UDP 的性能差异 |
| W9 | HTTP/1.1 + HTTP/2：请求方法、状态码、多路复用、头部压缩 | 用 curl 调试各种场景 |
| W10 | TLS/SSL：握手过程、证书链、对称/非对称加密、HTTPS | 用 openssl 手动完成 TLS 握手 |
| W11-12 | Socket 编程基础 + TUN/TAP 接口 | 写 TCP/UDP echo 服务；配置 TUN 设备 |
| W13-16 | **用户态 TCP/IP 协议栈**：逐层实现（详见下方项目） | 核心项目 |
| W17-18 | 手写 HTTP Server（可基于自研协议栈或标准 socket） | 应用层实战 |

**配套阅读**:

- 📖 *TCP/IP 详解（卷一）* — 经典参考，必读
- 📖 *图解 TCP/IP* — 快速入门
- 📖 *HTTP 权威指南* — HTTP 全景
- 📖 *TCP/IP 协议栈实现*（W. Richard Stevens）— 用户态协议栈的圣经
- 🌐 [RFC 793 (TCP)](https://tools.ietf.org/html/rfc793)、[RFC 7230 (HTTP/1.1)](https://tools.ietf.org/html/rfc7230)
- 📺 [Beej's Guide to Network Programming](https://beej.us/guide/bgnet/) — Socket 编程实战
- 📖 Linux TUN/TAP 文档 — 用户态网络编程基础

**项目: `用户态 TCP/IP 协议栈`（核心项目）**

> 这是整个计算机网络阶段的核心项目。从零实现一个用户态的 TCP/IP 协议栈，
> 所有数据包在用户空间处理，不经过内核网络栈。通过 TUN 设备与内核网络栈桥接。
> 这个项目会强迫你真正理解每一层协议的每一个字节。

**Layer 1 — 基础设施（W11-12）**:

- [ ] TUN/TAP 设备初始化：打开 `/dev/net/tun`，配置 IP 地址和路由
- [ ] 数据帧收发框架：从 TUN 读取原始帧 → 解析 → 处理 → 写回 TUN
- [ ] 帧缓冲区设计：内存池 + ring buffer，零拷贝收发
- [ ] 协议分发器：根据 EtherType 分发到对应处理函数

**Layer 2 — 以太网 + ARP（W13）**:

- [ ] 以太网帧解析与构造：目标 MAC / 源 MAC / 类型 / CRC
- [ ] ARP 协议实现：ARP 请求/应答、ARP 缓存表（定时老化）
- [ ] MAC 地址解析：给定目标 IP，查找或发送 ARP 请求获取 MAC
- [ ] 用 `tcpdump` 抓包验证：你的 ARP 包与内核实现的包逐字节对比

**Layer 3 — IP 层（W14）**:

- [ ] IPv4 数据报解析与构造：版本、首部长度、TTL、协议、校验和
- [ ] IP 校验和算法（RFC 1071）
- [ ] IP 分片与重组（处理 MTU 限制）
- [ ] ICMP 实现：Echo Request/Reply（能 ping 通你自己！）
- [ ] 简单路由表：根据目标 IP 查表转发
- [ ] 验证：`ping <你的 TUN 设备 IP>` 能收到回复

**Layer 4 — UDP（W15）**:

- [ ] UDP 数据报解析与构造：源端口、目的端口、长度、校验和
- [ ] UDP 校验和（含伪首部）
- [ ] UDP socket API 抽象：bind / sendto / recvto
- [ ] 验证：用标准 UDP 客户端向你的协议栈发送数据并收到回复

**Layer 4 — TCP（W15-16，核心难点）**:

- [ ] TCP 报文段解析与构造：序列号、确认号、标志位、窗口、校验和
- [ ] TCP 有限状态机完整实现：CLOSED → LISTEN → SYN_SENT → SYN_RCVD → ESTABLISHED → FIN_WAIT_1 → FIN_WAIT_2 → TIME_WAIT → CLOSED 等
- [ ] 三次握手：被动打开（server 端）+ 主动打开（client 端）
- [ ] 四次挥手：FIN/ACK 交互 + TIME_WAIT 定时器
- [ ] 可靠传输：序列号 + 确认 + 超时重传（指数退避）
- [ ] 滑动窗口：发送窗口 + 接收窗口 + 零窗口探测
- [ ] 拥塞控制：慢启动 + 拥塞避免 + 快重传 + 快恢复（Reno）
- [ ] Nagle 算法 + 延迟 ACK
- [ ] TCP socket API：socket / bind / listen / accept / connect / read / write / close
- [ ] 验证：用标准 `netcat` 连接你的 TCP 服务器，完成数据交互

**Layer 5 — 应用层 + 集成（W17-18）**:

- [ ] 基于自研 TCP 实现一个简单的 HTTP Server（复用 HTTP Server 项目）
- [ ] 验证：`curl http://127.0.0.1:<端口>/` 通过你的协议栈返回 HTML
- [ ] 性能基准测试：对比你的协议栈 vs 内核协议栈的吞吐量和延迟
- [ ] 压力测试：并发连接、大量数据传输、异常包处理
- [ ] 边界测试：乱序包、重复包、丢包模拟、TTL 过期

**验证手段**:

- `tcpdump` / `tshark` 抓包对比：你的协议栈发出的包 vs 内核发出的包
- `ping` / `nc` / `curl` 等标准工具与你的协议栈交互
- Wireshark 解码：确认每一层的每一个字段都正确
- 异常注入：用 `iptables` 模拟丢包/延迟/乱序，观察协议栈行为

**项目: `手写 HTTP Server`（C 语言）**

- [ ] TCP Socket 服务器骨架（socket/bind/listen/accept）
- [ ] HTTP 请求解析器（GET/POST、Header、Body）
- [ ] HTTP 响应构建器（状态码、Content-Type、Body）
- [ ] 静态文件服务（MIME 类型检测、目录列表）
- [ ] 并发模型：fork-per-connection → 线程池 → epoll
- [ ] 简单的路由匹配
- [ ] CGI 支持（可选）
- [ ] 可选：基于自研 TCP/IP 协议栈运行
- [ ] 基本的压力测试（用 wrk 或 ab）

**里程碑检查**:

- ✅ 能不查资料画出 TCP 三次握手/四次挥手的完整状态机
- ✅ 能解释 TIME_WAIT 的作用以及为什么不能随意关闭
- ✅ 用户态协议栈能处理 ping（ICMP Echo）、UDP 收发、TCP 连接
- ✅ 通过自研协议栈的 HTTP Server 能被 `curl` 正常访问
- ✅ 能解释拥塞控制的四个阶段以及它们在你的代码中对应哪个函数
- ✅ HTTP Server（标准 socket）能处理 1000+ 并发连接，性能可测量
- ✅ 能用 tcpdump/wireshark 分析任意网络交互

---

### ━━━ Month 11–12: 数据库系统原理 ━━━

**为什么**: 几乎所有后端系统的核心都是"数据的存储与查询"。理解数据库内部原理（索引、事务、MVCC）是区分普通 CRUD 程序员和优秀后端工程师的关键。

**核心知识点**:

| 周 | 主题 | 能力验证 |
| ---- | ------ | ---------- |
| W1 | 关系模型：关系代数、ER 图、范式（1NF→BCNF） | 设计一个博客系统的数据库 schema |
| W2 | SQL DDL/DML：建表、CRUD、JOIN、子查询、窗口函数 | 写出 20+ 种复杂查询 |
| W3 | 索引原理：B+树索引、哈希索引、覆盖索引、前缀索引 | 用 EXPLAIN 分析查询计划 |
| W4 | 索引实战：联合索引、最左前缀原则、索引失效场景 | 优化一个慢查询从 5s 到 50ms |
| W5 | 事务：ACID、隔离级别（RU/RC/RR/Serializable）、幻读问题 | 手动演示脏读/不可重复读/幻读 |
| W6 | 并发控制：MVCC 原理、Undo Log、Read View | 画出 MVCC 的版本链 |
| W7 | 锁机制：行锁/表锁/间隙锁/临键锁、死锁检测 | 手动构造并分析死锁 |
| W8 | 查询优化：代价模型、连接算法（Nested Loop/Hash/Sort-Merge）、统计信息 | 优化复杂 SQL 的执行计划 |
| W9 | MySQL InnoDB 架构：Buffer Pool、Redo Log、Doublewrite、Check Point | 画出 InnoDB 内存/磁盘架构图 |
| W10 | PostgreSQL 对比：MVCC 实现差异、WAL、进程模型 | 对比 InnoDB vs PostgreSQL |
| W11-12 | 项目实战：blog-system 后端 | 应用所学设计并实现 |

**配套阅读**:

- 📖 *MySQL 技术内幕：InnoDB 存储引擎* — InnoDB 深入
- 📖 *数据库系统概论*（王珊）— 中文经典教材
- 📖 *高性能 MySQL*（第 4 版）— 实战调优
- 📖 *Designing Data-Intensive Applications*（DDIA）第 1-7 章 — 数据系统全景
- 📺 CMU 15-445（Database Systems）— Andy Pavlo 的免费课程

**项目: `blog-system`**

- [ ] 数据库设计：用户表、文章表、评论表、标签表（3NF + 合理冗余）
- [ ] 用户认证：注册、登录、JWT Token、密码哈希（bcrypt）
- [ ] 文章 CRUD：创建、编辑、发布、删除、列表（分页）、详情
- [ ] 评论系统：嵌套评论、富文本
- [ ] 标签系统：多对多关系、标签聚合
- [ ] 搜索：全文索引、模糊匹配
- [ ] 性能优化：连接池、预编译语句、读写分离
- [ ] 数据库迁移脚本
- [ ] 基本的单元测试和集成测试

**里程碑检查**:

- ✅ 能解释 InnoDB 为什么用 B+树而不是 B树或哈希做索引
- ✅ 能在 RR 隔离级别下手动推演 MVCC 的 Read View 判定过程
- ✅ blog-system 通过所有功能测试和基本性能测试
- ✅ Phase 1 完成：能独立用 C/C++ 实现中等复杂度的系统软件

---

## Phase 2: Golang 后端工程师（Month 13–30）

### ━━━ Month 13–15: Go 语言精通 ━━━

**为什么选 Go**: Go 是后端工程的"工业级语言"。它的并发模型（goroutine + channel）、编译速度、标准库完备性、部署简洁性，让它成为云原生时代后端开发的首选。

**前置要求**: Phase 1 全部完成

**核心知识点**:

| 周 | 主题 | 能力验证 |
| ---- | ------ | ---------- |
| W1-2 | Go 基础：类型系统、结构体、方法、接口（鸭子类型）、错误处理 | 用 Go 重写 blog-system 的 HTTP 层 |
| W3-4 | Go 并发①：goroutine、channel、select、sync 包 | 实现并发爬虫/下载器 |
| W5-6 | Go 并发②：GMP 调度模型、channel 底层实现、内存模型（happens-before） | 用 race detector 检测并修复竞态 |
| W7-8 | Go Runtime：GC（三色标记+混合写屏障）、栈增长、逃逸分析 | 解释 `go build -gcflags=-m` 的输出 |
| W9-10 | Go 标准库：net/http、database/sql、io、os、sync、context | 能解释标准库关键接口的设计 |
| W11-12 | Go 工程实践：模块管理、测试（table-driven）、benchmark、go generate | 写 benchmark 并分析性能 |
| W13-14 | 设计模式在 Go 中的应用：option pattern、middleware、plugin | 用 functional options 重构配置 |
| W15-16 | Go 高级：反射、unsafe、cgo、泛型（Go 1.18+） | 能在必要时使用 unsafe 优化热点 |
| W17-18 | CLI 工具开发：cobra/viper | 开发一个完整的 CLI 工具 |
| W19-20 | Go 源码阅读（runtime/scheduler, net/http server） | 能解释 goroutine 如何被调度 |
| W21-22 | 项目实践：URL Shortener 完整实现 | 全功能 REST API |
| W23-24 | Go 认证和安全：OAuth2, RBAC, 输入验证 | 完善 URL Shortener 的安全层 |
| W25-26 | 性能优化：pprof、内存分析、CPU profiling | 优化一个有性能问题的服务 |
| W27-28 | Go 中的系统编程：syscall、unsafe pointer、内存对齐 | 理解 Go 与 C 互操作 |
| W29-30 | Go 错误处理最佳实践：error wrapping、sentinel errors、自定义错误 | 建立统一的错误处理规范 |

**配套阅读**:

- 📖 *The Go Programming Language*（Donovan & Kernighan）— Go 圣经
- 📖 *Concurrency in Go*（Katherine Cox-Buday）— 并发编程专著
- 📖 *Go 程序设计语言*（中文版）
- 🌐 [Go Blog](https://go.dev/blog/) — 官方博客
- 🌐 [Go 源码](https://go.googlesource.com/go) — 阅读 runtime 和标准库
- 📺 [7 Days of Projects](https://github.com/PacktPublishing/7-days-of-projects-in-golang) — 快速上手

**项目: `URL Shortener`**

- [ ] RESTful API 设计：创建短链、重定向、统计、过期
- [ ] 分层架构：Handler → Service → Repository
- [ ] 中间件：日志、认证、限流、CORS
- [ ] 配置管理（viper）：多环境配置
- [ ] Graceful Shutdown
- [ ] 单元测试 + 集成测试
- [ ] 基准测试
- [ ] Docker 容器化
- [ ] API 文档（Swagger/OpenAPI）

**里程碑检查**:

- ✅ 能解释 goroutine 的创建成本（初始栈大小、调度方式）
- ✅ 能手写一个线程安全的并发数据结构（如无锁队列或分段锁 Map）
- ✅ URL Shortener 能处理 10k QPS，p99 < 10ms
- ✅ 能阅读并理解 net/http Server 的源码关键路径

---

### ━━━ Month 16–18: Go 后端工程 ━━━

**核心知识点**:

| 周 | 主题 | 能力验证 |
| ---- | ------ | ---------- |
| W1-2 | Web 框架：Gin/Echo 深入、路由树实现、参数绑定验证 | 用框架重构 URL Shortener |
| W3-4 | 数据库工程：GORM、数据库迁移（migrate）、连接池调优 | 实现完整的 Repository 层 |
| W5-6 | Redis：数据结构、缓存策略（Cache-Aside/Write-Through/Write-Behind）、分布式锁 | 实现缓存层 + 分布式锁 |
| W7-8 | 消息队列：Kafka/RabbitMQ 原理、Go 客户端、异步处理 | 实现异步事件驱动 |
| W9-10 | gRPC + Protocol Buffers：服务定义、流式 RPC、拦截器 | 用 gRPC 实现内部服务通信 |
| W11-12 | API 网关：认证、限流、路由、熔断 | 实现简化版 API Gateway |
| W13-14 | 微服务架构：服务发现、配置中心、链路追踪、健康检查 | 设计微服务架构图 |
| W15-16 | 日志与可观测性：结构化日志（slog/zerolog）、OpenTelemetry、Prometheus metrics | 建立统一的可观测性方案 |
| W17-18 | 安全工程：SQL 注入、XSS、CSRF、CSRF、速率限制、HTTPS | 安全加固 checklist |

**项目: `microservice-platform`**

一个简化的微服务平台，包含以下服务：

- [ ] **用户服务** (user-service): 注册、登录、权限管理
- [ ] **内容服务** (content-service): 文章 CRUD、评论
- [ ] **搜索服务** (search-service): 全文检索
- [ ] **API Gateway**: 统一入口、认证、限流
- [ ] **消息总线**: 事件驱动（文章发布→搜索索引更新）
- [ ] **链路追踪**: OpenTelemetry 集成
- [ ] **容器化**: 每个服务一个 Dockerfile + docker-compose 编排
- [ ] **CI/CD**: GitHub Actions 流水线

**里程碑检查**:

- ✅ 能设计一个包含 3+ 微服务的系统架构并画出交互图
- ✅ microservice-platform 能通过端到端测试
- ✅ 能用 OpenTelemetry 追踪一个请求跨 3 个服务的完整链路
- ✅ 能在 Redis 实现分布式锁并解释 Redlock 算法的争议

---

### ━━━ Month 19–21: 分布式系统 + 云原生 ━━━

**核心知识点**:

| 周 | 主题 | 能力验证 |
| ---- | ------ | ---------- |
| W1-2 | 分布式理论：CAP、BASE、一致性模型（强/最终/因果） | 分析具体场景的 CAP 取舍 |
| W3-4 | 分布式共识：Paxos、Raft 协议（日志复制、领导者选举） | 手动推演 Raft 选举过程 |
| W5-6 | 分布式事务：2PC、3PC、Saga、TCC | 设计一个跨服务转账方案 |
| W7-8 | 分布式存储：一致性哈希、数据分片、副本策略 | 一致性哈希的实现 |
| W9-10 | Docker 深入：镜像分层、多阶段构建、安全扫描 | 优化镜像大小从 800MB 到 30MB |
| W11-12 | Kubernetes：Pod、Deployment、Service、Ingress、ConfigMap | 部署 microservice-platform 到 K8s |
| W13-14 | Kubernetes 高级：HPA、PDB、RBAC、NetworkPolicy | 实现自动扩缩容 |
| W15-16 | 服务网格：Istio/Envoy 概念、流量管理、mTLS | 理解 sidecar 模式 |
| W17-18 | 分布式 KV 存储引擎设计 | 综合 Phase 1 的知识 |
| W19-20 | 项目实践：分布式 KV 实现（单机版 Raft） | 完成核心功能 |
| W21-24 | 开源贡献：选择一个 Go 开源项目（如 etcd/cockroachdb/tidb）做贡献 | 至少 2 个 merged PR |

**项目: `分布式 KV 存储引擎`**

- [ ] 基于 B+Tree 的单机存储引擎（复用 Phase 1 的 B+Tree 知识）
- [ ] 实现 Raft 共识协议（日志复制、领导者选举、安全性）
- [ ] 基于 Raft 的多节点复制
- [ ] 一致性哈希分片
- [ ] 客户端 SDK
- [ ] 基准测试和故障注入测试

**里程碑检查**:

- ✅ 能解释 Raft 在网络分区时的行为并手动推演
- ✅ K8s 集群能自动扩缩容 microservice-platform
- ✅ 分布式 KV 能在 3 节点集群中容忍 1 节点故障
- ✅ 至少向一个开源项目贡献了有效代码

---

### ━━━ Month 22–24: DevOps + 生产级工程 ━━━

**核心知识点**:

| 周 | 主题 | 能力验证 |
| ---- | ------ | ---------- |
| W1-2 | CI/CD：GitHub Actions/GitLab CI、构建流水线、制品管理 | 为项目配置完整的 CI/CD |
| W3-4 | 监控：Prometheus + Grafana、指标定义（RED/USE）、告警规则 | 搭建完整的监控栈 |
| W5-6 | 日志：ELK/Loki、结构化日志、日志聚合 | 搭建日志系统 |
| W7-8 | 链路追踪：Jaeger/Tempo、Span 分析、性能瓶颈定位 | 追踪并优化一个慢请求 |
| W9-10 | 性能工程：负载测试（k6/wrk）、性能分析、内存/CPU/IO 优化 | 写出性能分析报告 |
| W11-12 | 生产就绪：SLO/SLI/SLA、故障注入、混沌工程 | 设计故障演练方案 |
| W13-14 | 安全加固：Secret 管理、镜像签名、网络策略、审计日志 | 安全加固 checklist |
| W15-16 | 成本优化：资源限制、HPA 调优、Spot 实例 | 分析并优化基础设施成本 |
| W17-18 | 数据库运维：备份恢复、主从复制、读写分离、分库分表 | 实现读写分离 |
| W19-20 | 消息队列运维：Kafka 集群管理、消费者组、消息可靠投递 | 管理 3 节点 Kafka 集群 |
| W21-24 | 全链路可观测平台项目 | 综合应用所学 |

**项目: `全链路可观测平台`**

- [ ] Metrics 收集（Prometheus exporter）
- [ ] 分布式追踪（OpenTelemetry → Jaeger）
- [ ] 结构化日志（JSON → Loki → Grafana）
- [ ] 自定义 Dashboard（RED 指标）
- [ ] 告警规则（PrometheusAlertManager）
- [ ] 健康检查和就绪探针
- [ ] 性能基准测试和回归检测
- [ ] 文档和运维手册

**里程碑检查**:

- ✅ 能独立搭建一套生产级的可观测性栈
- ✅ 能通过监控数据定位并优化系统瓶颈
- ✅ 全链路可观测平台覆盖 metric/log/trace 三大支柱

---

### ━━━ Month 25–30: Capstone + 求职冲刺 ━━━

#### Month 25-27: Capstone 开源项目

选择一个方向，做一个有影响力的开源项目：

- **选项 A**: 分布式 SQL 数据库（致敬 CockroachDB/TiDB）
- **选项 B**: 高性能 HTTP 框架（致敬 Gin/Echo 但有创新）
- **选项 C**: 云原生 DevOps 工具链
- **选项 D**: 分布式任务调度系统（致敬 Airflow）

要求：

- [ ] 完整的架构设计文档
- [ ] 单元测试 + 集成测试覆盖率 > 80%
- [ ] CI/CD + Docker + K8s 部署
- [ ] 详细的 README 和贡献指南
- [ ] 技术博客文章 3+ 篇
- [ ] 在 GitHub 上获得 100+ stars

#### Month 28-29: 系统设计 + 求职准备

- [ ] 系统设计专题：设计短链服务/消息队列/分布式缓存/搜索引擎
- [ ] 系统设计模板：需求→估算→架构→数据→扩展
- [ ] LeetCode Hard 题 50+ 题
- [ ] 行为面试准备（STAR 方法）
- [ ] 简历打磨和作品集整理
- [ ] 模拟面试 5+ 次

#### Month 30: 最终冲刺

- [ ] 查漏补缺
- [ ] 复习所有项目和核心知识点
- [ ] 面试

---

## 学习方法论

### 每日节奏

```shell
┌─────────────────────────────────────────────────┐
│  08:00-09:00  复习昨天的笔记（间隔重复）          │
│  09:00-12:00  新知识学习（看书/视频 + 做笔记）     │
│  12:00-13:30  午餐 + 轻松阅读（技术博客/播客）     │
│  13:30-17:30  项目编码实践（核心时间）              │
│  17:30-18:00  今日总结（写笔记）                   │
│  19:00-21:00  LeetCode / 习题 / 补充学习           │
│  21:00-21:30  回顾 + 明日计划                     │
└─────────────────────────────────────────────────┘
```

### 每周检查点

- ✅ 本周学了什么？（笔记更新）
- ✅ 项目进度如何？（Git commit 历史）
- ✅ 有什么没理解的？（标记待解决）
- ✅ 下周目标是什么？

### 里程碑验收标准

每个阶段结束时，必须满足：

1. **知识验证**: 不查资料，能向"虚拟面试官"解释核心概念
2. **代码验证**: 项目代码通过所有测试，无已知 bug
3. **文档验证**: 笔记完整，能作为复习材料
4. **工程验证**: 代码质量达标（代码审查、测试覆盖）

---

## 资源总表

### 书籍

| 阶段 | 书名 | 用途 |
| ------ | ------ | ------ |
| C 语言 | *C Primer Plus* (第6版) | 入门教材 |
| 计算机系统 | *CS:APP* (深入理解计算机系统) | 系统理解 |
| C++ | *Effective Modern C++* | 最佳实践 |
| 算法 | *Introduction to Algorithms* (CLRS) | 算法圣经 |
| 操作系统 | *OSTEP* (Operating Systems: Three Easy Pieces) | OS 入门 |
| 网络 | *TCP/IP 详解 (卷一)* | 网络参考 |
| 数据库 | *MySQL 技术内幕: InnoDB 存储引擎* | DB 内部 |
| 数据库 | *DDIA* (Designing Data-Intensive Applications) | 数据系统全景 |
| Go | *The Go Programming Language* | Go 圣经 |
| Go 并发 | *Concurrency in Go* | 并发专著 |
| 分布式 | *DDIA* (第 5-11 章) | 分布式系统 |

### 在线课程

| 课程 | 平台 | 链接 |
| ------ | ------ | ------ |
| CS50 | edX/Harvard | <https://cs50.harvard.edu> |
| MIT 6.S081 | MIT OCW | <https://pdos.csail.mit.edu/6.828/2021/> |
| CMU 15-445 | YouTube | <https://15445.courses.cs.cmu.edu/> |
| MIT 6.824 | MIT OCW | <https://pdos.csail.mit.edu/6.824/> |
| Go Tour | Go 官方 | <https://go.dev/tour/> |

### 刷题

| 平台 | 用途 | 目标 |
| ------ | ------ | ------ |
| LeetCode (leetcode.cn) | 算法练习 | 300+ 题 |
| 代码随想录 | 中文学习路径 | 配合使用 |

---

## 我们的工作方式

### 如何推进

1. **你**: 按照每月计划自主学习，遇到问题随时问我
2. **我**: 每周 review 你的进度，解答疑难，调整计划
3. **代码**: 所有代码提交到 GitHub，我帮你做 code review
4. **笔记**: 用 Markdown 写在 `01-notes/` 下，我帮你补充和纠正
5. **里程碑**: 每个阶段结束时，我会做一个验收评估

### 提问规范

```shell
❌ "C++ 是什么？" （太泛）
✅ "在 mini-kv-cpp 中，unique_ptr 和 shared_ptr 应该分别用在什么场景？
    我的理解是 X，对吗？" （具体 + 有上下文 + 有假设）
```

### 进度跟踪

在仓库根目录维护一个 `PROGRESS.md` 文件，记录：

```markdown
# 学习进度

## 当前阶段: Phase 1 / Month 1
## 当前周: Week 1
## 本周目标: C 语言基础语法

### 完成项
- [x] C 语言控制流（if/for/while/switch）
- [x] 函数定义和调用

### 进行中
- [ ] 数组和字符串操作

### 待解决
- ？指针和数组的关系不太清楚
```

---

> **第一周任务**: 从 C 语言基础语法开始。
> 读 C Primer Plus 第 1-3 章，写 3 个小程序：
>
> 1. 温度转换器（摄氏 ↔ 华氏）
> 2. 简单计算器（加减乘除）
> 3. 猜数字游戏（随机数 + 循环）
>
> 写完后推到 `02-practice/modern-c/` 目录，我来 review。
