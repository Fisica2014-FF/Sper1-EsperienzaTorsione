#!/bin/bash
# Spostare in dati grezzi

for file in *
do
	cut -f1 $file >../datiformattati/${file}_p
	cut -f2 $file >../datiformattati/${file}_v
	cut -f3 $file >../datiformattati/${file}_t
done
exit 0
