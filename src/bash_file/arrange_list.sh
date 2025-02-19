#!/bin/bash
DOWNLOAD_DIR="$HOME/Downloads"

if[ ! -d "$DOWNLOAD_DIR"]; then
    echo "directory is not exist:$DOWNLOAD_DIR"
    exit 1
fi

find "$DOWNLOAD_DIR" -type f | while read -r file; do
    extension="${file##*.}"
        
    if[[ "$file" != *.* ]]; then
        continue
    fi

    traget_dir="$DOWNLOAD_DIR/$extension"
    mkdir -p "target_dir"

    mv "$file" "$target_dir/${file##*/}"
done

echo "list is arranged completely"
