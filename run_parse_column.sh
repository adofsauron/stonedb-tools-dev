#!/bin/bash

XID=`ls ./data/v`

echo ./stonedb-tools column ./data/v/$XID,./data/DN,./data/META,./data/DATA

echo -e "\n"

./stonedb-tools column ./data/v/$XID,./data/DN,./data/META,./data/DATA

