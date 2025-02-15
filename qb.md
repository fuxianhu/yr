# MC

## bot指令
| 名称 | 指令 |
| ----- | ----- |
| 家中（仓库、刷铁机） | `/player jia spawn at -160.50 100.00 256.50 facing 0 0 in minecraft:overworld`|
| 潜影贝农场 | `/player ke spawn at -1469.50 61.00 922.50 facing 0 0 in minecraft:the_end`|
| 守卫者农场下界收集 | `/player shou_ji spawn at 146.50 160.50 -44.5 facing 0 0 in minecraft:the_nether`|
| 未知 | `/player m spawn at 1214.50 167.00 -366.50 facing 0 0 in minecraft:overworld`|
| 伪和平 | `/player he_pin spawn at -1029.50 128.00 211.50 facing 0 0 in minecraft:the_nether`|
| 刷沙机 | `/player shua_sha spawn at 95.50 44.00 -13.50 facing 0 0 in minecraft:the_end` |
| 刷石机 | `/player shua_shi spawn at 8.50 80.00 165.50 facing 0 0 in minecraft:the_end` |

## 待办事项
1. [ ] 激活所有折跃门
2. [ ] 挖空所有黑曜石柱
3. [ ] 清空末地主岛

## QBM-Fabric (QuickBackupMulti-Fabric)
> 这是一个用于**备份、管理备份与回档**的 Mod，支持回档自动重启服务器。模组的默认指令为`/qb` 或 `/quickbackupmulti`。

| 指令 | 描述 |
| ---------- | ---------- |
| `/qb back <name>` | **回档** |
| `/qb cancel` | **取消**回档 |
| `/qb confirm` | **确认**回档 |
| `/qb delete <name>` | **删除**某备份 |
| `/qb list` | 显示备份**列表** |
| `/qb make <name> [<text>]` | **创建**该存档的备份 |
| `/qb permission` | 设置玩家**权限** |
| `/qb search <name>` | **搜索**该存档的备份 |
| `/qb show <name>` | 显示该存档的**具体信息** |

> TPS<20且mspt>50：掉刻
1. 启用实时显示怪物数量和刷怪上线：`/log mobcaps`
2. 查看更详细的刷怪信息：`/log mobcaps full`
3. 旁观：`/spectator`
4. 调视距：`/carpet viewDistance <视距>`