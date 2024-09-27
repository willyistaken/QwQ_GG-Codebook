setxkbmap -option caps:swapescape #caps to esc
cpp file.cpp -dD -P -fpreprocessed | tr -d '[:space:]' | md5sum | cut -c-6 #hash command
