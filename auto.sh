#!/bin/bash
cd /Users/3y/markdown
time=$(date "+%Y%m%d-%H%M%S")
git add .
git commit -m "study times ${time}"
git push -u origin master
