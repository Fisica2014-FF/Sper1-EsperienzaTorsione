#!/bin/bash

for filegrezzo in *
do
	paste ../dati_formattati/${filegrezzo}_{p,t,v} | sort -n | uniq --check-chars=12 --all-repeated=separate | perl -pe "s/^$/@/" >../risultati/${filegrezzo}_sigma_v
	paste ../dati_formattati/${filegrezzo}_{v,t,p} | sort -n | uniq --check-chars=13 --all-repeated=separate | perl -pe "s/^$/@/" >../risultati/${filegrezzo}_sigma_p
done

exit 0
