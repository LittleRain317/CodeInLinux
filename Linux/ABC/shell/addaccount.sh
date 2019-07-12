#!/bin/bash
# Program:
#	批量创建账号
# History:
#	date:2019-07-10 20:55:25	author:littlerain	version:1.0
PATH=/home/littlerain/Java/jdk-11.0.2/bin:/home/littlerain/bin:/home/littlerain/Java/jdk-11.0.2/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games:/sbin:/usr/sbin:/home/littlerain/bin
export PATH
for username in myquota1 myquota2 myquota3 myquota4 myquota5
do
	useradd -g "myquotagrp" $username 
	echo "$username:password" | chpasswd -m
done
