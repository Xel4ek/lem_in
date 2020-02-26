#!/bin/zsh
while IFS= read -r -d '' file
 do
    printf "\n\e[35m---------------%s---------------\e[00m\n" "$(basename "${file}")"
  while read -r str;
  do
    if [[ ${str} =~ "#" ]]; then
      num_need=${str//[^0-9]/}
    elif [[ ${str} =~ "step" ]]; then
      num_calc=${str//[^0-9]/}
    fi
    printf "%s\n" ${str}
  done < <(./cmake-build-release/lem_in < "${file}" | grep "steps\|number of lines\|total\|calc\|Error\|vertex" | uniq)
  dif=$(( num_calc - num_need))
  if [[ dif -gt 0 ]]; then
    printf "\e[31m -- Fail [%d] --\e[00m\n" ${dif}
  else
      printf "\e[32m -- Succes [%d] --\e[00m\n" ${dif}
  fi
done < <(find checker/lemin-tools/maps/valid/big_sup/ -type f -name "map*" -print0)
