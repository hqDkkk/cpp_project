#!/bin/bash
DOWNLOAD_DIR="$HOME/Downloads"

# 检查目录是否存在
if [ ! -d "$DOWNLOAD_DIR" ]; then
    echo "Directory does not exist: $DOWNLOAD_DIR"
    exit 1
fi

# 遍历下载目录中的所有文件
find "$DOWNLOAD_DIR" -type f | while read -r file; do
    # 提取文件扩展名
    extension="${file##*.}"

    # 跳过没有扩展名的文件
    if [[ "$file" != *.* ]]; then
        continue
    fi

    # 创建目标目录
    target_dir="$DOWNLOAD_DIR/$extension"
    mkdir -p "$target_dir"

    # 移动文件到目标目录
    mv "$file" "$target_dir/${file##*/}"
done

echo "Directory is arranged completely"