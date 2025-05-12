#/bin/bash

cpu=$(
  awk '{printf "%.1fGHz\n", $1/1000000}' /sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq
)

echo " $cpu "
