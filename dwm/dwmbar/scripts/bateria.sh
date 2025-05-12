#!/bin/bash

BAT_PATH="/sys/class/power_supply/BAT0"

capacity=$(cat "$BAT_PATH/capacity" 2>/dev/null)
status=$(cat "$BAT_PATH/status" 2>/dev/null)

if [ "$status" = "Charging" ]; then
  cat /sys/class/power_supply/BAT*/capacity 2>/dev/null | awk '{print " " $1 "% "}' # enchufe
elif [ "$status" = "Discharging" ]; then
  cat /sys/class/power_supply/BAT*/capacity 2>/dev/null | awk '{print " " $1 "% "}' # batería
else
  echo "B: ? "
fi
