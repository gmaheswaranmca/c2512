sources=("./headers/ui_settings.h" "./headers/ui_common.h" "./headers/floor_main.h" "./headers/admin_main.h" "./headers/app_main.h" "./main.cpp" "./sources/floor_main.cpp" "./sources/admin_main.cpp" "./sources/app_main.cpp")

echo "//single source file app..."> "page.cpp"
for e in ${sources[@]}; do 
    cat $e  | grep -v '^#include "' | grep -v '^#pragma once' >> "page.cpp"
done