#!/bin/bash

LOG_FILE="/var/log/nginx/access.log"

echo "Top 10 IP addresses by access count:"

# 提取IP并统计访问次数
awk '{
    count[$1]++
}
END { 
    for (ip in count){
        print count[ip],ip  
    } 
}' "$LOG_FILE" | \
sort -nr | \
head -n 10

