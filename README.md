# 后端工程师：学习计划

```mermaid
graph TB
    subgraph P1["🟢 Phase 1 · 计算机基础（M1-12）"]

        direction TB
        C["🔤 C 语言 + 计算机组成<br/>M1-2"]
        CPP_CPP["🔷 C++ 现代特性<br/>M3-5"]
        DSA["📊 数据结构与算法<br/>M3-5"]
        OS["⚙️ 操作系统<br/>M6-8"]
        NET["🌐 计算机网络<br/>M9-10"]
        DB["🗄️ 数据库系统原理<br/>M11-12"]

        C --> CPP_CPP
        C --> DSA
        CPP_CPP --> OS
        CPP_CPP --> NET
        DSA --> NET
        OS --> NET
        OS --> DB
        NET --> DB
    end

    subgraph P1P["📦 Phase 1 · 项目驱动"]

        direction TB
        KV_C["mini-kv-c<br/>C 语言内存管理 + 哈希表"]
        BTREE["B+Tree 存储引擎<br/>磁盘索引 + 范围查询"]
        KV_CPP["mini-kv-cpp<br/>C++ 重写 + 模板化"]
        SHELL["unix-shell<br/>fork/exec + 信号 + 管道"]
        SKIPLIST["redis-skiplist<br/>并发安全有序结构"]
        TCPIP["用户态 TCP/IP 协议栈<br/>逐层实现以太网→IP→TCP"]
        HTTP["手写 HTTP Server<br/>Socket 编程 + 并发模型"]
        BLOG["blog-system<br/>认证 + CRUD + 索引优化"]

        C -.->|"M2 哈希表 + 持久化"| KV_C
        DSA -.->|"M5 B+Tree"| BTREE
        CPP_CPP -.->|"M5 模板 + RAII"| KV_CPP
        CPP_CPP -.->|"M5 STL 重写"| KV_CPP
        OS -.->|"M7 进程 + 信号"| SHELL
        OS -.->|"M8 跳跃表 + 并发"| SKIPLIST
        NET -.->|"M10 协议逐层实现"| TCPIP
        NET -.->|"M11 Socket + epoll"| HTTP
        DB -.->|"M12 Schema + 事务"| BLOG
    end

    subgraph P2["🔵 Phase 2 · Golang 后端（M13-30）"]

        direction TB
        GO["🐹 Go 语言精通<br/>M13-15"]
        BE["🏗️ Go 后端工程<br/>M16-18"]
        DIST["🌍 分布式系统 + 云原生<br/>M19-21"]
        DEVOPS["🔧 DevOps + 生产级工程<br/>M22-24"]
        CAP["🎯 Capstone + 求职冲刺<br/>M25-30"]

        GO --> BE
        BE --> DIST
        DIST --> DEVOPS
        DEVOPS --> CAP
    end

    subgraph P2P["📦 Phase 2 · 项目驱动"]

        direction TB
        URL["URL Shortener<br/>REST API + 中间件"]
        MICRO["microservice-platform<br/>服务拆分 + gRPC + 追踪"]
        DKV["分布式 KV 存储<br/>Raft 共识 + 一致性哈希"]
        OBS["全链路可观测平台<br/>Prometheus + Jaeger + Loki"]

        GO -.->|"M15 REST + 并发"| URL
        BE -.->|"M18 微服务架构"| MICRO
        DIST -.->|"M21 Raft + 分片"| DKV
        DEVOPS -.->|"M24 可观测性三支柱"| OBS
    end

    DB --> GO
    NET --> GO
    DSA --> GO
    OS --> GO
```

仓库目录结构

```shell
backend/
├── README.md                 # 学习计划（2.5 年后端工程师路径）
├── .clangd                   # clangd 配置（C++23 标准 + 模块支持）
├── .gitignore                # Git 忽略规则
│
├── 01-notes/                 # 📝 学习笔记
│   ├── modern-c/                 #   C 语言笔记
│   ├── modern-cpp/               #   C++ 笔记
│   ├── data-structures/          #   数据结构与算法笔记
│   ├── computer-architecture/    #   计算机组成原理笔记
│   ├── operating-system/         #   操作系统笔记
│   ├── computer-networking/      #   计算机网络笔记
│   ├── database/                 #   数据库原理笔记
│   ├── golang/                   #   Go 语言笔记
│   ├── microservice/             #   微服务笔记
│   └── cloud-native/             #   云原生笔记
│
├── 02-practice/              # 💻 练习题与课堂实践
│   ├── modern-c/                 #   C 语言练习
│   ├── modern-cpp/               #   C++ 练习
│   ├── data-structures/          #   数据结构练习
│   ├── operating-system/         #   操作系统练习
│   ├── networking/               #   网络编程练习
│   ├── database/                 #   SQL 练习
│   └── golang/                   #   Go 语言练习
│
├── 03-projects/              # 🚀 综合项目
│   ├── mini-kv-c/                  #   mini-kv 存储引擎（C 版）
│   ├── mini-kv-cpp/                #   mini-kv 存储引擎（C++ 版）
│   ├── bplus-tree/                 #   B+Tree 存储引擎
│   ├── redis-skiplist/             #   Redis 跳跃表 + 字典实现
│   ├── unix-shell/                 #   极简 Unix Shell
│   ├── userspace-tcpip/            #   用户态 TCP/IP 协议栈
│   ├── blog-system/                #   博客系统全栈后端
│   ├── url-shortener/              #   URL 短链服务
│   ├── microservice-platform/      #   微服务平台
│   ├── distributed-kv/             #   分布式 KV 存储引擎（Raft）
│   └── observability-platform/     #   全链路可观测平台
│
├── 04-exercises/             # 📖 课后习题代码
│   └── leetcode/                 #   LeetCode 刷题记录
```
