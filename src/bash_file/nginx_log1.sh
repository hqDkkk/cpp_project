#!/bin/bash
LOG_DIR="/var/log/nginx/access.log"
echo "visit nginx top 10:"

awk '{
    times[$1]++
} END {
    for (i in times){
        print times[$1] ,"  ", i    
    }
}' "$LOG_DIR" | \
sort -nr | \
head -n 10
