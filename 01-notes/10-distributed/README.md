# 10-distributed · 云原生与分布式（M23–M26）

主线项目：distributed-kv（Raft 库 + 分片路由 + K8s 部署，节点宕机自动切换）；或 observability-platform 二选一做深。
阅读主线：Raft 论文与可视化逐图推演 + DDIA + K8s/etcd 官方文档。

## M23 · 分布式理论与共识

- 01-CAP-BASE与一致性模型.md
- 02-Paxos与Raft.md
- 03-etcd架构与raft实现.md
- 04-分布式时间-向量时钟与TrueTime.md

## M24 · 分布式存储

- 05-分片与一致性哈希.md
- 06-副本与quorum读写.md
- 07-故障恢复.md
- 08-分布式表与分库分表.md
- 09-对象存储概念.md

## M25 · 云原生

- 10-K8s核心资源.md
- 11-K8s调度与探针.md
- 12-Helm与Operator.md
- 13-K8s网络与存储基础.md
- 14-CI-CD流水线.md

## M26 · 可观测性与性能

- 15-Prometheus指标设计-RED-USE.md
- 16-告警规则.md
- 17-ELK与Loki日志体系.md
- 18-OpenTelemetry全链路追踪.md
- 19-Go性能调优实战.md
- 20-容量规划与全链路压测.md
