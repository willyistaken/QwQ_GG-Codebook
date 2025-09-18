se rnu nu ai ts=4 sw=4 mouse=vi incsearch
sy on
ino ( ()<Esc>i
ino ' ''<Esc>i
ino " ""<Esc>i
ino [ []<Esc>i
ino { {}<Esc>i
ino {<CR> {<CR><Tab><CR>}<Esc>hxka
ino jj <Esc>
ino jk <Esc>
ino kk <Esc>
map <F5> :w<CR>:!g++ -g -fsanitize=undefined,address  -Wall -Wextra -Wshadow %:r.cpp &&echo "Compiled" && ./a.out<CR>
