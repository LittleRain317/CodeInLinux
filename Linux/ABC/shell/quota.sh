#!/bin/bash
# Program:
#	批量设置quota
# History:
#	date:2019-07-13 11:36:33	author:abc	version:1.0
PATH=/home/littlerain/Java/jdk-11.0.2/bin:/home/littlerain/bin:/home/littlerain/Java/jdk-11.0.2/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games:/sbin:/usr/sbin:/home/littlerain/bin
export PATH

for user in my1 my2 my3 my4
do
	setquota -u $user 40000 5000000 0 0 /mnt/quota
done
