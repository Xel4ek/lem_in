#!/bin/zsh

SUCCES_COUNT=0
FAIL_COUNT=0

while IFS= read -r -d '' file
 do
    printf "\n\e[35m--------------- %s ---------------\e[00m\n" "$(basename "${file}")"
  while read -r str;
  do
    if [[ ${str} =~ "#" ]]; then
      num_need=${str//[^0-9]/}
    elif [[ ${str} =~ "step" ]]; then
      num_calc=${str//[^0-9]/}
    fi
    printf "%s\n" "${str}"
  done < <(./cmake-build-release/lem_in < "${file}" | grep "steps\|number of lines\|total\|calc\|Error\|vertex" | uniq)
  dif=$(( num_calc - num_need))
  if [[ dif -gt 0 ]]; then
    printf "\e[31m -- Fail [%d] --\e[00m\n" ${dif}
    FAIL_COUNT=$(( FAIL_COUNT + 1 ))
  else
    SUCCES_COUNT=$(( SUCCES_COUNT + 1))
     printf "\e[32m -- Success [%d] --\e[00m\n" ${dif}
  fi
done < <(find checker/lemin-tools/maps/valid/b*/ -type f -name "map*" -print0)
  if [ "$FAIL_COUNT" -ne  "0" ]; then
    printf "\n -- \e[32m[%d]\e[00m -- \e[31m[%d]\e[00m --\n"  ${SUCCES_COUNT} ${FAIL_COUNT}
  else
    printf "\n \e[32m---== SUCCESS ==---\e[00m\n"
  fi
