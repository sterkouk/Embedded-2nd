#!/bin/bash
# this script makes the cross compilation and then sends the result in zsun
#zsun must be connected
#needs chmod 755 cross_compile_file.c


#1.Connect zsun on the network openWrt

#2.Open terminal and type:   sudo  ssh 192.168.1.1

#3.Type the password to enter into zsun (if error set the password again on browser)

#4.In another terminal use this script in order to cross compile the file

#5.Then run $sudo scp -P 22 executable   root@OpenWrt:~/

#6.Go back into the first terminal (inside zsun) and run the executable this way:

#$ ./executable <<number of samples>>  << number of interval in seconds>> <<calibration parameter>>

#@calibration parameter is used to calibrate the sleep in order to reduce the error

#7.After the execution check the .txt file for results


echo 'wait to cross compile the file...'

cd /home/gavg/Desktop/openwrt/openwrt-zsun/staging_dir/toolchain-mips_mips32_gcc-4.8-linaro_uClibc-0.9.33.2/bin

mips-openwrt-linux-gcc /home/gavg/Desktop/github_proj/C-and-embedded-systems/zsun_timer.c -o executable
echo ' '
cp executable /home/gavg/Desktop/github_proj/C-and-embedded-systems

echo 'cross compilation finished!File with the name <<executable>> created!'
echo ' '
