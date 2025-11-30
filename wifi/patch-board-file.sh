#!/bin/sh

wget https://git.kernel.org/pub/scm/linux/kernel/git/firmware/linux-firmware.git/plain/ath11k/WCN6855/hw2.0/board-2.bin
wget https://raw.githubusercontent.com/qca/qca-swiss-army-knife/refs/heads/master/tools/scripts/ath11k/ath11k-bdencoder

./ath11k-bdencoder -e board-2.bin >/dev/null
patch -p1 < add-tw220-board-file.patch
./ath11k-bdencoder -c board-2.json
