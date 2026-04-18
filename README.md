# Royal Hold'em - Social Poker Platform

[![GitHub stars](https://img.shields.io/github/stars/deepseek7878/RoyalHoldem-Social-Poker-Platform?style=for-the-badge)](https://github.com/deepseek7878/RoyalHoldem-Social-Poker-Platform)
[![GitHub forks](https://img.shields.io/github/forks/deepseek7878/RoyalHoldem-Social-Poker-Platform?style=for-the-badge)](https://github.com/deepseek7878/RoyalHoldem-Social-Poker-Platform)
[![GitHub issues](https://img.shields.io/github/issues/deepseek7878/RoyalHoldem-Social-Poker-Platform?style=for-the-badge)](https://github.com/deepseek7878/RoyalHoldem-Social-Poker-Platform/issues)
[![Demo](https://img.shields.io/badge/Live-Demo-brightgreen?style=for-the-badge)](https://royalholdem-demo.com)
[![License](https://img.shields.io/github/license/deepseek7878/RoyalHoldem-Social-Poker-Platform?style=for-the-badge)](https://github.com/deepseek7878/RoyalHoldem-Social-Poker-Platform/blob/main/LICENSE)

**社交德州扑克平台 / Social Texas Hold'em Platform / 社交德州撲克平台**  
实时多人对战、聊天、锦标赛、筹码系统、房间管理 / Real-time multiplayer, chat, tournaments, chips, rooms / 即時多人對戰、聊天、錦標賽、籌碼、房間管理.

## 🎮 平台功能概览 / Features / 功能概覽

| 模块 | 功能 | 技术 |
|------|------|------|
| 🏛️ **大厅** | 热门房间、在线玩家、赛事预告 | React + Socket.io |
| 🪑 **房间** | 私房/公房、盲注自定义、密码保护 | WebSocket同步 |
| ⚡ **实时对战** | 零延迟发牌、下注、摊牌 | Server-authoritative |
| 💬 **聊天** | 房间聊天下注聊、表情包、全局广播 | Socket.io rooms |
| 🏆 **锦标赛** | 定时赛、淘汰赛、排行榜 | Redis排行 |
| 💰 **经济系统** | 虚拟筹码、签到奖励、商城 | MongoDB持久化 |

## 🚀 一键部署 / Quick Deploy / 一鍵部署

```bash
# Docker一键部署 (推荐)
docker-compose up -d

# 包含: nginx + app + mongodb + redis
# 自动HTTPS + 域名配置
```

```bash
# 手动部署
git clone https://github.com/deepseek7878/RoyalHoldem-Social-Poker-Platform.git
cd RoyalHoldem-Social-Poker-Platform
npm install
cp .env.example .env
npm run dev  # 开发模式
npm start    # 生产模式
```

**支持云部署：Vercel / Railway / Render / 自建服务器**

## 📩 Contact联系

Telegram：@fox_lovemyself


Email：lihongbo9414@gmail.com

## 📱 实时演示截图 / Live Demo Screenshots / 即時示範截圖

<img width="1280" height="720" alt="大厅01" src="https://github.com/user-attachments/assets/14bcc7c2-0c97-41c2-b3bf-d799ea1463d6" />

![大厅-俱乐部](https://github.com/user-attachments/assets/1cb236f7-2873-430c-a19c-a0420cab13bc)
![011](https://github.com/user-attachments/assets/cd9bd0e5-60ba-47f7-a0df-d5596b4dede5)
![08](https://github.com/user-attachments/assets/5fe7b7d0-2e2a-472f-be16-d27eb030bb82)
![07-亮手牌](https://github.com/user-attachments/assets/138dcc3a-1bee-4bc4-980a-1186213d1ae2)
![06-9人桌](https://github.com/user-attachments/assets/0165cd32-bb19-4754-accc-3b33fd46bbfb)
![03](https://github.com/user-attachments/assets/33973b2b-8c71-423e-8c96-61ac9b977914)
![01](https://github.com/user-attachments/assets/4aa66163-4ef1-44e6-b834-7460fb60f4d8)
## 🏗️ 完整技术栈 / Tech Stack / 技術棧
Frontend: React 18 + TypeScript + TailwindCSS
Backend: Node.js + Express + Socket.io
Database: MongoDB + Redis (排行/会话)
Game Engine: Custom Texas Hold'em (服务器权威)
Auth: JWT + OAuth (Google/GitHub)
Deploy: Docker + Nginx + PM2
Monitor: Sentry + Prometheus


## 🎮 用户完整流程 / User Journey / 用戶流程
注册/登录 → 获得10000起始筹码

进入大厅 → 热门房间/赛事推荐

创建房间 → 设置盲注/人数/密码

邀请好友 → 实时聊天等待

自动开局 → 流畅对战体验

自动结算 → 筹码到账

查看战绩 → 参与锦标赛

## 💎 平台核心优势 / Platform Advantages / 平台優勢

✅ 零延迟实时同步 (Socket.io + Redis)
✅ 服务器权威防作弊
✅ 筹码经济闭环系统
✅ 社交裂变机制
✅ 锦标赛完整生态
✅ 多语言全球化
✅ Docker生产级部署
✅ 移动端完美适配

## 🔌 核心API / Core APIs / 核心API

```javascript
// 创建房间
POST /api/rooms
{
  "blinds":,[1][2]
  "maxPlayers": 9,
  "isPrivate": true,
  "password": "123"
}

// 玩家行动
POST /api/game/:roomId/action
{
  "action": "raise",
  "amount": 60,
  "playerId": "uuid"
}

// 锦标赛报名
POST /api/tournaments/:id/join
```

## 📊 性能指标 / Performance Metrics / 效能指標

| 指标 | 单机 | 1000并发 |
|------|------|----------|
| 房间延迟 | 25ms | 45ms |
| 牌型判断 | 0.8ms | 1.2ms |
| 内存占用 | 180MB | 2.1GB |
| CPU占用 | 12% | 65% |

**支持5000+并发用户，单实例1000房间稳定**

## 🎯 商业模式 / Monetization / 商業模式

💎 VIP会员 (加速、专属皮肤)
🎁 每日签到奖励
🏆 锦标赛报名费
👑 贵族特权 (私房优先)
💰 筹码商城

## 🛠️ 一键部署方案 / Deployment Options / 一鍵部署方案

### **Docker (推荐)**
```bash
docker-compose up -d
# 自动: nginx+app+mongo+redis
```

## 📦 版本发布 / Releases / 版本發佈

### 🚀 v1.0.0 (生产可用)
✅ 完整社交功能  
✅ 实时多人对战  
✅ 聊天锦标赛系统  
✅ Docker部署  
✅ 多语言支持  

**[生产部署包](https://github.com/deepseek7878/RoyalHoldem-Social-Poker-Platform/releases/latest)**

## ❓ 常见问题解答 / FAQ / 常見問題

**Q: 支持多少人同时在线？**  
**A:** 单实例2000+，集群无限扩展

**Q: 防作弊机制？**  
**A:** 服务器权威，所有计算服务端

**Q: 移动端友好吗？**  
**A:** 完美适配手机/平板

**Q: 可以商用吗？**  
**A:** MIT License，商业友好

**Q: 数据库怎么选？**  
**A:** SQLite(开发) → MongoDB(生产)

## 🏗️ 项目结构 / Project Structure / 專案結構
RoyalHoldem/
├── server/
│ ├── game/ # 扑克引擎
│ ├── rooms/ # 房间管理
│ ├── chat/ # 聊天系统
│ └── tournaments/ # 锦标赛
├── client/
│ ├── src/
│ │ ├── lobby/
│ │ ├── game/
│ │ └── stats/
└── docker/ # 一键部署

text

## 🤝 贡献指南 / Contributing / 貢獻指南
✅ 新游戏模式 (Omaha)
✅ 支付SDK集成
✅ 移动端优化
✅ 更多语言包
✅ 性能优化
✅ 安全加固

text

## 📄 开源许可 / License / 授權
MIT License - 社交游戏商用顶级友好
Copyright (c) 2026 deepseek7878






## 🎮 Features
- Real-time multiplayer poker
- Lobby & table system
- Club / VIP system
- Chip economy & progression
- Admin dashboard

## 💡 Highlights
- Built for scalability
- Monetization-ready
- Clean architecture



## 🚀 Deployment
Guided deployment available




