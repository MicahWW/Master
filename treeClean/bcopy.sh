#!/usr/bin/bash

tree -fiQo .tree.txt

cat .tree.txt | while read name
do
#	echo $name
	echo encoded/$name.encode
#	./copy $name > encoded/$name.encode
done
