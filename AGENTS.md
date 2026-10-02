# AGENTS.md — 后端工程师学习仓库

后端学习路线（2.5 年版）的课程仓库：中文 Markdown 笔记 + 小型 C++ 练习代码 + 综合项目。**没有构建系统、没有测试套件、没有 CI**（无 package.json / Makefile / go.mod）。计划按每周 10–20 小时业余投入设计，见 `CURRICULUM.md`（前 15 月计算机基础 + 后 15 月 Go 后端），进度见 `PROGRESS.md`。当前处于 Phase 1 · M1（现代 C++，从基础学起）。

## 目录布局

- `01-notes/<topic>/` — 学习笔记（Markdown），topic 如 `modern-cpp`、`operating-system`、`golang`
- `02-practice/<topic>/` — 练习/演示代码，与笔记同主题对应
- `03-projects/<name>/` — 综合项目（目前全是 `.gitkeep` 占位，尚无代码）
- `04-exercises/leetcode/` — 刷题记录（空）
- `README.md` — 目录结构 + 路线图；`PROGRESS.md` — 每周五更新的周记

笔记与练习的 topic 命名不完全一致（笔记用 `computer-networking`，练习用 `networking`），按实际目录走。

## 开发环境

WSL2 (Arch Linux, pacman)。工具链安装：

```shell
sudo pacman -S --needed base-devel gcc cmake make gdb
sudo pacman -S --needed valgrind lldb cppcheck ninja ccache clang
```

- 主线语言是 **C++**：`g++ -std=c++23`，练习放 `02-practice/modern-cpp/`；C 独有特性集中在计划 M5 尾声「C++ 不包含的特性」（对照验证片段也放 `modern-cpp/`）；`.clangd` 已按此配置
- 编辑器走 **clangd**（VS Code + `llvm-vs-code-extensions.vscode-clangd`，formatOnSave 开启）。**不要装微软 `ms-vscode.cpptools`**——两套 IntelliSense 会打架
- 多文件项目才需要 `compile_commands.json`（`cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1`），单文件练习用根目录 `.clangd` 即可

## 编译与运行

没有统一命令，单文件用 g++/gcc 直接编译：

```shell
cd 02-practice/modern-cpp
g++ -Wall -Wextra -std=c++23 main.cpp -o main   # C++ 主线
g++ -g main.cpp -o main                         # 带调试信息（gdb）
gcc -std=c23 snippet.c -o snippet               # M5 尾声的 C 对照片段
```

编译四阶段（gcc 分步实操，每步产出中间文件）：

```shell
gcc -E main.c -o main.i   # 预处理
gcc -S main.i -o main.s   # 编译为汇编
gcc -c main.s -o main.o   # 汇编为目标文件
gcc main.o -o main        # 链接
```

内存检查用 `valgrind`（后续项目里程碑要求 Valgrind 无泄漏）。未定义行为/静态分析用 `cppcheck`。

## 约定（观察自现有笔记与提交）

- **全部中文**，教学口吻（我们/你）；术语一次定义、全篇统一
- 笔记用相对链接引用练习代码：`[demo.cpp](../../02-practice/modern-cpp/demo.cpp)`，行文内同一文件写 `` `demo.cpp` ``
- 笔记中的代码块必须与所链接的练习文件**逐字节一致**；引用的命令输出/行数/版本号必须是刚实测的真实结果，不能凭记忆写
- 提交信息格式：`Phase1: <中文描述>`（如 `Phase1: C++ 变量与类型`）；远程走 HTTPS + gh 凭证助手，分支 `main`
- `PROGRESS.md`：每周五更新；「完成项/进行中/待解决」条目区分「讲解完成」与「笔记整理中」；列出的 commit hash 必须真实存在于 `git log --oneline`
- 笔记里用 GitHub callout（`> [!NOTE]` / `> [!TIP]` / `> [!WARNING]`）、`+` 并列要点、表格做对照、`mermaid` 画图

## 陷阱

- `.gitignore` 忽略 `build/`、`bin/`、`out/` 等构建产物；`*.i`/`*.s` 不在忽略列表，生成中间产物时注意别误提交
- `.vscode/*` 被忽略、唯独 `settings.json` 入库——改编辑器配置只应动这一个文件
- 计划不设 C 阶段：C++ 从基础开始（M1-5），C 独有特性在 M5 尾声「C++ 不包含的特性」补充；C 语言的笔记/练习目录已删除，不要重建 `modern-c/` 目录，新内容写入 `modern-cpp/`。提交历史已于 2026-10-02 重建为单一 init 提交，旧历史不存在
- `03-projects/` 目前全是占位目录（`.gitkeep`）；计划内必做：mini-kv-cpp（M1-5 主线）、bplus-tree、userspace-tcpip（M13 核心项目）、项目① url-shortener、项目② microservice-platform、项目③ distributed-kv（或 observability-platform 二选一），动手前对照 `CURRICULUM.md` 和 `PROGRESS.md` 确认当前模块
