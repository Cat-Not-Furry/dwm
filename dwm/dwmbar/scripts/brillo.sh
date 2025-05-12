#!/bin/bash

#brightnessctl | grep "Current" | awk '{print " " $4}' | tr -d '()%'

# Obtener brillo actual como número
BRIGHTNESS=$(brightnessctl | grep "Current" | awk '{print $4}' | tr -d '()%')

# Escoger icono
if ((BRIGHTNESS <= 0)); then
  ICON="󰃞"
elif ((BRIGHTNESS <= 25)); then
  ICON="󰃝"
elif ((BRIGHTNESS <= 50)); then
  ICON="󰃟"
elif ((BRIGHTNESS <= 75)); then
  ICON="󰃠"
else
  ICON=""
fi
# ""
# Salida
echo "$ICON $BRIGHTNESS% "
