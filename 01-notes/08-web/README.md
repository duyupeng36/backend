# 08-web · Web 后端技术栈（M16–M19）

主线项目：url-shortener-pro（M16 立项 → M19 v1.0：Docker Compose 一键起 + 压测报告）。
阅读主线：Go 标准库 net/http 源码 + Gin/GORM 官方文档（英文）+《Redis 设计与实现》。

## M16 · Web 后端基础

- 01-net-http原理.md
- 02-Gin与Echo框架.md
- 03-参数校验与优雅退出.md
- 04-分层架构-handler-service-repository.md
- 05-依赖注入.md
- 06-配置管理-viper.md
- 07-日志-zap与zerolog.md
- 08-单元测试与mock.md

## M17 · 存储层：MySQL + Redis

- 09-GORM与sqlx-连接池.md
- 10-事务与锁的正确用法.md
- 11-慢查询与索引优化.md
- 12-Redis五大结构实战.md
- 13-Redis持久化.md
- 14-缓存三大问题-穿透击穿雪崩.md
- 15-分布式锁-Redlock之争.md
- 16-Lua脚本.md
- 17-缓存与DB一致性.md

## M18 · 消息队列 + 认证 + 可靠性

- 18-Kafka-分区副本与消费组.md
- 19-幂等与Exactly-once.md
- 20-JWT与OAuth2.md
- 21-RBAC权限.md
- 22-接口幂等.md
- 23-限流-令牌桶.md
- 24-熔断降级-gobreaker.md
- 25-超时与重试设计.md

## M19 · 容器化与项目收官

- 26-Docker镜像构建-多阶段.md
- 27-Docker-Compose.md
- 28-Docker网络与存储.md
- 29-Makefile与脚本化开发.md
- 30-配置与密钥管理.md
- 31-压测-wrk-vegeta与瓶颈分析.md
