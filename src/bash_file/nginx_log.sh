# Step 1: 提取请求路径
# 使用grep和sed提取请求路径部分（假设请求路径在第7列）
grep -oP '"\K[^ ]+' nginx_access.log | sed 's/HTTP.*//' > paths.txt

# Step 2: 使用awk统计每个路径的访问次数
awk '{ count[$0]++ } END { for (path in count) print count[path], path }' paths.txt > counts.txt

# Step 3: 按访问次数排序并输出Top 10
sort -rn counts.txt | head -n 10