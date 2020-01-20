#### docker 文件隔离

#### docker commit的流程

#### 如何设计rest API
- 基于数据建模，而不是基于功能建模 
```
GET /api/dogs
GET /api/dogs/{id}
GET /api/dogs/?name=xxx
POST /api/dogs
PUT /api/dogs/{id}
DELETE /api/dogs/{id}
```

- 保持数据的简洁，Data和Timestamp尽量用string来表达
- URL的表现形式
  - 只使用名词
  - 选择合适的ID
  - 要表达资源间的联系
  - 要支持查询
  - 要支持
- 数据分页 - 分批返回
```json
GET https://dogtracker.com/dogs?limit=25,offset=0 
返回
{
  "self": "https://dogtracker.com/dogs?limit=25,offset=0",
  "kind": "Page",
  "pageOf": "https://dogtracker.com/dogs",
  "next": "https://dogtracker.com/dogs?limit=25,offset=25",
  "contents": [...]
}
```