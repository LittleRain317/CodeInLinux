#!/bin/bash
# Program:
#	爬虫
# History:
#	date:2019-07-07 19:13:05	author:littlerain	version:1.0
PATH=/home/littlerain/Java/jdk-11.0.2/bin:/home/littlerain/Java/jdk-11.0.2/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games:/sbin:/usr/sbin:/home/littlerain/bin
export PATH
export http_proxy=http://47.105.131.73:80

head=""
pHead=""
read -p "请输入需要爬取的网址:" url
url=${url:-"www.baidu.com"}

#截取出然后创建改目录
homeDirName=$(echo $url | cut -c 18-) 
homeDirName=${homeDirName%/}
if [ ! -e "$homeDirName" ]; then
	mkdir  $homeDirName	
fi
homeFileName="./$homeDirName/$homeDirName.html"
#爬取URl ArtZG这一层并导出
wget $url -O $homeFileName

#获取首页信息
homeFileContent=$(cat $homeFileName)
if [ -z "$homeFileContent" ]; then
	echo "获取首页信息失败"
	rm -rf $homeFileName
	exit 127
fi

#获取ArtZG/2152/这一层信息
format="s#^#${url%/}#g"
grepFormat="/${homeDirName}.*\" target"

echo $homeFileContent |grep -oa "$grepFormat" | sed "s/\"\ target//g" | sed "s/\/${homeDirName}//g" | sed -e $format | sort | uniq > "$homeDirName/list.txt"

cat "$homeDirName/list.txt" | while read line
do
	listDirName="$homeDirName/$(echo $line | grep -Eo '[0-9]{4}')/"
	mkdir  $listDirName
	listFileName="${listDirName}$(echo $line | grep -Eo '[0-9]{4}').html"
	wget $line -O $listFileName
done

#find ArtZG/ | grep -E '[0-9]{4}.html'
#获取每个文件的文件名
find $homeDirName | grep -E '[0-9]{4}.html' | while read line
do
	MAXindex=$(cat ${line} | grep -Eoa '<b>[0-9]' | sort | uniq | sed 's/<b>//g')
	pageDirName="$(echo $line | cut -c1-11)"
	pageDirName="${pageDirName}page"
	mkdir $pageDirName
	listURL="$(echo $line | cut -c1-11)"
	listURL="${head}${listURL}index_"
	for (( temp=1; temp<= MAXindex; ++temp))
	do
		if [ "$temp" == "1" ]; then
			tempURL=${listURL%_}
			tempURL="${tempURL}.html"
		else
			tempURL="${listURL}${temp}.html"
		fi
		wget $tempURL -O "$pageDirName/tmp.txt"
		cat "$pageDirName/tmp.txt" >> "$pageDirName/page.txt"
	done
done

find $homeDirName -name page.txt  | while read line
do
	#line的结果ArtZG/2143/page/page.txt
	MaxPages=$(cat "$line" | grep -Eao "\b[0-9]+.html" | wc -l)
	for (( temp=1; temp<= $MaxPages; ++temp))
	do
		finalURL="${head}$(echo $line | cut -c1-11)${temp}.html"
		wget $finalURL -O "${homeDirName}tmp.txt"
		cat "${homeDirName}tmp.txt" >> "${homeDirName}image.txt"
	done
done
cat "${homeDirName}image.txt" | grep -Eao "\b${pHead}.*/[0-9]+.jpg" | xargs wget
